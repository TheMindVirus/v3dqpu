#include "driver.hxx"

#ifdef ALLOC_PRAGMA
#pragma alloc(INIT, DriverEntry)
#endif

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
    debug("[CALL]: DriverEntry");
    NTSTATUS status = STATUS_SUCCESS;
    DRIVER_INITIALIZATION_DATA config = { 0 };

    status = IoAllocateDriverObjectExtension(DriverObject, DRIVER_TAG_EXTENSION, sizeof(DRIVER_CONTEXT), (PVOID*)&ctx);
    if (!NT_SUCCESS(status)) { debug("[WARN]: IoAllocateDriverObjectExtension: 0x%08lX", status); return status; }
    DriverObject->DriverUnload = DriverUnload;

    if (!ARGUMENT_PRESENT(DriverObject)
    || !ARGUMENT_PRESENT(RegistryPath))
    {
        debug("[WARN]: The Specified DriverObject or RegistryPath is Invalid");
        return STATUS_INVALID_PARAMETER;
    }

    DxgkDdiCallbackPatch(&config);
    status = DxgkInitialize(DriverObject, RegistryPath, &config);
    if (NT_ERROR(status)) { debug("[WARN]: DxgkInitialize() Failed"); return status; }
    return STATUS_SUCCESS;
}

void DriverUnload(PDRIVER_OBJECT DriverObject)
{
    debug("[CALL]: DriverUnload");
    DxgkUnInitialize(DriverObject);
    if (!ctx) { debug("[WARN]: Failed to Allocate Driver Extension while Unloading"); return; }
    if (ctx->iobase_pwr) { MmUnmapIoSpace(ctx->iobase_pwr, V3D_PWR_SIZE); ctx->iobase_pwr = NULL; }
    if (ctx->iobase_asb) { MmUnmapIoSpace(ctx->iobase_asb, V3D_PWR_ASB_SIZE); ctx->iobase_asb = NULL; }
    if (ctx->iobase_v3d) { MmUnmapIoSpace(ctx->iobase_v3d, V3D_PERI_SIZE); ctx->iobase_v3d = NULL; }
}

