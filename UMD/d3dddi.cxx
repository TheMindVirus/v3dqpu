#include "device.hxx"

/// -- WDDM2 Control Flow -- Windows Display Driver Model 2.0 -- Windows Kernel Mode Driver Framework --
///https://docs.microsoft.com/en-us/windows-hardware/drivers/display/windows-vista-and-later-display-driver-model-operation-flow

//D3DDDI_OPEN_PATCH (Undocumented) - Patches all callbacks to Direct3D in one go for OpenAdapter10_2()
VOID WINAPI D3dDdiOpenPatch(D3D10DDIARG_OPENADAPTER& Info)
{
	Info.pAdapterCallbacks->pfnQueryAdapterInfoCb;
	Info.pAdapterCallbacks->pfnGetMultisampleMethodListCb;
	Info.pAdapterCallbacks->pfnQueryAdapterInfoCb2;

	Info.pAdapterFuncs_2->pfnCalcPrivateDeviceSize;
	Info.pAdapterFuncs_2->pfnCloseAdapter;
	Info.pAdapterFuncs_2->pfnCreateDevice;
	Info.pAdapterFuncs_2->pfnGetCaps;
	Info.pAdapterFuncs_2->pfnGetSupportedVersions;
}

//WDDMDDI_CREATE_PATCH (Undocumented) - Patches all callbacks to Windows Display Driver Model in one go for D3dDdiCreateDevice()
VOID WINAPI WddmDdiCreatePatch(D3D10DDIARG_CREATEDEVICE& Info)
{
	//Info.pKTCallbacks->pfnAllocateCb = WddmDdiAllocateCb; //pKTCallbacks is provided as const

	//Vertex Shader
	Info.pWDDM2_6DeviceFuncs->pfnCreateVertexShader = WddmDdiCreateVertexShader;
	Info.pWDDM2_6DeviceFuncs->pfnSetVertexPipelineOutput = WddmDdiSetVertexPipelineOutput;
	Info.pWDDM2_6DeviceFuncs->pfnVsSetShader = WddmDdiVsSetShader;
	Info.pWDDM2_6DeviceFuncs->pfnVsSetShaderWithIfaces = WddmDdiVsSetShaderWithIfaces;
	Info.pWDDM2_6DeviceFuncs->pfnVsSetShaderResources = WddmDdiVsSetShaderResources;
	Info.pWDDM2_6DeviceFuncs->pfnVsSetConstantBuffers = WddmDdiVsSetConstantBuffers;
	Info.pWDDM2_6DeviceFuncs->pfnVsSetSamplers = WddmDdiVsSetSamplers;

	//Geometry Shader
	Info.pWDDM2_6DeviceFuncs->pfnCreateGeometryShader = WddmDdiCreateGeometryShader;
	Info.pWDDM2_6DeviceFuncs->pfnCreateGeometryShaderWithStreamOutput = WddmDdiCreateGeometryShaderWithStreamOutput;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateGeometryShaderWithStreamOutput = WddmDdiCalcPrivateGeometryShaderWithStreamOutput;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateTessellationShaderSize = WddmDdiCalcPrivateTessellationShaderSize;
	Info.pWDDM2_6DeviceFuncs->pfnSoSetTargets = WddmDdiSoSetTargets;
	Info.pWDDM2_6DeviceFuncs->pfnGsSetShader = WddmDdiGsSetShader;
	Info.pWDDM2_6DeviceFuncs->pfnGsSetShaderWithIfaces = WddmDdiGsSetShaderWithIfaces;
	Info.pWDDM2_6DeviceFuncs->pfnGsSetShaderResources = WddmDdiGsSetShaderResources;
	Info.pWDDM2_6DeviceFuncs->pfnGsSetConstantBuffers = WddmDdiGsSetConstantBuffers;
	Info.pWDDM2_6DeviceFuncs->pfnGsSetSamplers = WddmDdiGsSetSamplers;

	//Pixel Shader
	Info.pWDDM2_6DeviceFuncs->pfnCreatePixelShader = WddmDdiCreatePixelShader;
	Info.pWDDM2_6DeviceFuncs->pfnPsSetShader = WddmDdiPsSetShader;
	Info.pWDDM2_6DeviceFuncs->pfnPsSetShaderWithIfaces = WddmDdiPsSetShaderWithIfaces;
	Info.pWDDM2_6DeviceFuncs->pfnPsSetShaderResources = WddmDdiPsSetShaderResources;
	Info.pWDDM2_6DeviceFuncs->pfnPsSetConstantBuffers = WddmDdiPsSetConstantBuffers;
	Info.pWDDM2_6DeviceFuncs->pfnPsSetSamplers = WddmDdiPsSetSamplers;

	//Hull Shader
	Info.pWDDM2_6DeviceFuncs->pfnCreateHullShader = WddmDdiCreateHullShader;
	Info.pWDDM2_6DeviceFuncs->pfnHsSetShader = WddmDdiHsSetShader;
	Info.pWDDM2_6DeviceFuncs->pfnHsSetShaderWithIfaces = WddmDdiHsSetShaderWithIfaces;
	Info.pWDDM2_6DeviceFuncs->pfnHsSetShaderResources = WddmDdiHsSetShaderResources;
	Info.pWDDM2_6DeviceFuncs->pfnHsSetConstantBuffers = WddmDdiHsSetConstantBuffers;
	Info.pWDDM2_6DeviceFuncs->pfnHsSetSamplers = WddmDdiHsSetSamplers;
	
	//Domain Shader
	Info.pWDDM2_6DeviceFuncs->pfnCreateDomainShader = WddmDdiCreateDomainShader;
	Info.pWDDM2_6DeviceFuncs->pfnDsSetShader = WddmDdiDsSetShader;
	Info.pWDDM2_6DeviceFuncs->pfnDsSetShaderWithIfaces = WddmDdiDsSetShaderWithIfaces;
	Info.pWDDM2_6DeviceFuncs->pfnDsSetConstantBuffers = WddmDdiDsSetConstantBuffers;
	Info.pWDDM2_6DeviceFuncs->pfnDsSetShaderResources = WddmDdiDsSetShaderResources;
	Info.pWDDM2_6DeviceFuncs->pfnDsSetSamplers = WddmDdiDsSetSamplers;

	//Compute Shader
	Info.pWDDM2_6DeviceFuncs->pfnCreateComputeShader = WddmDdiCreateComputeShader;
	Info.pWDDM2_6DeviceFuncs->pfnCsSetShader = WddmDdiCsSetShader;
	Info.pWDDM2_6DeviceFuncs->pfnCsSetShaderWithIfaces = WddmDdiCsSetShaderWithIfaces;
	Info.pWDDM2_6DeviceFuncs->pfnCsSetShaderResources = WddmDdiCsSetShaderResources;
	Info.pWDDM2_6DeviceFuncs->pfnCsSetConstantBuffers = WddmDdiCsSetConstantBuffers;
	Info.pWDDM2_6DeviceFuncs->pfnCsSetSamplers = WddmDdiCsSetSamplers;
	Info.pWDDM2_6DeviceFuncs->pfnCsSetUnorderedAccessViews = WddmDdiCsSetUnorderedAccessViews;

	//Miscellaneous Shader Methods
	Info.pWDDM2_6DeviceFuncs->pfnDestroyShader = WddmDdiDestroyShader;
	Info.pWDDM2_6DeviceFuncs->pfnCreateSampler = WddmDdiCreateSampler;
	Info.pWDDM2_6DeviceFuncs->pfnDestroySampler = WddmDdiDestroySampler;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateSamplerSize = WddmDdiCalcPrivateSamplerSize;
	Info.pWDDM2_6DeviceFuncs->pfnRetrieveShaderComment = WddmDdiRetrieveShaderComment;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateShaderSize = WddmDdiCalcPrivateShaderSize;

    //Input Assembler
	Info.pWDDM2_6DeviceFuncs->pfnIaSetInputLayout = WddmDdiIaSetInputLayout;
	Info.pWDDM2_6DeviceFuncs->pfnIaSetVertexBuffers = WddmDdiIaSetVertexBuffers;
	Info.pWDDM2_6DeviceFuncs->pfnIaSetIndexBuffer = WddmDdiIaSetIndexBuffer;
	Info.pWDDM2_6DeviceFuncs->pfnIaSetTopology = WddmDdiIaSetTopology;
	Info.pWDDM2_6DeviceFuncs->pfnDynamicIABufferMapNoOverwrite = WddmDdiDynamicIABufferMapNoOverwrite;
	Info.pWDDM2_6DeviceFuncs->pfnDynamicIABufferUnmap = WddmDdiDynamicIABufferUnmap;
	Info.pWDDM2_6DeviceFuncs->pfnDynamicIABufferMapDiscard = WddmDdiDynamicIABufferMapDiscard;

	//Constant Buffer (Uniforms?)
	Info.pWDDM2_6DeviceFuncs->pfnDefaultConstantBufferUpdateSubresourceUP = WddmDdiDefaultConstantBufferUpdateSubResourceUP;
	Info.pWDDM2_6DeviceFuncs->pfnDynamicConstantBufferMapDiscard = WddmDdiDynamicConstantBufferMapDiscard;
	Info.pWDDM2_6DeviceFuncs->pfnDynamicConstantBufferUnmap = WddmDdiDynamicConstantBufferUnmap;
	Info.pWDDM2_6DeviceFuncs->pfnDynamicConstantBufferMapNoOverwrite = WddmDdiDynamicConstantBufferMapNoOverwrite;

	//Counter (Scoreboard?)
	Info.pWDDM2_6DeviceFuncs->pfnCheckCounterInfo = WddmDdiCheckCounterInfo;
	Info.pWDDM2_6DeviceFuncs->pfnCheckCounter = WddmDdiCheckCounter;

	//Draw
	Info.pWDDM2_6DeviceFuncs->pfnDraw = WddmDdiDraw;
	Info.pWDDM2_6DeviceFuncs->pfnDrawAuto = WddmDdiDrawAuto;
	Info.pWDDM2_6DeviceFuncs->pfnDrawIndexed = WddmDdiDrawIndexed;
	Info.pWDDM2_6DeviceFuncs->pfnDrawInstanced = WddmDdiDrawInstanced;
	Info.pWDDM2_6DeviceFuncs->pfnDrawIndexedInstanced = WddmDdiDrawIndexedInstanced;
	Info.pWDDM2_6DeviceFuncs->pfnDrawInstancedIndirect = WddmDdiDrawInstancedIndirect;
	Info.pWDDM2_6DeviceFuncs->pfnDrawIndexedInstancedIndirect = WddmDdiDrawIndexedInstancedIndirect;
	Info.pWDDM2_6DeviceFuncs->pfnCheckDirectFlipSupport = WddmDdiCheckDirectFlipSupport;
	Info.pWDDM2_6DeviceFuncs->pfnSetBlendState = WddmDdiSetBlendState;
	Info.pWDDM2_6DeviceFuncs->pfnSetDepthStencilState = WddmDdiSetDepthStencilState;
	Info.pWDDM2_6DeviceFuncs->pfnSetRasterizerState = WddmDdiSetRasterizerState;
	Info.pWDDM2_6DeviceFuncs->pfnFlush = WddmDdiFlush;
	Info.pWDDM2_6DeviceFuncs->pfnClearView = WddmDdiClearView;
	Info.pWDDM2_6DeviceFuncs->pfnDestroyDevice = WddmDdiDestroyDevice;

	//Viewport
	Info.pWDDM2_6DeviceFuncs->pfnSetViewports = WddmDdiSetViewports;
	Info.pWDDM2_6DeviceFuncs->pfnSetScissorRects = WddmDdiSetScissorRects;
	Info.pWDDM2_6DeviceFuncs->pfnSetRenderTargets = WddmDdiSetRenderTargets;
	Info.pWDDM2_6DeviceFuncs->pfnCheckFormatSupport = WddmDdiCheckFormatSupport;
	Info.pWDDM2_6DeviceFuncs->pfnSetTextFilterSize = WddmDdiSetTextFilterSize;
	Info.pWDDM2_6DeviceFuncs->pfnSetResourceMinLOD = WddmDdiSetResourceMinLOD;
	Info.pWDDM2_6DeviceFuncs->pfnResetPrimitiveID = WddmDdiResetPrimitiveID;
	Info.pWDDM2_6DeviceFuncs->pfnCopyStructureCount = WddmDdiCopyStructureCount;

	//Resource
	Info.pWDDM2_6DeviceFuncs->pfnCreateResource = WddmDdiCreateResource;
	Info.pWDDM2_6DeviceFuncs->pfnOpenResource = WddmDdiOpenResource;
	Info.pWDDM2_6DeviceFuncs->pfnAcquireResource = WddmDdiAcquireResource;
	Info.pWDDM2_6DeviceFuncs->pfnReleaseResource = WddmDdiReleaseResource;
	Info.pWDDM2_6DeviceFuncs->pfnDestroyResource = WddmDdiDestroyResource;
	Info.pWDDM2_6DeviceFuncs->pfnCreateShaderResourceView = WddmDdiCreateShaderResourceView;
	Info.pWDDM2_6DeviceFuncs->pfnDestroyShaderResourceView = WddmDdiDestroyShaderResourceView;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateResourceSize = WddmDdiCalcPrivateResourceSize;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateOpenedResourceSize = WddmDdiCalcPrivateOpenedResourceSize;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateShaderResourceViewSize = WddmDdiCalcPrivateShaderResourceViewSize;
	Info.pWDDM2_6DeviceFuncs->pfnResourceCopy = WddmDdiResourceCopy;
	Info.pWDDM2_6DeviceFuncs->pfnResourceCopyRegion = WddmDdiResourceCopyRegion;
	Info.pWDDM2_6DeviceFuncs->pfnResourceMap = WddmDdiResourceMap;
	Info.pWDDM2_6DeviceFuncs->pfnResourceUnmap = WddmDdiResourceUnmap;
	Info.pWDDM2_6DeviceFuncs->pfnResourceIsStagingBusy = WddmDdiResourceIsStagingBusy;
	Info.pWDDM2_6DeviceFuncs->pfnResourceConvert = WddmDdiResourceConvert;
	Info.pWDDM2_6DeviceFuncs->pfnResourceConvertRegion = WddmDdiResourceConvertRegion;
	Info.pWDDM2_6DeviceFuncs->pfnShaderResourceViewReadAfterWriteHazard = WddmDdiShaderResourceViewReadAfterWriteHazard;
	Info.pWDDM2_6DeviceFuncs->pfnResourceReadAfterWriteHazard = WddmDdiResourceReadAfterWriteHazard;
	Info.pWDDM2_6DeviceFuncs->pfnResourceUpdateSubresourceUP = WddmDdiResourceUpdateSubResourceUP;
	Info.pWDDM2_6DeviceFuncs->pfnResourceResolveSubresource = WddmDdiResourceResolveSubResource;
	Info.pWDDM2_6DeviceFuncs->pfnDynamicResourceMapDiscard = WddmDdiDynamicResourceMapDiscard;
	Info.pWDDM2_6DeviceFuncs->pfnDynamicResourceUnmap = WddmDdiDynamicResourceUnmap;
	Info.pWDDM2_6DeviceFuncs->pfnStagingResourceMap = WddmDdiStagingResourceMap;
	Info.pWDDM2_6DeviceFuncs->pfnStagingResourceUnmap = WddmDdiStagingResourceUnmap;
	Info.pWDDM2_6DeviceFuncs->pfnGetResourceLayout = WddmDdiGetResourceLayout;

	//Command List
	Info.pWDDM2_6DeviceFuncs->pfnCreateCommandList = WddmDdiCreateCommandList;
	Info.pWDDM2_6DeviceFuncs->pfnDestroyCommandList = WddmDdiDestroyCommandList;
	Info.pWDDM2_6DeviceFuncs->pfnCommandListExecute = WddmDdiCommandListExecute;
	Info.pWDDM2_6DeviceFuncs->pfnAbandonCommandList = WddmDdiAbandonCommandList;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateCommandListSize = WddmDdiCalcPrivateCommandListSize;
	Info.pWDDM2_6DeviceFuncs->pfnRecycleCommandList = WddmDdiRecycleCommandList;
	Info.pWDDM2_6DeviceFuncs->pfnRecycleCreateCommandList = WddmDdiRecycleCreateCommandList;
	Info.pWDDM2_6DeviceFuncs->pfnRecycleCreateDeferredContext = WddmDdiRecycleCreateDeferredContext;
	Info.pWDDM2_6DeviceFuncs->pfnRecycleDestroyCommandList = WddmDdiRecycleDestroyCommandList;
	Info.pWDDM2_6DeviceFuncs->pfnDispatch = WddmDdiDispatch;
	Info.pWDDM2_6DeviceFuncs->pfnDispatchIndirect = WddmDdiDispatchIndirect;
	Info.pWDDM2_6DeviceFuncs->pfnDiscard = WddmDdiDiscard;

	//Query
	Info.pWDDM2_6DeviceFuncs->pfnCreateQuery = WddmDdiCreateQuery;
	Info.pWDDM2_6DeviceFuncs->pfnDestroyQuery = WddmDdiDestroyQuery;
	Info.pWDDM2_6DeviceFuncs->pfnQueryBegin = WddmDdiQueryBegin;
	Info.pWDDM2_6DeviceFuncs->pfnQueryEnd = WddmDdiQueryEnd;
	Info.pWDDM2_6DeviceFuncs->pfnSetPredication = WddmDdiSetPredication;
	Info.pWDDM2_6DeviceFuncs->pfnQueryGetData = WddmDdiQueryGetData;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateQuerySize = WddmDdiCalcPrivateQuerySize;

	//Cache
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateShaderCacheSessionSize = WddmDdiCalcPrivateShaderCacheSessionSize;
	Info.pWDDM2_6DeviceFuncs->pfnCreateShaderCacheSession = WddmDdiCreateShaderCacheSession;
	Info.pWDDM2_6DeviceFuncs->pfnDestroyShaderCacheSession = WddmDdiDestroyShaderCacheSession;
	Info.pWDDM2_6DeviceFuncs->pfnSetShaderCacheSession = WddmDdiSetShaderCacheSession;

	//State
	Info.pWDDM2_6DeviceFuncs->pfnRelocateDeviceFuncs = WddmDdiRelocateDeviceFuncs;
	Info.pWDDM2_6DeviceFuncs->pfnCreateBlendState = WddmDdiCreateBlendState;
	Info.pWDDM2_6DeviceFuncs->pfnDestroyBlendState = WddmDdiDestroyBlendState;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateBlendStateSize = WddmDdiCalcPrivateBlendStateSize;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateDepthStencilStateSize = WddmDdiCalcPrivateDepthStencilStateSize;
	Info.pWDDM2_6DeviceFuncs->pfnCreateDepthStencilState = WddmDdiCreateDepthStencilState;
	Info.pWDDM2_6DeviceFuncs->pfnDestroyDepthStencilState = WddmDdiDestroyDepthStencilState;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateRasterizerStateSize = WddmDdiCalcPrivateRasterizerStateSize;
	Info.pWDDM2_6DeviceFuncs->pfnCreateRasterizerState = WddmDdiCreateRasterizerState;
	Info.pWDDM2_6DeviceFuncs->pfnDestroyRasterizerState = WddmDdiDestroyRasterizerState;

	//Other
	Info.pWDDM2_6DeviceFuncs->pfnGenMips = WddmDdiGenMips;
	Info.pWDDM2_6DeviceFuncs->pfnGetMipPacking = WddmDdiGetMipPacking;
	Info.pWDDM2_6DeviceFuncs->pfnCreateRenderTargetView = WddmDdiCreateRenderTargetView;
	Info.pWDDM2_6DeviceFuncs->pfnDestroyRenderTargetView = WddmDdiDestroyRenderTargetView;
	Info.pWDDM2_6DeviceFuncs->pfnClearRenderTargetView = WddmDdiClearRenderTargetView;
	Info.pWDDM2_6DeviceFuncs->pfnClearDepthStencilView = WddmDdiClearDepthStencilView;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateRenderTargetViewSize = WddmDdiCalcPrivateRenderTargetViewSize;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateDepthStencilViewSize = WddmDdiCalcPrivateDepthStencilViewSize;
	Info.pWDDM2_6DeviceFuncs->pfnCreateDepthStencilView = WddmDdiCreateDepthStencilView;
	Info.pWDDM2_6DeviceFuncs->pfnDestroyDepthStencilView = WddmDdiDestroyDepthStencilView;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateElementLayoutSize = WddmDdiCalcPrivateElementLayoutSize;
	Info.pWDDM2_6DeviceFuncs->pfnCreateElementLayout = WddmDdiCreateElementLayout;
	Info.pWDDM2_6DeviceFuncs->pfnDestroyElementLayout = WddmDdiDestroyElementLayout;
	Info.pWDDM2_6DeviceFuncs->pfnCheckMultisampleQualityLevels = WddmDdiCheckMultisampleQualityLevels;
	Info.pWDDM2_6DeviceFuncs->pfnCheckDeferredContextHandleSizes = WddmDdiCheckDeferredContextHandleSizes;
	Info.pWDDM2_6DeviceFuncs->pfnCalcDeferredContextHandleSize = WddmDdiCalcDeferredContextHandleSize;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateDeferredContextSize = WddmDdiCalcPrivateDeferredContextSize;
	Info.pWDDM2_6DeviceFuncs->pfnCreateDeferredContext = WddmDdiCreateDeferredContext;
	Info.pWDDM2_6DeviceFuncs->pfnCalcPrivateUnorderedAccessViewSize = WddmDdiCalcPrivateUnorderedAccessViewSize;
	Info.pWDDM2_6DeviceFuncs->pfnCreateUnorderedAccessView = WddmDdiCreateUnorderedAccessView;
	Info.pWDDM2_6DeviceFuncs->pfnDestroyUnorderedAccessView = WddmDdiDestroyUnorderedAccessView;
	Info.pWDDM2_6DeviceFuncs->pfnClearUnorderedAccessViewUint = WddmDdiClearUnorderedAccessViewUint;
	Info.pWDDM2_6DeviceFuncs->pfnClearUnorderedAccessViewFloat = WddmDdiClearUnorderedAccessViewFloat;
	Info.pWDDM2_6DeviceFuncs->pfnAssignDebugBinary = WddmDdiAssignDebugBinary;
	Info.pWDDM2_6DeviceFuncs->pfnUpdateTileMappings = WddmDdiUpdateTileMappings;
	Info.pWDDM2_6DeviceFuncs->pfnCopyTileMappings = WddmDdiCopyTileMappings;
	Info.pWDDM2_6DeviceFuncs->pfnCopyTiles = WddmDdiCopyTiles;
	Info.pWDDM2_6DeviceFuncs->pfnUpdateTiles = WddmDdiUpdateTiles;
	Info.pWDDM2_6DeviceFuncs->pfnTiledResourceBarrier = WddmDdiTiledResourceBarrier;
	Info.pWDDM2_6DeviceFuncs->pfnResizeTilePool = WddmDdiResizeTilePool;
	Info.pWDDM2_6DeviceFuncs->pfnSetMarker = WddmDdiSetMarker;
	Info.pWDDM2_6DeviceFuncs->pfnSetMarkerMode = WddmDdiSetMarkerMode;
	Info.pWDDM2_6DeviceFuncs->pfnSetHardwareProtection = WddmDdiSetHardwareProtection;
	Info.pWDDM2_6DeviceFuncs->pfnSetHardwareProtectionState = WddmDdiSetHardwareProtectionState;
	Info.pWDDM2_6DeviceFuncs->pfnQueryScanoutCaps = WddmDdiQueryScanoutCaps;
	Info.pWDDM2_6DeviceFuncs->pfnPrepareScanoutTransformation = WddmDdiPrepareScanoutTransformation;

	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnPresent = WddmDdiPresent;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnGetGammaCaps = WddmDdiGetGammaCaps;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnSetDisplayMode = WddmDdiSetDisplayMode;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnSetResourcePriority = WddmDdiSetResourcePriority;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnQueryResourceResidency = WddmDdiQueryResourceResidency;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnRotateResourceIdentities = WddmDdiRotateResourceIdentities;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnBlt = WddmDdiBlt;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnResolveSharedResource = WddmDdiResolveSharedResource;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnBlt1 = WddmDdiBlt1;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnOfferResources1 = WddmDdiOfferResources1;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnReclaimResources = WddmDdiReclaimResources;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnGetMultiplaneOverlayCaps = WddmDdiGetMultiplaneOverlayCaps;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnGetMultiplaneOverlayGroupCaps = WddmDdiGetMultiplaneOverlayGroupCaps;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnReserved1 = WddmDdiReserved1;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnPresentMultiplaneOverlay = WddmDdiPresentMultiplaneOverlay;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnReserved2 = WddmDdiReserved2;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnPresent1 = WddmDdiPresent1;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnCheckPresentDurationSupport = WddmDdiCheckPresentDurationSupport;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnTrimResidencySet = WddmDdiTrimResidencySet;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnCheckMultiplaneOverlayColorSpaceSupport = WddmDdiCheckMultiplaneOverlayColorSpaceSupport;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnPresentMultiplaneOverlay1 = WddmDdiPresentMultiplaneOverlay1;
	Info.DXGIBaseDDI.pDXGIDDIBaseFunctions6_1->pfnReclaimResources1 = WddmDdiReclaimResources1;

	Info.DXGIBaseDDI.pDXGIBaseCallbacks->pfnPresentCb = WddmDdiPresentCb;
	Info.DXGIBaseDDI.pDXGIBaseCallbacks->pfnPresentMultiplaneOverlayCb = WddmDdiPresentMultiplaneOverlayCb;
	Info.DXGIBaseDDI.pDXGIBaseCallbacks->pfnPresentMultiplaneOverlay1Cb = WddmDdiPresentMultiplaneOverlay1Cb;
	Info.DXGIBaseDDI.pDXGIBaseCallbacks->pfnSubmitPresentBltToHwQueueCb = WddmDdiSubmitPresentBltToHwQueueCb;
	Info.DXGIBaseDDI.pDXGIBaseCallbacks->pfnSubmitPresentToHwQueueCb = WddmDdiSubmitPresentToHwQueueCb;

	//Info.pWDDM2_6UMCallbacks->pfnSetErrorCb = WddmDdiSetErrorCb; //pWDDM2_6UMCallbacks is provided as const

	*(Info.ppfnRetrieveSubObject) = WddmDdiRetrieveSubObject;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------------------------------------------------------------
#pragma region //Adapter Functions (D3D10_2DDI_ADAPTERFUNCS) [D3D10_2]

//PFND3D10DDI_CALCPRIVATEDEVICESIZE
SIZE_T APIENTRY D3dDdiCalcPrivateDeviceSize(D3D10DDI_HADAPTER, _In_ CONST D3D10DDIARG_CALCPRIVATEDEVICESIZE*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3D10DDI_CLOSEADAPTER
HRESULT APIENTRY D3dDdiCloseAdapter(D3D10DDI_HADAPTER)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//PFND3D10DDI_CREATEDEVICE
HRESULT APIENTRY D3dDdiCreateDevice(D3D10DDI_HADAPTER, _In_ D3D10DDIARG_CREATEDEVICE* pArgs)
{
	debug("[CALL]: %s (pArgs = %p)", __FUNCTION__, pArgs);
	if (pArgs) { WddmDdiCreatePatch(*pArgs); }
	return S_OK;
}

//PFND3D10_2DDI_GETCAPS
HRESULT APIENTRY D3dDdiGetCaps(D3D10DDI_HADAPTER, _In_ CONST D3D10_2DDIARG_GETCAPS* pArgs)
{
	debug("[CALL]: %s", __FUNCTION__);
    //https://docs.microsoft.com/en-us/windows-hardware/drivers/display/providing-capabilities-for-video-decoding //DXVA 2.0 Goes Here
	//PFND3DDDI_CREATEDECODEDEVICE and PFND3DDDI_DESTROYDECODEDEVICE
	if (pArgs)
	{
		/*
		switch (pArgs->Type)
		{
		    case (D3DDDICAPS_GETDECODEGUIDCOUNT): { return 5; } break;
			case (D3DDDICAPS_GETDECODEGUIDS):
			{
				GUID supported[5] = { DXVADDI_ModeMPEG2_MOCOMP, DXVADDI_ModeWMV8_MoComp, DXVADDI_ModeWMV9_IDCT, DXVADDI_ModeVC1_VLD, DXVADDI_ModeH264_VLD_FGT };
				return S_OK; //(HRESULT)&supported; ///!!! 64-bit HRESULT Required?
			}
			break;
			case (D3DDDICAPS_GETDECODERTFORMATCOUNT): { return 0; } break;
			case (D3DDDICAPS_GETDECODERTFORMATS):
			{
				GUID formats = *(GUID*)(pArgs->pInfo);
				return S_OK; //(HRESULT)&formats;
			}
			break;
			case (D3DDDICAPS_GETDECODECOMPRESSEDBUFFERINFOCOUNT): { return 0; } break;
			case (D3DDDICAPS_GETDECODECOMPRESSEDBUFFERINFO):
			{
				DXVADDI_DECODEINPUT inputType = *(DXVADDI_DECODEINPUT*)(pArgs->pInfo);
				DXVADDI_DECODEBUFFERINFO bufferTypes = *(DXVADDI_DECODEBUFFERINFO*)(pArgs->pData);
				return S_OK; //(HRESULT)&bufferTypes;
			}
			break;
			case (D3DDDICAPS_GETDECODECONFIGURATIONCOUNT): { return 0; } break;
			case (D3DDDICAPS_GETDECODECONFIGURATIONS):
			{
				DXVADDI_DECODEINPUT inputType = *(DXVADDI_DECODEINPUT*)(pArgs->pInfo);
				DXVADDI_CONFIGPICTUREDECODE decoderTypes = *(DXVADDI_CONFIGPICTUREDECODE*)(pArgs->pData);
				return S_OK; //(HRESULT)&decoderTypes;
			}
			break;
			default: break;
		}
		*///Invalid Values for pArgs->Type, Documentation is out of date
	}
	return S_OK;
}

//PFND3D10_2DDI_GETSUPPORTEDVERSIONS
HRESULT APIENTRY D3dDdiGetSupportedVersions(D3D10DDI_HADAPTER, _Inout_ UINT32* puEntries, _Out_writes_opt_(*puEntries) UINT64* pSupportedDDIInterfaceVersions)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
	puEntries;
	pSupportedDDIInterfaceVersions;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Adapter Callbacks (D3DDDI_ADAPTERCALLBACKS) [D3D10_2]

 //PFND3DDDI_QUERYADAPTERINFOCB
_Check_return_ HRESULT APIENTRY CALLBACK D3dDdiQueryAdapterInfoCb(_In_ HANDLE hAdapter, _Inout_ CONST D3DDDICB_QUERYADAPTERINFO*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
	hAdapter;
}

//PFND3DDDI_GETMULTISAMPLEMETHODLISTCB
_Check_return_ HRESULT APIENTRY CALLBACK D3dDdiGetMultisampleMethodListCb(_In_ HANDLE hAdapter, _Inout_ D3DDDICB_GETMULTISAMPLEMETHODLIST*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
	hAdapter;
}

//PFND3DDDI_QUERYADAPTERINFOCB2
_Check_return_ HRESULT APIENTRY CALLBACK D3dDdiQueryAdapterInfo2Cb(_In_ HANDLE hAdapter, _Inout_ CONST D3DDDICB_QUERYADAPTERINFO2*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
	hAdapter;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Device Function Declarations (D3DWDDM2_6DDI_DEVICEFUNCS) [WDDM2_6]

//PFND3D11_1DDI_RESOURCEUPDATESUBRESOURCEUP
VOID APIENTRY WddmDdiDefaultConstantBufferUpdateSubResourceUP(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, _In_opt_ CONST D3D10_DDI_BOX*, _In_ CONST VOID*, UINT, UINT, UINT CopyFlags)
{
	debug("[CALL]: %s", __FUNCTION__);
	CopyFlags;
}

//PFND3D11_1DDI_SETCONSTANTBUFFERS
VOID APIENTRY WddmDdiVsSetConstantBuffers(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot) UINT NumBuffers, _In_reads_(NumBuffers) CONST D3D10DDI_HRESOURCE*, _In_reads_opt_(NumBuffers) CONST UINT* pFirstConstant, _In_reads_opt_(NumBuffers) CONST UINT* pNumConstants)
{
	debug("[CALL]: %s", __FUNCTION__);
	pNumConstants;
	pFirstConstant;
	NumBuffers;
	StartSlot;
}

//PFND3D10DDI_SETSHADERRESOURCES
VOID APIENTRY WddmDdiPsSetShaderResources(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot) UINT NumViews, _In_reads_(NumViews) CONST D3D10DDI_HSHADERRESOURCEVIEW*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumViews;
	StartSlot;
}

//PFND3D10DDI_SETSHADER
VOID APIENTRY WddmDdiPsSetShader(D3D10DDI_HDEVICE, D3D10DDI_HSHADER)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_SETSAMPLERS
VOID APIENTRY WddmDdiPsSetSamplers(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot) UINT NumSamplers, _In_reads_(NumSamplers) CONST D3D10DDI_HSAMPLER*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumSamplers;
	StartSlot;
}

