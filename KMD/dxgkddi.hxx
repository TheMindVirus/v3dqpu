#ifndef _DXGKDDI_HXX_
#define _DXGKDDI_HXX_

#define DXGKDDI_UNDEFINED   extern void*

extern "C"
{
#include <dispmprt.h>
#pragma comment(lib, "displib.lib")
}
//Also set "Linker->Additional Dependencies" to "$(DDK_LIB_PATH)displib.lib;%(AdditionalDependencies)" for
//All Configurations and Platforms (Default: [Debug|ARM64])

//DXGKDDI_CALLBACK_PATCH (Undocumented) - Patches all callbacks to DXGK in one go for DxgkInitialize()
typedef VOID WINAPI DXGKDDI_CALLBACK_PATCH(PDRIVER_INITIALIZATION_DATA config);
typedef DXGKDDI_CALLBACK_PATCH* PDXGKDDI_CALLBACK_PATCH;
DXGKDDI_CALLBACK_PATCH DxgkDdiCallbackPatch;

//--------------------------------------------------------------------------------------------------------
#pragma region //Device Section

DXGKDDI_CREATEDEVICE                                   DxgkDdiCreateDevice;
DXGKDDI_ADD_DEVICE                                     DxgkDdiAddDevice;
DXGKDDI_LINK_DEVICE                                    DxgkDdiLinkDevice;
DXGKDDI_START_DEVICE                                   DxgkDdiStartDevice;
DXGKDDI_RESET_DEVICE                                   DxgkDdiResetDevice;
DXGKDDI_STOP_DEVICE                                    DxgkDdiStopDevice;
DXGKDDI_REMOVE_DEVICE                                  DxgkDdiRemoveDevice;
DXGKDDI_DESTROYDEVICE                                  DxgkDdiDestroyDevice;
DXGKDDI_UNLOAD                                         DxgkDdiUnload;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Present Section

DXGKDDI_PRESENT                                        DxgkDdiPresent;
DXGKDDI_RENDER                                         DxgkDdiRender;
DXGKDDI_RENDER                                         DxgkDdiRenderKm;
DXGKDDI_RENDERGDI                                      DxgkDdiRenderGdi;
DXGKDDI_UNDEFINED                                      DxgkDdiSubmitRender;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Command Section

DXGKDDI_PATCH                                          DxgkDdiPatch;
DXGKDDI_PREEMPTCOMMAND                                 DxgkDdiPreemptCommand;
DXGKDDI_SUBMITCOMMAND                                  DxgkDdiSubmitCommand;
DXGKDDI_SUBMITCOMMANDVIRTUAL                           DxgkDdiSubmitCommandVirtual;
DXGKDDI_VALIDATESUBMITCOMMAND                          DxgkDdiValidateSubmitCommand;
DXGKDDI_CANCELCOMMAND                                  DxgkDdiCancelCommand;
DXGKDDI_BUILDPAGINGBUFFER                              DxgkDdiBuildPagingBuffer;
DXGKDDI_RESETFROMTIMEOUT                               DxgkDdiResetFromTimeout;
DXGKDDI_RESTARTFROMTIMEOUT                             DxgkDdiRestartFromTimeout;
DXGKDDI_ESCAPE                                         DxgkDdiEscape;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Calibration Section

DXGKDDI_EXCHANGEPRESTARTINFO                           DxgkDdiExchangePreStartInfo;
DXGKDDI_FORMATHISTORYBUFFER                            DxgkDdiFormatHistoryBuffer;
DXGKDDI_CONTROLDIAGNOSTICREPORTING                     DxgkDdiControlDiagnosticReporting;
DXGKDDI_COLLECTDIAGNOSTICINFO                          DxgkDdiCollectDiagnosticInfo;
DXGKDDI_CALIBRATEGPUCLOCK                              DxgkDdiCalibrateGpuClock;
DXGKDDI_CONTROLMODEBEHAVIOR                            DxgkDdiControlModeBehavior;
DXGKDDI_UPDATEMONITORLINKINFO                          DxgkDdiUpdateMonitorLinkInfo;
DXGKDDI_VALIDATEUPDATEALLOCATIONPROPERTY               DxgkDdiValidateUpdateAllocationProperty;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Set Calibration Section

