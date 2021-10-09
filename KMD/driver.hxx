#ifndef _DRIVER_HXX_
#define _DRIVER_HXX_

#ifdef DBG
#define DBG   1
#define debug(...)   \
	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, __VA_ARGS__)); \
    KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "\n"));
#else
#define debug(...)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <ntddk.h>
#include <wdf.h>

typedef struct
{
	PULONG iobase_pwr;
	PULONG iobase_asb;
	PULONG iobase_v3d;
}   DRIVER_CONTEXT, *PDRIVER_CONTEXT;
static PDRIVER_CONTEXT ctx;
#define DRIVER_TAG_EXTENSION   (PVOID)1

extern "C"
{
	DRIVER_INITIALIZE   DriverEntry;
	DRIVER_UNLOAD       DriverUnload;
}

#include "dxgkddi.hxx"
#include "mbox.hxx"

///BCM2711 ARM Peripherals - Page 5
///https://datasheets.raspberrypi.org/bcm2711/bcm2711-peripherals.pdf

///Broadcom VideocoreIV 3D Architecture Guide - Page 82
///https://docs.broadcom.com/doc/12358545

///GitHub - PeterLemon/RaspberryPi/V3D/V3DINIT/LIB/V3D.INC
///https://github.com/PeterLemon/RaspberryPi/blob/master/V3D/V3DINIT/LIB/V3D.INC

///GitHub - kumaashi/RaspberryPI/RPI4/v3d_power_on/main.c
///https://github.com/kumaashi/RaspberryPI/blob/master/RPI4/v3d_power_on/main.c

//#define VC4_STRIDE   4   //sizeof(ULONG) //32-bit...or 64-bit if you're on Linux...

#define VC4_PERI_BASE   0xFC000000
#define V3D_PERI_BASE   VC4_PERI_BASE + 0x2C00000 + 0x4000
#define V3D_PERI_SIZE   0xF20

#define V3D_PWR_REG        0xFE10010C   //V3D Power Switch Register
#define V3D_PWR_SIZE       4            //1x 32-bit Register (4-bytes)
#define V3D_PWR_CMD        0x5A000000   //V3D Power On Command
#define V3D_PWR_ON         0x00000040   //V3D Power On Value

#define V3D_PWR_ASB_REG    0xFEC11008   //V3D ASB Power Release Register
#define V3D_PWR_ASB_SIZE   8            //2x 32-bit Register (8-bytes)
#define V3D_PWR_ASB_CMD    0x5A000000   //V3D ASB Power On Command
#define V3D_PWR_ASB_MASK   0xFFFFFFFE   //V3D ASB Power On Mask

#define V3D_IDENT0    0     //0x00000 //V3D Identification 0 (V3D Block Identity)
#define V3D_IDENT1    1     //0x00004 //V3D Identification 1 (Configuration A)
#define V3D_IDENT2    2     //0x00008 //V3D Identification 2 (Configuration B)
#define V3D_IDENT3    3     //0x0000C //V3D Identification 3 (Configuration C)
#define V3D_SCRATCH   4     //0x00010 //V3D Scratch Register
#define V3D_L2CACTL   8     //0x00020 //V3D L2 Cache Control
#define V3D_SLCACTL   9     //0x00024 //V3D Slices Cache Control
#define V3D_INTCTL    12    //0x00030 //V3D Interrupt Control
#define V3D_INTENA    13    //0x00034 //V3D Interrupt Enables
#define V3D_INTDIS    14    //0x00038 //V3D Interrupt Disables
#define V3D_CT0CS     64    //0x00100 //V3D Control List Executor Thread 0 (Control and Status)
#define V3D_CT1CS     65    //0x00104 //V3D Control List Executor Thread 1 (Control and Status)
#define V3D_CT0EA     66    //0x00108 //V3D Control List Executor Thread 0 (End Address)
#define V3D_CT1EA     67    //0x0010C //V3D Control List Executor Thread 1 (End Address)
#define V3D_CT0CA     68    //0x00110 //V3D Control List Executor Thread 0 (Current Address)
#define V3D_CT1CA     69    //0x00114 //V3D Control List Executor Thread 1 (Current Address)
#define V3D_CT00RA0   70    //0x00118 //V3D Control List Executor Thread 0 (Return Address)
#define V3D_CT01RA0   71    //0x0011C //V3D Control List Executor Thread 1 (Return Address)
#define V3D_CT0LC     72    //0x00120 //V3D Control List Executor Thread 0 (List Counter)
#define V3D_CT1LC     73    //0x00124 //V3D Control List Executor Thread 1 (List Counter)
#define V3D_CT0PC     74    //0x00128 //V3D Control List Executor Thread 0 (Primitive List Counter)
#define V3D_CT1PC     75    //0x0012C //V3D Control List Executor Thread 1 (Primitive List Counter)
#define V3D_PCS       76    //0x00130 //V3D Pipeline (Control and Status)
#define V3D_BFC       77    //0x00134 //V3D Binning Mode Flush Count
#define V3D_RFC       78    //0x00138 //V3D Rendering Mode Frame Count
#define V3D_BPCA      192   //0x00300 //V3D Current Address of Binning Memory Pool
#define V3D_BPCS      193   //0x00304 //V3D Remaining Size of Binning Memory Pool

