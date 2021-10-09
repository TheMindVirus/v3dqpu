#include "driver.hxx"

/// -- WDDM2 Control Flow -- Windows Display Driver Model 2.0 -- Windows Kernel Mode Driver Framework --
///https://docs.microsoft.com/en-us/windows-hardware/drivers/display/windows-vista-and-later-display-driver-model-operation-flow

//DXGKDDI_CALLBACK_PATCH (Undocumented) - Patches all callbacks to DXGK in one go for DxgkInitialize()
VOID WINAPI DxgkDdiCallbackPatch(PDRIVER_INITIALIZATION_DATA pConfig)
{
    pConfig->Version = DXGKDDI_INTERFACE_VERSION;
#pragma region //Device Section
    pConfig->DxgkDdiCreateDevice = DxgkDdiCreateDevice;
    pConfig->DxgkDdiAddDevice = DxgkDdiAddDevice;
    pConfig->DxgkDdiLinkDevice = DxgkDdiLinkDevice;
    pConfig->DxgkDdiStartDevice = DxgkDdiStartDevice;
    pConfig->DxgkDdiResetDevice = DxgkDdiResetDevice;
    pConfig->DxgkDdiStopDevice = DxgkDdiStopDevice;
    pConfig->DxgkDdiRemoveDevice = DxgkDdiRemoveDevice;
    pConfig->DxgkDdiDestroyDevice = DxgkDdiDestroyDevice;
    pConfig->DxgkDdiUnload = DxgkDdiUnload;
#pragma endregion
#pragma region //Present Section
    pConfig->DxgkDdiPresent = DxgkDdiPresent;
    pConfig->DxgkDdiRender = DxgkDdiRender;
    pConfig->DxgkDdiRenderKm = DxgkDdiRenderKm;
    pConfig->DxgkDdiRenderGdi = DxgkDdiRenderGdi;
    pConfig->DxgkDdiSubmitRender = DxgkDdiSubmitRender;
#pragma endregion
#pragma region //Command Section
    pConfig->DxgkDdiPatch = DxgkDdiPatch;
    pConfig->DxgkDdiPreemptCommand = DxgkDdiPreemptCommand;
    pConfig->DxgkDdiSubmitCommand = DxgkDdiSubmitCommand;
    pConfig->DxgkDdiSubmitCommandVirtual = DxgkDdiSubmitCommandVirtual;
    pConfig->DxgkDdiValidateSubmitCommand = DxgkDdiValidateSubmitCommand;
    pConfig->DxgkDdiCancelCommand = DxgkDdiCancelCommand;
    pConfig->DxgkDdiBuildPagingBuffer = DxgkDdiBuildPagingBuffer;
    pConfig->DxgkDdiResetFromTimeout = DxgkDdiResetFromTimeout;
    pConfig->DxgkDdiRestartFromTimeout = DxgkDdiRestartFromTimeout;
    pConfig->DxgkDdiEscape = DxgkDdiEscape;
#pragma endregion
#pragma region //Calibration Section
    pConfig->DxgkDdiExchangePreStartInfo = DxgkDdiExchangePreStartInfo;
    pConfig->DxgkDdiFormatHistoryBuffer = DxgkDdiFormatHistoryBuffer;
    pConfig->DxgkDdiControlDiagnosticReporting = DxgkDdiControlDiagnosticReporting;
    pConfig->DxgkDdiCollectDiagnosticInfo = DxgkDdiCollectDiagnosticInfo;
    pConfig->DxgkDdiCalibrateGpuClock = DxgkDdiCalibrateGpuClock;
    pConfig->DxgkDdiControlModeBehavior = DxgkDdiControlModeBehavior;
    pConfig->DxgkDdiUpdateMonitorLinkInfo = DxgkDdiUpdateMonitorLinkInfo;
    pConfig->DxgkDdiValidateUpdateAllocationProperty = DxgkDdiValidateUpdateAllocationProperty;
#pragma endregion
#pragma region //Set Calibration Section
    pConfig->DxgkDdiSetupPriorityBands = DxgkDdiSetupPriorityBands;
    pConfig->DxgkDdiSetContextSchedulingProperties = DxgkDdiSetContextSchedulingProperties;
    pConfig->DxgkDdiSetSchedulingLogBuffer = DxgkDdiSetSchedulingLogBuffer;
    pConfig->DxgkDdiSetTargetGamma = DxgkDdiSetTargetGamma;
    pConfig->DxgkDdiSetTargetContentType = DxgkDdiSetTargetContentType;
    pConfig->DxgkDdiSetTargetAnalogCopyProtection = DxgkDdiSetTargetAnalogCopyProtection;
    pConfig->DxgkDdiSetTargetAdjustedColorimetry = DxgkDdiSetTargetAdjustedColorimetry;
    pConfig->DxgkDdiSetTargetAdjustedColorimetry2 = DxgkDdiSetTargetAdjustedColorimetry2;
#pragma endregion
#pragma region //Set Section
    pConfig->DxgkDdiSetPalette = DxgkDdiSetPalette;
    pConfig->DxgkDdiSetPointerPosition = DxgkDdiSetPointerPosition;
    pConfig->DxgkDdiSetPointerShape = DxgkDdiSetPointerShape;
    pConfig->DxgkDdiSetPowerState = DxgkDdiSetPowerState;
    pConfig->DxgkDdiSetPowerPState = DxgkDdiSetPowerPState;
    pConfig->DxgkDdiSetPowerComponentFState = DxgkDdiSetPowerComponentFState;
    pConfig->DxgkDdiSetStablePowerState = DxgkDdiSetStablePowerState;
    pConfig->DxgkDdiSetTrackedWorkloadPowerLevel = DxgkDdiSetTrackedWorkloadPowerLevel;
    pConfig->DxgkDdiSetDisplayPrivateDriverFormat = DxgkDdiSetDisplayPrivateDriverFormat;
    pConfig->DxgkDdiSetVideoProtectedRegion = DxgkDdiSetVideoProtectedRegion;
#pragma endregion
#pragma region //Get Section
    pConfig->DxgkDdiGetScanLine = DxgkDdiGetScanLine;
    pConfig->DxgkDdiGetNodeMetadata = DxgkDdiGetNodeMetadata;
    pConfig->DxgkDdiGetChildContainerId = DxgkDdiGetChildContainerId;
    pConfig->DxgkDdiGetPostCompositionCaps = DxgkDdiGetPostCompositionCaps;
#pragma endregion
#pragma region //Notify Section
    pConfig->DxgkDdiNotifyAcpiEvent = DxgkDdiNotifyAcpiEvent;
    pConfig->DxgkDdiNotifyFocusPresent = DxgkDdiNotifyFocusPresent;
    pConfig->DxgkDdiNotifySurpriseRemoval = DxgkDdiNotifySurpriseRemoval;
    pConfig->DxgkDdiPowerRuntimeControlRequest = DxgkDdiPowerRuntimeControlRequest;
    pConfig->DxgkDdiPowerRuntimeSetDeviceHandle = DxgkDdiPowerRuntimeSetDeviceHandle;
    pConfig->DxgkDdiCreatePeriodicFrameNotification = DxgkDdiCreatePeriodicFrameNotification;
    pConfig->DxgkDdiDestroyPeriodicFrameNotification = DxgkDdiDestroyPeriodicFrameNotification;
    pConfig->DxgkDdiSignalMonitoredFence = DxgkDdiSignalMonitoredFence;
    pConfig->DxgkDdiDisplayDetectControl = DxgkDdiDisplayDetectControl;
    pConfig->DxgkDdiRecommendMonitorModes = DxgkDdiRecommendMonitorModes;
#pragma endregion
#pragma region //Query Section
    pConfig->DxgkDdiQueryInterface = DxgkDdiQueryInterface;
    pConfig->DxgkDdiQueryAdapterInfo = DxgkDdiQueryAdapterInfo;
    pConfig->DxgkDdiQueryCurrentFence = DxgkDdiQueryCurrentFence;
    pConfig->DxgkDdiQueryDeviceDescriptor = DxgkDdiQueryDeviceDescriptor;
    pConfig->DxgkDdiQueryVidPnHWCapability = DxgkDdiQueryVidPnHWCapability;
    pConfig->DxgkDdiQueryChildRelations = DxgkDdiQueryChildRelations;
    pConfig->DxgkDdiQueryChildStatus = DxgkDdiQueryChildStatus;
    pConfig->DxgkDdiQueryConnectionChange = DxgkDdiQueryConnectionChange;
    pConfig->DxgkDdiQueryDiagnosticTypesSupport = DxgkDdiQueryDiagnosticTypesSupport;
    pConfig->DxgkDdiQueryDependentEngineGroup = DxgkDdiQueryDependentEngineGroup;
    pConfig->DxgkDdiQueryEngineStatus = DxgkDdiQueryEngineStatus;
#pragma endregion
#pragma region //Video Present Network (VidPn) Section
    pConfig->DxgkDdiCommitVidPn = DxgkDdiCommitVidPn;
    pConfig->DxgkDdiIsSupportedVidPn = DxgkDdiIsSupportedVidPn;
    pConfig->DxgkDdiEnumVidPnCofuncModality = DxgkDdiEnumVidPnCofuncModality;
    pConfig->DxgkDdiRecommendFunctionalVidPn = DxgkDdiRecommendFunctionalVidPn;
    pConfig->DxgkDdiGetMultiPlaneOverlayCaps = DxgkDdiGetMultiPlaneOverlayCaps;
    pConfig->DxgkDdiPostMultiPlaneOverlayPresent = DxgkDdiPostMultiPlaneOverlayPresent;
    pConfig->DxgkDdiCheckMultiPlaneOverlaySupport = DxgkDdiCheckMultiPlaneOverlaySupport;
    pConfig->DxgkDdiCheckMultiPlaneOverlaySupport2 = DxgkDdiCheckMultiPlaneOverlaySupport2;
    pConfig->DxgkDdiCheckMultiPlaneOverlaySupport3 = DxgkDdiCheckMultiPlaneOverlaySupport3;
    pConfig->DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay = DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay;
    pConfig->DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2 = DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2;
    pConfig->DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay3 = DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay3;
    pConfig->DxgkDdiSetVidPnSourceAddress = DxgkDdiSetVidPnSourceAddress;
    pConfig->DxgkDdiSetVidPnSourceVisibility = DxgkDdiSetVidPnSourceVisibility;
    pConfig->DxgkDdiSetTimingsFromVidPn = DxgkDdiSetTimingsFromVidPn;
    pConfig->DxgkDdiUpdateActiveVidPnPresentPath = DxgkDdiUpdateActiveVidPnPresentPath;
    pConfig->DxgkDdiRecommendVidPnTopology = DxgkDdiRecommendVidPnTopology;
#pragma endregion
#pragma region //Engine Section
    pConfig->DxgkDdiResetEngine = DxgkDdiResetEngine;
    pConfig->DxgkDdiResumeHwEngine = DxgkDdiResumeHwEngine;
    pConfig->DxgkDdiResetHwEngine = DxgkDdiResetHwEngine;
    pConfig->DxgkDdiCreateProcess = DxgkDdiCreateProcess;
    pConfig->DxgkDdiDestroyProcess = DxgkDdiDestroyProcess;
    pConfig->DxgkDdiStopCapture = DxgkDdiStopCapture;
    pConfig->DxgkDdiStopDeviceAndReleasePostDisplayOwnership = DxgkDdiStopDeviceAndReleasePostDisplayOwnership;
    pConfig->DxgkDdiSystemDisplayEnable = DxgkDdiSystemDisplayEnable;
    pConfig->DxgkDdiSystemDisplayWrite = DxgkDdiSystemDisplayWrite;
#pragma endregion
#pragma region //Interrupt Section
    pConfig->DxgkDdiDpcRoutine = DxgkDdiDpcRoutine;
    pConfig->DxgkDdiInterruptRoutine = DxgkDdiInterruptRoutine;
    pConfig->DxgkDdiDispatchIoRequest = DxgkDdiDispatchIoRequest;
    pConfig->DxgkDdiControlInterrupt = DxgkDdiControlInterrupt;
    pConfig->DxgkDdiControlInterrupt2 = DxgkDdiControlInterrupt2;
    pConfig->DxgkDdiControlInterrupt3 = DxgkDdiControlInterrupt3;
    pConfig->DxgkDdiControlEtwLogging = DxgkDdiControlEtwLogging;
    pConfig->DxgkDdiCollectDbgInfo = DxgkDdiCollectDbgInfo;
#pragma endregion
#pragma region //Allocation Section
    pConfig->DxgkDdiGetStandardAllocationDriverData = DxgkDdiGetStandardAllocationDriverData;
    pConfig->DxgkDdiDescribeAllocation = DxgkDdiDescribeAllocation;
    pConfig->DxgkDdiCreateAllocation = DxgkDdiCreateAllocation;
    pConfig->DxgkDdiCreateAllocation2 = DxgkDdiCreateAllocation2;
    pConfig->DxgkDdiOpenAllocation = DxgkDdiOpenAllocation;
    pConfig->DxgkDdiCloseAllocation = DxgkDdiCloseAllocation;
    pConfig->DxgkDdiDestroyAllocation = DxgkDdiDestroyAllocation;
#pragma endregion
#pragma region //Context Section
    pConfig->DxgkDdiCreateContext = DxgkDdiCreateContext;
    pConfig->DxgkDdiSuspendContext = DxgkDdiSuspendContext;
    pConfig->DxgkDdiResumeContext = DxgkDdiResumeContext;
    pConfig->DxgkDdiDestroyContext = DxgkDdiDestroyContext;
    pConfig->DxgkDdiCreateHwContext = DxgkDdiCreateHwContext;
    pConfig->DxgkDdiDestroyHwContext = DxgkDdiDestroyHwContext;
    pConfig->DxgkDdiCreateHwQueue = DxgkDdiCreateHwQueue;
    pConfig->DxgkDdiPresentToHwQueue = DxgkDdiPresentToHwQueue;
    pConfig->DxgkDdiUpdateHwContextState = DxgkDdiUpdateHwContextState;
    pConfig->DxgkDdiSubmitCommandToHwQueue = DxgkDdiSubmitCommandToHwQueue;
    pConfig->DxgkDdiSwitchToHwContextList = DxgkDdiSwitchToHwContextList;
    pConfig->DxgkDdiDestroyHwQueue = DxgkDdiDestroyHwQueue;
#pragma endregion
#pragma region //Overlay Section
    pConfig->DxgkDdiCreateOverlay = DxgkDdiCreateOverlay;
    pConfig->DxgkDdiUpdateOverlay = DxgkDdiUpdateOverlay;
    pConfig->DxgkDdiFlipOverlay = DxgkDdiFlipOverlay;
    pConfig->DxgkDdiDestroyOverlay = DxgkDdiDestroyOverlay;
    pConfig->DxgkDdiMapCpuHostAperture = DxgkDdiMapCpuHostAperture;
    pConfig->DxgkDdiUnmapCpuHostAperture = DxgkDdiUnmapCpuHostAperture;
    pConfig->DxgkDdiAcquireSwizzlingRange = DxgkDdiAcquireSwizzlingRange;
    pConfig->DxgkDdiReleaseSwizzlingRange = DxgkDdiReleaseSwizzlingRange;
#pragma endregion
#pragma region //Exclusive Section
    pConfig->DxgkDdiCreateProtectedSession = DxgkDdiCreateProtectedSession;
    pConfig->DxgkDdiDestroyProtectedSession = DxgkDdiDestroyProtectedSession;
    pConfig->DxgkDdiSetVirtualMachineData = DxgkDdiSetVirtualMachineData;
    pConfig->DxgkDdiBeginExclusiveAccess = DxgkDdiBeginExclusiveAccess;
    pConfig->DxgkDdiEndExclusiveAccess = DxgkDdiEndExclusiveAccess;
    pConfig->DxgkDdiSaveMemoryForHotUpdate = DxgkDdiSaveMemoryForHotUpdate;
    pConfig->DxgkDdiRestoreMemoryForHotUpdate = DxgkDdiRestoreMemoryForHotUpdate;
#pragma endregion
#pragma region //Reserved Section
    pConfig->DxgkDdiSetRootPageTable = DxgkDdiSetRootPageTable;
    pConfig->DxgkDdiGetRootPageTableSize = DxgkDdiGetRootPageTableSize;
    pConfig->DxgkDdiDescribePageTable = DxgkDdiDescribePageTable;
    pConfig->DxgkDdiUpdatePageTable = DxgkDdiUpdatePageTable;
    pConfig->DxgkDdiUpdatePageDirectory = DxgkDdiUpdatePageDirectory;
    pConfig->DxgkDdiMovePageDirectory = DxgkDdiMovePageDirectory;
    pConfig->Reserved = Reserved;
    pConfig->Reserved1 = Reserved1;
    pConfig->Reserved2 = Reserved2;
    pConfig->Reserved3 = Reserved3;
#pragma endregion
}