DXGKDDI_SETUPPRIORITYBANDS                             DxgkDdiSetupPriorityBands;
DXGKDDI_SETCONTEXTSCHEDULINGPROPERTIES                 DxgkDdiSetContextSchedulingProperties;
DXGKDDI_SETSCHEDULINGLOGBUFFER                         DxgkDdiSetSchedulingLogBuffer;
DXGKDDI_SETTARGETGAMMA                                 DxgkDdiSetTargetGamma;
DXGKDDI_SETTARGETCONTENTTYPE                           DxgkDdiSetTargetContentType;
DXGKDDI_SETTARGETANALOGCOPYPROTECTION                  DxgkDdiSetTargetAnalogCopyProtection;
DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY                   DxgkDdiSetTargetAdjustedColorimetry;
DXGKDDI_SETTARGETADJUSTEDCOLORIMETRY2                  DxgkDdiSetTargetAdjustedColorimetry2;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Set Section

DXGKDDI_SETPALETTE                                     DxgkDdiSetPalette;
DXGKDDI_SETPOINTERPOSITION                             DxgkDdiSetPointerPosition;
DXGKDDI_SETPOINTERSHAPE                                DxgkDdiSetPointerShape;
DXGKDDI_SET_POWER_STATE                                DxgkDdiSetPowerState;
DXGKDDISETPOWERPSTATE                                  DxgkDdiSetPowerPState;
DXGKDDISETPOWERCOMPONENTFSTATE                         DxgkDdiSetPowerComponentFState;
DXGKDDI_SETSTABLEPOWERSTATE                            DxgkDdiSetStablePowerState;
DXGKDDI_SETTRACKEDWORKLOADPOWERLEVEL                   DxgkDdiSetTrackedWorkloadPowerLevel;
DXGKDDI_SETDISPLAYPRIVATEDRIVERFORMAT                  DxgkDdiSetDisplayPrivateDriverFormat;
DXGKDDI_SETVIDEOPROTECTEDREGION                        DxgkDdiSetVideoProtectedRegion;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Get Section

DXGKDDI_GETSCANLINE                                    DxgkDdiGetScanLine;
DXGKDDI_GETNODEMETADATA                                DxgkDdiGetNodeMetadata;
DXGKDDI_GET_CHILD_CONTAINER_ID                         DxgkDdiGetChildContainerId;
DXGKDDI_GETPOSTCOMPOSITIONCAPS                         DxgkDdiGetPostCompositionCaps;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Notify Section

DXGKDDI_NOTIFY_ACPI_EVENT                              DxgkDdiNotifyAcpiEvent;
DXGKDDI_NOTIFYFOCUSPRESENT                             DxgkDdiNotifyFocusPresent;
DXGKDDI_NOTIFY_SURPRISE_REMOVAL                        DxgkDdiNotifySurpriseRemoval;
DXGKDDIPOWERRUNTIMECONTROLREQUEST                      DxgkDdiPowerRuntimeControlRequest;
DXGKDDI_POWERRUNTIMESETDEVICEHANDLE                    DxgkDdiPowerRuntimeSetDeviceHandle;
DXGKDDI_CREATEPERIODICFRAMENOTIFICATION                DxgkDdiCreatePeriodicFrameNotification;
DXGKDDI_DESTROYPERIODICFRAMENOTIFICATION               DxgkDdiDestroyPeriodicFrameNotification;
DXGKDDI_SIGNALMONITOREDFENCE                           DxgkDdiSignalMonitoredFence;
DXGKDDI_DISPLAYDETECTCONTROL                           DxgkDdiDisplayDetectControl;
DXGKDDI_RECOMMENDMONITORMODES                          DxgkDdiRecommendMonitorModes;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Query Section

DXGKDDI_QUERY_INTERFACE                                DxgkDdiQueryInterface;
DXGKDDI_QUERYADAPTERINFO                               DxgkDdiQueryAdapterInfo;
DXGKDDI_QUERYCURRENTFENCE                              DxgkDdiQueryCurrentFence;
DXGKDDI_QUERY_DEVICE_DESCRIPTOR                        DxgkDdiQueryDeviceDescriptor;
DXGKDDI_QUERYVIDPNHWCAPABILITY                         DxgkDdiQueryVidPnHWCapability;
DXGKDDI_QUERY_CHILD_RELATIONS                          DxgkDdiQueryChildRelations;
DXGKDDI_QUERY_CHILD_STATUS                             DxgkDdiQueryChildStatus;
DXGKDDI_QUERYCONNECTIONCHANGE                          DxgkDdiQueryConnectionChange;
DXGKDDI_QUERYDIAGNOSTICTYPESSUPPORT                    DxgkDdiQueryDiagnosticTypesSupport;
DXGKDDI_QUERYDEPENDENTENGINEGROUP                      DxgkDdiQueryDependentEngineGroup;
DXGKDDI_QUERYENGINESTATUS                              DxgkDdiQueryEngineStatus;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Video Present Network (VidPn) Section