//PFND3D10DDI_SETSHADER
VOID APIENTRY WddmDdiVsSetShader(D3D10DDI_HDEVICE, D3D10DDI_HSHADER)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DRAWINDEXED
VOID APIENTRY WddmDdiDrawIndexed(D3D10DDI_HDEVICE, UINT, UINT, INT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DRAW
VOID APIENTRY WddmDdiDraw(D3D10DDI_HDEVICE, UINT, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_RESOURCEMAP
VOID APIENTRY WddmDdiDynamicIABufferMapNoOverwrite(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, _Out_ D3D10DDI_MAPPED_SUBRESOURCE* pOut)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pOut = D3D10DDI_MAPPED_SUBRESOURCE();
}

//PFND3D10DDI_RESOURCEUNMAP
VOID APIENTRY WddmDdiDynamicIABufferUnmap(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_RESOURCEMAP
VOID APIENTRY WddmDdiDynamicConstantBufferMapDiscard(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, _Out_ D3D10DDI_MAPPED_SUBRESOURCE* pOut)
{
	debug("[CALL]: %s", __FUNCTION__);
	pOut = NULL;
}

//PFND3D10DDI_RESOURCEMAP
VOID APIENTRY WddmDdiDynamicIABufferMapDiscard(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, _Out_ D3D10DDI_MAPPED_SUBRESOURCE* pOut)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pOut = D3D10DDI_MAPPED_SUBRESOURCE();
}

//PFND3D10DDI_RESOURCEUNMAP
VOID APIENTRY WddmDdiDynamicConstantBufferUnmap(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11_1DDI_SETCONSTANTBUFFERS
VOID APIENTRY WddmDdiPsSetConstantBuffers(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot) UINT NumBuffers, _In_reads_(NumBuffers) CONST D3D10DDI_HRESOURCE*, _In_reads_opt_(NumBuffers) CONST UINT* pFirstConstant, _In_reads_opt_(NumBuffers) CONST UINT* pNumConstants)
{
	debug("[CALL]: %s", __FUNCTION__);
	pNumConstants;
	pFirstConstant;
	NumBuffers;
	StartSlot;
}

//PFND3D10DDI_SETINPUTLAYOUT
VOID APIENTRY WddmDdiIaSetInputLayout(D3D10DDI_HDEVICE, D3D10DDI_HELEMENTLAYOUT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_IA_SETVERTEXBUFFERS
VOID APIENTRY WddmDdiIaSetVertexBuffers(D3D10DDI_HDEVICE, _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot) UINT NumBuffers, _In_reads_(NumBuffers) CONST D3D10DDI_HRESOURCE*, _In_reads_(NumBuffers) CONST UINT*, _In_reads_(NumBuffers) CONST UINT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumBuffers;
	StartSlot;
}

//PFND3D10DDI_IA_SETINDEXBUFFER
VOID APIENTRY WddmDdiIaSetIndexBuffer(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, DXGI_FORMAT, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DRAWINDEXEDINSTANCED
VOID APIENTRY WddmDdiDrawIndexedInstanced(D3D10DDI_HDEVICE, UINT, UINT, UINT, INT, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DRAWINSTANCED
VOID APIENTRY WddmDdiDrawInstanced(D3D10DDI_HDEVICE, UINT, UINT, UINT, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_RESOURCEMAP
VOID APIENTRY WddmDdiDynamicResourceMapDiscard(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, _Out_ D3D10DDI_MAPPED_SUBRESOURCE* pOut)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pOut = D3D10DDI_MAPPED_SUBRESOURCE();
}

//PFND3D10DDI_RESOURCEUNMAP
VOID APIENTRY WddmDdiDynamicResourceUnmap(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11_1DDI_SETCONSTANTBUFFERS
VOID APIENTRY WddmDdiGsSetConstantBuffers(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot) UINT NumBuffers, _In_reads_(NumBuffers) CONST D3D10DDI_HRESOURCE*, _In_reads_opt_(NumBuffers) CONST UINT* pFirstConstant, _In_reads_opt_(NumBuffers) CONST UINT* pNumConstants)
{
	debug("[CALL]: %s", __FUNCTION__);
	pNumConstants;
	pFirstConstant;
	NumBuffers;
	StartSlot;
}

//PFND3D10DDI_SETSHADER
VOID APIENTRY WddmDdiGsSetShader(D3D10DDI_HDEVICE, D3D10DDI_HSHADER)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_IA_SETTOPOLOGY
VOID APIENTRY WddmDdiIaSetTopology(D3D10DDI_HDEVICE, D3D10_DDI_PRIMITIVE_TOPOLOGY)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_RESOURCEMAP
VOID APIENTRY WddmDdiStagingResourceMap(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, _Out_ D3D10DDI_MAPPED_SUBRESOURCE* pOut)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pOut = D3D10DDI_MAPPED_SUBRESOURCE();
}

//PFND3D10DDI_RESOURCEUNMAP
VOID APIENTRY WddmDdiStagingResourceUnmap(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_SETSHADERRESOURCES
VOID APIENTRY WddmDdiVsSetShaderResources(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot) UINT NumViews, _In_reads_(NumViews) CONST D3D10DDI_HSHADERRESOURCEVIEW*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumViews;
	StartSlot;
}

//PFND3D10DDI_SETSAMPLERS
VOID APIENTRY WddmDdiVsSetSamplers(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot) UINT NumSamplers, _In_reads_(NumSamplers) CONST D3D10DDI_HSAMPLER*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumSamplers;
	StartSlot;
}

//PFND3D10DDI_SETSHADERRESOURCES
VOID APIENTRY WddmDdiGsSetShaderResources(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot) UINT NumViews, _In_reads_(NumViews) CONST D3D10DDI_HSHADERRESOURCEVIEW*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumViews;
	StartSlot;
}