//dxgkddi.hxx Override
NTSTATUS WINAPI DxgkDdiAddDevice(IN_CONST_PDEVICE_OBJECT PhysicalDeviceObject, OUT_PPVOID MiniportDeviceContext)
{
    debug("[CALL]: DxgkDdiAddDevice");
    UNREFERENCED_PARAMETER(PhysicalDeviceObject);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    PHYSICAL_ADDRESS pwr = { 0 };
    PHYSICAL_ADDRESS asb = { 0 };
    PHYSICAL_ADDRESS v3d = { 0 };

    pwr.QuadPart = V3D_PWR_REG;
    asb.QuadPart = V3D_PWR_ASB_REG;
    v3d.QuadPart = V3D_PERI_BASE;

    if (!ctx) { debug("[WARN]: Failed to Allocate Driver Extension while Loading"); return STATUS_ABANDONED; }
    ctx->iobase_pwr = (PULONG)MmMapIoSpace(pwr, V3D_PWR_SIZE, MmNonCached);
    ctx->iobase_asb = (PULONG)MmMapIoSpace(asb, V3D_PWR_ASB_SIZE, MmNonCached);
    ctx->iobase_v3d = (PULONG)MmMapIoSpace(v3d, V3D_PERI_SIZE, MmNonCached);

    mbox_mmio_setup();

    if ((ctx->iobase_pwr) && (ctx->iobase_asb) && (ctx->iobase_v3d))
    {
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// QPU POWER SEQUENCE
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        debug("[INFO]: INIT_HARDWARE");

        ULONG pwrreg = READ_REGISTER_ULONG(ctx->iobase_pwr);
        debug("[V3D]: PWR_READ | Address: 0x%016llX | Value: 0x%08lX", MmGetPhysicalAddress(ctx->iobase_pwr).QuadPart, pwrreg);
        pwrreg |= V3D_PWR_CMD;
        pwrreg |= V3D_PWR_ON;
        WRITE_REGISTER_ULONG(ctx->iobase_pwr, pwrreg);
        pwrreg = READ_REGISTER_ULONG(ctx->iobase_pwr);
        debug("[V3D]: PWR_WRITE | Address: 0x%016llX | Value: 0x%08lX", MmGetPhysicalAddress(ctx->iobase_pwr).QuadPart, pwrreg);

        ULONG asbsreg = READ_REGISTER_ULONG(ctx->iobase_asb);
        debug("[V3D]: ASB_S_READ | Address: 0x%016llX | Value: 0x%08lX", MmGetPhysicalAddress(ctx->iobase_asb).QuadPart, asbsreg);
        asbsreg |= V3D_PWR_ASB_CMD;
        asbsreg &= V3D_PWR_ASB_MASK;
        WRITE_REGISTER_ULONG(ctx->iobase_asb, asbsreg);
        asbsreg = READ_REGISTER_ULONG(ctx->iobase_asb);
        debug("[V3D]: ASB_S_WRITE | Address: 0x%016llX | Value: 0x%08lX", MmGetPhysicalAddress(ctx->iobase_asb).QuadPart, asbsreg);

        ULONG asbmreg = READ_REGISTER_ULONG(ctx->iobase_asb + 1);
        debug("[V3D]: ASB_M_READ | Address: 0x%016llX | Value: 0x%08lX", MmGetPhysicalAddress(ctx->iobase_asb + 1).QuadPart, asbmreg);
        asbmreg |= V3D_PWR_ASB_CMD;
        asbmreg &= V3D_PWR_ASB_MASK;
        WRITE_REGISTER_ULONG(ctx->iobase_asb + 1, asbmreg);
        asbmreg = READ_REGISTER_ULONG(ctx->iobase_asb + 1);
        debug("[V3D]: ASB_M_WRITE | Address: 0x%016llX | Value: 0x%08lX", MmGetPhysicalAddress(ctx->iobase_asb + 1).QuadPart, asbmreg);

        //WRITE_REGISTER_ULONG(ctx->iobase_v3d + V3D_VPMBASE, 0b00000000000000000000000000000000);

        debug("[INFO]: BEGIN_READ");
        for (ULONG i = 0; i <= V3D_PERI_SIZE / 4; ++i)
        {
            PHYSICAL_ADDRESS address = MmGetPhysicalAddress(ctx->iobase_v3d + i);
            //WRITE_REGISTER_ULONG(ctx->iobase_v3d + i, 0b00000000000000000000000000000000);
            debug("[MMIO]: Offset: 0x%02lX | Address: 0x%016llX | Raw Read: 0x%08lX | Macro Read: 0x%08lX",
                i * 4, address.QuadPart, *(ctx->iobase_v3d + i), READ_REGISTER_ULONG(ctx->iobase_v3d + i));
        }
        debug("[INFO]: END_READ");

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// QPU MEMORY PREPARE
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //TODO: Init Shared Memory and fill with sample QPU Opcodes and Uniforms (not as complex as FFT sample)
        const size_t numQpus = 8;
        VALUE sm_pointer = NULL;
        VALUE sm_data[numQpus] = {};
        VALUE sm_instructions[numQpus] = {};
        VALUE size = 64; //Preliminary: Fill these in
        VALUE align = 4;
        VALUE flags = 0;
        
        qpu_enable(1);
        mem_alloc(sm_pointer, size, align, flags);
        mem_lock(sm_pointer);
        
        //Refer to Broadcom V3D Architecture Guide for Opcodes and Uniforms Structure
        /*
        int mb,         // mailbox file_desc
        int log2_N,     // log2(FFT_length) = 8...22
        int direction,  // GPU_FFT_FWD: fft(); GPU_FFT_REV: ifft()
        
        struct GPU_FFT **fft)
        {
            unsigned info_bytes, twid_bytes, data_bytes, code_bytes, unif_bytes, mail_bytes;
            unsigned size, *uptr, vc_tw, vc_data;
            int i, q, shared, unique, passes, ret;
        }

        if (gpu_fft_twiddle_size(log2_N, &shared, &unique, &passes)) return -2;

        info_bytes = 4096;
        data_bytes = (1+((sizeof(COMPLEX)<<log2_N)|4095));
        code_bytes = gpu_fft_shader_size(log2_N);
        twid_bytes = sizeof(COMPLEX)*16*(shared+GPU_FFT_QPUS*unique);
        unif_bytes = sizeof(int)*GPU_FFT_QPUS*(5+jobs*2);
        mail_bytes = sizeof(int)*GPU_FFT_QPUS*2;

        size  = info_bytes +        // header
                data_bytes*jobs*2 + // ping-pong data, aligned
                code_bytes +        // shader, aligned
                twid_bytes +        // twiddles
                unif_bytes +        // uniforms
                mail_bytes;         // mailbox message

        uart_write("[QPU]: Allocating...\n");
        ret = gpu_fft_alloc(mb, size, &ptr);
        if (ret) return ret;
        uart_write("[QPU]: Allocated\n");

        // Header
        info = (struct GPU_FFT *) ptr.arm.vptr;
        base = (struct GPU_FFT_BASE *) info;
        gpu_fft_ptr_inc(&ptr, info_bytes);

        // For transpose
        info->x = 1<<log2_N;
        info->y = jobs;

        // Ping-pong buffers leave results in or out of place
        info->in = info->out = ptr.arm.cptr;
        info->step = data_bytes / sizeof(COMPLEX);
        if (passes&1) info->out += info->step * jobs; // odd => out of place
        vc_data = gpu_fft_ptr_inc(&ptr, data_bytes*jobs*2);

        // Shader code
        memcpy(ptr.arm.vptr, gpu_fft_shader_code(log2_N), code_bytes);
        base->vc_code = gpu_fft_ptr_inc(&ptr, code_bytes);

        // Twiddles
        gpu_fft_twiddle_data(log2_N, direction, ptr.arm.fptr);
        vc_tw = gpu_fft_ptr_inc(&ptr, twid_bytes);

        uptr = ptr.arm.uptr;

        // Uniforms
        for (q=0; q<GPU_FFT_QPUS; q++)
        {
            *uptr++ = vc_tw;
            *uptr++ = vc_tw + sizeof(COMPLEX)*16*(shared + q*unique);
            *uptr++ = q;
            for (i=0; i<jobs; i++)
            {
                *uptr++ = vc_data + data_bytes*i;
                *uptr++ = vc_data + data_bytes*i + data_bytes*jobs;
            }
            *uptr++ = 0;
            *uptr++ = (q==0); // For mailbox: IRQ enable, master only

            base->vc_unifs[q] = gpu_fft_ptr_inc(&ptr, sizeof(int)*(5+jobs*2));
        }

        // Mailbox message
        for (size_t q=0; q<GPU_FFT_QPUS; q++)
        {
            *uptr++ = base->vc_unifs[q];
            *uptr++ = base->vc_code;
        }
        */

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// QPU HARDWARE TEST
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        int t = 0;
        int tMax = 100;

        debug("[QPU]: STAGE[0]: SANITY_CHECK");
        debug("[QPU]: STAGE[0]: V3D_IDENT0 = 0x%08lX", READ_REGISTER_ULONG(ctx->iobase_v3d + V3D_IDENT0));

        debug("[QPU]: STAGE[1]: DISABLE_IRQ");
        WRITE_REGISTER_ULONG(ctx->iobase_v3d + V3D_DBCFG,   0x00000000); // Disallows IRQ
        WRITE_REGISTER_ULONG(ctx->iobase_v3d + V3D_DBQITE,  0x00000000); // Disables IRQ
        WRITE_REGISTER_ULONG(ctx->iobase_v3d + V3D_DBQITC,  0xFFFFFFFF); // Resets IRQ Flags

        debug("[QPU]: STAGE[2]: CLEAR_L2_CACHE");
        WRITE_REGISTER_ULONG(ctx->iobase_v3d + V3D_L2CACTL, 0x00000004); // Resets IRQ Flags
        WRITE_REGISTER_ULONG(ctx->iobase_v3d + V3D_SLCACTL, 0xFFFFFFFF); // Clears Caches

        debug("[QPU]: STAGE[3]: RESET_ERROR_BITS");
        WRITE_REGISTER_ULONG(ctx->iobase_v3d + V3D_SRQCS,   0x000080C0); // Resets Error Bits and Counts

        debug("[QPU]: STAGE[4]: LAUNCH_SHADERS");
        for (size_t q = 0; q < numQpus; ++q) // Launch shader(s)
        {
            WRITE_REGISTER_ULONG(ctx->iobase_v3d + V3D_SRQUA, sm_data[q]); // Uniforms Address in Shared Memory
            WRITE_REGISTER_ULONG(ctx->iobase_v3d + V3D_SRQPC, sm_instructions[q]); // Program Counter in Shared Memory
        }

        debug("[QPU]: STAGE[5]: POLL_SCOREBOARD");
        while (true) // Busy wait polling
        {
            //Scoreboard Format: 0xXXYY - XX: Total Jobs, YY: Failed Jobs
            if (((READ_REGISTER_ULONG(ctx->iobase_v3d + V3D_SRQCS) >> 8) & 0xFF) == (ULONG)numQpus) { break; } // All done?
            debug("[QPU]: STAGE[5]: V3D_SRQCS = 0x%08lX", READ_REGISTER_ULONG(ctx->iobase_v3d + V3D_SRQCS));
            KeStallExecutionProcessor(1000);
            ++t; if (t > tMax) { break; }
        }

        debug("[QPU]: STAGE[6]: COMPLETE\n");

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// QPU MEMORY RELEASE
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //TODO: Release Shared Memory previously allocated with sample QPU Opcodes and Uniforms
        mem_unlock(sm_pointer);
        mem_free(sm_pointer);
        qpu_enable(0);
        sm_pointer = NULL; //cleanup all pointers to shared memory

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
    else { debug("[WARN]: Failed to Map I/O Space Memory"); return STATUS_NONE_MAPPED; }

    mbox_mmio_cleanup();

    return STATUS_SUCCESS;
}