#define V3D_BPOA      194   //0x00308 //V3D Address of Overspill Binning Memory Block
#define V3D_BPOS      195   //0x0030C //V3D Size of Overspill Binning Memory Block
#define V3D_BXCF      196   //0x00310 //V3D Binner Debug
#define V3D_SQRSV0    260   //0x00410 //V3D Reserve QPU Slices 0-7
#define V3D_SQRSV1    261   //0x00414 //V3D Reserve QPU Slices 8-15
#define V3D_SQCNTL    262   //0x00418 //V3D QPU Scheduler Control
#define V3D_SQCSTAT   263   //0x0041C //V3D QPU Scheduler State
#define V3D_SRQPC     268   //0x00430 //V3D QPU User Program Request (Program Address)
#define V3D_SRQUA     269   //0x00434 //V3D QPU User Program Request (Uniforms Address)
#define V3D_SRQUL     270   //0x00438 //V3D QPU User Program Request (Uniforms Length)
#define V3D_SRQCS     271   //0x0043C //V3D QPU User Program Request (Control and Status)
#define V3D_VPACNTL   320   //0x00500 //V3D VPM Allocator Control
#define V3D_VPMBASE   321   //0x00504 //V3D VPM Base (User) Memory Reservation

#define V3D_PCTRC     412   //0x00670 //V3D Performance Counter Clear
#define V3D_PCTRE     413   //0x00674 //V3D Performance Coutner Enables
#define V3D_PCTR0     416   //0x00680 //V3D Performance Counter Count 0
#define V3D_PCTRS0    417   //0x00684 //V3D Performance Counter Mapping 0
#define V3D_PCTR1     418   //0x00688 //V3D Performance Counter Count 1
#define V3D_PCTRS1    419   //0x0068C //V3D Performance Counter Mapping 1
#define V3D_PCTR2     420   //0x00690 //V3D Performance Counter Count 2
#define V3D_PCTRS2    421   //0x00694 //V3D Performance Counter Mapping 2
#define V3D_PCTR3     422   //0x00698 //V3D Performance Counter Count 3
#define V3D_PCTRS3    423   //0x0069C //V3D Performance Counter Mapping 3
#define V3D_PCTR4     424   //0x006A0 //V3D Performance Counter Count 4
#define V3D_PCTRS4    425   //0x006A4 //V3D Performance Counter Mapping 4
#define V3D_PCTR5     426   //0x006A8 //V3D Performance Counter Count 5
#define V3D_PCTRS5    427   //0x006AC //V3D Performance Counter Mapping 5
#define V3D_PCTR6     428   //0x006B0 //V3D Performance Counter Count 6
#define V3D_PCTRS6    429   //0x006B4 //V3D Performance Counter Mapping 6
#define V3D_PCTR7     430   //0x006B8 //V3D Performance Counter Count 7
#define V3D_PCTRS7    431   //0x006BC //V3D Performance Counter Mapping 7
#define V3D_PCTR8     432   //0x006C0 //V3D Performance Counter Count 8
#define V3D_PCTRS8    433   //0x006C4 //V3D Performance Counter Mapping 8
#define V3D_PCTR9     434   //0x006C8 //V3D Performance Counter Count 9
#define V3D_PCTRS9    435   //0x006CC //V3D Performance Counter Mapping 9
#define V3D_PCTR10    436   //0x006D0 //V3D Performance Counter Count 10
#define V3D_PCTRS10   437   //0x006D4 //V3D Performance Counter Mapping 10
#define V3D_PCTR11    438   //0x006D8 //V3D Performance Counter Count 11
#define V3D_PCTRS11   439   //0x006DC //V3D Performance Counter Mapping 11
#define V3D_PCTR12    440   //0x006E0 //V3D Performance Counter Count 12
#define V3D_PCTRS12   441   //0x006E4 //V3D Performance Counter Mapping 12
#define V3D_PCTR13    442   //0x006E8 //V3D Performance Counter Count 13
#define V3D_PCTRS13   443   //0x006EC //V3D Performance Counter Mapping 13
#define V3D_PCTR14    444   //0x006F0 //V3D Performance Counter Count 14
#define V3D_PCTRS14   445   //0x006F4 //V3D Performance Counter Mapping 14
#define V3D_PCTR15    446   //0x006F8 //V3D Performance Counter Count 15
#define V3D_PCTRS15   447   //0x006FC //V3D Performance Counter Mapping 15