DXGKDDI_COMMITVIDPN                                    DxgkDdiCommitVidPn;
DXGKDDI_ISSUPPORTEDVIDPN                               DxgkDdiIsSupportedVidPn;
DXGKDDI_ENUMVIDPNCOFUNCMODALITY                        DxgkDdiEnumVidPnCofuncModality;
DXGKDDI_RECOMMENDFUNCTIONALVIDPN                       DxgkDdiRecommendFunctionalVidPn;
DXGKDDI_GETMULTIPLANEOVERLAYCAPS                       DxgkDdiGetMultiPlaneOverlayCaps;
DXGKDDI_POSTMULTIPLANEOVERLAYPRESENT                   DxgkDdiPostMultiPlaneOverlayPresent;
DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT                  DxgkDdiCheckMultiPlaneOverlaySupport;
DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT2                 DxgkDdiCheckMultiPlaneOverlaySupport2;
DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT3                 DxgkDdiCheckMultiPlaneOverlaySupport3;
DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY     DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay;
DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2    DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2;
DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3    DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay3;
DXGKDDI_SETVIDPNSOURCEADDRESS                          DxgkDdiSetVidPnSourceAddress;
DXGKDDI_SETVIDPNSOURCEVISIBILITY                       DxgkDdiSetVidPnSourceVisibility;
DXGKDDI_SETTIMINGSFROMVIDPN                            DxgkDdiSetTimingsFromVidPn;
DXGKDDI_UPDATEACTIVEVIDPNPRESENTPATH                   DxgkDdiUpdateActiveVidPnPresentPath;
DXGKDDI_RECOMMENDVIDPNTOPOLOGY                         DxgkDdiRecommendVidPnTopology;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Engine Section

DXGKDDI_RESETENGINE                                    DxgkDdiResetEngine;
DXGKDDI_RESUMEHWENGINE                                 DxgkDdiResumeHwEngine;
DXGKDDI_RESETHWENGINE                                  DxgkDdiResetHwEngine;
DXGKDDI_CREATEPROCESS                                  DxgkDdiCreateProcess;
DXGKDDI_DESTROYPROCESS                                 DxgkDdiDestroyProcess;
DXGKDDI_STOPCAPTURE                                    DxgkDdiStopCapture;
DXGKDDI_STOP_DEVICE_AND_RELEASE_POST_DISPLAY_OWNERSHIP DxgkDdiStopDeviceAndReleasePostDisplayOwnership;
DXGKDDI_SYSTEM_DISPLAY_ENABLE                          DxgkDdiSystemDisplayEnable;
DXGKDDI_SYSTEM_DISPLAY_WRITE                           DxgkDdiSystemDisplayWrite;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Interrupt Section

DXGKDDI_DPC_ROUTINE                                    DxgkDdiDpcRoutine;
DXGKDDI_INTERRUPT_ROUTINE                              DxgkDdiInterruptRoutine;
DXGKDDI_DISPATCH_IO_REQUEST                            DxgkDdiDispatchIoRequest;
DXGKDDI_CONTROLINTERRUPT                               DxgkDdiControlInterrupt;
DXGKDDI_CONTROLINTERRUPT2                              DxgkDdiControlInterrupt2;
DXGKDDI_CONTROLINTERRUPT3                              DxgkDdiControlInterrupt3;
DXGKDDI_CONTROL_ETW_LOGGING                            DxgkDdiControlEtwLogging;
DXGKDDI_COLLECTDBGINFO                                 DxgkDdiCollectDbgInfo;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Allocation Section