//--------------------------------------------------------------------------------------------------------
#pragma region //Device Section

//DXGKDDI_CREATEDEVICE
NTSTATUS APIENTRY DxgkDdiCreateDevice
(
    IN_CONST_HANDLE               hAdapter,
    INOUT_PDXGKARG_CREATEDEVICE   pCreateDevice
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pCreateDevice);
    return STATUS_ABANDONED;
}
/* //Override
//DXGKDDI_ADD_DEVICE
NTSTATUS DxgkDdiAddDevice
(
    IN_CONST_PDEVICE_OBJECT   PhysicalDeviceObject,
    OUT_PPVOID                MiniportDeviceContext
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(PhysicalDeviceObject);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    return STATUS_ABANDONED;
}
*/
//DXGKDDI_LINK_DEVICE
NTSTATUS DxgkDdiLinkDevice
(
    IN_CONST_PDEVICE_OBJECT   PhysicalDeviceObject,
    IN_CONST_PVOID            MiniportDeviceContext,
    INOUT_PLINKED_DEVICE      LinkedDevice
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(PhysicalDeviceObject);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(LinkedDevice);
    return STATUS_ABANDONED;
}

//DXGKDDI_START_DEVICE
NTSTATUS DxgkDdiStartDevice
(
    IN_CONST_PVOID          MiniportDeviceContext,
    IN_PDXGK_START_INFO     DxgkStartInfo,
    IN_PDXGKRNL_INTERFACE   DxgkInterface,
    OUT_PULONG              NumberOfVideoPresentSources,
    OUT_PULONG              NumberOfChildren
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(DxgkStartInfo);
    UNREFERENCED_PARAMETER(DxgkInterface);
    UNREFERENCED_PARAMETER(NumberOfVideoPresentSources);
    UNREFERENCED_PARAMETER(NumberOfChildren);
    return STATUS_ABANDONED;
}

