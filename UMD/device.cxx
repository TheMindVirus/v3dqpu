#include "device.hxx"

extern HINSTANCE g_hDLL = NULL;

HRESULT APIENTRY OpenAdapter10_2(D3D10DDIARG_OPENADAPTER* pArgs)
{
    debug("[CALL]: %s (pArgs = %p)", __FUNCTION__, pArgs);
    //DebugBreak();
    if (pArgs)
    {
        debug("[INFO]: _In_  pArgs->hRTAdapter        = %p", pArgs->hRTAdapter.handle);
        debug("[INFO]: _Out_ pArgs->hAdapter          = %p", pArgs->hAdapter.pDrvPrivate);
        debug("[INFO]: _In_  pArgs->Interface         = %d", pArgs->Interface);
        debug("[INFO]: _In_  pArgs->Version           = %d", pArgs->Version);
        debug("[INFO]: _In_  pArgs->pAdapterCallbacks = %p", pArgs->pAdapterCallbacks);
        debug("[INFO]: _Out_ pArgs->pAdapterFuncs     = %p", pArgs->pAdapterFuncs);
        debug("[INFO]: _Out_ pArgs->pAdapterFuncs_2   = %p", pArgs->pAdapterFuncs_2);
        D3dDdiOpenPatch(*pArgs);
    }
    return S_OK;
}

BOOL WINAPI DllMain(HINSTANCE hmod, UINT dwReason, LPVOID lpvReserved)
{
    debug("[CALL]: %s", __FUNCTION__);
    switch (dwReason)
    {
        case (DLL_PROCESS_ATTACH):
        {
            debug("[INFO]: DLL_PROCESS_ATTACH (hmod = 0x%p)", hmod);
            g_hDLL = hmod;
            //DebugBreak();
            //InitializeShaderCompilerLibrary();
            //InitInstructionInfo();
        }
        break;
        case (DLL_PROCESS_DETACH):
        {
            debug("[INFO]: DLL_PROCESS_DETACH (hmod = 0x%p)", hmod);
            g_hDLL = NULL;
            return TRUE;
        }
        default: break;
    }
    return TRUE;
    lpvReserved; // unused
}