//--HIDDEN-DEBUG-INTERFACE----------------------------------------

#define V3D_DBCFG     896   //0x00E00 //V3D Debug Configure
#define V3D_DBSCS     897   //0x00E04 //V3D Debug S (Control and Status)
#define V3D_DBSCFG    898   //0x00E08 //V3D Debug S Configure
#define V3D_DBSSR     899   //0x00E0C //V3D Debug S SR
#define V3D_DBSDR0    900   //0x00E10 //V3D Debug SD R0
#define V3D_DBSDR1    901   //0x00E14 //V3D Debug SD R1
#define V3D_DBSDR2    902   //0x00E18 //V3D Debug SD R2
#define V3D_DBSDR3    903   //0x00E1C //V3D Debug SD R3
#define V3D_DBQRUN    904   //0x00E20 //V3D Debug QPU Run
#define V3D_DBQHLT    905   //0x00E24 //V3D Debug QPU Halt
#define V3D_DBQSTP    906   //0x00E28 //V3D Debug QPU Step
#define V3D_DBQITE    907   //0x00E2C //V3D Debug QPU Interrupt Enables
#define V3D_DBQITC    908   //0x00E30 //V3D Debug QPU Interrupt Control
#define V3D_DBQGHC    909   //0x00E34 //V3D Debug QPU GHC
#define V3D_DBQGHG    910   //0x00E38 //V3D Debug QPU GHG
#define V3D_DBQGHH    911   //0x00E3C //V3D Debug QPU GHH

//----------------------------------------------------------------

#define V3D_DBGE      960   //0x00F00 //V3D Debug PSE Error Signals
#define V3D_FDBGO     961   //0x00F04 //V3D Debug FEP Overrun Error Signals
#define V3D_FDBGB     962   //0x00F08 //V3D Debug FEP Interface Ready/Stall/Busy Signals
#define V3D_FDBGR     963   //0x00F0C //V3D Debug FEP Internal Ready Signals
#define V3D_FDBGS     964   //0x00F10 //V3D Debug FEP Internal Stall Input Signals
#define V3D_ERRSTAT   968   //0x00F20 //V3D Debug Miscellaneous Error Signals (VPM, VDW, VCD, VCM, L2C)

//Note: A lot of registers are missing...All reads are assumed 32-bit value 64-bit address (not 8-bit offset)

#endif//_DRIVER_HXX_