//PFND3D10DDI_SETSAMPLERS
VOID APIENTRY WddmDdiGsSetSamplers(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot) UINT NumSamplers, _In_reads_(NumSamplers) CONST D3D10DDI_HSAMPLER*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumSamplers;
	StartSlot;
}

//PFND3D11DDI_SETRENDERTARGETS
VOID APIENTRY WddmDdiSetRenderTargets(D3D10DDI_HDEVICE, _In_reads_(NumRTVs) CONST D3D10DDI_HRENDERTARGETVIEW*, _In_range_(0, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT) UINT NumRTVs, _In_range_(0, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT) UINT ClearSlots, D3D10DDI_HDEPTHSTENCILVIEW, _In_reads_(NumUAVs) CONST D3D11DDI_HUNORDEREDACCESSVIEW*, _In_reads_(NumUAVs) CONST UINT*, _In_range_(0, D3D11_1_UAV_SLOT_COUNT - 1) UINT UAVStartSlot, _In_range_(0, D3D11_1_UAV_SLOT_COUNT - UAVStartSlot) UINT NumUAVs, _In_range_(0, D3D11_1_UAV_SLOT_COUNT - 1) UINT UAVRangeStart, _In_range_(0, D3D11_1_UAV_SLOT_COUNT - UAVRangeStart) UINT UAVRangeSize)
{
	debug("[CALL]: %s", __FUNCTION__);
	UAVRangeSize;
	UAVRangeStart;
	NumUAVs;
	UAVStartSlot;
	ClearSlots;
	NumRTVs;
}

