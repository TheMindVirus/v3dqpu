#ifndef _DEVICE_HXX_
#define _DEVICE_HXX_

#ifdef DBG
#define DBG   1
#define debug(...)   \
	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, __VA_ARGS__)); \
    KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "\n"));
#else
#define debug(...)
#endif

#include <windows.h>

#include "d3dddi.hxx"

extern HINSTANCE g_hDLL;

#endif//_DEVICE_HXX_