//DXGKDDI_RESET_DEVICE
VOID DxgkDdiResetDevice
(
    IN_CONST_PVOID   MiniportDeviceContext
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
}

//DXGKDDI_STOP_DEVICE
NTSTATUS DxgkDdiStopDevice
(
    IN_CONST_PVOID   MiniportDeviceContext
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    return STATUS_ABANDONED;
}

//DXGKDDI_REMOVE_DEVICE
NTSTATUS DxgkDdiRemoveDevice
(
    IN_CONST_PVOID   MiniportDeviceContext
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    return STATUS_ABANDONED;
}

//DXGKDDI_DESTROYDEVICE
NTSTATUS APIENTRY DxgkDdiDestroyDevice
(
    IN_CONST_HANDLE   hDevice
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hDevice);
    return STATUS_ABANDONED;
}

//DXGKDDI_UNLOAD
VOID DxgkDdiUnload
(
    VOID
)
{
    debug("[CALL]: %s", __FUNCTION__);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Present Section

//DXGKDDI_PRESENT
NTSTATUS APIENTRY DxgkDdiPresent
(
    IN_CONST_HANDLE          hContext,
    INOUT_PDXGKARG_PRESENT   pPresent
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hContext);
    UNREFERENCED_PARAMETER(pPresent);
    return STATUS_ABANDONED;
}

//DXGKDDI_RENDER
NTSTATUS APIENTRY DxgkDdiRender
(
    IN_CONST_HANDLE         hContext,
    INOUT_PDXGKARG_RENDER   pRender
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hContext);
    UNREFERENCED_PARAMETER(pRender);
    return STATUS_ABANDONED;
}

//DXGKDDI_RENDER
NTSTATUS APIENTRY DxgkDdiRenderKm
(
    IN_CONST_HANDLE         hContext,
    INOUT_PDXGKARG_RENDER   pRender
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hContext);
    UNREFERENCED_PARAMETER(pRender);
    return STATUS_ABANDONED;
}

//DXGKDDI_RENDERGDI
NTSTATUS APIENTRY DxgkDdiRenderGdi
(
    IN_CONST_HANDLE            hContext,
    INOUT_PDXGKARG_RENDERGDI   pRenderGdi
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hContext);
    UNREFERENCED_PARAMETER(pRenderGdi);
    return STATUS_ABANDONED;
}

//DXGKDDI_SUBMITRENDER (Reserved)
DXGKDDI_UNDEFINED DxgkDdiSubmitRender = NULL;
//(
//    IN_CONST_HANDLE               hContext,
//    INOUT_PDXGKARG_SUBMITRENDER   pSubmitRender
//)
//{
//	  debug("[CALL]: %s", __FUNCTION__);
//    UNREFERENCED_PARAMETER(hContext);
//    UNREFERENCED_PARAMETER(pSubmitRender);
//}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Command Section

//DXGKDDI_PATCH
NTSTATUS APIENTRY DxgkDdiPatch
(
    IN_CONST_HANDLE           hAdapter,
    IN_CONST_PDXGKARG_PATCH   pPatch
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pPatch);
    return STATUS_ABANDONED;
}

//DXGKDDI_PREEMPTCOMMAND
NTSTATUS APIENTRY DxgkDdiPreemptCommand
(
    IN_CONST_HANDLE                    hAdapter,
    IN_CONST_PDXGKARG_PREEMPTCOMMAND   pPreemptCommand
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pPreemptCommand);
    return STATUS_ABANDONED;
}

//DXGKDDI_SUBMITCOMMAND
NTSTATUS APIENTRY DxgkDdiSubmitCommand
(
    IN_CONST_HANDLE                   hAdapter,
    IN_CONST_PDXGKARG_SUBMITCOMMAND   pSubmitCommand
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSubmitCommand);
    return STATUS_ABANDONED;
}

//DXGKDDI_SUBMITCOMMANDVIRTUAL
NTSTATUS APIENTRY DxgkDdiSubmitCommandVirtual
(
    IN_CONST_HANDLE                          hAdapter,
    IN_CONST_PDXGKARG_SUBMITCOMMANDVIRTUAL   pSubmitCommand
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSubmitCommand);
    return STATUS_ABANDONED;
}

//DXGKDDI_VALIDATESUBMITCOMMAND
NTSTATUS APIENTRY DxgkDdiValidateSubmitCommand
(
    IN_CONST_HANDLE                        hContext,
    INOUT_PDXGKARG_VALIDATESUBMITCOMMAND   pArgs
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hContext);
    UNREFERENCED_PARAMETER(pArgs);
    return STATUS_ABANDONED;
}

//DXGKDDI_CANCELCOMMAND
NTSTATUS APIENTRY DxgkDdiCancelCommand
(
    IN_CONST_HANDLE                   hAdapter,
    IN_CONST_PDXGKARG_CANCELCOMMAND   pCancelCommand
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pCancelCommand);
    return STATUS_ABANDONED;
}

//DXGKDDI_BUILDPAGINGBUFFER
NTSTATUS APIENTRY DxgkDdiBuildPagingBuffer
(
    IN_CONST_HANDLE                 hAdapter,
    IN_PDXGKARG_BUILDPAGINGBUFFER   pBuildPagingBuffer
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pBuildPagingBuffer);
    return STATUS_ABANDONED;
}

//DXGKDDI_RESETFROMTIMEOUT
NTSTATUS APIENTRY CALLBACK DxgkDdiResetFromTimeout
(
    IN_CONST_HANDLE   hAdapter
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    return STATUS_ABANDONED;
}

//DXGKDDI_RESTARTFROMTIMEOUT
NTSTATUS APIENTRY CALLBACK DxgkDdiRestartFromTimeout
(
    IN_CONST_HANDLE   hAdapter
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    return STATUS_ABANDONED;
}

//DXGKDDI_ESCAPE
NTSTATUS APIENTRY DxgkDdiEscape
(
    IN_CONST_HANDLE            hAdapter,
    IN_CONST_PDXGKARG_ESCAPE   pEscape
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pEscape);
    return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Calibration Section

//DXGKDDI_EXCHANGEPRESTARTINFO
NTSTATUS DxgkDdiExchangePreStartInfo
(
    IN_CONST_HANDLE               hAdapter,
    IN_OUT_PDXGK_PRE_START_INFO   pPreStartInfo
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pPreStartInfo);
    return STATUS_ABANDONED;
}

//DXGKDDI_FORMATHISTORYBUFFER
NTSTATUS APIENTRY DxgkDdiFormatHistoryBuffer
(
    IN_CONST_HANDLE                   hContext,
    IN DXGKARG_FORMATHISTORYBUFFER* pFormatData
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hContext);
    UNREFERENCED_PARAMETER(pFormatData);
    return STATUS_ABANDONED;
}

//DXGKDDI_CONTROLDIAGNOSTICREPORTING
NTSTATUS APIENTRY DxgkDdiControlDiagnosticReporting
(
    IN_CONST_PVOID                           MiniportDeviceContext,
    IN_PDXGKARG_CONTROLDIAGNOSTICREPORTING   pArgControlDiagnosticReporting
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(pArgControlDiagnosticReporting);
    return STATUS_ABANDONED;
}

//DXGKDDI_COLLECTDIAGNOSTICINFO
NTSTATUS APIENTRY DxgkDdiCollectDiagnosticInfo
(
    IN_CONST_PDEVICE_OBJECT                PhysicalDeviceObject,
    INOUT_PDXGKARG_COLLECTDIAGNOSTICINFO   pCollectDiagnosticInfo
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(PhysicalDeviceObject);
    UNREFERENCED_PARAMETER(pCollectDiagnosticInfo);
    return STATUS_ABANDONED;
}

//DXGKDDI_CALIBRATEGPUCLOCK
NTSTATUS APIENTRY DxgkDdiCalibrateGpuClock
(
    IN_CONST_HANDLE                  hAdapter,
    IN UINT32                        NodeOrdinal,
    IN UINT32                        EngineOrdinal,
    OUT_PDXGKARG_CALIBRATEGPUCLOCK   pClockCalibration
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(NodeOrdinal);
    UNREFERENCED_PARAMETER(EngineOrdinal);
    UNREFERENCED_PARAMETER(pClockCalibration);
    return STATUS_ABANDONED;
}

//DXGKDDI_CONTROLMODEBEHAVIOR
NTSTATUS APIENTRY DxgkDdiControlModeBehavior
(
    IN_CONST_HANDLE                      hAdapter,
    INOUT_PDXGKARG_CONTROLMODEBEHAVIOR   pControlModeBehaviorArg
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pControlModeBehaviorArg);
    return STATUS_ABANDONED;
}

//DXGKDDI_UPDATEMONITORLINKINFO
NTSTATUS APIENTRY DxgkDdiUpdateMonitorLinkInfo
(
    IN_CONST_HANDLE                        hAdapter,
    INOUT_PDXGKARG_UPDATEMONITORLINKINFO   pUpdateMonitorLinkInfoArg
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pUpdateMonitorLinkInfoArg);
    return STATUS_ABANDONED;
}

//DXGKDDI_VALIDATEUPDATEALLOCATIONPROPERTY
NTSTATUS APIENTRY DxgkDdiValidateUpdateAllocationProperty
(
    IN_CONST_HANDLE                                 hAdapter,
    IN_CONST_PDXGKARG_VALIDATEUPDATEALLOCPROPERTY   pValidateUpdateAllocProperty
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pValidateUpdateAllocProperty);
    return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Set Calibration Section