DXGKDDI_GETSTANDARDALLOCATIONDRIVERDATA                DxgkDdiGetStandardAllocationDriverData;
DXGKDDI_DESCRIBEALLOCATION                             DxgkDdiDescribeAllocation;
DXGKDDI_CREATEALLOCATION                               DxgkDdiCreateAllocation;
DXGKDDI_UNDEFINED                                      DxgkDdiCreateAllocation2;
DXGKDDI_OPENALLOCATIONINFO                             DxgkDdiOpenAllocation;
DXGKDDI_CLOSEALLOCATION                                DxgkDdiCloseAllocation;
DXGKDDI_DESTROYALLOCATION                              DxgkDdiDestroyAllocation;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Context Section

DXGKDDI_CREATECONTEXT                                  DxgkDdiCreateContext;
DXGKDDI_SUSPENDCONTEXT                                 DxgkDdiSuspendContext;
DXGKDDI_RESUMECONTEXT                                  DxgkDdiResumeContext;
DXGKDDI_DESTROYCONTEXT                                 DxgkDdiDestroyContext;
DXGKDDI_CREATEHWCONTEXT                                DxgkDdiCreateHwContext;
DXGKDDI_DESTROYHWCONTEXT                               DxgkDdiDestroyHwContext;
DXGKDDI_CREATEHWQUEUE                                  DxgkDdiCreateHwQueue;
DXGKDDI_PRESENTTOHWQUEUE                               DxgkDdiPresentToHwQueue;
DXGKDDI_UPDATEHWCONTEXTSTATE                           DxgkDdiUpdateHwContextState;
DXGKDDI_SUBMITCOMMANDTOHWQUEUE                         DxgkDdiSubmitCommandToHwQueue;
DXGKDDI_SWITCHTOHWCONTEXTLIST                          DxgkDdiSwitchToHwContextList;
DXGKDDI_DESTROYHWQUEUE                                 DxgkDdiDestroyHwQueue;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Overlay Section

DXGKDDI_CREATEOVERLAY                                  DxgkDdiCreateOverlay;
DXGKDDI_UPDATEOVERLAY                                  DxgkDdiUpdateOverlay;
DXGKDDI_FLIPOVERLAY                                    DxgkDdiFlipOverlay;
DXGKDDI_DESTROYOVERLAY                                 DxgkDdiDestroyOverlay;
DXGKDDI_MAPCPUHOSTAPERTURE                             DxgkDdiMapCpuHostAperture;
DXGKDDI_UNMAPCPUHOSTAPERTURE                           DxgkDdiUnmapCpuHostAperture;
DXGKDDI_ACQUIRESWIZZLINGRANGE                          DxgkDdiAcquireSwizzlingRange;
DXGKDDI_RELEASESWIZZLINGRANGE                          DxgkDdiReleaseSwizzlingRange;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Exclusive Section

DXGKDDI_CREATEPROTECTEDSESSION                         DxgkDdiCreateProtectedSession;
DXGKDDI_DESTROYPROTECTEDSESSION                        DxgkDdiDestroyProtectedSession;
DXGKDDI_SETVIRTUALMACHINEDATA                          DxgkDdiSetVirtualMachineData;
DXGKDDI_BEGINEXCLUSIVEACCESS                           DxgkDdiBeginExclusiveAccess;
DXGKDDI_ENDEXCLUSIVEACCESS                             DxgkDdiEndExclusiveAccess;
DXGKDDI_SAVEMEMORYFORHOTUPDATE                         DxgkDdiSaveMemoryForHotUpdate;
DXGKDDI_RESTOREMEMORYFORHOTUPDATE                      DxgkDdiRestoreMemoryForHotUpdate;

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Reserved Section

DXGKDDI_SETROOTPAGETABLE                               DxgkDdiSetRootPageTable;
DXGKDDI_GETROOTPAGETABLESIZE                           DxgkDdiGetRootPageTableSize;
DXGKDDI_UNDEFINED                                      DxgkDdiDescribePageTable;
DXGKDDI_UNDEFINED                                      DxgkDdiUpdatePageTable;
DXGKDDI_UNDEFINED                                      DxgkDdiUpdatePageDirectory;
DXGKDDI_UNDEFINED                                      DxgkDdiMovePageDirectory;
DXGKDDI_UNDEFINED                                      Reserved;
DXGKDDI_UNDEFINED                                      Reserved1;
DXGKDDI_UNDEFINED                                      Reserved2;
DXGKDDI_UNDEFINED                                      Reserved3;

#pragma endregion
//--------------------------------------------------------------------------------------------------------

#endif//_DXGKDDI_HXX_