//PFND3D10DDI_SHADERRESOURCEVIEWREADAFTERWRITEHAZARD
VOID APIENTRY WddmDdiShaderResourceViewReadAfterWriteHazard(D3D10DDI_HDEVICE, D3D10DDI_HSHADERRESOURCEVIEW, D3D10DDI_HRESOURCE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_RESOURCEREADAFTERWRITEHAZARD
VOID APIENTRY WddmDdiResourceReadAfterWriteHazard(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_SETBLENDSTATE
VOID APIENTRY WddmDdiSetBlendState(D3D10DDI_HDEVICE, D3D10DDI_HBLENDSTATE, CONST FLOAT[4], UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_SETDEPTHSTENCILSTATE
VOID APIENTRY WddmDdiSetDepthStencilState(D3D10DDI_HDEVICE, D3D10DDI_HDEPTHSTENCILSTATE, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_SETRASTERIZERSTATE
VOID APIENTRY WddmDdiSetRasterizerState(D3D10DDI_HDEVICE, D3D10DDI_HRASTERIZERSTATE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_QUERYEND
VOID APIENTRY WddmDdiQueryEnd(D3D10DDI_HDEVICE, D3D10DDI_HQUERY)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_QUERYBEGIN
VOID APIENTRY WddmDdiQueryBegin(D3D10DDI_HDEVICE, D3D10DDI_HQUERY)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11_1DDI_RESOURCECOPYREGION
VOID APIENTRY WddmDdiResourceCopyRegion(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, UINT, UINT, UINT, D3D10DDI_HRESOURCE, UINT, _In_opt_ CONST D3D10_DDI_BOX*, UINT CopyFlags)
{
	debug("[CALL]: %s", __FUNCTION__);
	CopyFlags;
}

//PFND3D11_1DDI_RESOURCEUPDATESUBRESOURCEUP
VOID APIENTRY WddmDdiResourceUpdateSubResourceUP(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, _In_opt_ CONST D3D10_DDI_BOX*, _In_ CONST VOID*, UINT, UINT, UINT CopyFlags)
{
	debug("[CALL]: %s", __FUNCTION__);
	CopyFlags;
}

//PFND3D10DDI_SO_SETTARGETS
VOID APIENTRY WddmDdiSoSetTargets(D3D10DDI_HDEVICE, _In_range_(0, D3D11_SO_BUFFER_SLOT_COUNT) UINT NumBuffers, _In_range_(0, D3D11_SO_BUFFER_SLOT_COUNT) UINT ClearTargets, _In_reads_(NumBuffers) CONST D3D10DDI_HRESOURCE*, _In_reads_(NumBuffers) CONST UINT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	ClearTargets;
	NumBuffers;
}

//PFND3D10DDI_DRAWAUTO
VOID APIENTRY WddmDdiDrawAuto(D3D10DDI_HDEVICE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_SETVIEWPORTS
VOID APIENTRY WddmDdiSetViewports(D3D10DDI_HDEVICE, _In_range_(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE) UINT NumViewports, _In_range_(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE - NumViewports) UINT ClearViewports, _In_reads_(NumViewports) CONST D3D10_DDI_VIEWPORT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	ClearViewports;
	NumViewports;
}

//PFND3D10DDI_SETSCISSORRECTS
VOID APIENTRY WddmDdiSetScissorRects(D3D10DDI_HDEVICE, _In_range_(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE) UINT NumRects, _In_range_(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE - NumRects) UINT ClearRects, _In_reads_(NumRects) CONST D3D10_DDI_RECT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	ClearRects;
	NumRects;
}

//PFND3D10DDI_CLEARRENDERTARGETVIEW
VOID APIENTRY WddmDdiClearRenderTargetView(D3D10DDI_HDEVICE, D3D10DDI_HRENDERTARGETVIEW, FLOAT[4])
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_CLEARDEPTHSTENCILVIEW
VOID APIENTRY WddmDdiClearDepthStencilView(D3D10DDI_HDEVICE, D3D10DDI_HDEPTHSTENCILVIEW, UINT, FLOAT, UINT8)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_SETPREDICATION
VOID APIENTRY WddmDdiSetPredication(D3D10DDI_HDEVICE, D3D10DDI_HQUERY, BOOL)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_QUERYGETDATA
VOID APIENTRY WddmDdiQueryGetData(D3D10DDI_HDEVICE, D3D10DDI_HQUERY, _Out_writes_bytes_all_opt_(DataSize) VOID*, UINT DataSize, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
	DataSize;
}

//PFND3DWDDM2_0DDI_FLUSH
BOOL APIENTRY WddmDdiFlush(D3D10DDI_HDEVICE, UINT contextType, UINT FlushFlags)
{
	debug("[CALL]: %s", __FUNCTION__);
	return true;
	FlushFlags;
	contextType;
}

//PFND3D10DDI_GENMIPS
VOID APIENTRY WddmDdiGenMips(D3D10DDI_HDEVICE, D3D10DDI_HSHADERRESOURCEVIEW)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_RESOURCECOPY
VOID APIENTRY WddmDdiResourceCopy(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, D3D10DDI_HRESOURCE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_RESOURCERESOLVESUBRESOURCE
VOID APIENTRY WddmDdiResourceResolveSubResource(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10DDI_HRESOURCE, UINT, DXGI_FORMAT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_RESOURCEMAP
VOID APIENTRY WddmDdiResourceMap(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, _Out_ D3D10DDI_MAPPED_SUBRESOURCE* pOut)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pOut = D3D10DDI_MAPPED_SUBRESOURCE();
}

//PFND3D10DDI_RESOURCEUNMAP
VOID APIENTRY WddmDdiResourceUnmap(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_RESOURCEISSTAGINGBUSY
BOOL APIENTRY WddmDdiResourceIsStagingBusy(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE)
{
	debug("[CALL]: %s", __FUNCTION__);
	return false;
}

//PFND3DWDDM2_6DDI_RELOCATEDEVICEFUNCS
VOID APIENTRY WddmDdiRelocateDeviceFuncs(D3D10DDI_HDEVICE, _In_ struct D3DWDDM2_6DDI_DEVICEFUNCS*)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_CALCPRIVATERESOURCESIZE
SIZE_T APIENTRY WddmDdiCalcPrivateResourceSize(D3D10DDI_HDEVICE, _In_ CONST D3D11DDIARG_CREATERESOURCE*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3D10DDI_CALCPRIVATEOPENEDRESOURCESIZE
SIZE_T APIENTRY WddmDdiCalcPrivateOpenedResourceSize(D3D10DDI_HDEVICE, _In_ CONST D3D10DDIARG_OPENRESOURCE*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3D11DDI_CREATERESOURCE
VOID APIENTRY WddmDdiCreateResource(D3D10DDI_HDEVICE, _In_ CONST D3D11DDIARG_CREATERESOURCE*, D3D10DDI_HRESOURCE, D3D10DDI_HRTRESOURCE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_OPENRESOURCE
VOID APIENTRY WddmDdiOpenResource(D3D10DDI_HDEVICE, _In_ CONST D3D10DDIARG_OPENRESOURCE*, D3D10DDI_HRESOURCE, D3D10DDI_HRTRESOURCE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DESTROYRESOURCE
VOID APIENTRY WddmDdiDestroyResource(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3DWDDM2_0DDI_CALCPRIVATESHADERRESOURCEVIEWSIZE
SIZE_T APIENTRY WddmDdiCalcPrivateShaderResourceViewSize(D3D10DDI_HDEVICE, _In_ CONST D3DWDDM2_0DDIARG_CREATESHADERRESOURCEVIEW*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3DWDDM2_0DDI_CREATESHADERRESOURCEVIEW
VOID APIENTRY WddmDdiCreateShaderResourceView(D3D10DDI_HDEVICE, _In_ CONST D3DWDDM2_0DDIARG_CREATESHADERRESOURCEVIEW*, D3D10DDI_HSHADERRESOURCEVIEW, D3D10DDI_HRTSHADERRESOURCEVIEW)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DESTROYSHADERRESOURCEVIEW
VOID APIENTRY WddmDdiDestroyShaderResourceView(D3D10DDI_HDEVICE, D3D10DDI_HSHADERRESOURCEVIEW)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3DWDDM2_0DDI_CALCPRIVATERENDERTARGETVIEWSIZE
SIZE_T APIENTRY WddmDdiCalcPrivateRenderTargetViewSize(D3D10DDI_HDEVICE, _In_ CONST D3DWDDM2_0DDIARG_CREATERENDERTARGETVIEW*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3DWDDM2_0DDI_CREATERENDERTARGETVIEW
VOID APIENTRY WddmDdiCreateRenderTargetView(D3D10DDI_HDEVICE, _In_ CONST D3DWDDM2_0DDIARG_CREATERENDERTARGETVIEW*, D3D10DDI_HRENDERTARGETVIEW, D3D10DDI_HRTRENDERTARGETVIEW)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DESTROYRENDERTARGETVIEW
VOID APIENTRY WddmDdiDestroyRenderTargetView(D3D10DDI_HDEVICE, D3D10DDI_HRENDERTARGETVIEW)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_CALCPRIVATEDEPTHSTENCILVIEWSIZE
SIZE_T APIENTRY WddmDdiCalcPrivateDepthStencilViewSize(D3D10DDI_HDEVICE, _In_ CONST D3D11DDIARG_CREATEDEPTHSTENCILVIEW*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3D11DDI_CREATEDEPTHSTENCILVIEW
VOID APIENTRY WddmDdiCreateDepthStencilView(D3D10DDI_HDEVICE, _In_ CONST D3D11DDIARG_CREATEDEPTHSTENCILVIEW*, D3D10DDI_HDEPTHSTENCILVIEW, D3D10DDI_HRTDEPTHSTENCILVIEW)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DESTROYDEPTHSTENCILVIEW
VOID APIENTRY WddmDdiDestroyDepthStencilView(D3D10DDI_HDEVICE, D3D10DDI_HDEPTHSTENCILVIEW)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_CALCPRIVATEELEMENTLAYOUTSIZE
SIZE_T APIENTRY WddmDdiCalcPrivateElementLayoutSize(D3D10DDI_HDEVICE, _In_ CONST D3D10DDIARG_CREATEELEMENTLAYOUT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3D10DDI_CREATEELEMENTLAYOUT
VOID APIENTRY WddmDdiCreateElementLayout(D3D10DDI_HDEVICE, _In_ CONST D3D10DDIARG_CREATEELEMENTLAYOUT*, D3D10DDI_HELEMENTLAYOUT, D3D10DDI_HRTELEMENTLAYOUT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DESTROYELEMENTLAYOUT
VOID APIENTRY WddmDdiDestroyElementLayout(D3D10DDI_HDEVICE, D3D10DDI_HELEMENTLAYOUT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11_1DDI_CALCPRIVATEBLENDSTATESIZE
SIZE_T APIENTRY WddmDdiCalcPrivateBlendStateSize(D3D10DDI_HDEVICE, _In_ CONST D3D11_1_DDI_BLEND_DESC*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3D11_1DDI_CREATEBLENDSTATE
VOID APIENTRY WddmDdiCreateBlendState(D3D10DDI_HDEVICE, _In_ CONST D3D11_1_DDI_BLEND_DESC*, D3D10DDI_HBLENDSTATE, D3D10DDI_HRTBLENDSTATE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DESTROYBLENDSTATE
VOID APIENTRY WddmDdiDestroyBlendState(D3D10DDI_HDEVICE, D3D10DDI_HBLENDSTATE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_CALCPRIVATEDEPTHSTENCILSTATESIZE
SIZE_T APIENTRY WddmDdiCalcPrivateDepthStencilStateSize(D3D10DDI_HDEVICE, _In_ CONST D3D10_DDI_DEPTH_STENCIL_DESC*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3D10DDI_CREATEDEPTHSTENCILSTATE
VOID APIENTRY WddmDdiCreateDepthStencilState(D3D10DDI_HDEVICE, _In_ CONST D3D10_DDI_DEPTH_STENCIL_DESC*, D3D10DDI_HDEPTHSTENCILSTATE, D3D10DDI_HRTDEPTHSTENCILSTATE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DESTROYDEPTHSTENCILSTATE
VOID APIENTRY WddmDdiDestroyDepthStencilState(D3D10DDI_HDEVICE, D3D10DDI_HDEPTHSTENCILSTATE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3DWDDM2_0DDI_CALCPRIVATERASTERIZERSTATESIZE
SIZE_T APIENTRY WddmDdiCalcPrivateRasterizerStateSize(D3D10DDI_HDEVICE, _In_ CONST D3DWDDM2_0DDI_RASTERIZER_DESC*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3DWDDM2_0DDI_CREATERASTERIZERSTATE
VOID APIENTRY WddmDdiCreateRasterizerState(D3D10DDI_HDEVICE, _In_ CONST D3DWDDM2_0DDI_RASTERIZER_DESC*, D3D10DDI_HRASTERIZERSTATE, D3D10DDI_HRTRASTERIZERSTATE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DESTROYRASTERIZERSTATE
VOID APIENTRY WddmDdiDestroyRasterizerState(D3D10DDI_HDEVICE, D3D10DDI_HRASTERIZERSTATE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11_1DDI_CALCPRIVATESHADERSIZE
SIZE_T APIENTRY WddmDdiCalcPrivateShaderSize(D3D10DDI_HDEVICE, _In_reads_(pShaderCode[1]) CONST UINT* pShaderCode, _In_ CONST D3D11_1DDIARG_STAGE_IO_SIGNATURES*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
	pShaderCode;
}

//PFND3D11_1DDI_CREATEVERTEXSHADER
VOID APIENTRY WddmDdiCreateVertexShader(D3D10DDI_HDEVICE, _In_reads_(pShaderCode[1]) CONST UINT* pShaderCode, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER, _In_ CONST D3D11_1DDIARG_STAGE_IO_SIGNATURES*)
{
	debug("[CALL]: %s", __FUNCTION__);
	pShaderCode;
}

//PFND3D11_1DDI_CREATEGEOMETRYSHADER
VOID APIENTRY WddmDdiCreateGeometryShader(D3D10DDI_HDEVICE, _In_reads_(pShaderCode[1]) CONST UINT* pShaderCode, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER, _In_ CONST D3D11_1DDIARG_STAGE_IO_SIGNATURES*)
{
	debug("[CALL]: %s", __FUNCTION__);
	pShaderCode;
}

//PFND3D11_1DDI_CREATEPIXELSHADER
VOID APIENTRY WddmDdiCreatePixelShader(D3D10DDI_HDEVICE, _In_reads_(pShaderCode[1]) CONST UINT* pShaderCode, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER, _In_ CONST D3D11_1DDIARG_STAGE_IO_SIGNATURES*)
{
	debug("[CALL]: %s", __FUNCTION__);
	pShaderCode;
}

//PFND3D11_1DDI_CALCPRIVATEGEOMETRYSHADERWITHSTREAMOUTPUT
SIZE_T APIENTRY WddmDdiCalcPrivateGeometryShaderWithStreamOutput(D3D10DDI_HDEVICE, _In_ CONST D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT*, _In_ CONST D3D11_1DDIARG_STAGE_IO_SIGNATURES*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3D11_1DDI_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT
VOID APIENTRY WddmDdiCreateGeometryShaderWithStreamOutput(D3D10DDI_HDEVICE, _In_ CONST D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT*, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER, _In_ CONST D3D11_1DDIARG_STAGE_IO_SIGNATURES*)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DESTROYSHADER
VOID APIENTRY WddmDdiDestroyShader(D3D10DDI_HDEVICE, D3D10DDI_HSHADER)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_CALCPRIVATESAMPLERSIZE
SIZE_T APIENTRY WddmDdiCalcPrivateSamplerSize(D3D10DDI_HDEVICE, _In_ CONST D3D10_DDI_SAMPLER_DESC*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3D10DDI_CREATESAMPLER
VOID APIENTRY WddmDdiCreateSampler(D3D10DDI_HDEVICE, _In_ CONST D3D10_DDI_SAMPLER_DESC*, D3D10DDI_HSAMPLER, D3D10DDI_HRTSAMPLER)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DESTROYSAMPLER
VOID APIENTRY WddmDdiDestroySampler(D3D10DDI_HDEVICE, D3D10DDI_HSAMPLER)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3DWDDM2_0DDI_CALCPRIVATEQUERYSIZE
SIZE_T APIENTRY WddmDdiCalcPrivateQuerySize(D3D10DDI_HDEVICE, _In_ CONST D3DWDDM2_0DDIARG_CREATEQUERY*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3DWDDM2_0DDI_CREATEQUERY
VOID APIENTRY WddmDdiCreateQuery(D3D10DDI_HDEVICE, _In_ CONST D3DWDDM2_0DDIARG_CREATEQUERY*, D3D10DDI_HQUERY, D3D10DDI_HRTQUERY)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_DESTROYQUERY
VOID APIENTRY WddmDdiDestroyQuery(D3D10DDI_HDEVICE, D3D10DDI_HQUERY)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_CHECKFORMATSUPPORT
VOID APIENTRY WddmDdiCheckFormatSupport(D3D10DDI_HDEVICE, DXGI_FORMAT, _Out_ UINT* pOut)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pOut = 0;
}

//PFND3DWDDM1_3DDI_CHECKMULTISAMPLEQUALITYLEVELS
VOID APIENTRY WddmDdiCheckMultisampleQualityLevels(D3D10DDI_HDEVICE hDevice, DXGI_FORMAT Format, UINT SampleCount, UINT Flags, _Out_ UINT* pNumQualityLevels)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pNumQualityLevels = 0;
	Flags;
	SampleCount;
	Format;
	hDevice;
}

//PFND3D10DDI_CHECKCOUNTERINFO
VOID APIENTRY WddmDdiCheckCounterInfo(D3D10DDI_HDEVICE, _Out_ D3D10DDI_COUNTER_INFO* pOut)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pOut = D3D10DDI_COUNTER_INFO();
}

//PFND3D10DDI_CHECKCOUNTER
VOID APIENTRY WddmDdiCheckCounter(D3D10DDI_HDEVICE, D3D10DDI_QUERY, _Out_ D3D10DDI_COUNTER_TYPE* pOut1, _Out_ UINT* pOut2, _Out_writes_to_opt_(*pNameLength, *pNameLength) LPSTR, _Inout_opt_ UINT* pNameLength, _Out_writes_to_opt_(*pUnitsLength, *pUnitsLength) LPSTR, _Inout_opt_ UINT* pUnitsLength, _Out_writes_to_opt_(*pDescriptionLength, *pDescriptionLength) LPSTR, _Inout_opt_ UINT* pDescriptionLength)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pOut1 = D3D10DDI_COUNTER_TYPE();
	*pOut2 = 0;
	pNameLength;
	pUnitsLength;
	pDescriptionLength;
}

//PFND3D10DDI_DESTROYDEVICE
VOID APIENTRY WddmDdiDestroyDevice(D3D10DDI_HDEVICE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_SETTEXTFILTERSIZE
VOID APIENTRY WddmDdiSetTextFilterSize(D3D10DDI_HDEVICE, UINT, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_RESOURCECOPY
VOID APIENTRY WddmDdiResourceConvert(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, D3D10DDI_HRESOURCE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11_1DDI_RESOURCECOPYREGION
VOID APIENTRY WddmDdiResourceConvertRegion(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, UINT, UINT, UINT, D3D10DDI_HRESOURCE, UINT, _In_opt_ CONST D3D10_DDI_BOX*, UINT CopyFlags)
{
	debug("[CALL]: %s", __FUNCTION__);
	CopyFlags;
}

//PFND3D10DDI_RESETPRIMITIVEID
VOID APIENTRY WddmDdiResetPrimitiveID(D3D10DDI_HDEVICE, BOOL)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_SETVERTEXPIPELINEOUTPUT
VOID APIENTRY WddmDdiSetVertexPipelineOutput(D3D10DDI_HDEVICE, _In_ CONST D3D10DDIARG_VERTEXPIPELINEOUTPUT*)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_DRAWINDEXEDINSTANCEDINDIRECT
VOID APIENTRY WddmDdiDrawIndexedInstancedIndirect(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_DRAWINSTANCEDINDIRECT
VOID APIENTRY WddmDdiDrawInstancedIndirect(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_COMMANDLISTEXECUTE
VOID APIENTRY WddmDdiCommandListExecute(D3D10DDI_HDEVICE, D3D11DDI_HCOMMANDLIST)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_SETSHADERRESOURCES
VOID APIENTRY WddmDdiHsSetShaderResources(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot) UINT NumViews, _In_reads_(NumViews) CONST D3D10DDI_HSHADERRESOURCEVIEW*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumViews;
	StartSlot;
}

//PFND3D10DDI_SETSHADER
VOID APIENTRY WddmDdiHsSetShader(D3D10DDI_HDEVICE, D3D10DDI_HSHADER)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_SETSAMPLERS
VOID APIENTRY WddmDdiHsSetSamplers(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot) UINT NumSamplers, _In_reads_(NumSamplers) CONST D3D10DDI_HSAMPLER*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumSamplers;
	StartSlot;
}

//PFND3D11_1DDI_SETCONSTANTBUFFERS
VOID APIENTRY WddmDdiHsSetConstantBuffers(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot) UINT NumBuffers, _In_reads_(NumBuffers) CONST D3D10DDI_HRESOURCE*, _In_reads_opt_(NumBuffers) CONST UINT* pFirstConstant, _In_reads_opt_(NumBuffers) CONST UINT* pNumConstants)
{
	debug("[CALL]: %s", __FUNCTION__);
	pNumConstants;
	pFirstConstant;
	NumBuffers;
	StartSlot;
}

//PFND3D10DDI_SETSHADERRESOURCES
VOID APIENTRY WddmDdiDsSetShaderResources(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot) UINT NumViews, _In_reads_(NumViews) CONST D3D10DDI_HSHADERRESOURCEVIEW*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumViews;
	StartSlot;
}

//PFND3D10DDI_SETSHADER
VOID APIENTRY WddmDdiDsSetShader(D3D10DDI_HDEVICE, D3D10DDI_HSHADER)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_SETSAMPLERS
VOID APIENTRY WddmDdiDsSetSamplers(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot) UINT NumSamplers, _In_reads_(NumSamplers) CONST D3D10DDI_HSAMPLER*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumSamplers;
	StartSlot;
}

//PFND3D11_1DDI_SETCONSTANTBUFFERS
VOID APIENTRY WddmDdiDsSetConstantBuffers(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot) UINT NumBuffers, _In_reads_(NumBuffers) CONST D3D10DDI_HRESOURCE*, _In_reads_opt_(NumBuffers) CONST UINT* pFirstConstant, _In_reads_opt_(NumBuffers) CONST UINT* pNumConstants)
{
	debug("[CALL]: %s", __FUNCTION__);
	pNumConstants;
	pFirstConstant;
	NumBuffers;
	StartSlot;
}

//PFND3D11_1DDI_CREATEHULLSHADER
VOID APIENTRY WddmDdiCreateHullShader(D3D10DDI_HDEVICE, _In_reads_(pShaderCode[1]) CONST UINT* pShaderCode, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER, _In_ CONST D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES*)
{
	debug("[CALL]: %s", __FUNCTION__);
	pShaderCode;
}

//PFND3D11_1DDI_CREATEDOMAINSHADER
VOID APIENTRY WddmDdiCreateDomainShader(D3D10DDI_HDEVICE, _In_reads_(pShaderCode[1]) CONST UINT* pShaderCode, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER, _In_ CONST D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES*)
{
	debug("[CALL]: %s", __FUNCTION__);
	pShaderCode;
}

//PFND3D11DDI_CHECKDEFERREDCONTEXTHANDLESIZES
VOID APIENTRY WddmDdiCheckDeferredContextHandleSizes(D3D10DDI_HDEVICE, _Inout_ UINT* pHSizes, _Out_writes_to_opt_(*pHSizes, *pHSizes) D3D11DDI_HANDLESIZE*)
{
	debug("[CALL]: %s", __FUNCTION__);
	pHSizes;
}

//PFND3D11DDI_CALCDEFERREDCONTEXTHANDLESIZE
SIZE_T APIENTRY WddmDdiCalcDeferredContextHandleSize(D3D10DDI_HDEVICE, D3D11DDI_HANDLETYPE, _In_ VOID*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3D11DDI_CALCPRIVATEDEFERREDCONTEXTSIZE
SIZE_T APIENTRY WddmDdiCalcPrivateDeferredContextSize(D3D10DDI_HDEVICE, _In_ CONST D3D11DDIARG_CALCPRIVATEDEFERREDCONTEXTSIZE*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3D11DDI_CREATEDEFERREDCONTEXT
VOID APIENTRY WddmDdiCreateDeferredContext(D3D10DDI_HDEVICE, _In_ CONST D3D11DDIARG_CREATEDEFERREDCONTEXT*)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_ABANDONCOMMANDLIST
VOID APIENTRY WddmDdiAbandonCommandList(D3D10DDI_HDEVICE)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_CALCPRIVATECOMMANDLISTSIZE
SIZE_T APIENTRY WddmDdiCalcPrivateCommandListSize(D3D10DDI_HDEVICE, _In_ CONST D3D11DDIARG_CREATECOMMANDLIST*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3D11DDI_CREATECOMMANDLIST
VOID APIENTRY WddmDdiCreateCommandList(D3D10DDI_HDEVICE, _In_ CONST D3D11DDIARG_CREATECOMMANDLIST*, D3D11DDI_HCOMMANDLIST, D3D11DDI_HRTCOMMANDLIST)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_DESTROYCOMMANDLIST
VOID APIENTRY WddmDdiDestroyCommandList(D3D10DDI_HDEVICE, D3D11DDI_HCOMMANDLIST)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11_1DDI_CALCPRIVATETESSELLATIONSHADERSIZE
SIZE_T APIENTRY WddmDdiCalcPrivateTessellationShaderSize(D3D10DDI_HDEVICE, _In_reads_(pShaderCode[1]) CONST UINT* pShaderCode, _In_ CONST D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
	pShaderCode;
}

//PFND3D11DDI_SETSHADER_WITH_IFACES
VOID APIENTRY WddmDdiPsSetShaderWithIfaces(D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT NumClassInstances, _In_reads_(NumClassInstances) CONST UINT*, _In_reads_(NumClassInstances) CONST D3D11DDIARG_POINTERDATA*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumClassInstances;
}

//PFND3D11DDI_SETSHADER_WITH_IFACES
VOID APIENTRY WddmDdiVsSetShaderWithIfaces(D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT NumClassInstances, _In_reads_(NumClassInstances) CONST UINT*, _In_reads_(NumClassInstances) CONST D3D11DDIARG_POINTERDATA*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumClassInstances;
}

//PFND3D11DDI_SETSHADER_WITH_IFACES
VOID APIENTRY WddmDdiGsSetShaderWithIfaces(D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT NumClassInstances, _In_reads_(NumClassInstances) CONST UINT*, _In_reads_(NumClassInstances) CONST D3D11DDIARG_POINTERDATA*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumClassInstances;
}

//PFND3D11DDI_SETSHADER_WITH_IFACES
VOID APIENTRY WddmDdiHsSetShaderWithIfaces(D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT NumClassInstances, _In_reads_(NumClassInstances) CONST UINT*, _In_reads_(NumClassInstances) CONST D3D11DDIARG_POINTERDATA*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumClassInstances;
}

//PFND3D11DDI_SETSHADER_WITH_IFACES
VOID APIENTRY WddmDdiDsSetShaderWithIfaces(D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT NumClassInstances, _In_reads_(NumClassInstances) CONST UINT*, _In_reads_(NumClassInstances) CONST D3D11DDIARG_POINTERDATA*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumClassInstances;
}

//PFND3D11DDI_SETSHADER_WITH_IFACES
VOID APIENTRY WddmDdiCsSetShaderWithIfaces(D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT NumClassInstances, _In_reads_(NumClassInstances) CONST UINT*, _In_reads_(NumClassInstances) CONST D3D11DDIARG_POINTERDATA*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumClassInstances;
}

//PFND3D11DDI_CREATECOMPUTESHADER
VOID APIENTRY WddmDdiCreateComputeShader(D3D10DDI_HDEVICE, _In_reads_(pShaderCode[1]) CONST UINT* pShaderCode, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER)
{
	debug("[CALL]: %s", __FUNCTION__);
	pShaderCode;
}

//PFND3D10DDI_SETSHADER
VOID APIENTRY WddmDdiCsSetShader(D3D10DDI_HDEVICE, D3D10DDI_HSHADER)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D10DDI_SETSHADERRESOURCES
VOID APIENTRY WddmDdiCsSetShaderResources(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot) UINT NumViews, _In_reads_(NumViews) CONST D3D10DDI_HSHADERRESOURCEVIEW*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumViews;
	StartSlot;
}

//PFND3D10DDI_SETSAMPLERS
VOID APIENTRY WddmDdiCsSetSamplers(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot) UINT NumSamplers, _In_reads_(NumSamplers) CONST D3D10DDI_HSAMPLER*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumSamplers;
	StartSlot;
}

//PFND3D11_1DDI_SETCONSTANTBUFFERS
VOID APIENTRY WddmDdiCsSetConstantBuffers(D3D10DDI_HDEVICE, _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot) UINT NumBuffers, _In_reads_(NumBuffers) CONST D3D10DDI_HRESOURCE*, _In_reads_opt_(NumBuffers) CONST UINT* pFirstConstant, _In_reads_opt_(NumBuffers) CONST UINT* pNumConstants)
{
	debug("[CALL]: %s", __FUNCTION__);
	pNumConstants;
	pFirstConstant;
	NumBuffers;
	StartSlot;
}

//PFND3DWDDM2_0DDI_CALCPRIVATEUNORDEREDACCESSVIEWSIZE
SIZE_T APIENTRY WddmDdiCalcPrivateUnorderedAccessViewSize(D3D10DDI_HDEVICE, _In_ CONST D3DWDDM2_0DDIARG_CREATEUNORDEREDACCESSVIEW*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3DWDDM2_0DDI_CREATEUNORDEREDACCESSVIEW
VOID APIENTRY WddmDdiCreateUnorderedAccessView(D3D10DDI_HDEVICE, _In_ CONST D3DWDDM2_0DDIARG_CREATEUNORDEREDACCESSVIEW*, D3D11DDI_HUNORDEREDACCESSVIEW, D3D11DDI_HRTUNORDEREDACCESSVIEW)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_DESTROYUNORDEREDACCESSVIEW
VOID APIENTRY WddmDdiDestroyUnorderedAccessView(D3D10DDI_HDEVICE, D3D11DDI_HUNORDEREDACCESSVIEW)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_CLEARUNORDEREDACCESSVIEWUINT
VOID APIENTRY WddmDdiClearUnorderedAccessViewUint(D3D10DDI_HDEVICE, D3D11DDI_HUNORDEREDACCESSVIEW, CONST UINT[4])
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_CLEARUNORDEREDACCESSVIEWFLOAT
VOID APIENTRY WddmDdiClearUnorderedAccessViewFloat(D3D10DDI_HDEVICE, D3D11DDI_HUNORDEREDACCESSVIEW, CONST FLOAT[4])
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_SETUNORDEREDACCESSVIEWS
VOID APIENTRY WddmDdiCsSetUnorderedAccessViews(D3D10DDI_HDEVICE, _In_range_(0, D3D11_1_UAV_SLOT_COUNT - 1) UINT StartSlot, _In_range_(0, D3D11_1_UAV_SLOT_COUNT - StartSlot) UINT NumViews, _In_reads_(NumViews) CONST D3D11DDI_HUNORDEREDACCESSVIEW*, _In_reads_(NumViews) CONST UINT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumViews;
	StartSlot;
}

//PFND3D11DDI_DISPATCH
VOID APIENTRY WddmDdiDispatch(D3D10DDI_HDEVICE, UINT, UINT, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_DISPATCHINDIRECT
VOID APIENTRY WddmDdiDispatchIndirect(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_SETRESOURCEMINLOD
VOID APIENTRY WddmDdiSetResourceMinLOD(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, FLOAT)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_COPYSTRUCTURECOUNT
VOID APIENTRY WddmDdiCopyStructureCount(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D11DDI_HUNORDEREDACCESSVIEW)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_RECYCLECOMMANDLIST
VOID APIENTRY WddmDdiRecycleCommandList(D3D10DDI_HDEVICE, D3D11DDI_HCOMMANDLIST)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11DDI_RECYCLECREATECOMMANDLIST
HRESULT APIENTRY WddmDdiRecycleCreateCommandList(D3D10DDI_HDEVICE, _In_ CONST D3D11DDIARG_CREATECOMMANDLIST*, D3D11DDI_HCOMMANDLIST, D3D11DDI_HRTCOMMANDLIST)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//PFND3D11DDI_RECYCLECREATEDEFERREDCONTEXT
HRESULT APIENTRY WddmDdiRecycleCreateDeferredContext(D3D10DDI_HDEVICE, _In_ CONST D3D11DDIARG_CREATEDEFERREDCONTEXT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//PFND3D11DDI_DESTROYCOMMANDLIST
VOID APIENTRY WddmDdiRecycleDestroyCommandList(D3D10DDI_HDEVICE, D3D11DDI_HCOMMANDLIST)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3D11_1DDI_DISCARD
VOID APIENTRY WddmDdiDiscard(D3D10DDI_HDEVICE, D3D11DDI_HANDLETYPE HandleType, VOID* hResourceOrView, _In_reads_opt_(NumRects) CONST D3D10_DDI_RECT*, UINT NumRects)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumRects;
	hResourceOrView;
	HandleType;
}

//PFND3D11_1DDI_ASSIGNDEBUGBINARY
VOID APIENTRY WddmDdiAssignDebugBinary(D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT uBinarySize, _In_reads_bytes_(uBinarySize) CONST VOID* pBinary)
{
	debug("[CALL]: %s", __FUNCTION__);
	pBinary;
	uBinarySize;
}

//PFND3D10DDI_RESOURCEMAP
VOID APIENTRY WddmDdiDynamicConstantBufferMapNoOverwrite(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, _Out_ D3D10DDI_MAPPED_SUBRESOURCE* pOut)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pOut = D3D10DDI_MAPPED_SUBRESOURCE();
}

//PFND3D11_1DDI_CHECKDIRECTFLIPSUPPORT
VOID APIENTRY WddmDdiCheckDirectFlipSupport(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, D3D10DDI_HRESOURCE, UINT CheckDirectFlipFlags, _Out_ BOOL* pSupported)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pSupported = true;
	CheckDirectFlipFlags;
}

//PFND3D11_1DDI_CLEARVIEW
VOID APIENTRY WddmDdiClearView(D3D10DDI_HDEVICE hDevice, D3D11DDI_HANDLETYPE viewType, VOID* hView, CONST FLOAT Color[4], _In_reads_opt_(NumRects) CONST D3D10_DDI_RECT* pRect, UINT NumRects)
{
	debug("[CALL]: %s", __FUNCTION__);
	NumRects;
	pRect;
	Color;
	hView;
	viewType;
	hDevice;
}

//PFND3DWDDM1_3DDI_UPDATETILEMAPPINGS
VOID APIENTRY WddmDdiUpdateTileMappings(D3D10DDI_HDEVICE hDevice, D3D10DDI_HRESOURCE hTiledResource, UINT NumTiledResourceRegions, _In_reads_(NumTiledResourceRegions) const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE* pTiledResourceRegionStartCoords, _In_reads_opt_(NumTiledResourceRegions) const D3DWDDM1_3DDI_TILE_REGION_SIZE* pTiledResourceRegionSizes, D3D10DDI_HRESOURCE hTilePool, UINT NumRanges, _In_reads_opt_(NumRanges) const UINT* pRangeFlags, _In_reads_opt_(NumRanges) const UINT* pTilePoolStartOffsets, _In_reads_opt_(NumRanges) const UINT* pRangeTileCounts, UINT Flags)
{
	debug("[CALL]: %s", __FUNCTION__);
	Flags;
	pRangeTileCounts;
	pTilePoolStartOffsets;
	pRangeFlags;
	NumRanges;
	hTilePool;
	pTiledResourceRegionSizes;
	pTiledResourceRegionStartCoords;
	NumTiledResourceRegions;
	hTiledResource;
	hDevice;
}

//PFND3DWDDM1_3DDI_COPYTILEMAPPINGS
VOID APIENTRY WddmDdiCopyTileMappings(D3D10DDI_HDEVICE hDevice, D3D10DDI_HRESOURCE hDestTiledResource, _In_ const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE* pDestRegionStartCoord, D3D10DDI_HRESOURCE hSourceTiledResource, _In_ const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE* pSourceRegionStartCoord, _In_ const D3DWDDM1_3DDI_TILE_REGION_SIZE* pTileRegionSize, UINT Flags)
{
	debug("[CALL]: %s", __FUNCTION__);
	Flags;
	pTileRegionSize;
	pSourceRegionStartCoord;
	hSourceTiledResource;
	pDestRegionStartCoord;
	hDestTiledResource;
	hDevice;
}

//PFND3DWDDM1_3DDI_COPYTILES
VOID APIENTRY WddmDdiCopyTiles(D3D10DDI_HDEVICE hDevice, D3D10DDI_HRESOURCE hTiledResource, _In_ const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE* pTileRegionStartCoord, _In_ const D3DWDDM1_3DDI_TILE_REGION_SIZE* pTileRegionSize, D3D10DDI_HRESOURCE hBuffer, UINT64 BufferStartOffsetInBytes, UINT Flags)
{
	debug("[CALL]: %s", __FUNCTION__);
	Flags;
	BufferStartOffsetInBytes;
	hBuffer;
	pTileRegionSize;
	pTileRegionStartCoord;
	hTiledResource;
	hDevice;
}

//PFND3DWDDM1_3DDI_UPDATETILES
VOID APIENTRY WddmDdiUpdateTiles(D3D10DDI_HDEVICE hDevice, D3D10DDI_HRESOURCE hDestTiledResource, _In_ const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE* pDestTileRegionStartCoord, _In_ const D3DWDDM1_3DDI_TILE_REGION_SIZE* pDestTileRegionSize, _In_ const VOID* pSourceTileData, UINT Flags)
{
	debug("[CALL]: %s", __FUNCTION__);
	Flags;
	pSourceTileData;
	pDestTileRegionSize;
	pDestTileRegionStartCoord;
	hDestTiledResource;
	hDevice;
}

//PFND3DWDDM1_3DDI_TILEDRESOURCEBARRIER
VOID APIENTRY WddmDdiTiledResourceBarrier(D3D10DDI_HDEVICE hDevice, D3D11DDI_HANDLETYPE TiledResourceAccessBeforeBarrierHandleType, _In_opt_ VOID* hTiledResourceAccessBeforeBarrier, D3D11DDI_HANDLETYPE TiledResourceAccessAfterBarrierHandleType, _In_opt_ VOID* hTiledResourceAccessAfterBarrier)
{
	debug("[CALL]: %s", __FUNCTION__);
	hTiledResourceAccessAfterBarrier;
	TiledResourceAccessAfterBarrierHandleType;
	hTiledResourceAccessBeforeBarrier;
	TiledResourceAccessBeforeBarrierHandleType;
	hDevice;
}

//PFND3DWDDM1_3DDI_GETMIPPACKING
VOID APIENTRY WddmDdiGetMipPacking(D3D10DDI_HDEVICE hDevice, D3D10DDI_HRESOURCE hTiledResource, _Out_ UINT* pNumPackedMips, _Out_ UINT* pNumTilesForPackedMips)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pNumPackedMips = 0;
	*pNumTilesForPackedMips = 0;
	hTiledResource;
	hDevice;
}

//PFND3DWDDM1_3DDI_RESIZETILEPOOL
VOID APIENTRY WddmDdiResizeTilePool(D3D10DDI_HDEVICE hDevice, D3D10DDI_HRESOURCE hTilePool, UINT64 NewSizeInBytes)
{
	debug("[CALL]: %s", __FUNCTION__);
	NewSizeInBytes;
	hTilePool;
	hDevice;
}

//PFND3DWDDM1_3DDI_SETMARKER
VOID APIENTRY WddmDdiSetMarker(D3D10DDI_HDEVICE hDevice)
{
	debug("[CALL]: %s", __FUNCTION__);
	hDevice;
}

//FND3DWDDM1_3DDI_SETMARKERMODE
VOID APIENTRY WddmDdiSetMarkerMode(D3D10DDI_HDEVICE hDevice, D3DWDDM1_3DDI_MARKER_TYPE Type, UINT Flags)
{
	debug("[CALL]: %s", __FUNCTION__);
	Flags;
	Type;
	hDevice;
}

//PFND3DWDDM2_0DDI_SETHARDWAREPROTECTION
VOID APIENTRY WddmDdiSetHardwareProtection(D3D10DDI_HDEVICE hDevice, D3D10DDI_HRESOURCE hResource, BOOL Protected)
{
	debug("[CALL]: %s", __FUNCTION__);
	Protected;
	hResource;
	hDevice;
}

//PFND3DWDDM2_0DDI_GETRESOURCELAYOUT
VOID APIENTRY WddmDdiGetResourceLayout(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT SubResourceCount, _Out_ D3DKMT_HANDLE* pOut1, _Out_ D3DWDDM2_0DDI_TEXTURE_LAYOUT* pOut2, _Out_ UINT* pMipLevelSwizzleTransition, _Out_writes_opt_(SubResourceCount) D3DWDDM2_0DDI_SUBRESOURCE_LAYOUT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pOut1 = D3DKMT_HANDLE();
	*pOut2 = D3DWDDM2_0DDI_TEXTURE_LAYOUT();
	*pMipLevelSwizzleTransition = 0;
	SubResourceCount;
}

//PFND3DWDDM2_0DDI_RETRIEVE_SHADER_COMMENT
HRESULT APIENTRY WddmDdiRetrieveShaderComment(D3D10DDI_HDEVICE, D3D10DDI_HSHADER, _Out_writes_z_(*CharacterCountIncludingNullTerminator) WCHAR* pBuffer, _Inout_ SIZE_T* CharacterCountIncludingNullTerminator)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
	CharacterCountIncludingNullTerminator;
	pBuffer;
}

//PFND3DWDDM2_0DDI_SETHARDWAREPROTECTIONSTATE
void APIENTRY WddmDdiSetHardwareProtectionState(D3D10DDI_HDEVICE, BOOL HwProtectionEnable)
{
	debug("[CALL]: %s", __FUNCTION__);
	HwProtectionEnable;
}

//PFND3DWDDM2_1DDI_SYNC_TOKEN
VOID APIENTRY WddmDdiAcquireResource(D3D10DDI_HDEVICE, _In_opt_ D3D10DDI_HRESOURCE hResource, HANDLE hSyncToken)
{
	debug("[CALL]: %s", __FUNCTION__);
	hSyncToken;
	hResource;
}

//PFND3DWDDM2_1DDI_SYNC_TOKEN
VOID APIENTRY WddmDdiReleaseResource(D3D10DDI_HDEVICE, _In_opt_ D3D10DDI_HRESOURCE hResource, HANDLE hSyncToken)
{
	debug("[CALL]: %s", __FUNCTION__);
	hSyncToken;
	hResource;
}

//PFND3DWDDM2_2DDI_CALCPRIVATE_SHADERCACHE_SESSION_SIZE
SIZE_T APIENTRY WddmDdiCalcPrivateShaderCacheSessionSize(D3D10DDI_HDEVICE)
{
	debug("[CALL]: %s", __FUNCTION__);
	return 0;
}

//PFND3DWDDM2_2DDI_CREATE_SHADERCACHE_SESSION
VOID APIENTRY WddmDdiCreateShaderCacheSession(D3D10DDI_HDEVICE, D3DWDDM2_2DDI_HCACHESESSION, D3DWDDM2_2DDI_HRTCACHESESSION)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3DWDDM2_2DDI_DESTROY_SHADERCACHE_SESSION
VOID APIENTRY WddmDdiDestroyShaderCacheSession(D3D10DDI_HDEVICE, D3DWDDM2_2DDI_HCACHESESSION)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3DWDDM2_2DDI_SET_SHADERCACHE_SESSION
VOID APIENTRY WddmDdiSetShaderCacheSession(D3D10DDI_HDEVICE, D3DWDDM2_2DDI_HCACHESESSION)
{
	debug("[CALL]: %s", __FUNCTION__);
}

//PFND3DWDDM2_6DDI_QUERY_SCANOUT_CAPS
void APIENTRY WddmDdiQueryScanoutCaps(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT SubResource, D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId, UINT PlaneIdx, _Out_ D3DWDDM2_6DDI_SCANOUT_FLAGS* pFlags)
{
	debug("[CALL]: %s", __FUNCTION__);
	*pFlags = D3DWDDM2_6DDI_SCANOUT_FLAGS();
	PlaneIdx;
	VidPnSourceId;
	SubResource;
}

//PFND3DWDDM2_6DDI_PREPARE_SCANOUT_TRANSFORMATION
void APIENTRY WddmDdiPrepareScanoutTransformation(D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT SubResource, D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId, UINT PlaneIdx, _In_opt_ D3D10_DDI_RECT* pSubRect)
{
	debug("[CALL]: %s", __FUNCTION__);
	pSubRect;
	PlaneIdx;
	VidPnSourceId;
	SubResource;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Device Infrastructure Functions (DXGI1_6_1_DDI_BASE_FUNCTIONS) [DXGI1_6_1]

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnPresent
HRESULT APIENTRY WddmDdiPresent(DXGI_DDI_ARG_PRESENT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnGetGammaCaps
HRESULT APIENTRY WddmDdiGetGammaCaps(DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnSetDisplayMode
HRESULT APIENTRY WddmDdiSetDisplayMode(DXGI_DDI_ARG_SETDISPLAYMODE*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnSetResourcePriority
HRESULT APIENTRY WddmDdiSetResourcePriority(DXGI_DDI_ARG_SETRESOURCEPRIORITY*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnQueryResourceResidency
HRESULT APIENTRY WddmDdiQueryResourceResidency(DXGI_DDI_ARG_QUERYRESOURCERESIDENCY*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnRotateResourceIdentities
HRESULT APIENTRY WddmDdiRotateResourceIdentities(DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnBlt
HRESULT APIENTRY WddmDdiBlt(DXGI_DDI_ARG_BLT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnResolveSharedResource
HRESULT APIENTRY WddmDdiResolveSharedResource(DXGI_DDI_ARG_RESOLVESHAREDRESOURCE*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnBlt1
HRESULT APIENTRY WddmDdiBlt1(DXGI_DDI_ARG_BLT1*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnOfferResources1
HRESULT APIENTRY WddmDdiOfferResources1(DXGI_DDI_ARG_OFFERRESOURCES1*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnReclaimResources
HRESULT APIENTRY WddmDdiReclaimResources(DXGI_DDI_ARG_RECLAIMRESOURCES*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnGetMultiplaneOverlayCaps
HRESULT APIENTRY WddmDdiGetMultiplaneOverlayCaps(DXGI_DDI_ARG_GETMULTIPLANEOVERLAYCAPS*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnGetMultiplaneOverlayGroupCaps
HRESULT APIENTRY WddmDdiGetMultiplaneOverlayGroupCaps(DXGI_DDI_ARG_GETMULTIPLANEOVERLAYGROUPCAPS*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnReserved1
HRESULT APIENTRY WddmDdiReserved1(void*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnPresentMultiplaneOverlay
HRESULT APIENTRY WddmDdiPresentMultiplaneOverlay(DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnReserved2
HRESULT APIENTRY WddmDdiReserved2(void*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnPresent1
HRESULT APIENTRY WddmDdiPresent1(DXGI1_6_1_DDI_ARG_PRESENT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnCheckPresentDurationSupport
HRESULT APIENTRY WddmDdiCheckPresentDurationSupport(DXGI_DDI_ARG_CHECKPRESENTDURATIONSUPPORT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnTrimResidencySet
HRESULT APIENTRY WddmDdiTrimResidencySet(DXGI_DDI_ARG_TRIMRESIDENCYSET*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnCheckMultiplaneOverlayColorSpaceSupport
HRESULT APIENTRY WddmDdiCheckMultiplaneOverlayColorSpaceSupport(DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYCOLORSPACESUPPORT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnPresentMultiplaneOverlay1
HRESULT APIENTRY WddmDdiPresentMultiplaneOverlay1(DXGI1_6_1_DDI_ARG_PRESENTMULTIPLANEOVERLAY*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

//DXGI1_6_1_DDI_BASE_FUNCTIONS->pfnReclaimResources1
HRESULT APIENTRY WddmDdiReclaimResources1(DXGI_DDI_ARG_RECLAIMRESOURCES1*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------
#pragma region //Device Infrastructure Callbacks (DXGI_DDI_BASE_CALLBACKS) [DXGI]

//PFNDDXGIDDI_PRESENTCB
_Check_return_ HRESULT APIENTRY CALLBACK WddmDdiPresentCb(_In_ HANDLE hDevice, _In_ DXGIDDICB_PRESENT*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
	hDevice;
}

//PFNDDXGIDDI_PRESENT_MULTIPLANE_OVERLAYCB
_Check_return_ HRESULT APIENTRY CALLBACK WddmDdiPresentMultiplaneOverlayCb(_In_ HANDLE hDevice, _In_ CONST DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
	hDevice;
}

//PFNDDXGIDDI_PRESENT_MULTIPLANE_OVERLAY1CB
_Check_return_ HRESULT APIENTRY CALLBACK WddmDdiPresentMultiplaneOverlay1Cb(_In_ HANDLE hDevice, _In_ CONST DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY1*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
	hDevice;
}

//PFNDDXGIDDI_SUBMITPRESENTBLTTOHWQUEUECB
_Check_return_ HRESULT APIENTRY CALLBACK WddmDdiSubmitPresentBltToHwQueueCb(_In_ HANDLE hDevice, _In_ DXGIDDICB_SUBMITPRESENTBLTTOHWQUEUE*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
	hDevice;
}

//PFNDDXGIDDI_SUBMITPRESENTTOHWQUEUECB
_Check_return_ HRESULT APIENTRY CALLBACK WddmDdiSubmitPresentToHwQueueCb(_In_ HANDLE hDevice, _In_ DXGIDDICB_SUBMITPRESENTTOHWQUEUE*)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
	hDevice;
}

#pragma endregion
//--------------------------------------------------------------------------------------------------------

//PFND3D10DDI_RETRIEVESUBOBJECT
HRESULT APIENTRY WddmDdiRetrieveSubObject(D3D10DDI_HDEVICE, _In_ UINT32 SubDeviceID, _In_ SIZE_T ParamSize, _In_reads_bytes_opt_(ParamSize) void* pParams, _In_ SIZE_T OutputParamSize, _Out_writes_bytes_(OutputParamSize) void* pOutputParamsBuffer)
{
	debug("[CALL]: %s", __FUNCTION__);
	return S_OK;
	pOutputParamsBuffer;
	OutputParamSize;
	pParams;
	ParamSize;
	SubDeviceID;
}