//DXGKDDI_SETUPPRIORITYBANDS
NTSTATUS APIENTRY DxgkDdiSetupPriorityBands
(
    IN_CONST_HANDLE                        hAdapter,
    IN_CONST_PDXGKARG_SETUPPRIORITYBANDS   pSetupPriorityBands
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetupPriorityBands);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETCONTEXTSCHEDULINGPROPERTIES
NTSTATUS APIENTRY DxgkDdiSetContextSchedulingProperties
(
    IN_CONST_HANDLE                                    hAdapter,
    IN_CONST_PDXGKARG_SETCONTEXTSCHEDULINGPROPERTIES   pSetContextSchedulingProperties
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetContextSchedulingProperties);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETSCHEDULINGLOGBUFFER
NTSTATUS APIENTRY DxgkDdiSetSchedulingLogBuffer
(
    IN_CONST_HANDLE                            hAdapter,
    IN_CONST_PDXGKARG_SETSCHEDULINGLOGBUFFER   pSetSchedulingLogBuffer
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetSchedulingLogBuffer);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETTARGETGAMMA
NTSTATUS APIENTRY DxgkDdiSetTargetGamma
(
    IN_CONST_HANDLE                    hAdapter,
    IN_CONST_PDXGKARG_SETTARGETGAMMA   pSetTargetGammaArg
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetTargetGammaArg);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETTARGETCONTENTTYPE
NTSTATUS APIENTRY DxgkDdiSetTargetContentType
(
    IN_CONST_HANDLE                          hAdapter,
    IN_CONST_PDXGKARG_SETTARGETCONTENTTYPE   pSetTargetContentTypeArg
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetTargetContentTypeArg);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETTARGETANALOGCOPYPROTECTION
NTSTATUS APIENTRY DxgkDdiSetTargetAnalogCopyProtection
(
    IN_CONST_HANDLE                                   hAdapter,
    IN_CONST_PDXGKARG_SETTARGETANALOGCOPYPROTECTION   pSetTargetAnalogCopyProtectionArg
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetTargetAnalogCopyProtectionArg);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY
NTSTATUS APIENTRY DxgkDdiSetTargetAdjustedColorimetry
(
    IN_CONST_HANDLE                     hAdapter,
    IN D3DDDI_VIDEO_PRESENT_TARGET_ID   TargetId,
    IN DXGK_COLORIMETRY                 AdjustedColorimetry
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(TargetId);
    UNREFERENCED_PARAMETER(AdjustedColorimetry);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY2
NTSTATUS APIENTRY DxgkDdiSetTargetAdjustedColorimetry2
(
    IN_CONST_HANDLE                             hAdapter,
    IN_PDXGKARG_SETTARGETADJUSTEDCOLORIMETRY2   pArgSetTargetAdjustedColorimetry
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pArgSetTargetAdjustedColorimetry);
    return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Set Section

//DXGKDDI_SETPALETTE
NTSTATUS APIENTRY DxgkDdiSetPalette
(
    IN_CONST_HANDLE                hAdapter,
    IN_CONST_PDXGKARG_SETPALETTE   pSetPalette
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetPalette);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETPOINTERPOSITION
NTSTATUS APIENTRY DxgkDdiSetPointerPosition
(
    IN_CONST_HANDLE                        hAdapter,
    IN_CONST_PDXGKARG_SETPOINTERPOSITION   pSetPointerPosition
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetPointerPosition);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETPOINTERSHAPE
NTSTATUS APIENTRY DxgkDdiSetPointerShape
(
    IN_CONST_HANDLE                     hAdapter,
    IN_CONST_PDXGKARG_SETPOINTERSHAPE   pSetPointerShape
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetPointerShape);
    return STATUS_ABANDONED;
}

//DXGKDDI_SET_POWER_STATE
NTSTATUS DxgkDdiSetPowerState
(
    IN_CONST_PVOID          MiniportDeviceContext,
    IN_ULONG                DeviceUid,
    IN_DEVICE_POWER_STATE   DevicePowerState,
    IN_POWER_ACTION         ActionType
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(DeviceUid);
    UNREFERENCED_PARAMETER(DevicePowerState);
    UNREFERENCED_PARAMETER(ActionType);
    return STATUS_ABANDONED;
}

//DXGKDDISETPOWERPSTATE
NTSTATUS APIENTRY DxgkDdiSetPowerPState
(
    IN_CONST_HANDLE   DriverContext,
    UINT              ComponentIndex,
    UINT              RequestedComponentPState
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(DriverContext);
    UNREFERENCED_PARAMETER(ComponentIndex);
    UNREFERENCED_PARAMETER(RequestedComponentPState);
    return STATUS_ABANDONED;
}

//DXGKDDISETPOWERCOMPONENTFSTATE
NTSTATUS APIENTRY DxgkDdiSetPowerComponentFState
(
    IN_CONST_HANDLE   DriverContext,
    UINT              ComponentIndex,
    UINT              FState
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(DriverContext);
    UNREFERENCED_PARAMETER(ComponentIndex);
    UNREFERENCED_PARAMETER(FState);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETSTABLEPOWERSTATE
VOID APIENTRY DxgkDdiSetStablePowerState
(
    IN_CONST_HANDLE                         hAdapter,
    IN_CONST_PDXGKARG_SETSTABLEPOWERSTATE   pArgs
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pArgs);
}

//DXGKDDI_SETTRACKEDWORKLOADPOWERLEVEL
NTSTATUS APIENTRY DxgkDdiSetTrackedWorkloadPowerLevel
(
    IN_CONST_HANDLE                               hContext,
    INOUT_PDXGKARG_SETTRACKEDWORKLOADPOWERLEVEL   pTrackedWorkloadPowerLevel
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hContext);
    UNREFERENCED_PARAMETER(pTrackedWorkloadPowerLevel);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETDISPLAYPRIVATEDRIVERFORMAT
NTSTATUS APIENTRY DxgkDdiSetDisplayPrivateDriverFormat
(
    IN_CONST_HANDLE                                   hAdapter,
    IN_CONST_PDXGKARG_SETDISPLAYPRIVATEDRIVERFORMAT   pSetDisplayPrivateDriverFormat
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetDisplayPrivateDriverFormat);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETVIDEOPROTECTEDREGION
NTSTATUS APIENTRY DxgkDdiSetVideoProtectedRegion
(
    IN_CONST_HANDLE                             hAdapter,
    IN_CONST_PDXGKARG_SETVIDEOPROTECTEDREGION   pArgs
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pArgs);
    return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Get Section

//DXGKDDI_GETSCANLINE
NTSTATUS APIENTRY DxgkDdiGetScanLine
(
    IN_CONST_HANDLE              hAdapter,
    INOUT_PDXGKARG_GETSCANLINE   pGetScanLine
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pGetScanLine);
    return STATUS_ABANDONED;
}

//DXGKDDI_GETNODEMETADATA
NTSTATUS APIENTRY DxgkDdiGetNodeMetadata
(
    IN_CONST_HANDLE                hAdapter,
    UINT                           NodeOrdinalAndAdapterIndex, //WDDMv2: High word is physical adapter index, low word is node ordinal
    OUT_PDXGKARG_GETNODEMETADATA   pGetNodeMetadata
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(NodeOrdinalAndAdapterIndex);
    UNREFERENCED_PARAMETER(pGetNodeMetadata);
    return STATUS_ABANDONED;
}

//DXGKDDI_GET_CHILD_CONTAINER_ID
NTSTATUS DxgkDdiGetChildContainerId
(
    _In_ PVOID                         MiniportDeviceContext,
    _In_ ULONG                         ChildUid,
    _Inout_ PDXGK_CHILD_CONTAINER_ID   ContainerId
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(ChildUid);
    UNREFERENCED_PARAMETER(ContainerId);
    return STATUS_ABANDONED;
}

//DXGKDDI_GETPOSTCOMPOSITIONCAPS
NTSTATUS APIENTRY DxgkDdiGetPostCompositionCaps
(
    IN_CONST_HANDLE                          hAdapter,
    IN_OUT_PDXGKARG_GETPOSTCOMPOSITIONCAPS   pGetPostCompositionCaps
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pGetPostCompositionCaps);
    return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Notify Section

//DXGKDDI_NOTIFY_ACPI_EVENT
NTSTATUS DxgkDdiNotifyAcpiEvent
(
    IN_CONST_PVOID       MiniportDeviceContext,
    IN_DXGK_EVENT_TYPE   EventType,
    IN_ULONG             Event,
    IN_PVOID             Argument,
    OUT_PULONG           AcpiFlags
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(EventType);
    UNREFERENCED_PARAMETER(Event);
    UNREFERENCED_PARAMETER(Argument);
    UNREFERENCED_PARAMETER(AcpiFlags);
    return STATUS_ABANDONED;
}

//DXGKDDI_NOTIFYFOCUSPRESENT
NTSTATUS APIENTRY DxgkDdiNotifyFocusPresent
(
    IN_CONST_HANDLE   hAdapter
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    return STATUS_ABANDONED;
}

//DXGKDDI_NOTIFY_SURPRISE_REMOVAL
NTSTATUS DxgkDdiNotifySurpriseRemoval
(
    _In_ PVOID                        MiniportDeviceContext,
    _In_ DXGK_SURPRISE_REMOVAL_TYPE   RemovalType
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(RemovalType);
    return STATUS_ABANDONED;
}

