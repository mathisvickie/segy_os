#include "kernel32.h"
#include "nt.c"

typedef int(__stdcall* fn_LoadLibraryA)(char*);
__declspec(dllexport) fn_LoadLibraryA pLoadLibraryA;

char __stdcall EntryPoint(void* hModule, int dwReason, void* lpReserved)
{
	if (dwReason != DLL_PROCESS_ATTACH)
		return 1;

	pLoadLibraryA = NtGetProcAddress(NtGetModuleHandle(L"KERNEL32.DLL"), "LoadLibraryA");
	pLoadLibraryA("USER32.DLL");

	return 1;
}