//DXGKDDIPOWERRUNTIMECONTROLREQUEST
NTSTATUS APIENTRY DxgkDdiPowerRuntimeControlRequest
(
    IN_CONST_HANDLE        DriverContext,
    IN LPCGUID             PowerControlCode,
    IN OPTIONAL PVOID      InBuffer,
    IN SIZE_T              InBufferSize,
    OUT OPTIONAL PVOID     OutBuffer,
    IN SIZE_T              OutBufferSize,
    OUT OPTIONAL PSIZE_T   BytesReturned
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(DriverContext);
    UNREFERENCED_PARAMETER(PowerControlCode);
    UNREFERENCED_PARAMETER(InBuffer);
    UNREFERENCED_PARAMETER(InBufferSize);
    UNREFERENCED_PARAMETER(OutBuffer);
    UNREFERENCED_PARAMETER(OutBufferSize);
    UNREFERENCED_PARAMETER(BytesReturned);
    return STATUS_ABANDONED;
}

//DXGKDDI_POWERRUNTIMESETDEVICEHANDLE
NTSTATUS APIENTRY DxgkDdiPowerRuntimeSetDeviceHandle
(
    IN_CONST_HANDLE   DriverContext,
    IN HANDLE         PoDeviceHandle
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(DriverContext);
    UNREFERENCED_PARAMETER(PoDeviceHandle);
    return STATUS_ABANDONED;
}

//DXGKDDI_CREATEPERIODICFRAMENOTIFICATION
NTSTATUS APIENTRY DxgkDdiCreatePeriodicFrameNotification
(
    INOUT_PDXGKARG_CREATEPERIODICFRAMENOTIFICATION   pCreatePeriodicFrameNotification
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(pCreatePeriodicFrameNotification);
    return STATUS_ABANDONED;
}

//DXGKDDI_DESTROYPERIODICFRAMENOTIFICATION
NTSTATUS APIENTRY DxgkDdiDestroyPeriodicFrameNotification
(
    IN_CONST_PDXGKARG_DESTROYPERIODICFRAMENOTIFICATION   pDestroyPeriodicFrameNotification
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(pDestroyPeriodicFrameNotification);
    return STATUS_ABANDONED;
}

//DXGKDDI_SIGNALMONITOREDFENCE
NTSTATUS APIENTRY DxgkDdiSignalMonitoredFence
(
    IN_CONST_HANDLE                       hContext,
    INOUT_PDXGKARG_SIGNALMONITOREDFENCE   pSignalMonitoredFence
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hContext);
    UNREFERENCED_PARAMETER(pSignalMonitoredFence);
    return STATUS_ABANDONED;
}

//DXGKDDI_DISPLAYDETECTCONTROL
NTSTATUS APIENTRY DxgkDdiDisplayDetectControl
(
    IN_CONST_HANDLE                          hAdapter,
    IN_CONST_PDXGKARG_DISPLAYDETECTCONTROL   pDisplayDetectControl
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pDisplayDetectControl);
    return STATUS_ABANDONED;
}

//DXGKDDI_RECOMMENDMONITORMODES
NTSTATUS APIENTRY DxgkDdiRecommendMonitorModes
(
    IN_CONST_HANDLE                                 hAdapter,
    IN_CONST_PDXGKARG_RECOMMENDMONITORMODES_CONST   pRecommendMonitorModes
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pRecommendMonitorModes);
    return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Query Section

//DXGKDDI_QUERY_INTERFACE
NTSTATUS DxgkDdiQueryInterface
(
    IN_CONST_PVOID        MiniportDeviceContext,
    IN_PQUERY_INTERFACE   QueryInterface
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(QueryInterface);
    return STATUS_ABANDONED;
}

//DXGKDDI_QUERYADAPTERINFO
NTSTATUS APIENTRY DxgkDdiQueryAdapterInfo
(
    IN_CONST_HANDLE                      hAdapter,
    IN_CONST_PDXGKARG_QUERYADAPTERINFO   pQueryAdapterInfo
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pQueryAdapterInfo);
    return STATUS_ABANDONED;
}

//DXGKDDI_QUERYCURRENTFENCE
NTSTATUS APIENTRY DxgkDdiQueryCurrentFence
(
    IN_CONST_HANDLE                    hAdapter,
    INOUT_PDXGKARG_QUERYCURRENTFENCE   pCurrentFence
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pCurrentFence);
    return STATUS_ABANDONED;
}

//DXGKDDI_QUERY_DEVICE_DESCRIPTOR
NTSTATUS DxgkDdiQueryDeviceDescriptor
(
    IN_CONST_PVOID                  MiniportDeviceContext,
    IN_ULONG                        ChildUid,
    INOUT_PDXGK_DEVICE_DESCRIPTOR   DeviceDescriptor
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(ChildUid);
    UNREFERENCED_PARAMETER(DeviceDescriptor);
    return STATUS_ABANDONED;
}

//DXGKDDI_QUERYVIDPNHWCAPABILITY
NTSTATUS APIENTRY DxgkDdiQueryVidPnHWCapability
(
    IN_CONST_HANDLE                         i_hAdapter,
    INOUT_PDXGKARG_QUERYVIDPNHWCAPABILITY   io_pVidPnHWCaps
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(i_hAdapter);
    UNREFERENCED_PARAMETER(io_pVidPnHWCaps);
    return STATUS_ABANDONED;
}

//DXGKDDI_QUERY_CHILD_RELATIONS
NTSTATUS DxgkDdiQueryChildRelations
(
    IN_CONST_PVOID                                                     MiniportDeviceContext,
    _Inout_updates_bytes_(ChildRelationsSize) PDXGK_CHILD_DESCRIPTOR   ChildRelations,        //SAL 2.0 Annotation
    _In_ ULONG                                                         ChildRelationsSize
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(ChildRelations);
    UNREFERENCED_PARAMETER(ChildRelationsSize);
    return STATUS_ABANDONED;
}

//DXGKDDI_QUERY_CHILD_STATUS
NTSTATUS DxgkDdiQueryChildStatus
(
    IN_CONST_PVOID             MiniportDeviceContext,
    INOUT_PDXGK_CHILD_STATUS   ChildStatus,
    IN_BOOLEAN                 NonDestructiveOnly
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(ChildStatus);
    UNREFERENCED_PARAMETER(NonDestructiveOnly);
    return STATUS_ABANDONED;
}

//DXGKDDI_QUERYCONNECTIONCHANGE
NTSTATUS APIENTRY DxgkDdiQueryConnectionChange
(
    IN_CONST_HANDLE                     hAdapter,
    IN_PDXGKARG_QUERYCONNECTIONCHANGE   pQueryConnectionChange
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pQueryConnectionChange);
    return STATUS_ABANDONED;
}

//DXGKDDI_QUERYDIAGNOSTICTYPESSUPPORT
NTSTATUS APIENTRY DxgkDdiQueryDiagnosticTypesSupport
(
    IN_CONST_PVOID                               MiniportDeviceContext,
    INOUT_PDXGKARG_QUERYDIAGNOSTICTYPESSUPPORT   pArgQueryDiagnosticTypesSupport
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(pArgQueryDiagnosticTypesSupport);
    return STATUS_ABANDONED;
}

//DXGKDDI_QUERYDEPENDENTENGINEGROUP
NTSTATUS APIENTRY DxgkDdiQueryDependentEngineGroup
(
    IN_CONST_HANDLE                           hAdapter,
    INOUT_DXGKARG_QUERYDEPENDENTENGINEGROUP   pQueryDependentEngineGroup
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pQueryDependentEngineGroup);
    return STATUS_ABANDONED;
}

//DXGKDDI_QUERYENGINESTATUS
NTSTATUS APIENTRY DxgkDdiQueryEngineStatus
(
    IN_CONST_HANDLE                    hAdapter,
    INOUT_PDXGKARG_QUERYENGINESTATUS   pQueryEngineStatus
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pQueryEngineStatus);
    return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Video Present Network (VidPn) Section

//DXGKDDI_COMMITVIDPN
NTSTATUS APIENTRY DxgkDdiCommitVidPn
(
    IN_CONST_HANDLE                       hAdapter,
    IN_CONST_PDXGKARG_COMMITVIDPN_CONST   pCommitVidPn
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pCommitVidPn);
    return STATUS_ABANDONED;
}

//DXGKDDI_ISSUPPORTEDVIDPN
NTSTATUS APIENTRY DxgkDdiIsSupportedVidPn
(
    IN_CONST_HANDLE                   hAdapter,
    INOUT_PDXGKARG_ISSUPPORTEDVIDPN   pIsSupportedVidPn
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pIsSupportedVidPn);
    return STATUS_ABANDONED;
}

//DXGKDDI_ENUMVIDPNCOFUNCMODALITY
NTSTATUS APIENTRY DxgkDdiEnumVidPnCofuncModality
(
    IN_CONST_HANDLE                                   hAdapter,
    IN_CONST_PDXGKARG_ENUMVIDPNCOFUNCMODALITY_CONST   pEnumCofuncModality
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pEnumCofuncModality);
    return STATUS_ABANDONED;
}

//DXGKDDI_RECOMMENDFUNCTIONALVIDPN
NTSTATUS APIENTRY DxgkDdiRecommendFunctionalVidPn
(
    IN_CONST_HANDLE                                    hAdapter,
    IN_CONST_PDXGKARG_RECOMMENDFUNCTIONALVIDPN_CONST   pRecommendFunctionalVidPn
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pRecommendFunctionalVidPn);
    return STATUS_ABANDONED;
}

//DXGKDDI_GETMULTIPLANEOVERLAYCAPS
NTSTATUS APIENTRY DxgkDdiGetMultiPlaneOverlayCaps
(
    IN_CONST_HANDLE                            hAdapter,
    IN_OUT_PDXGKARG_GETMULTIPLANEOVERLAYCAPS   pGetMultiPlaneOverlayCaps
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pGetMultiPlaneOverlayCaps);
    return STATUS_ABANDONED;
}

//DXGKDDI_POSTMULTIPLANEOVERLAYPRESENT
NTSTATUS APIENTRY DxgkDdiPostMultiPlaneOverlayPresent
(
    IN_CONST_HANDLE                                  hAdapter,
    IN_CONST_PDXGKARG_POSTMULTIPLANEOVERLAYPRESENT   pPostPresent
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pPostPresent);
    return STATUS_ABANDONED;
}

//DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT
NTSTATUS APIENTRY DxgkDdiCheckMultiPlaneOverlaySupport
(
    IN_CONST_HANDLE                                 hAdapter,
    IN_OUT_PDXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT   pCheckMultiPlaneOverlaySupport
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pCheckMultiPlaneOverlaySupport);
    return STATUS_ABANDONED;
}

//DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT2
NTSTATUS APIENTRY DxgkDdiCheckMultiPlaneOverlaySupport2
(
    IN_CONST_HANDLE                                  hAdapter,
    IN_OUT_PDXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT2   pCheckMultiPlaneOverlaySupport
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pCheckMultiPlaneOverlaySupport);
    return STATUS_ABANDONED;
}

//DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT3
NTSTATUS APIENTRY DxgkDdiCheckMultiPlaneOverlaySupport3
(
    IN_CONST_HANDLE                                  hAdapter,
    IN_OUT_PDXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT3   pCheckMultiPlaneOverlaySupport
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pCheckMultiPlaneOverlaySupport);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY
NTSTATUS APIENTRY DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay
(
    IN_CONST_HANDLE                                                hAdapter,
    IN_CONST_PDXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY   pSetVidPnSourceAddressWithMultiPlaneOverlay
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetVidPnSourceAddressWithMultiPlaneOverlay);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2
NTSTATUS APIENTRY DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2
(
    IN_CONST_HANDLE                                                 hAdapter,
    IN_CONST_PDXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2   pSetVidPnSourceAddressWithMultiPlaneOverlay
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetVidPnSourceAddressWithMultiPlaneOverlay);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3
NTSTATUS APIENTRY DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay3
(
    IN_CONST_HANDLE                                               hAdapter,
    IN_OUT_PDXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3   pSetVidPnSourceAddressWithMultiPlaneOverlay
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetVidPnSourceAddressWithMultiPlaneOverlay);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETVIDPNSOURCEADDRESS
NTSTATUS APIENTRY DxgkDdiSetVidPnSourceAddress
(
    IN_CONST_HANDLE                           hAdapter,
    IN_CONST_PDXGKARG_SETVIDPNSOURCEADDRESS   pSetVidPnSourceAddress
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetVidPnSourceAddress);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETVIDPNSOURCEVISIBILITY
NTSTATUS APIENTRY DxgkDdiSetVidPnSourceVisibility
(
    IN_CONST_HANDLE                              hAdapter,
    IN_CONST_PDXGKARG_SETVIDPNSOURCEVISIBILITY   pSetVidPnSourceVisibility
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetVidPnSourceVisibility);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETTIMINGSFROMVIDPN
NTSTATUS APIENTRY DxgkDdiSetTimingsFromVidPn
(
    IN_CONST_HANDLE                       hAdapter,
    IN_OUT_PDXGKARG_SETTIMINGSFROMVIDPN   pSetTimings
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetTimings);
    return STATUS_ABANDONED;
}

//DXGKDDI_UPDATEACTIVEVIDPNPRESENTPATH
NTSTATUS APIENTRY DxgkDdiUpdateActiveVidPnPresentPath
(
    IN_CONST_HANDLE                                        hAdapter,
    IN_CONST_PDXGKARG_UPDATEACTIVEVIDPNPRESENTPATH_CONST   pUpdateActiveVidPnPresentPath
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pUpdateActiveVidPnPresentPath);
    return STATUS_ABANDONED;
}

//DXGKDDI_RECOMMENDVIDPNTOPOLOGY
NTSTATUS APIENTRY DxgkDdiRecommendVidPnTopology
(
    IN_CONST_HANDLE                                  hAdapter,
    IN_CONST_PDXGKARG_RECOMMENDVIDPNTOPOLOGY_CONST   pRecommendVidPnTopology
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pRecommendVidPnTopology);
    return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Engine Section

//DXGKDDI_RESETENGINE
NTSTATUS APIENTRY DxgkDdiResetEngine
(
    IN_CONST_HANDLE              hAdapter,
    INOUT_PDXGKARG_RESETENGINE   pResetEngine
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pResetEngine);
    return STATUS_ABANDONED;
}

//DXGKDDI_RESUMEHWENGINE
NTSTATUS APIENTRY DxgkDdiResumeHwEngine
(
    IN_CONST_HANDLE                 hAdapter,
    INOUT_PDXGKARG_RESUMEHWENGINE   pResumeHwEngine
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pResumeHwEngine);
    return STATUS_ABANDONED;
}

//DXGKDDI_RESETHWENGINE
NTSTATUS APIENTRY DxgkDdiResetHwEngine
(
    IN_CONST_HANDLE                hAdapter,
    INOUT_PDXGKARG_RESETHWENGINE   pResetHwEngine
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pResetHwEngine);
    return STATUS_ABANDONED;
}

//DXGKDDI_CREATEPROCESS
NTSTATUS APIENTRY DxgkDdiCreateProcess
(
    IN_CONST_HANDLE                hAdapter,
    INOUT_PDXGKARG_CREATEPROCESS   pArgs
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pArgs);
    return STATUS_ABANDONED;
}

//DXGKDDI_DESTROYPROCESS
NTSTATUS APIENTRY DxgkDdiDestroyProcess
(
    IN_CONST_HANDLE   hAdapter,
    IN_CONST_HANDLE   hKmdProcess
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(hKmdProcess);
    return STATUS_ABANDONED;
}

//DXGKDDI_STOPCAPTURE
NTSTATUS APIENTRY DxgkDdiStopCapture
(
    IN_CONST_HANDLE                 hAdapter,
    IN_CONST_PDXGKARG_STOPCAPTURE   pStopCapture
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pStopCapture);
    return STATUS_ABANDONED;
}

//DXGKDDI_STOP_DEVICE_AND_RELEASE_POST_DISPLAY_OWNERSHIP
NTSTATUS DxgkDdiStopDeviceAndReleasePostDisplayOwnership
(
    _In_ PVOID                            MiniportDeviceContext,
    _In_ D3DDDI_VIDEO_PRESENT_TARGET_ID   TargetId,
    _Out_ PDXGK_DISPLAY_INFORMATION       DisplayInfo
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(TargetId);
    DisplayInfo->Width = 1280;
    DisplayInfo->Height = 720;
    DisplayInfo->Pitch = DisplayInfo->Width * (8 * 4);
    DisplayInfo->ColorFormat = D3DDDIFMT_A8R8G8B8;
    DisplayInfo->PhysicAddress.QuadPart = 0x0;
    DisplayInfo->TargetId = 0;
    DisplayInfo->AcpiId = 0;
    return STATUS_ABANDONED;
}

//DXGKDDI_SYSTEM_DISPLAY_ENABLE
NTSTATUS DxgkDdiSystemDisplayEnable
(
    _In_ PVOID                                  MiniportDeviceContext,
    _In_ D3DDDI_VIDEO_PRESENT_TARGET_ID         TargetId,
    _In_ PDXGKARG_SYSTEM_DISPLAY_ENABLE_FLAGS   Flags,
    _Out_ UINT* Width,
    _Out_ UINT* Height,
    _Out_ D3DDDIFORMAT* ColorFormat
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(TargetId);
    UNREFERENCED_PARAMETER(Flags);
    *Width = 1280;
    *Height = 720;
    *ColorFormat = D3DDDIFMT_A8R8G8B8;
    return STATUS_ABANDONED;
}

//DXGKDDI_SYSTEM_DISPLAY_WRITE
VOID DxgkDdiSystemDisplayWrite
(
    _In_ PVOID                                            MiniportDeviceContext,
    _In_reads_bytes_(SourceHeight* SourceStride) PVOID   Source,                //SAL 2.0 Annotation
    _In_ UINT                                             SourceWidth,
    _In_ UINT                                             SourceHeight,
    _In_ UINT                                             SourceStride,
    _In_ UINT                                             PositionX,
    _In_ UINT                                             PositionY
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(Source);
    UNREFERENCED_PARAMETER(SourceWidth);
    UNREFERENCED_PARAMETER(SourceHeight);
    UNREFERENCED_PARAMETER(SourceStride);
    UNREFERENCED_PARAMETER(PositionX);
    UNREFERENCED_PARAMETER(PositionY);
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Interrupt Section

//DXGKDDI_DPC_ROUTINE
VOID DxgkDdiDpcRoutine
(
    IN_CONST_PVOID   MiniportDeviceContext
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
}

//DXGKDDI_INTERRUPT_ROUTINE
BOOLEAN DxgkDdiInterruptRoutine
(
    IN_CONST_PVOID   MiniportDeviceContext,
    IN_ULONG         MessageNumber
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(MessageNumber);
    return STATUS_ABANDONED;
}

//DXGKDDI_DISPATCH_IO_REQUEST
NTSTATUS DxgkDdiDispatchIoRequest
(
    IN_CONST_PVOID             MiniportDeviceContext,
    IN_ULONG                   VidPnSourceId,
    IN_PVIDEO_REQUEST_PACKET   VideoRequestPacket
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(MiniportDeviceContext);
    UNREFERENCED_PARAMETER(VidPnSourceId);
    UNREFERENCED_PARAMETER(VideoRequestPacket);
    return STATUS_ABANDONED;
}

//DXGKDDI_CONTROLINTERRUPT
NTSTATUS APIENTRY DxgkDdiControlInterrupt
(
    IN_CONST_HANDLE                hAdapter,
    IN_CONST_DXGK_INTERRUPT_TYPE   InterruptType,
    IN_BOOLEAN                     EnableInterrupt
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(InterruptType);
    UNREFERENCED_PARAMETER(EnableInterrupt);
    return STATUS_ABANDONED;
}

//DXGKDDI_CONTROLINTERRUPT2
NTSTATUS APIENTRY DxgkDdiControlInterrupt2
(
    IN_CONST_HANDLE                      hAdapter,
    IN_CONST_DXGKARG_CONTROLINTERRUPT2   InterruptControl
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(InterruptControl);
    return STATUS_ABANDONED;
}

//DXGKDDI_CONTROLINTERRUPT3
NTSTATUS APIENTRY DxgkDdiControlInterrupt3
(
    IN_CONST_HANDLE                       hAdapter,
    IN_CONST_PDXGKARG_CONTROLINTERRUPT3   InterruptControl
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(InterruptControl);
    return STATUS_ABANDONED;
}

//DXGKDDI_CONTROL_ETW_LOGGING
VOID DxgkDdiControlEtwLogging
(
    IN_BOOLEAN   Enable,
    IN_ULONG     Flags,
    IN_UCHAR     Level
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(Enable);
    UNREFERENCED_PARAMETER(Flags);
    UNREFERENCED_PARAMETER(Level);
}

//DXGKDDI_COLLECTDBGINFO
NTSTATUS APIENTRY DxgkDdiCollectDbgInfo
(
    IN_CONST_HANDLE                    hAdapter,
    IN_CONST_PDXGKARG_COLLECTDBGINFO   pCollectDbgInfo
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pCollectDbgInfo);
    return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Allocation Section

//DXGKDDI_GETSTANDARDALLOCATIONDRIVERDATA
NTSTATUS APIENTRY DxgkDdiGetStandardAllocationDriverData
(
    IN_CONST_HANDLE                                  hAdapter,
    INOUT_PDXGKARG_GETSTANDARDALLOCATIONDRIVERDATA   pGetStandardAllocationDriverData
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pGetStandardAllocationDriverData);
    return STATUS_ABANDONED;
}

//DXGKDDI_DESCRIBEALLOCATION
NTSTATUS APIENTRY DxgkDdiDescribeAllocation
(
    IN_CONST_HANDLE                     hAdapter,
    INOUT_PDXGKARG_DESCRIBEALLOCATION   pDescribeAllocation
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pDescribeAllocation);
    return STATUS_ABANDONED;
}

//DXGKDDI_CREATEALLOCATION
NTSTATUS APIENTRY DxgkDdiCreateAllocation
(
    IN_CONST_HANDLE                   hAdapter,
    INOUT_PDXGKARG_CREATEALLOCATION   pCreateAllocation
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pCreateAllocation);
    return STATUS_ABANDONED;
}

//DXGKDDI_CREATEALLOCATION2 (Reserved)
DXGKDDI_UNDEFINED DxgkDdiCreateAllocation2 = NULL;
//(
//    IN_CONST_HANDLE                    hAdapter,
//    INOUT_PDXGKARG_CREATEALLOCATION2   pCreateAllocation
//)
//{
//	  debug("[CALL]: %s", __FUNCTION__);
//    UNREFERENCED_PARAMETER(hAdapter);
//    UNREFERENCED_PARAMETER(pCreateAllocation);
//}

//DXGKDDI_OPENALLOCATIONINFO
NTSTATUS APIENTRY DxgkDdiOpenAllocation
(
    IN_CONST_HANDLE                    hDevice,
    IN_CONST_PDXGKARG_OPENALLOCATION   pOpenAllocation
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hDevice);
    UNREFERENCED_PARAMETER(pOpenAllocation);
    return STATUS_ABANDONED;
}

//DXGKDDI_CLOSEALLOCATION
NTSTATUS APIENTRY DxgkDdiCloseAllocation
(
    IN_CONST_HANDLE                     hDevice,
    IN_CONST_PDXGKARG_CLOSEALLOCATION   pCloseAllocation
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hDevice);
    UNREFERENCED_PARAMETER(pCloseAllocation);
    return STATUS_ABANDONED;
}

//DXGKDDI_DESTROYALLOCATION
NTSTATUS APIENTRY DxgkDdiDestroyAllocation
(
    IN_CONST_HANDLE                       hAdapter,
    IN_CONST_PDXGKARG_DESTROYALLOCATION   pDestroyAllocation
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pDestroyAllocation);
    return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Context Section

//DXGKDDI_CREATECONTEXT
NTSTATUS APIENTRY DxgkDdiCreateContext
(
    IN_CONST_HANDLE                hDevice,
    INOUT_PDXGKARG_CREATECONTEXT   pCreateContext
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hDevice);
    UNREFERENCED_PARAMETER(pCreateContext);
    return STATUS_ABANDONED;
}

//DXGKDDI_SUSPENDCONTEXT
NTSTATUS APIENTRY DxgkDdiSuspendContext
(
    IN_CONST_HANDLE                    hAdapter,
    IN_CONST_PDXGKARG_SUSPENDCONTEXT   pSuspendContext
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSuspendContext);
    return STATUS_ABANDONED;
}

//DXGKDDI_RESUMECONTEXT
NTSTATUS APIENTRY DxgkDdiResumeContext
(
    IN_CONST_HANDLE                   hAdapter,
    IN_CONST_PDXGKARG_RESUMECONTEXT   pResumeContext
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pResumeContext);
    return STATUS_ABANDONED;
}

//DXGKDDI_DESTROYCONTEXT
NTSTATUS APIENTRY DxgkDdiDestroyContext
(
    IN_CONST_HANDLE   hContext
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hContext);
    return STATUS_ABANDONED;
}

//DXGKDDI_CREATEHWCONTEXT
NTSTATUS APIENTRY DxgkDdiCreateHwContext
(
    IN_CONST_HANDLE                  hDevice,
    INOUT_PDXGKARG_CREATEHWCONTEXT   pCreateContext
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hDevice);
    UNREFERENCED_PARAMETER(pCreateContext);
    return STATUS_ABANDONED;
}

//DXGKDDI_DESTROYHWCONTEXT
NTSTATUS APIENTRY DxgkDdiDestroyHwContext
(
    IN_CONST_HANDLE   hHwContext
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hHwContext);
    return STATUS_ABANDONED;
}

//DXGKDDI_CREATEHWQUEUE
NTSTATUS APIENTRY DxgkDdiCreateHwQueue
(
    IN_CONST_HANDLE                hHwContext,
    INOUT_PDXGKARG_CREATEHWQUEUE   pCreateHwQueue
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hHwContext);
    UNREFERENCED_PARAMETER(pCreateHwQueue);
    return STATUS_ABANDONED;
}

//DXGKDDI_PRESENTTOHWQUEUE
NTSTATUS APIENTRY DxgkDdiPresentToHwQueue
(
    IN_CONST_HANDLE          hHwQueue,
    INOUT_PDXGKARG_PRESENT   pPresent
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hHwQueue);
    UNREFERENCED_PARAMETER(pPresent);
    return STATUS_ABANDONED;
}

//DXGKDDI_UPDATEHWCONTEXTSTATE
NTSTATUS APIENTRY DxgkDdiUpdateHwContextState
(
    IN_CONST_HANDLE                          hAdapter,
    IN_CONST_PDXGKARG_UPDATEHWCONTEXTSTATE   pUpdateHwContextState
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pUpdateHwContextState);
    return STATUS_ABANDONED;
}

//DXGKDDI_SUBMITCOMMANDTOHWQUEUE
NTSTATUS APIENTRY DxgkDdiSubmitCommandToHwQueue
(
    IN_CONST_HANDLE                            hAdapter,
    IN_CONST_PDXGKARG_SUBMITCOMMANDTOHWQUEUE   pSubmitCommandToHwQueue
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSubmitCommandToHwQueue);
    return STATUS_ABANDONED;
}

//DXGKDDI_SWITCHTOHWCONTEXTLIST
NTSTATUS APIENTRY DxgkDdiSwitchToHwContextList
(
    IN_CONST_HANDLE                           hAdapter,
    IN_CONST_PDXGKARG_SWITCHTOHWCONTEXTLIST   pHwContextList
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pHwContextList);
    return STATUS_ABANDONED;
}

//DXGKDDI_DESTROYHWQUEUE
NTSTATUS APIENTRY DxgkDdiDestroyHwQueue
(
    IN_CONST_HANDLE   hHwQueue
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hHwQueue);
    return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Overlay Section

//DXGKDDI_CREATEOVERLAY
NTSTATUS APIENTRY DxgkDdiCreateOverlay
(
    IN_CONST_HANDLE                hAdapter,
    INOUT_PDXGKARG_CREATEOVERLAY   pCreateOverlay
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pCreateOverlay);
    return STATUS_ABANDONED;
}

//DXGKDDI_UPDATEOVERLAY
NTSTATUS APIENTRY DxgkDdiUpdateOverlay
(
    IN_CONST_HANDLE                   hOverlay,
    IN_CONST_PDXGKARG_UPDATEOVERLAY   pUpdateOverlay
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hOverlay);
    UNREFERENCED_PARAMETER(pUpdateOverlay);
    return STATUS_ABANDONED;
}

//DXGKDDI_FLIPOVERLAY
NTSTATUS APIENTRY DxgkDdiFlipOverlay
(
    IN_CONST_HANDLE                 hOverlay,
    IN_CONST_PDXGKARG_FLIPOVERLAY   pFlipOverlay
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hOverlay);
    UNREFERENCED_PARAMETER(pFlipOverlay);
    return STATUS_ABANDONED;
}

//DXGKDDI_DESTROYOVERLAY
NTSTATUS APIENTRY DxgkDdiDestroyOverlay
(
    IN_CONST_HANDLE   hOverlay
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hOverlay);
    return STATUS_ABANDONED;
}

//DXGKDDI_MAPCPUHOSTAPERTURE
NTSTATUS APIENTRY DxgkDdiMapCpuHostAperture
(
    IN_CONST_HANDLE                        hAdapter,
    IN_CONST_PDXGKARG_MAPCPUHOSTAPERTURE   pArgs
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pArgs);
    return STATUS_ABANDONED;
}

//DXGKDDI_UNMAPCPUHOSTAPERTURE
NTSTATUS APIENTRY DxgkDdiUnmapCpuHostAperture
(
    IN_CONST_HANDLE                          hAdapter,
    IN_CONST_PDXGKARG_UNMAPCPUHOSTAPERTURE   pArgs
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pArgs);
    return STATUS_ABANDONED;
}

//DXGKDDI_ACQUIRESWIZZLINGRANGE
NTSTATUS APIENTRY DxgkDdiAcquireSwizzlingRange
(
    IN_CONST_HANDLE                        hAdapter,
    INOUT_PDXGKARG_ACQUIRESWIZZLINGRANGE   pAcquireSwizzlingRange
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pAcquireSwizzlingRange);
    return STATUS_ABANDONED;
}

//DXGKDDI_RELEASESWIZZLINGRANGE
NTSTATUS APIENTRY DxgkDdiReleaseSwizzlingRange
(
    IN_CONST_HANDLE                           hAdapter,
    IN_CONST_PDXGKARG_RELEASESWIZZLINGRANGE   pReleaseSwizzlingRange
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pReleaseSwizzlingRange);
    return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Exclusive Section

//DXGKDDI_CREATEPROTECTEDSESSION
NTSTATUS APIENTRY DxgkDdiCreateProtectedSession
(
    IN_CONST_HANDLE                         hAdapter,
    INOUT_PDXGKARG_CREATEPROTECTEDSESSION   pCreateProtectedSession
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pCreateProtectedSession);
    return STATUS_ABANDONED;
}

//DXGKDDI_DESTROYPROTECTEDSESSION
NTSTATUS APIENTRY DxgkDdiDestroyProtectedSession
(
    IN_CONST_HANDLE   hAdapter,
    IN_CONST_HANDLE   hProtectedSession
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(hProtectedSession);
    return STATUS_ABANDONED;
}

//DXGKDDI_SETVIRTUALMACHINEDATA
NTSTATUS APIENTRY DxgkDdiSetVirtualMachineData
(
    IN_CONST_HANDLE                           hAdapter,
    IN_CONST_PDXGKARG_SETVIRTUALMACHINEDATA   Args
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(Args);
    return STATUS_ABANDONED;
}

//DXGKDDI_BEGINEXCLUSIVEACCESS
NTSTATUS APIENTRY DxgkDdiBeginExclusiveAccess
(
    IN_CONST_HANDLE                    hAdapter,
    IN_PDXGKARG_BEGINEXCLUSIVEACCESS   pBeginExclusiveAccess
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pBeginExclusiveAccess);
    return STATUS_ABANDONED;
}

//DXGKDDI_ENDEXCLUSIVEACCESS
NTSTATUS APIENTRY DxgkDdiEndExclusiveAccess
(
    IN_CONST_HANDLE                  hAdapter,
    IN_PDXGKARG_ENDEXCLUSIVEACCESS   pEndExclusiveAccess
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pEndExclusiveAccess);
    return STATUS_ABANDONED;
}

//DXGKDDI_SAVEMEMORYFORHOTUPDATE
NTSTATUS APIENTRY DxgkDdiSaveMemoryForHotUpdate
(
    IN_CONST_HANDLE                            hContext,
    IN_CONST_PDXGKARG_SAVEMEMORYFORHOTUPDATE   pArgs
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hContext);
    UNREFERENCED_PARAMETER(pArgs);
    return STATUS_ABANDONED;
}

//DXGKDDI_RESTOREMEMORYFORHOTUPDATE
NTSTATUS APIENTRY DxgkDdiRestoreMemoryForHotUpdate
(
    IN_CONST_HANDLE                               hContext,
    IN_CONST_PDXGKARG_RESTOREMEMORYFORHOTUPDATE   pArgs
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hContext);
    UNREFERENCED_PARAMETER(pArgs);
    return STATUS_ABANDONED;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Reserved Section

//DXGKDDI_SETROOTPAGETABLE
VOID APIENTRY DxgkDdiSetRootPageTable
(
    IN_CONST_HANDLE                      hAdapter,
    IN_CONST_PDXGKARG_SETROOTPAGETABLE   pSetPageTable
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pSetPageTable);
}

//DXGKDDI_GETROOTPAGETABLESIZE
SIZE_T APIENTRY DxgkDdiGetRootPageTableSize
(
    IN_CONST_HANDLE                       hAdapter,
    INOUT_PDXGKARG_GETROOTPAGETABLESIZE   pArgs
)
{
    debug("[CALL]: %s", __FUNCTION__);
    UNREFERENCED_PARAMETER(hAdapter);
    UNREFERENCED_PARAMETER(pArgs);
    return 0;
}

//DXGKDDI_DESCRIBEPAGETABLE (Reserved)
DXGKDDI_UNDEFINED DxgkDdiDescribePageTable = NULL;
//(
//    IN_CONST_HANDLE                    hDevice,
//    INOUT_PDXGKARG_DESCRIBEPAGETABLE   pDescribePageTable
//)
//{
//	  debug("[CALL]: %s", __FUNCTION__);
//    UNREFERENCED_PARAMETER(hDevice);
//    UNREFERENCED_PARAMETER(pDescribePageTable);
//}

//DXGKDDI_UPDATEPAGETABLE (Reserved)
DXGKDDI_UNDEFINED DxgkDdiUpdatePageTable = NULL;
//(
//    IN_CONST_HANDLE                  hDevice,
//    INOUT_PDXGKARG_UPDATEPAGETABLE   pUpdatePageTable
//)
//{
//	  debug("[CALL]: %s", __FUNCTION__);
//    UNREFERENCED_PARAMETER(hDevice);
//    UNREFERENCED_PARAMETER(pUpdatePageTable);
//}

//DxgkDdiUpdatePageDirectory (Reserved)
DXGKDDI_UNDEFINED DxgkDdiUpdatePageDirectory = NULL;
//(
//    IN_CONST_HANDLE                      hDevice,
//    INOUT_PDXGKARG_UPDATEPAGEDIRECTORY   pUpdatePageDirectory
//)
//{
//	  debug("[CALL]: %s", __FUNCTION__);
//    UNREFERENCED_PARAMETER(hDevice);
//    UNREFERENCED_PARAMETER(pUpdatePageDirectory);
//}

//DxgkDdiMovePageDirectory (Reserved)
DXGKDDI_UNDEFINED DxgkDdiMovePageDirectory = NULL;
//(
//    _In_    CONST HANDLE                 hContext,
//    _Inout_ DXGKARG_MOVEPAGEDIRECTORY*   pMovePageDirectory
//)
//{
//	  debug("[CALL]: %s", __FUNCTION__);
//    UNREFERENCED_PARAMETER(hContext);
//    UNREFERENCED_PARAMETER(pMovePageDirectory);
//}

//(Reserved)
DXGKDDI_UNDEFINED Reserved = NULL;
//(
//	  VOID
//)
//{
//	  debug("[CALL]: %s", __FUNCTION__);
//}

//(Reserved)
DXGKDDI_UNDEFINED Reserved1 = NULL;
//(
//    VOID
//)
//{
//	  debug("[CALL]: %s", __FUNCTION__);
//}

//(Reserved)
DXGKDDI_UNDEFINED Reserved2 = NULL;
//(
//    VOID
//)
//{
//	  debug("[CALL]: %s", __FUNCTION__);
//}

//(Reserved)
DXGKDDI_UNDEFINED Reserved3 = NULL;
//(
//    VOID
//)
//{
//	  debug("[CALL]: %s", __FUNCTION__);
//}

#pragma endregion
//--------------------------------------------------------------------------------------------------------