#pragma once

#define DLL_PROCESS_DETACH   0
#define DLL_PROCESS_ATTACH   1
#define DLL_THREAD_ATTACH    2
#define DLL_THREAD_DETACH    3

/*
Abandoned functions:
FID_conflict:_StringCbCatExW@24 /retarded : character
_StringCatWorkerW /redefinition
*/

void* g_funcs[1000];

#define __JMP_API __declspec(dllexport) __declspec(naked)

void __JMP_API DeviceIoControl(void) { __asm jmp dword ptr[g_funcs + 0] }
void __JMP_API GetSystemTime(void) { __asm jmp dword ptr[g_funcs + 4] }
void __JMP_API GetSystemTimeAsFileTime(void) { __asm jmp dword ptr[g_funcs + 8] }
void __JMP_API ReadFile(void) { __asm jmp dword ptr[g_funcs + 12] }
void __JMP_API CreateFileA(void) { __asm jmp dword ptr[g_funcs + 16] }
void __JMP_API VirtualProtectEx(void) { __asm jmp dword ptr[g_funcs + 20] }
void __JMP_API VirtualProtect(void) { __asm jmp dword ptr[g_funcs + 24] }
void __JMP_API LoadLibraryExA(void) { __asm jmp dword ptr[g_funcs + 28] }
void __JMP_API LoadLibraryA(void) { __asm jmp dword ptr[g_funcs + 32] }
void __JMP_API LoadLibraryExW(void) { __asm jmp dword ptr[g_funcs + 36] }
void __JMP_API TerminateProcess(void) { __asm jmp dword ptr[g_funcs + 40] }
void __JMP_API GetStartupInfoW(void) { __asm jmp dword ptr[g_funcs + 44] }
void __JMP_API GetStartupInfoA(void) { __asm jmp dword ptr[g_funcs + 48] }
void __JMP_API ReadProcessMemory(void) { __asm jmp dword ptr[g_funcs + 52] }
void __JMP_API WriteProcessMemory(void) { __asm jmp dword ptr[g_funcs + 56] }
void __JMP_API CreateProcessW(void) { __asm jmp dword ptr[g_funcs + 60] }
void __JMP_API CreateProcessA(void) { __asm jmp dword ptr[g_funcs + 64] }
void __JMP_API SleepEx(void) { __asm jmp dword ptr[g_funcs + 68] }
void __JMP_API Sleep(void) { __asm jmp dword ptr[g_funcs + 72] }
void __JMP_API ReleaseMutex(void) { __asm jmp dword ptr[g_funcs + 76] }
void __JMP_API __SEH_prolog(void) { __asm jmp dword ptr[g_funcs + 80] }
void __JMP_API __SEH_epilog(void) { __asm jmp dword ptr[g_funcs + 84] }
void __JMP_API WaitForSingleObject(void) { __asm jmp dword ptr[g_funcs + 88] }
void __JMP_API WaitForSingleObjectEx(void) { __asm jmp dword ptr[g_funcs + 92] }
void __JMP_API GetTickCount(void) { __asm jmp dword ptr[g_funcs + 96] }
void __JMP_API CreateFileMappingW(void) { __asm jmp dword ptr[g_funcs + 100] }
void __JMP_API CreateFileMappingA(void) { __asm jmp dword ptr[g_funcs + 104] }
void __JMP_API WaitForMultipleObjectsEx(void) { __asm jmp dword ptr[g_funcs + 108] }
void __JMP_API SetWaitableTimer(void) { __asm jmp dword ptr[g_funcs + 112] }
void __JMP_API GetCurrentThreadId(void) { __asm jmp dword ptr[g_funcs + 116] }
void __JMP_API TlsGetValue(void) { __asm jmp dword ptr[g_funcs + 120] }
void __JMP_API InterlockedIncrement(void) { __asm jmp dword ptr[g_funcs + 124] }
void __JMP_API InterlockedDecrement(void) { __asm jmp dword ptr[g_funcs + 128] }
void __JMP_API InterlockedExchange(void) { __asm jmp dword ptr[g_funcs + 132] }
void __JMP_API InterlockedCompareExchange(void) { __asm jmp dword ptr[g_funcs + 136] }
void __JMP_API InterlockedExchangeAdd(void) { __asm jmp dword ptr[g_funcs + 140] }
void __JMP_API MulDiv(void) { __asm jmp dword ptr[g_funcs + 144] }
void __JMP_API GetCurrentThread(void) { __asm jmp dword ptr[g_funcs + 148] }
void __JMP_API GetACP(void) { __asm jmp dword ptr[g_funcs + 152] }
void __JMP_API GetCurrentProcessId(void) { __asm jmp dword ptr[g_funcs + 156] }
void __JMP_API LocalFree(void) { __asm jmp dword ptr[g_funcs + 160] }
void __JMP_API LocalAlloc(void) { __asm jmp dword ptr[g_funcs + 164] }
void __JMP_API lstrlenW(void) { __asm jmp dword ptr[g_funcs + 168] }
void __JMP_API VirtualAlloc(void) { __asm jmp dword ptr[g_funcs + 172] }
void __JMP_API VirtualAllocEx(void) { __asm jmp dword ptr[g_funcs + 176] }
void __JMP_API VirtualFree(void) { __asm jmp dword ptr[g_funcs + 180] }
void __JMP_API VirtualFreeEx(void) { __asm jmp dword ptr[g_funcs + 184] }
void __JMP_API CloseHandle(void) { __asm jmp dword ptr[g_funcs + 188] }
void __JMP_API TlsSetValue(void) { __asm jmp dword ptr[g_funcs + 192] }
void __JMP_API MultiByteToWideChar(void) { __asm jmp dword ptr[g_funcs + 196] }
void __JMP_API IsBadReadPtr(void) { __asm jmp dword ptr[g_funcs + 200] }
void __JMP_API IsBadWritePtr(void) { __asm jmp dword ptr[g_funcs + 204] }
void __JMP_API InitializeCriticalSection(void) { __asm jmp dword ptr[g_funcs + 208] }
void __JMP_API GetUserDefaultLCID(void) { __asm jmp dword ptr[g_funcs + 212] }
void __JMP_API LdrFindResource_U(void) { __asm jmp dword ptr[g_funcs + 216] }
void __JMP_API LdrAccessResource(void) { __asm jmp dword ptr[g_funcs + 220] }
void __JMP_API LoadResource(void) { __asm jmp dword ptr[g_funcs + 224] }
void __JMP_API SetEvent(void) { __asm jmp dword ptr[g_funcs + 228] }
void __JMP_API ResetEvent(void) { __asm jmp dword ptr[g_funcs + 232] }
void __JMP_API WaitForMultipleObjects(void) { __asm jmp dword ptr[g_funcs + 236] }
void __JMP_API _allmul(void) { __asm jmp dword ptr[g_funcs + 240] }
void __JMP_API WideCharToMultiByte(void) { __asm jmp dword ptr[g_funcs + 244] }
void __JMP_API CompareStringW(void) { __asm jmp dword ptr[g_funcs + 248] }
void __JMP_API GetThreadLocale(void) { __asm jmp dword ptr[g_funcs + 252] }
void __JMP_API QueryPerformanceCounter(void) { __asm jmp dword ptr[g_funcs + 256] }
void __JMP_API GetStringTypeW(void) { __asm jmp dword ptr[g_funcs + 260] }
void __JMP_API IsBadStringPtrW(void) { __asm jmp dword ptr[g_funcs + 264] }
void __JMP_API ActivateActCtx(void) { __asm jmp dword ptr[g_funcs + 268] }
void __JMP_API DeactivateActCtx(void) { __asm jmp dword ptr[g_funcs + 272] }
void __JMP_API CreateEventW(void) { __asm jmp dword ptr[g_funcs + 276] }
void __JMP_API GetQueuedCompletionStatus(void) { __asm jmp dword ptr[g_funcs + 280] }
void __JMP_API GetThreadPriority(void) { __asm jmp dword ptr[g_funcs + 284] }
void __JMP_API GetLocalTime(void) { __asm jmp dword ptr[g_funcs + 288] }
void __JMP_API lstrcmpiW(void) { __asm jmp dword ptr[g_funcs + 292] }
void __JMP_API lstrcmpW(void) { __asm jmp dword ptr[g_funcs + 296] }
void __JMP_API GetProcessHeap(void) { __asm jmp dword ptr[g_funcs + 300] }
void __JMP_API LdrUnloadDll(void) { __asm jmp dword ptr[g_funcs + 304] }
void __JMP_API FreeLibrary(void) { __asm jmp dword ptr[g_funcs + 308] }
void __JMP_API SetErrorMode(void) { __asm jmp dword ptr[g_funcs + 312] }
void __JMP_API FindResourceExW(void) { __asm jmp dword ptr[g_funcs + 316] }
void __JMP_API GetSystemWindowsDirectoryW(void) { __asm jmp dword ptr[g_funcs + 320] }
void __JMP_API GetWindowsDirectoryW(void) { __asm jmp dword ptr[g_funcs + 324] }
void __JMP_API LdrGetProcedureAddress(void) { __asm jmp dword ptr[g_funcs + 328] }
void __JMP_API GetProcAddress(void) { __asm jmp dword ptr[g_funcs + 332] }
void __JMP_API IsProcessorFeaturePresent(void) { __asm jmp dword ptr[g_funcs + 336] }
void __JMP_API LoadLibraryW(void) { __asm jmp dword ptr[g_funcs + 340] }
void __JMP_API GetVersionExW(void) { __asm jmp dword ptr[g_funcs + 344] }
void __JMP_API GetDriveTypeW(void) { __asm jmp dword ptr[g_funcs + 348] }
void __JMP_API LdrLockLoaderLock(void) { __asm jmp dword ptr[g_funcs + 352] }
void __JMP_API GetModuleFileNameW(void) { __asm jmp dword ptr[g_funcs + 356] }
void __JMP_API LdrUnlockLoaderLock(void) { __asm jmp dword ptr[g_funcs + 360] }
void __JMP_API GetModuleFileNameA(void) { __asm jmp dword ptr[g_funcs + 364] }
void __JMP_API GetModuleHandleA(void) { __asm jmp dword ptr[g_funcs + 372] }
void __JMP_API lstrlen(void) { __asm jmp dword ptr[g_funcs + 376] }
void __JMP_API lstrcpy(void) { __asm jmp dword ptr[g_funcs + 380] }
void __JMP_API FindResourceA(void) { __asm jmp dword ptr[g_funcs + 384] }
void __JMP_API GetSystemDefaultLCID(void) { __asm jmp dword ptr[g_funcs + 388] }
void __JMP_API GetUserDefaultLangID(void) { __asm jmp dword ptr[g_funcs + 392] }
void __JMP_API IsBadHugeWritePtr(void) { __asm jmp dword ptr[g_funcs + 396] }
void __JMP_API ReleaseSemaphore(void) { __asm jmp dword ptr[g_funcs + 400] }
void __JMP_API GetStringTypeExW(void) { __asm jmp dword ptr[g_funcs + 404] }
void __JMP_API ExitThread(void) { __asm jmp dword ptr[g_funcs + 408] }
void __JMP_API LdrShutdownThread(void) { __asm jmp dword ptr[g_funcs + 412] }
void __JMP_API SetThreadPriority(void) { __asm jmp dword ptr[g_funcs + 416] }
void __JMP_API FreeLibraryAndExitThread(void) { __asm jmp dword ptr[g_funcs + 420] }
void __JMP_API FlushFileBuffers(void) { __asm jmp dword ptr[g_funcs + 424] }
void __JMP_API DisconnectNamedPipe(void) { __asm jmp dword ptr[g_funcs + 428] }
void __JMP_API PostQueuedCompletionStatus(void) { __asm jmp dword ptr[g_funcs + 432] }
void __JMP_API ChangeTimerQueueTimer(void) { __asm jmp dword ptr[g_funcs + 436] }
void __JMP_API LockResource(void) { __asm jmp dword ptr[g_funcs + 440] }
void __JMP_API GetFileAttributesW(void) { __asm jmp dword ptr[g_funcs + 444] }
void __JMP_API IsDBCSLeadByte(void) { __asm jmp dword ptr[g_funcs + 448] }
void __JMP_API InitializeCriticalSectionAndSpinCount(void) { __asm jmp dword ptr[g_funcs + 452] }
void __JMP_API GetFullPathNameW(void) { __asm jmp dword ptr[g_funcs + 456] }
void __JMP_API GetCurrentDirectoryW(void) { __asm jmp dword ptr[g_funcs + 460] }
void __JMP_API MapViewOfFileEx(void) { __asm jmp dword ptr[g_funcs + 464] }
void __JMP_API MapViewOfFile(void) { __asm jmp dword ptr[g_funcs + 468] }
void __JMP_API UnmapViewOfFile(void) { __asm jmp dword ptr[g_funcs + 472] }
void __JMP_API VirtualQueryEx(void) { __asm jmp dword ptr[g_funcs + 476] }
void __JMP_API VirtualQuery(void) { __asm jmp dword ptr[g_funcs + 480] }
void __JMP_API lstrcpynW(void) { __asm jmp dword ptr[g_funcs + 484] }
void __JMP_API lstrcpyW(void) { __asm jmp dword ptr[g_funcs + 488] }
void __JMP_API lstrcmpi(void) { __asm jmp dword ptr[g_funcs + 492] }
void __JMP_API OpenFileMappingW(void) { __asm jmp dword ptr[g_funcs + 496] }
void __JMP_API OpenFileMappingA(void) { __asm jmp dword ptr[g_funcs + 500] }
void __JMP_API FindResourceW(void) { __asm jmp dword ptr[g_funcs + 504] }
void __JMP_API SizeofResource(void) { __asm jmp dword ptr[g_funcs + 508] }
void __JMP_API IsBadCodePtr(void) { __asm jmp dword ptr[g_funcs + 512] }
void __JMP_API FileTimeToSystemTime(void) { __asm jmp dword ptr[g_funcs + 516] }
void __JMP_API FileTimeToLocalFileTime(void) { __asm jmp dword ptr[g_funcs + 520] }
void __JMP_API CreateFileW(void) { __asm jmp dword ptr[g_funcs + 524] }
void __JMP_API GetFileSizeEx(void) { __asm jmp dword ptr[g_funcs + 528] }
void __JMP_API GetFileSize(void) { __asm jmp dword ptr[g_funcs + 532] }
void __JMP_API CompareFileTime(void) { __asm jmp dword ptr[g_funcs + 536] }
void __JMP_API SystemTimeToFileTime(void) { __asm jmp dword ptr[g_funcs + 540] }
void __JMP_API OpenConsoleW(void) { __asm jmp dword ptr[g_funcs + 544] }
void __JMP_API IsValidCodePage(void) { __asm jmp dword ptr[g_funcs + 548] }
void __JMP_API SetFilePointer(void) { __asm jmp dword ptr[g_funcs + 552] }
void __JMP_API GetFileInformationByHandle(void) { __asm jmp dword ptr[g_funcs + 556] }
void __JMP_API WriteFile(void) { __asm jmp dword ptr[g_funcs + 560] }
void __JMP_API GetFileType(void) { __asm jmp dword ptr[g_funcs + 564] }
void __JMP_API HeapDestroy(void) { __asm jmp dword ptr[g_funcs + 568] }
void __JMP_API lstrcatW(void) { __asm jmp dword ptr[g_funcs + 572] }
void __JMP_API LCMapStringW(void) { __asm jmp dword ptr[g_funcs + 576] }
void __JMP_API CompareStringA(void) { __asm jmp dword ptr[g_funcs + 580] }
void __JMP_API GetLocaleInfoA(void) { __asm jmp dword ptr[g_funcs + 584] }
void __JMP_API GetCurrentProcess(void) { __asm jmp dword ptr[g_funcs + 588] }
void __JMP_API DuplicateHandle(void) { __asm jmp dword ptr[g_funcs + 592] }
void __JMP_API __global_unwind2(void) { __asm jmp dword ptr[g_funcs + 596] }
void __JMP_API __abnormal_termination(void) { __asm jmp dword ptr[g_funcs + 600] }
void __JMP_API LdrLoadDll(void) { __asm jmp dword ptr[g_funcs + 604] }
void __JMP_API GetModuleHandleW(void) { __asm jmp dword ptr[g_funcs + 608] }
void __JMP_API LdrGetDllHandle(void) { __asm jmp dword ptr[g_funcs + 612] }
void __JMP_API GetFileAttributesExW(void) { __asm jmp dword ptr[g_funcs + 616] }
void __JMP_API GetVersion(void) { __asm jmp dword ptr[g_funcs + 620] }
void __JMP_API LdrFindResourceDirectory_U(void) { __asm jmp dword ptr[g_funcs + 624] }
void __JMP_API DisableThreadLibraryCalls(void) { __asm jmp dword ptr[g_funcs + 628] }
void __JMP_API LdrDisableThreadCalloutsForDll(void) { __asm jmp dword ptr[g_funcs + 632] }
void __JMP_API SearchPathW(void) { __asm jmp dword ptr[g_funcs + 636] }
void __JMP_API GetFileAttributesA(void) { __asm jmp dword ptr[g_funcs + 640] }
void __JMP_API GlobalFree(void) { __asm jmp dword ptr[g_funcs + 644] }
void __JMP_API GlobalAlloc(void) { __asm jmp dword ptr[g_funcs + 648] }
void __JMP_API GlobalUnlock(void) { __asm jmp dword ptr[g_funcs + 652] }
void __JMP_API GlobalLock(void) { __asm jmp dword ptr[g_funcs + 656] }
void __JMP_API GlobalAddAtomW(void) { __asm jmp dword ptr[g_funcs + 660] }
void __JMP_API CreateSemaphoreW(void) { __asm jmp dword ptr[g_funcs + 664] }
void __JMP_API lstrcpyn(void) { __asm jmp dword ptr[g_funcs + 668] }
void __JMP_API RtlEncodePointer(void) { __asm jmp dword ptr[g_funcs + 672] }
void __JMP_API RtlDecodePointer(void) { __asm jmp dword ptr[g_funcs + 676] }
void __JMP_API SetEnvironmentVariableW(void) { __asm jmp dword ptr[g_funcs + 680] }
void __JMP_API FindFirstFileExW(void) { __asm jmp dword ptr[g_funcs + 684] }
void __JMP_API FindFirstFileW(void) { __asm jmp dword ptr[g_funcs + 688] }
void __JMP_API FindClose(void) { __asm jmp dword ptr[g_funcs + 692] }
void __JMP_API FindNextFileW(void) { __asm jmp dword ptr[g_funcs + 696] }
void __JMP_API GetEnvironmentVariableW(void) { __asm jmp dword ptr[g_funcs + 700] }
void __JMP_API SetCurrentDirectoryW(void) { __asm jmp dword ptr[g_funcs + 704] }
void __JMP_API CreateRemoteThread(void) { __asm jmp dword ptr[g_funcs + 708] }
void __JMP_API CreateThread(void) { __asm jmp dword ptr[g_funcs + 712] }
void __JMP_API SwitchToFiber(void) { __asm jmp dword ptr[g_funcs + 716] }
void __JMP_API __ResourceCallEnumLangRoutine(void) { __asm jmp dword ptr[g_funcs + 720] }
void __JMP_API __ResourceCallEnumNameRoutine(void) { __asm jmp dword ptr[g_funcs + 724] }
void __JMP_API __ResourceCallEnumTypeRoutine(void) { __asm jmp dword ptr[g_funcs + 728] }
void __JMP_API GetPrivateProfileStringW(void) { __asm jmp dword ptr[g_funcs + 732] }
void __JMP_API GetVolumeInformationW(void) { __asm jmp dword ptr[g_funcs + 736] }
void __JMP_API wcsncpy(void) { __asm jmp dword ptr[g_funcs + 740] }
void __JMP_API GlobalReAlloc(void) { __asm jmp dword ptr[g_funcs + 744] }
void __JMP_API GetVersionExA(void) { __asm jmp dword ptr[g_funcs + 748] }
void __JMP_API HeapCreate(void) { __asm jmp dword ptr[g_funcs + 752] }
void __JMP_API GetProcessVersion(void) { __asm jmp dword ptr[g_funcs + 756] }
void __JMP_API GetSystemInfo(void) { __asm jmp dword ptr[g_funcs + 760] }
void __JMP_API TlsAlloc(void) { __asm jmp dword ptr[g_funcs + 764] }
void __JMP_API CreateSemaphoreA(void) { __asm jmp dword ptr[g_funcs + 768] }
void __JMP_API GetCPInfo(void) { __asm jmp dword ptr[g_funcs + 772] }
void __JMP_API GetEnvironmentStringsW(void) { __asm jmp dword ptr[g_funcs + 776] }
void __JMP_API GetCommandLineA(void) { __asm jmp dword ptr[g_funcs + 780] }
void __JMP_API GetStdHandle(void) { __asm jmp dword ptr[g_funcs + 784] }
void __JMP_API CreateMutexW(void) { __asm jmp dword ptr[g_funcs + 788] }
void __JMP_API CreateMutexA(void) { __asm jmp dword ptr[g_funcs + 792] }
void __JMP_API OpenMutexW(void) { __asm jmp dword ptr[g_funcs + 796] }
void __JMP_API OpenMutexA(void) { __asm jmp dword ptr[g_funcs + 800] }
void __JMP_API ProcessIdToSessionId(void) { __asm jmp dword ptr[g_funcs + 804] }
void __JMP_API GetSystemDefaultUILanguage(void) { __asm jmp dword ptr[g_funcs + 808] }
void __JMP_API ReleaseActCtx(void) { __asm jmp dword ptr[g_funcs + 812] }
void __JMP_API GetUserDefaultUILanguage(void) { __asm jmp dword ptr[g_funcs + 816] }
void __JMP_API IsDebuggerPresent(void) { __asm jmp dword ptr[g_funcs + 820] }
void __JMP_API OpenEventW(void) { __asm jmp dword ptr[g_funcs + 824] }
void __JMP_API OpenEventA(void) { __asm jmp dword ptr[g_funcs + 828] }
void __JMP_API WTSGetActiveConsoleSessionId(void) { __asm jmp dword ptr[g_funcs + 832] }
void __JMP_API GetLongPathNameW(void) { __asm jmp dword ptr[g_funcs + 836] }
void __JMP_API TlsFree(void) { __asm jmp dword ptr[g_funcs + 840] }
void __JMP_API GetFileAttributesExA(void) { __asm jmp dword ptr[g_funcs + 844] }
void __JMP_API FindFirstFileA(void) { __asm jmp dword ptr[g_funcs + 848] }
void __JMP_API GetFullPathNameA(void) { __asm jmp dword ptr[g_funcs + 852] }
void __JMP_API FreeEnvironmentStringsW(void) { __asm jmp dword ptr[g_funcs + 856] }
void __JMP_API GetEnvironmentVariableA(void) { __asm jmp dword ptr[g_funcs + 860] }
void __JMP_API LdrLoadAlternateResourceModule(void) { __asm jmp dword ptr[g_funcs + 864] }
void __JMP_API LdrUnloadAlternateResourceModule(void) { __asm jmp dword ptr[g_funcs + 868] }
void __JMP_API GetSystemDirectoryA(void) { __asm jmp dword ptr[g_funcs + 872] }
void __JMP_API NlsConvertIntegerToString(void) { __asm jmp dword ptr[g_funcs + 876] }
void __JMP_API BaseUpdateAppcompatCache(void) { __asm jmp dword ptr[g_funcs + 880] }
void __JMP_API IsWow64Process(void) { __asm jmp dword ptr[g_funcs + 884] }
void __JMP_API LdrCreateOutOfProcessImage(void) { __asm jmp dword ptr[g_funcs + 888] }
void __JMP_API LdrFindCreateProcessManifest(void) { __asm jmp dword ptr[g_funcs + 892] }
void __JMP_API LdrDestroyOutOfProcessImage(void) { __asm jmp dword ptr[g_funcs + 896] }
void __JMP_API CreateActCtxW(void) { __asm jmp dword ptr[g_funcs + 900] }
void __JMP_API LdrAccessOutOfProcessResource(void) { __asm jmp dword ptr[g_funcs + 904] }
void __JMP_API QueryActCtxW(void) { __asm jmp dword ptr[g_funcs + 908] }
void __JMP_API BaseInitAppcompatCache(void) { __asm jmp dword ptr[g_funcs + 912] }
void __JMP_API BaseCheckAppcompatCache(void) { __asm jmp dword ptr[g_funcs + 916] }
void __JMP_API _allshl(void) { __asm jmp dword ptr[g_funcs + 920] }
void __JMP_API GetCommandLineW(void) { __asm jmp dword ptr[g_funcs + 924] }
void __JMP_API RegisterWaitForInputIdle(void) { __asm jmp dword ptr[g_funcs + 928] }
void __JMP_API BaseProcessInitPostImport(void) { __asm jmp dword ptr[g_funcs + 932] }
void __JMP_API LdrEnumerateLoadedModules(void) { __asm jmp dword ptr[g_funcs + 936] }
void __JMP_API GetNlsSectionName(void) { __asm jmp dword ptr[g_funcs + 940] }
void __JMP_API LdrSetDllManifestProber(void) { __asm jmp dword ptr[g_funcs + 944] }
void __JMP_API RtlSetThreadPoolStartFunc(void) { __asm jmp dword ptr[g_funcs + 948] }
void __JMP_API BasepCheckWinSaferRestrictions(void) { __asm jmp dword ptr[g_funcs + 952] }
void __JMP_API DbgPrintEx(void) { __asm jmp dword ptr[g_funcs + 956] }
void __JMP_API LdrQueryImageFileExecutionOptions(void) { __asm jmp dword ptr[g_funcs + 960] }
void __JMP_API GetExitCodeProcess(void) { __asm jmp dword ptr[g_funcs + 964] }
void __JMP_API VerifyConsoleIoHandle(void) { __asm jmp dword ptr[g_funcs + 968] }
void __JMP_API GetConsoleMode(void) { __asm jmp dword ptr[g_funcs + 972] }
void __JMP_API GetConsoleOutputCP(void) { __asm jmp dword ptr[g_funcs + 976] }
void __JMP_API SetConsoleMode(void) { __asm jmp dword ptr[g_funcs + 980] }
void __JMP_API SetThreadUILanguage(void) { __asm jmp dword ptr[g_funcs + 984] }
void __JMP_API SetConsoleInputExeNameW(void) { __asm jmp dword ptr[g_funcs + 988] }
void __JMP_API SetConsoleCtrlHandler(void) { __asm jmp dword ptr[g_funcs + 992] }
void __JMP_API GetConsoleTitleW(void) { __asm jmp dword ptr[g_funcs + 996] }
void __JMP_API SetThreadLocale(void) { __asm jmp dword ptr[g_funcs + 1000] }
void __JMP_API GetConsoleScreenBufferInfo(void) { __asm jmp dword ptr[g_funcs + 1004] }
void __JMP_API IsValidLocale(void) { __asm jmp dword ptr[g_funcs + 1008] }
void __JMP_API ExitProcess(void) { __asm jmp dword ptr[g_funcs + 1012] }
void __JMP_API LdrShutdownProcess(void) { __asm jmp dword ptr[g_funcs + 1016] }
void __JMP_API TerminateThread(void) { __asm jmp dword ptr[g_funcs + 1020] }
void __JMP_API WriteConsoleA(void) { __asm jmp dword ptr[g_funcs + 1024] }
void __JMP_API GetEnvironmentStrings(void) { __asm jmp dword ptr[g_funcs + 1028] }
void __JMP_API SetFileApisToOEM(void) { __asm jmp dword ptr[g_funcs + 1032] }
void __JMP_API SetStdHandle(void) { __asm jmp dword ptr[g_funcs + 1036] }
void __JMP_API CloseConsoleHandle(void) { __asm jmp dword ptr[g_funcs + 1040] }
void __JMP_API DuplicateConsoleHandle(void) { __asm jmp dword ptr[g_funcs + 1044] }
void __JMP_API CreateProcessInternalA(void) { __asm jmp dword ptr[g_funcs + 1048] }
void __JMP_API FreeEnvironmentStringsA(void) { __asm jmp dword ptr[g_funcs + 1052] }
void __JMP_API CreatePipe(void) { __asm jmp dword ptr[g_funcs + 1056] }
void __JMP_API GetPrivateProfileSectionW(void) { __asm jmp dword ptr[g_funcs + 1060] }
void __JMP_API WritePrivateProfileStringW(void) { __asm jmp dword ptr[g_funcs + 1064] }
void __JMP_API TermsrvAppInstallMode(void) { __asm jmp dword ptr[g_funcs + 1068] }
void __JMP_API GetShortPathNameW(void) { __asm jmp dword ptr[g_funcs + 1072] }
void __JMP_API MoveFileWithProgressW(void) { __asm jmp dword ptr[g_funcs + 1076] }
void __JMP_API TransactNamedPipe(void) { __asm jmp dword ptr[g_funcs + 1080] }
void __JMP_API CreateIoCompletionPort(void) { __asm jmp dword ptr[g_funcs + 1084] }
void __JMP_API SetNamedPipeHandleState(void) { __asm jmp dword ptr[g_funcs + 1088] }
void __JMP_API ConnectNamedPipe(void) { __asm jmp dword ptr[g_funcs + 1092] }
void __JMP_API SetFileAttributesW(void) { __asm jmp dword ptr[g_funcs + 1096] }
void __JMP_API GetOverlappedResult(void) { __asm jmp dword ptr[g_funcs + 1100] }
void __JMP_API ReadDirectoryChangesW(void) { __asm jmp dword ptr[g_funcs + 1104] }
void __JMP_API GetComputerNameW(void) { __asm jmp dword ptr[g_funcs + 1108] }
void __JMP_API GetFileTime(void) { __asm jmp dword ptr[g_funcs + 1112] }
void __JMP_API SetFileTime(void) { __asm jmp dword ptr[g_funcs + 1116] }
void __JMP_API GetSystemDirectoryW(void) { __asm jmp dword ptr[g_funcs + 1120] }
void __JMP_API DeleteFileA(void) { __asm jmp dword ptr[g_funcs + 1124] }
void __JMP_API DeleteFileW(void) { __asm jmp dword ptr[g_funcs + 1128] }
void __JMP_API SetEndOfFile(void) { __asm jmp dword ptr[g_funcs + 1132] }
void __JMP_API FindNextChangeNotification(void) { __asm jmp dword ptr[g_funcs + 1136] }
void __JMP_API DosDateTimeToFileTime(void) { __asm jmp dword ptr[g_funcs + 1140] }
void __JMP_API IsBadStringPtrA(void) { __asm jmp dword ptr[g_funcs + 1144] }
void __JMP_API UnlockFile(void) { __asm jmp dword ptr[g_funcs + 1148] }
void __JMP_API UnlockFileEx(void) { __asm jmp dword ptr[g_funcs + 1152] }
void __JMP_API LockFile(void) { __asm jmp dword ptr[g_funcs + 1156] }
void __JMP_API GetTimeZoneInformation(void) { __asm jmp dword ptr[g_funcs + 1160] }
void __JMP_API MoveFileW(void) { __asm jmp dword ptr[g_funcs + 1164] }
void __JMP_API CreateDirectoryW(void) { __asm jmp dword ptr[g_funcs + 1168] }
void __JMP_API GetProcessTimes(void) { __asm jmp dword ptr[g_funcs + 1172] }
void __JMP_API GetCurrentDirectoryA(void) { __asm jmp dword ptr[g_funcs + 1176] }
void __JMP_API _hread(void) { __asm jmp dword ptr[g_funcs + 1180] }
void __JMP_API _llseek(void) { __asm jmp dword ptr[g_funcs + 1184] }
void __JMP_API WriteConsoleW(void) { __asm jmp dword ptr[g_funcs + 1188] }
void __JMP_API MoveFileExW(void) { __asm jmp dword ptr[g_funcs + 1192] }
void __JMP_API SetEnvironmentVariableA(void) { __asm jmp dword ptr[g_funcs + 1196] }
void __JMP_API GetSystemPowerStatus(void) { __asm jmp dword ptr[g_funcs + 1200] }
void __JMP_API LocalSize(void) { __asm jmp dword ptr[g_funcs + 1204] }
void __JMP_API DeleteAtom(void) { __asm jmp dword ptr[g_funcs + 1208] }
void __JMP_API AddAtomW(void) { __asm jmp dword ptr[g_funcs + 1212] }
void __JMP_API GetPrivateProfileIntW(void) { __asm jmp dword ptr[g_funcs + 1216] }
void __JMP_API memmove(void) { __asm jmp dword ptr[g_funcs + 1220] }
void __JMP_API ResumeThread(void) { __asm jmp dword ptr[g_funcs + 1224] }
void __JMP_API SwitchToThread(void) { __asm jmp dword ptr[g_funcs + 1228] }
void __JMP_API ExpandEnvironmentStringsA(void) { __asm jmp dword ptr[g_funcs + 1232] }
void __JMP_API GetPrivateProfileStringA(void) { __asm jmp dword ptr[g_funcs + 1236] }
void __JMP_API GetPrivateProfileSectionNamesA(void) { __asm jmp dword ptr[g_funcs + 1240] }
void __JMP_API LocalLock(void) { __asm jmp dword ptr[g_funcs + 1244] }
void __JMP_API LocalUnlock(void) { __asm jmp dword ptr[g_funcs + 1248] }
void __JMP_API GetAtomNameW(void) { __asm jmp dword ptr[g_funcs + 1252] }
void __JMP_API FindActCtxSectionStringW(void) { __asm jmp dword ptr[g_funcs + 1256] }
void __JMP_API WriteProfileStringW(void) { __asm jmp dword ptr[g_funcs + 1260] }
void __JMP_API OpenProfileUserMapping(void) { __asm jmp dword ptr[g_funcs + 1264] }
void __JMP_API GlobalMemoryStatusEx(void) { __asm jmp dword ptr[g_funcs + 1268] }
void __JMP_API VerifyVersionInfoW(void) { __asm jmp dword ptr[g_funcs + 1272] }
void __JMP_API GetVolumeNameForVolumeMountPointW(void) { __asm jmp dword ptr[g_funcs + 1276] }
void __JMP_API GetModuleHandleExW(void) { __asm jmp dword ptr[g_funcs + 1280] }
void __JMP_API GetComputerNameExW(void) { __asm jmp dword ptr[g_funcs + 1284] }
void __JMP_API GetVolumePathNamesForVolumeNameW(void) { __asm jmp dword ptr[g_funcs + 1288] }
void __JMP_API PrivCopyFileExW(void) { __asm jmp dword ptr[g_funcs + 1292] }
void __JMP_API SetHandleInformation(void) { __asm jmp dword ptr[g_funcs + 1296] }
void __JMP_API OpenSemaphoreW(void) { __asm jmp dword ptr[g_funcs + 1300] }
void __JMP_API CreateWaitableTimerW(void) { __asm jmp dword ptr[g_funcs + 1304] }
void __JMP_API OpenThread(void) { __asm jmp dword ptr[g_funcs + 1308] }
void __JMP_API GetSystemWindowsDirectoryA(void) { __asm jmp dword ptr[g_funcs + 1312] }
void __JMP_API GetWindowsDirectoryA(void) { __asm jmp dword ptr[g_funcs + 1316] }
void __JMP_API GetProfileStringW(void) { __asm jmp dword ptr[g_funcs + 1320] }
void __JMP_API AddAtomA(void) { __asm jmp dword ptr[g_funcs + 1324] }
void __JMP_API GetExitCodeThread(void) { __asm jmp dword ptr[g_funcs + 1328] }
void __JMP_API GetSystemWow64DirectoryA(void) { __asm jmp dword ptr[g_funcs + 1332] }
void __JMP_API GetProfileStringA(void) { __asm jmp dword ptr[g_funcs + 1336] }
void __JMP_API GetDriveTypeA(void) { __asm jmp dword ptr[g_funcs + 1340] }
void __JMP_API DeleteFiber(void) { __asm jmp dword ptr[g_funcs + 1344] }
void __JMP_API ConvertFiberToThread(void) { __asm jmp dword ptr[g_funcs + 1348] }
void __JMP_API ConvertThreadToFiber(void) { __asm jmp dword ptr[g_funcs + 1352] }
void __JMP_API CreateFiber(void) { __asm jmp dword ptr[g_funcs + 1356] }
void __JMP_API CreateFiberEx(void) { __asm jmp dword ptr[g_funcs + 1360] }
void __JMP_API GetComputerNameA(void) { __asm jmp dword ptr[g_funcs + 1364] }
void __JMP_API UnregisterWaitEx(void) { __asm jmp dword ptr[g_funcs + 1368] }
void __JMP_API GetCurrentActCtx(void) { __asm jmp dword ptr[g_funcs + 1372] }
void __JMP_API CancelIo(void) { __asm jmp dword ptr[g_funcs + 1376] }
void __JMP_API LockFileEx(void) { __asm jmp dword ptr[g_funcs + 1380] }
void __JMP_API CmdBatNotification(void) { __asm jmp dword ptr[g_funcs + 1384] }
void __JMP_API FormatMessageA(void) { __asm jmp dword ptr[g_funcs + 1388] }
void __JMP_API QueryPerformanceFrequency(void) { __asm jmp dword ptr[g_funcs + 1392] }
void __JMP_API SetThreadAffinityMask(void) { __asm jmp dword ptr[g_funcs + 1396] }
void __JMP_API GetProcessAffinityMask(void) { __asm jmp dword ptr[g_funcs + 1400] }
void __JMP_API CreateDirectoryA(void) { __asm jmp dword ptr[g_funcs + 1404] }
void __JMP_API FindAtomW(void) { __asm jmp dword ptr[g_funcs + 1408] }
void __JMP_API CopyFileW(void) { __asm jmp dword ptr[g_funcs + 1412] }
void __JMP_API GetProfileIntW(void) { __asm jmp dword ptr[g_funcs + 1416] }
void __JMP_API SetFilePointerEx(void) { __asm jmp dword ptr[g_funcs + 1420] }
void __JMP_API DeleteTimerQueueTimer(void) { __asm jmp dword ptr[g_funcs + 1424] }
void __JMP_API LdrAddRefDll(void) { __asm jmp dword ptr[g_funcs + 1428] }
void __JMP_API CreateTimerQueueTimer(void) { __asm jmp dword ptr[g_funcs + 1432] }
void __JMP_API RegisterWaitForSingleObject(void) { __asm jmp dword ptr[g_funcs + 1436] }
void __JMP_API CreateNamedPipeW(void) { __asm jmp dword ptr[g_funcs + 1440] }
void __JMP_API SearchPathA(void) { __asm jmp dword ptr[g_funcs + 1444] }
void __JMP_API OpenFile(void) { __asm jmp dword ptr[g_funcs + 1448] }
void __JMP_API GetVolumeInformationA(void) { __asm jmp dword ptr[g_funcs + 1452] }
void __JMP_API QueryDosDeviceW(void) { __asm jmp dword ptr[g_funcs + 1456] }
void __JMP_API DefineDosDeviceW(void) { __asm jmp dword ptr[g_funcs + 1460] }
void __JMP_API GetCommTimeouts(void) { __asm jmp dword ptr[g_funcs + 1464] }
void __JMP_API FreeResource(void) { __asm jmp dword ptr[g_funcs + 1468] }
void __JMP_API CopyFileExW(void) { __asm jmp dword ptr[g_funcs + 1472] }
void __JMP_API CopyFileA(void) { __asm jmp dword ptr[g_funcs + 1476] }
void __JMP_API wcsstr(void) { __asm jmp dword ptr[g_funcs + 1480] }
void __JMP_API EnumUILanguagesW(void) { __asm jmp dword ptr[g_funcs + 1484] }
void __JMP_API AssignProcessToJobObject(void) { __asm jmp dword ptr[g_funcs + 1488] }
void __JMP_API ReadFileEx(void) { __asm jmp dword ptr[g_funcs + 1492] }
void __JMP_API GetHandleInformation(void) { __asm jmp dword ptr[g_funcs + 1496] }
void __JMP_API AddRefActCtx(void) { __asm jmp dword ptr[g_funcs + 1500] }
void __JMP_API GetVolumePathNameW(void) { __asm jmp dword ptr[g_funcs + 1504] }
void __JMP_API GetVolumePathNameA(void) { __asm jmp dword ptr[g_funcs + 1508] }
void __JMP_API SystemTimeToTzSpecificLocalTime(void) { __asm jmp dword ptr[g_funcs + 1512] }
void __JMP_API wcslen(void) { __asm jmp dword ptr[g_funcs + 1516] }
void __JMP_API SetConsoleTitleW(void) { __asm jmp dword ptr[g_funcs + 1520] }
void __JMP_API WriteFileGather(void) { __asm jmp dword ptr[g_funcs + 1524] }
void __JMP_API ReadFileScatter(void) { __asm jmp dword ptr[g_funcs + 1528] }
void __JMP_API EnumResourceLanguagesA(void) { __asm jmp dword ptr[g_funcs + 1532] }
void __JMP_API CreateTimerQueue(void) { __asm jmp dword ptr[g_funcs + 1536] }
void __JMP_API UnregisterWait(void) { __asm jmp dword ptr[g_funcs + 1540] }
void __JMP_API BindIoCompletionCallback(void) { __asm jmp dword ptr[g_funcs + 1544] }
void __JMP_API RtlSetIoCompletionCallback(void) { __asm jmp dword ptr[g_funcs + 1548] }
void __JMP_API PulseEvent(void) { __asm jmp dword ptr[g_funcs + 1552] }
void __JMP_API QueueUserAPC(void) { __asm jmp dword ptr[g_funcs + 1556] }
void __JMP_API DosPathToSessionPathW(void) { __asm jmp dword ptr[g_funcs + 1560] }
void __JMP_API GetLogicalDriveStringsA(void) { __asm jmp dword ptr[g_funcs + 1564] }
void __JMP_API SetPriorityClass(void) { __asm jmp dword ptr[g_funcs + 1568] }
void __JMP_API GlobalGetAtomNameW(void) { __asm jmp dword ptr[g_funcs + 1572] }
void __JMP_API WaitNamedPipeW(void) { __asm jmp dword ptr[g_funcs + 1576] }
void __JMP_API CloseProfileUserMapping(void) { __asm jmp dword ptr[g_funcs + 1580] }
void __JMP_API SetProcessShutdownParameters(void) { __asm jmp dword ptr[g_funcs + 1584] }
void __JMP_API OpenSemaphoreA(void) { __asm jmp dword ptr[g_funcs + 1588] }
void __JMP_API SetInformationJobObject(void) { __asm jmp dword ptr[g_funcs + 1592] }
void __JMP_API CreateJobObjectW(void) { __asm jmp dword ptr[g_funcs + 1596] }
void __JMP_API CancelWaitableTimer(void) { __asm jmp dword ptr[g_funcs + 1600] }
void __JMP_API CreateMailslotA(void) { __asm jmp dword ptr[g_funcs + 1604] }
void __JMP_API CreateMailslotW(void) { __asm jmp dword ptr[g_funcs + 1608] }
void __JMP_API SetMailslotInfo(void) { __asm jmp dword ptr[g_funcs + 1612] }
void __JMP_API DnsHostnameToComputerNameW(void) { __asm jmp dword ptr[g_funcs + 1616] }
void __JMP_API RtlDnsHostNameToComputerName(void) { __asm jmp dword ptr[g_funcs + 1620] }
void __JMP_API FindVolumeClose(void) { __asm jmp dword ptr[g_funcs + 1624] }
void __JMP_API FindNextVolumeW(void) { __asm jmp dword ptr[g_funcs + 1628] }
void __JMP_API FindFirstVolumeW(void) { __asm jmp dword ptr[g_funcs + 1632] }
void __JMP_API GetSystemTimeAdjustment(void) { __asm jmp dword ptr[g_funcs + 1636] }
void __JMP_API CreateNlsSecurityDescriptor(void) { __asm jmp dword ptr[g_funcs + 1640] }
void __JMP_API OpenDataFile(void) { __asm jmp dword ptr[g_funcs + 1644] }
void __JMP_API InitAtomTable(void) { __asm jmp dword ptr[g_funcs + 1648] }
void __JMP_API QueryInformationJobObject(void) { __asm jmp dword ptr[g_funcs + 1652] }
void __JMP_API RegisterWaitForSingleObjectEx(void) { __asm jmp dword ptr[g_funcs + 1656] }
void __JMP_API VirtualLock(void) { __asm jmp dword ptr[g_funcs + 1660] }
void __JMP_API SetTimerQueueTimer(void) { __asm jmp dword ptr[g_funcs + 1664] }
void __JMP_API BaseInitAppcompatCacheSupport(void) { __asm jmp dword ptr[g_funcs + 1668] }
void __JMP_API GetNumberFormatA(void) { __asm jmp dword ptr[g_funcs + 1672] }
void __JMP_API VerLanguageNameA(void) { __asm jmp dword ptr[g_funcs + 1676] }
void __JMP_API VerLanguageNameW(void) { __asm jmp dword ptr[g_funcs + 1680] }
void __JMP_API GetDiskFreeSpaceW(void) { __asm jmp dword ptr[g_funcs + 1684] }
void __JMP_API GetDiskFreeSpaceA(void) { __asm jmp dword ptr[g_funcs + 1688] }
void __JMP_API GetDiskFreeSpaceExA(void) { __asm jmp dword ptr[g_funcs + 1692] }
void __JMP_API SetProcessWorkingSetSize(void) { __asm jmp dword ptr[g_funcs + 1696] }
void __JMP_API GetDateFormatW(void) { __asm jmp dword ptr[g_funcs + 1700] }
void __JMP_API GetTimeFormatW(void) { __asm jmp dword ptr[g_funcs + 1704] }
void __JMP_API GetNumberFormatW(void) { __asm jmp dword ptr[g_funcs + 1708] }
void __JMP_API CreateVirtualBuffer(void) { __asm jmp dword ptr[g_funcs + 1712] }
void __JMP_API FreeVirtualBuffer(void) { __asm jmp dword ptr[g_funcs + 1716] }
void __JMP_API FormatMessageW(void) { __asm jmp dword ptr[g_funcs + 1720] }
void __JMP_API FindFirstChangeNotificationW(void) { __asm jmp dword ptr[g_funcs + 1724] }
void __JMP_API ExpandEnvironmentStringsW(void) { __asm jmp dword ptr[g_funcs + 1728] }
void __JMP_API FileTimeToDosDateTime(void) { __asm jmp dword ptr[g_funcs + 1732] }
void __JMP_API GetTempPathW(void) { __asm jmp dword ptr[g_funcs + 1736] }
void __JMP_API CreateEventA(void) { __asm jmp dword ptr[g_funcs + 1740] }
void __JMP_API LocalReAlloc(void) { __asm jmp dword ptr[g_funcs + 1744] }
void __JMP_API OpenProcess(void) { __asm jmp dword ptr[g_funcs + 1748] }
void __JMP_API QueueUserWorkItem(void) { __asm jmp dword ptr[g_funcs + 1752] }
void __JMP_API GetLogicalDrives(void) { __asm jmp dword ptr[g_funcs + 1756] }
void __JMP_API GlobalDeleteAtom(void) { __asm jmp dword ptr[g_funcs + 1760] }
void __JMP_API FindAtomA(void) { __asm jmp dword ptr[g_funcs + 1764] }
void __JMP_API lstrcmp(void) { __asm jmp dword ptr[g_funcs + 1768] }
void __JMP_API GetDiskFreeSpaceExW(void) { __asm jmp dword ptr[g_funcs + 1772] }
void __JMP_API RaiseException(void) { __asm jmp dword ptr[g_funcs + 1776] }
void __JMP_API FindActCtxSectionGuid(void) { __asm jmp dword ptr[g_funcs + 1780] }
void __JMP_API GlobalMemoryStatus(void) { __asm jmp dword ptr[g_funcs + 1784] }
void __JMP_API GlobalHandle(void) { __asm jmp dword ptr[g_funcs + 1788] }
void __JMP_API lstrcat(void) { __asm jmp dword ptr[g_funcs + 1792] }
void __JMP_API FindNextFileA(void) { __asm jmp dword ptr[g_funcs + 1796] }
void __JMP_API GlobalSize(void) { __asm jmp dword ptr[g_funcs + 1800] }
void __JMP_API LocalFileTimeToFileTime(void) { __asm jmp dword ptr[g_funcs + 1804] }
void __JMP_API FlushInstructionCache(void) { __asm jmp dword ptr[g_funcs + 1808] }
void __JMP_API _lclose(void) { __asm jmp dword ptr[g_funcs + 1812] }
void __JMP_API GlobalFindAtomW(void) { __asm jmp dword ptr[g_funcs + 1816] }
void __JMP_API SetFileAttributesA(void) { __asm jmp dword ptr[g_funcs + 1820] }
void __JMP_API GetOEMCP(void) { __asm jmp dword ptr[g_funcs + 1824] }
void __JMP_API GetSystemDefaultLangID(void) { __asm jmp dword ptr[g_funcs + 1828] }
void __JMP_API FindCloseChangeNotification(void) { __asm jmp dword ptr[g_funcs + 1832] }
void __JMP_API NlsGetCacheUpdateCount(void) { __asm jmp dword ptr[g_funcs + 1836] }
void __JMP_API IsBadHugeReadPtr(void) { __asm jmp dword ptr[g_funcs + 1840] }
void __JMP_API AreFileApisANSI(void) { __asm jmp dword ptr[g_funcs + 1844] }
void __JMP_API FlushViewOfFile(void) { __asm jmp dword ptr[g_funcs + 1848] }
void __JMP_API GetTempFileNameW(void) { __asm jmp dword ptr[g_funcs + 1852] }
void __JMP_API GetShortPathNameA(void) { __asm jmp dword ptr[g_funcs + 1856] }
void __JMP_API WritePrivateProfileStringA(void) { __asm jmp dword ptr[g_funcs + 1860] }
void __JMP_API GetTempPathA(void) { __asm jmp dword ptr[g_funcs + 1864] }
void __JMP_API MoveFileA(void) { __asm jmp dword ptr[g_funcs + 1868] }
void __JMP_API MoveFileWithProgressA(void) { __asm jmp dword ptr[g_funcs + 1872] }
void __JMP_API GetPrivateProfileSectionA(void) { __asm jmp dword ptr[g_funcs + 1876] }
void __JMP_API FindResourceExA(void) { __asm jmp dword ptr[g_funcs + 1880] }
void __JMP_API GlobalAddAtomA(void) { __asm jmp dword ptr[g_funcs + 1884] }
void __JMP_API GlobalFindAtomA(void) { __asm jmp dword ptr[g_funcs + 1888] }
void __JMP_API SetCurrentDirectoryA(void) { __asm jmp dword ptr[g_funcs + 1892] }
void __JMP_API HeapCompact(void) { __asm jmp dword ptr[g_funcs + 1896] }
void __JMP_API GetDateFormatA(void) { __asm jmp dword ptr[g_funcs + 1900] }
void __JMP_API GetTimeFormatA(void) { __asm jmp dword ptr[g_funcs + 1904] }
void __JMP_API GetPrivateProfileIntA(void) { __asm jmp dword ptr[g_funcs + 1908] }
void __JMP_API GetProfileIntA(void) { __asm jmp dword ptr[g_funcs + 1912] }
void __JMP_API _lcreat(void) { __asm jmp dword ptr[g_funcs + 1916] }
void __JMP_API SetFileApisToANSI(void) { __asm jmp dword ptr[g_funcs + 1920] }
void __JMP_API SignalObjectAndWait(void) { __asm jmp dword ptr[g_funcs + 1924] }
void __JMP_API GlobalFlags(void) { __asm jmp dword ptr[g_funcs + 1928] }
void __JMP_API ReplaceFile(void) { __asm jmp dword ptr[g_funcs + 1932] }
void __JMP_API RemoveDirectoryW(void) { __asm jmp dword ptr[g_funcs + 1936] }
void __JMP_API wcscpy(void) { __asm jmp dword ptr[g_funcs + 1940] }
void __JMP_API GetNativeSystemInfo(void) { __asm jmp dword ptr[g_funcs + 1944] }
void __JMP_API GetUserGeoID(void) { __asm jmp dword ptr[g_funcs + 1948] }
void __JMP_API _wtol(void) { __asm jmp dword ptr[g_funcs + 1952] }
void __JMP_API Beep(void) { __asm jmp dword ptr[g_funcs + 1956] }
void __JMP_API GetConsoleDisplayMode(void) { __asm jmp dword ptr[g_funcs + 1960] }
void __JMP_API EnumSystemLocalesA(void) { __asm jmp dword ptr[g_funcs + 1964] }
void __JMP_API EnumCalendarInfoA(void) { __asm jmp dword ptr[g_funcs + 1968] }
void __JMP_API BaseQueryModuleData(void) { __asm jmp dword ptr[g_funcs + 1972] }
void __JMP_API ConvertDefaultLocale(void) { __asm jmp dword ptr[g_funcs + 1976] }
void __JMP_API GetCPFileNameFromRegistry(void) { __asm jmp dword ptr[g_funcs + 1980] }
void __JMP_API EnumDateFormatsW(void) { __asm jmp dword ptr[g_funcs + 1984] }
void __JMP_API EnumTimeFormatsW(void) { __asm jmp dword ptr[g_funcs + 1988] }
void __JMP_API GetStringTypeA(void) { __asm jmp dword ptr[g_funcs + 1992] }
void __JMP_API _hwrite(void) { __asm jmp dword ptr[g_funcs + 1996] }
void __JMP_API LCMapStringA(void) { __asm jmp dword ptr[g_funcs + 2000] }
void __JMP_API GetCalendarInfoW(void) { __asm jmp dword ptr[g_funcs + 2004] }
void __JMP_API SetThreadExecutionState(void) { __asm jmp dword ptr[g_funcs + 2008] }
void __JMP_API HeapSetInformation(void) { __asm jmp dword ptr[g_funcs + 2012] }
void __JMP_API RtlSetHeapInformation(void) { __asm jmp dword ptr[g_funcs + 2016] }
void __JMP_API QueryMemoryResourceNotification(void) { __asm jmp dword ptr[g_funcs + 2020] }
void __JMP_API CreateMemoryResourceNotification(void) { __asm jmp dword ptr[g_funcs + 2024] }
void __JMP_API GetThreadContext(void) { __asm jmp dword ptr[g_funcs + 2028] }
void __JMP_API SuspendThread(void) { __asm jmp dword ptr[g_funcs + 2032] }
void __JMP_API ValidateLocale(void) { __asm jmp dword ptr[g_funcs + 2036] }
void __JMP_API SetUnhandledExceptionFilter(void) { __asm jmp dword ptr[g_funcs + 2040] }
void __JMP_API EnumResourceNamesW(void) { __asm jmp dword ptr[g_funcs + 2044] }
void __JMP_API SetLocalTime(void) { __asm jmp dword ptr[g_funcs + 2048] }
void __JMP_API LocalFlags(void) { __asm jmp dword ptr[g_funcs + 2052] }
void __JMP_API LocalHandle(void) { __asm jmp dword ptr[g_funcs + 2056] }
void __JMP_API wcscat(void) { __asm jmp dword ptr[g_funcs + 2060] }
void __JMP_API BackupSeek(void) { __asm jmp dword ptr[g_funcs + 2064] }
void __JMP_API BackupRead(void) { __asm jmp dword ptr[g_funcs + 2068] }
void __JMP_API BackupWrite(void) { __asm jmp dword ptr[g_funcs + 2072] }
void __JMP_API SetComputerNameW(void) { __asm jmp dword ptr[g_funcs + 2076] }
void __JMP_API SetComputerNameExW(void) { __asm jmp dword ptr[g_funcs + 2080] }
void __JMP_API SetComputerNameA(void) { __asm jmp dword ptr[g_funcs + 2084] }
void __JMP_API GetComputerNameExA(void) { __asm jmp dword ptr[g_funcs + 2088] }
void __JMP_API SetComputerNameExA(void) { __asm jmp dword ptr[g_funcs + 2092] }
void __JMP_API EnumerateLocalComputerNamesW(void) { __asm jmp dword ptr[g_funcs + 2096] }
void __JMP_API EnumerateLocalComputerNamesA(void) { __asm jmp dword ptr[g_funcs + 2100] }
void __JMP_API DnsHostnameToComputerNameA(void) { __asm jmp dword ptr[g_funcs + 2104] }
void __JMP_API AddLocalAlternateComputerNameW(void) { __asm jmp dword ptr[g_funcs + 2108] }
void __JMP_API AddLocalAlternateComputerNameA(void) { __asm jmp dword ptr[g_funcs + 2112] }
void __JMP_API RemoveLocalAlternateComputerNameW(void) { __asm jmp dword ptr[g_funcs + 2116] }
void __JMP_API RemoveLocalAlternateComputerNameA(void) { __asm jmp dword ptr[g_funcs + 2120] }
void __JMP_API SetLocalPrimaryComputerNameW(void) { __asm jmp dword ptr[g_funcs + 2124] }
void __JMP_API SetLocalPrimaryComputerNameA(void) { __asm jmp dword ptr[g_funcs + 2128] }
void __JMP_API LZCopy(void) { __asm jmp dword ptr[g_funcs + 2132] }
void __JMP_API CopyLZFile(void) { __asm jmp dword ptr[g_funcs + 2136] }
void __JMP_API SetTimeZoneInformation(void) { __asm jmp dword ptr[g_funcs + 2140] }
void __JMP_API SetSystemTimeAdjustment(void) { __asm jmp dword ptr[g_funcs + 2144] }
void __JMP_API _StringCatWorkerW(void) { __asm jmp dword ptr[g_funcs + 2148] }
void __JMP_API SetSystemTime(void) { __asm jmp dword ptr[g_funcs + 2152] }
void __JMP_API SetClientTimeZoneInformation(void) { __asm jmp dword ptr[g_funcs + 2156] }
void __JMP_API _StringCchCatW(void) { __asm jmp dword ptr[g_funcs + 2160] }
void __JMP_API TzSpecificLocalTimeToSystemTime(void) { __asm jmp dword ptr[g_funcs + 2164] }
void __JMP_API CheckRemoteDebuggerPresent(void) { __asm jmp dword ptr[g_funcs + 2168] }
void __JMP_API DebugBreak(void) { __asm jmp dword ptr[g_funcs + 2172] }
void __JMP_API OutputDebugStringA(void) { __asm jmp dword ptr[g_funcs + 2176] }
void __JMP_API DebugActiveProcess(void) { __asm jmp dword ptr[g_funcs + 2180] }
void __JMP_API DebugBreakProcess(void) { __asm jmp dword ptr[g_funcs + 2184] }
void __JMP_API DebugSetProcessKillOnExit(void) { __asm jmp dword ptr[g_funcs + 2188] }
void __JMP_API GetThreadSelectorEntry(void) { __asm jmp dword ptr[g_funcs + 2192] }
void __JMP_API OutputDebugStringW(void) { __asm jmp dword ptr[g_funcs + 2196] }
void __JMP_API WaitForDebugEvent(void) { __asm jmp dword ptr[g_funcs + 2200] }
void __JMP_API ContinueDebugEvent(void) { __asm jmp dword ptr[g_funcs + 2204] }
void __JMP_API DebugActiveProcessStop(void) { __asm jmp dword ptr[g_funcs + 2208] }
void __JMP_API CreateDirectoryExW(void) { __asm jmp dword ptr[g_funcs + 2212] }
void __JMP_API RemoveDirectoryA(void) { __asm jmp dword ptr[g_funcs + 2216] }
void __JMP_API CreateDirectoryExA(void) { __asm jmp dword ptr[g_funcs + 2220] }
void __JMP_API GlobalGetAtomNameA(void) { __asm jmp dword ptr[g_funcs + 2224] }
void __JMP_API GetAtomNameA(void) { __asm jmp dword ptr[g_funcs + 2228] }
void __JMP_API QueryWin31IniFilesMappedToRegistry(void) { __asm jmp dword ptr[g_funcs + 2232] }
void __JMP_API WritePrivateProfileSectionA(void) { __asm jmp dword ptr[g_funcs + 2236] }
void __JMP_API WritePrivateProfileSectionW(void) { __asm jmp dword ptr[g_funcs + 2240] }
void __JMP_API GetPrivateProfileSectionNamesW(void) { __asm jmp dword ptr[g_funcs + 2244] }
void __JMP_API GetPrivateProfileStructA(void) { __asm jmp dword ptr[g_funcs + 2248] }
void __JMP_API GetPrivateProfileStructW(void) { __asm jmp dword ptr[g_funcs + 2252] }
void __JMP_API WritePrivateProfileStructA(void) { __asm jmp dword ptr[g_funcs + 2256] }
void __JMP_API WritePrivateProfileStructW(void) { __asm jmp dword ptr[g_funcs + 2260] }
void __JMP_API WriteProfileStringA(void) { __asm jmp dword ptr[g_funcs + 2264] }
void __JMP_API GetProfileSectionA(void) { __asm jmp dword ptr[g_funcs + 2268] }
void __JMP_API WriteProfileSectionA(void) { __asm jmp dword ptr[g_funcs + 2272] }
void __JMP_API GetProfileSectionW(void) { __asm jmp dword ptr[g_funcs + 2276] }
void __JMP_API WriteProfileSectionW(void) { __asm jmp dword ptr[g_funcs + 2280] }
void __JMP_API DefineDosDeviceA(void) { __asm jmp dword ptr[g_funcs + 2284] }
void __JMP_API QueryDosDeviceA(void) { __asm jmp dword ptr[g_funcs + 2288] }
void __JMP_API FindFirstChangeNotificationA(void) { __asm jmp dword ptr[g_funcs + 2292] }
void __JMP_API FindFirstFileExA(void) { __asm jmp dword ptr[g_funcs + 2296] }
void __JMP_API WriteFileEx(void) { __asm jmp dword ptr[g_funcs + 2300] }
void __JMP_API SetFileValidData(void) { __asm jmp dword ptr[g_funcs + 2304] }
void __JMP_API SetFileShortNameW(void) { __asm jmp dword ptr[g_funcs + 2308] }
void __JMP_API SetFileShortNameA(void) { __asm jmp dword ptr[g_funcs + 2312] }
void __JMP_API PrivMoveFileIdentityW(void) { __asm jmp dword ptr[g_funcs + 2316] }
void __JMP_API GetCompressedFileSizeW(void) { __asm jmp dword ptr[g_funcs + 2320] }
void __JMP_API GetCompressedFileSizeA(void) { __asm jmp dword ptr[g_funcs + 2324] }
void __JMP_API MoveFileExA(void) { __asm jmp dword ptr[g_funcs + 2328] }
void __JMP_API ReplaceFileA(void) { __asm jmp dword ptr[g_funcs + 2332] }
void __JMP_API CopyFileExA(void) { __asm jmp dword ptr[g_funcs + 2336] }
void __JMP_API GetFirmwareEnvironmentVariableW(void) { __asm jmp dword ptr[g_funcs + 2340] }
void __JMP_API SetFirmwareEnvironmentVariableW(void) { __asm jmp dword ptr[g_funcs + 2344] }
void __JMP_API GetFirmwareEnvironmentVariableA(void) { __asm jmp dword ptr[g_funcs + 2348] }
void __JMP_API SetFirmwareEnvironmentVariableA(void) { __asm jmp dword ptr[g_funcs + 2352] }
void __JMP_API RegisterWowBaseHandlers(void) { __asm jmp dword ptr[g_funcs + 2356] }
void __JMP_API GlobalFix(void) { __asm jmp dword ptr[g_funcs + 2360] }
void __JMP_API GlobalUnfix(void) { __asm jmp dword ptr[g_funcs + 2364] }
void __JMP_API GlobalWire(void) { __asm jmp dword ptr[g_funcs + 2368] }
void __JMP_API GlobalUnWire(void) { __asm jmp dword ptr[g_funcs + 2372] }
void __JMP_API VirtualUnlock(void) { __asm jmp dword ptr[g_funcs + 2376] }
void __JMP_API AllocateUserPhysicalPages(void) { __asm jmp dword ptr[g_funcs + 2380] }
void __JMP_API FreeUserPhysicalPages(void) { __asm jmp dword ptr[g_funcs + 2384] }
void __JMP_API MapUserPhysicalPages(void) { __asm jmp dword ptr[g_funcs + 2388] }
void __JMP_API MapUserPhysicalPagesScatter(void) { __asm jmp dword ptr[g_funcs + 2392] }
void __JMP_API GetWriteWatch(void) { __asm jmp dword ptr[g_funcs + 2396] }
void __JMP_API ResetWriteWatch(void) { __asm jmp dword ptr[g_funcs + 2400] }
void __JMP_API _lopen(void) { __asm jmp dword ptr[g_funcs + 2404] }
void __JMP_API GlobalCompact(void) { __asm jmp dword ptr[g_funcs + 2408] }
void __JMP_API LocalShrink(void) { __asm jmp dword ptr[g_funcs + 2412] }
void __JMP_API HeapExtend(void) { __asm jmp dword ptr[g_funcs + 2416] }
void __JMP_API HeapCreateTagsW(void) { __asm jmp dword ptr[g_funcs + 2420] }
void __JMP_API HeapQueryTagW(void) { __asm jmp dword ptr[g_funcs + 2424] }
void __JMP_API HeapSummary(void) { __asm jmp dword ptr[g_funcs + 2428] }
void __JMP_API HeapUsage(void) { __asm jmp dword ptr[g_funcs + 2432] }
void __JMP_API HeapValidate(void) { __asm jmp dword ptr[g_funcs + 2436] }
void __JMP_API GetProcessHeaps(void) { __asm jmp dword ptr[g_funcs + 2440] }
void __JMP_API HeapLock(void) { __asm jmp dword ptr[g_funcs + 2444] }
void __JMP_API HeapUnlock(void) { __asm jmp dword ptr[g_funcs + 2448] }
void __JMP_API HeapWalk(void) { __asm jmp dword ptr[g_funcs + 2452] }
void __JMP_API HeapQueryInformation(void) { __asm jmp dword ptr[g_funcs + 2456] }
void __JMP_API GetMailslotInfo(void) { __asm jmp dword ptr[g_funcs + 2460] }
void __JMP_API ExtendVirtualBuffer(void) { __asm jmp dword ptr[g_funcs + 2464] }
void __JMP_API TrimVirtualBuffer(void) { __asm jmp dword ptr[g_funcs + 2468] }
void __JMP_API VirtualBufferExceptionHandler(void) { __asm jmp dword ptr[g_funcs + 2472] }
void __JMP_API SetSearchPathMode(void) { __asm jmp dword ptr[g_funcs + 2476] }
void __JMP_API SetDllDirectoryW(void) { __asm jmp dword ptr[g_funcs + 2480] }
void __JMP_API SetDllDirectoryA(void) { __asm jmp dword ptr[g_funcs + 2484] }
void __JMP_API GetDllDirectoryW(void) { __asm jmp dword ptr[g_funcs + 2488] }
void __JMP_API VerifyVersionInfoA(void) { __asm jmp dword ptr[g_funcs + 2492] }
void __JMP_API UTRegister(void) { __asm jmp dword ptr[g_funcs + 2496] }
void __JMP_API GetDllDirectoryA(void) { __asm jmp dword ptr[g_funcs + 2500] }
void __JMP_API GetModuleHandleExA(void) { __asm jmp dword ptr[g_funcs + 2504] }
void __JMP_API EnumResourceTypesA(void) { __asm jmp dword ptr[g_funcs + 2508] }
void __JMP_API EnumResourceNamesA(void) { __asm jmp dword ptr[g_funcs + 2512] }
void __JMP_API EnumResourceTypesW(void) { __asm jmp dword ptr[g_funcs + 2516] }
void __JMP_API EnumResourceLanguagesW(void) { __asm jmp dword ptr[g_funcs + 2520] }
void __JMP_API GetNamedPipeInfo(void) { __asm jmp dword ptr[g_funcs + 2524] }
void __JMP_API PeekNamedPipe(void) { __asm jmp dword ptr[g_funcs + 2528] }
void __JMP_API GetNamedPipeHandleStateW(void) { __asm jmp dword ptr[g_funcs + 2532] }
void __JMP_API CallNamedPipeW(void) { __asm jmp dword ptr[g_funcs + 2536] }
void __JMP_API WaitNamedPipeA(void) { __asm jmp dword ptr[g_funcs + 2540] }
void __JMP_API CreateNamedPipeA(void) { __asm jmp dword ptr[g_funcs + 2544] }
void __JMP_API GetNamedPipeHandleStateA(void) { __asm jmp dword ptr[g_funcs + 2548] }
void __JMP_API CallNamedPipeA(void) { __asm jmp dword ptr[g_funcs + 2552] }
void __JMP_API GetNumaHighestNodeNumber(void) { __asm jmp dword ptr[g_funcs + 2556] }
void __JMP_API GetNumaProcessorNode(void) { __asm jmp dword ptr[g_funcs + 2560] }
void __JMP_API GetNumaNodeProcessorMask(void) { __asm jmp dword ptr[g_funcs + 2564] }
void __JMP_API GetNumaProcessorMap(void) { __asm jmp dword ptr[g_funcs + 2568] }
void __JMP_API GetNumaAvailableMemory(void) { __asm jmp dword ptr[g_funcs + 2572] }
void __JMP_API GetNumaAvailableMemoryNode(void) { __asm jmp dword ptr[g_funcs + 2576] }
void __JMP_API NumaVirtualQueryNode(void) { __asm jmp dword ptr[g_funcs + 2580] }
void __JMP_API GetLogicalDriveStringsW(void) { __asm jmp dword ptr[g_funcs + 2584] }
void __JMP_API SetVolumeLabelW(void) { __asm jmp dword ptr[g_funcs + 2588] }
void __JMP_API CheckNameLegalDOS8Dot3W(void) { __asm jmp dword ptr[g_funcs + 2592] }
void __JMP_API GetTempFileNameA(void) { __asm jmp dword ptr[g_funcs + 2596] }
void __JMP_API SetVolumeLabelA(void) { __asm jmp dword ptr[g_funcs + 2600] }
void __JMP_API CheckNameLegalDOS8Dot3A(void) { __asm jmp dword ptr[g_funcs + 2604] }
void __JMP_API SetSystemPowerState(void) { __asm jmp dword ptr[g_funcs + 2608] }
void __JMP_API RequestWakeupLatency(void) { __asm jmp dword ptr[g_funcs + 2612] }
void __JMP_API GetDevicePowerState(void) { __asm jmp dword ptr[g_funcs + 2616] }
void __JMP_API IsSystemResumeAutomatic(void) { __asm jmp dword ptr[g_funcs + 2620] }
void __JMP_API RequestDeviceWakeup(void) { __asm jmp dword ptr[g_funcs + 2624] }
void __JMP_API CancelDeviceWakeupRequest(void) { __asm jmp dword ptr[g_funcs + 2628] }
void __JMP_API SetMessageWaitingIndicator(void) { __asm jmp dword ptr[g_funcs + 2632] }
void __JMP_API _StringCopyWorkerW(void) { __asm jmp dword ptr[g_funcs + 2636] }
void __JMP_API CreateProcessInternalWSecure(void) { __asm jmp dword ptr[g_funcs + 2640] }
void __JMP_API GetProcessId(void) { __asm jmp dword ptr[g_funcs + 2644] }
void __JMP_API FatalAppExitW(void) { __asm jmp dword ptr[g_funcs + 2648] }
void __JMP_API FatalAppExitA(void) { __asm jmp dword ptr[g_funcs + 2652] }
void __JMP_API FatalExit(void) { __asm jmp dword ptr[g_funcs + 2656] }
void __JMP_API GetSystemDEPPolicy(void) { __asm jmp dword ptr[g_funcs + 2660] }
void __JMP_API GetLogicalProcessorInformation(void) { __asm jmp dword ptr[g_funcs + 2664] }
void __JMP_API GetPriorityClass(void) { __asm jmp dword ptr[g_funcs + 2668] }
void __JMP_API GetProcessShutdownParameters(void) { __asm jmp dword ptr[g_funcs + 2672] }
void __JMP_API GetSystemTimes(void) { __asm jmp dword ptr[g_funcs + 2676] }
void __JMP_API GetProcessWorkingSetSize(void) { __asm jmp dword ptr[g_funcs + 2680] }
void __JMP_API SetProcessAffinityMask(void) { __asm jmp dword ptr[g_funcs + 2684] }
void __JMP_API SetProcessPriorityBoost(void) { __asm jmp dword ptr[g_funcs + 2688] }
void __JMP_API GetProcessPriorityBoost(void) { __asm jmp dword ptr[g_funcs + 2692] }
void __JMP_API GetProcessIoCounters(void) { __asm jmp dword ptr[g_funcs + 2696] }
void __JMP_API GetProcessHandleCount(void) { __asm jmp dword ptr[g_funcs + 2700] }
void __JMP_API SetProcessDEPPolicy(void) { __asm jmp dword ptr[g_funcs + 2704] }
void __JMP_API GetProcessDEPPolicy(void) { __asm jmp dword ptr[g_funcs + 2708] }
void __JMP_API GetSystemRegistryQuota(void) { __asm jmp dword ptr[g_funcs + 2712] }
//void __JMP_API _StringCatWorkerW(void) { __asm jmp dword ptr[g_funcs + 2716] }
void __JMP_API _StringCbCatW(void) { __asm jmp dword ptr[g_funcs + 2720] }
void __JMP_API WinExec(void) { __asm jmp dword ptr[g_funcs + 2724] }
void __JMP_API LoadModule(void) { __asm jmp dword ptr[g_funcs + 2728] }
void __JMP_API DosPathToSessionPathA(void) { __asm jmp dword ptr[g_funcs + 2732] }
void __JMP_API OpenWaitableTimerW(void) { __asm jmp dword ptr[g_funcs + 2736] }
void __JMP_API CreateWaitableTimerA(void) { __asm jmp dword ptr[g_funcs + 2740] }
void __JMP_API OpenWaitableTimerA(void) { __asm jmp dword ptr[g_funcs + 2744] }
void __JMP_API SetTermsrvAppInstallMode(void) { __asm jmp dword ptr[g_funcs + 2748] }
//void __JMP_API FID_conflict : _StringCbCatExW(void) { __asm jmp dword ptr[g_funcs + 2752] }
void __JMP_API _StringCatExWorkerW(void) { __asm jmp dword ptr[g_funcs + 2756] }
void __JMP_API _StringCbCatExW(void) { __asm jmp dword ptr[g_funcs + 2760] }
void __JMP_API SetThreadPriorityBoost(void) { __asm jmp dword ptr[g_funcs + 2764] }
void __JMP_API GetThreadPriorityBoost(void) { __asm jmp dword ptr[g_funcs + 2768] }
void __JMP_API SetThreadContext(void) { __asm jmp dword ptr[g_funcs + 2772] }
void __JMP_API GetThreadTimes(void) { __asm jmp dword ptr[g_funcs + 2776] }
void __JMP_API GetThreadIOPendingFlag(void) { __asm jmp dword ptr[g_funcs + 2780] }
void __JMP_API SetThreadIdealProcessor(void) { __asm jmp dword ptr[g_funcs + 2784] }
void __JMP_API DeleteTimerQueueEx(void) { __asm jmp dword ptr[g_funcs + 2788] }
void __JMP_API DeleteTimerQueue(void) { __asm jmp dword ptr[g_funcs + 2792] }
void __JMP_API CancelTimerQueueTimer(void) { __asm jmp dword ptr[g_funcs + 2796] }
void __JMP_API Heap32ListFirst(void) { __asm jmp dword ptr[g_funcs + 2800] }
void __JMP_API Heap32ListNext(void) { __asm jmp dword ptr[g_funcs + 2804] }
void __JMP_API Heap32First(void) { __asm jmp dword ptr[g_funcs + 2808] }
void __JMP_API Heap32Next(void) { __asm jmp dword ptr[g_funcs + 2812] }
void __JMP_API Toolhelp32ReadProcessMemory(void) { __asm jmp dword ptr[g_funcs + 2816] }
void __JMP_API Process32FirstW(void) { __asm jmp dword ptr[g_funcs + 2820] }
void __JMP_API Process32First(void) { __asm jmp dword ptr[g_funcs + 2824] }
void __JMP_API Process32NextW(void) { __asm jmp dword ptr[g_funcs + 2828] }
void __JMP_API Process32Next(void) { __asm jmp dword ptr[g_funcs + 2832] }
void __JMP_API Thread32First(void) { __asm jmp dword ptr[g_funcs + 2836] }
void __JMP_API Thread32Next(void) { __asm jmp dword ptr[g_funcs + 2840] }
void __JMP_API Module32FirstW(void) { __asm jmp dword ptr[g_funcs + 2844] }
void __JMP_API Module32First(void) { __asm jmp dword ptr[g_funcs + 2848] }
void __JMP_API Module32NextW(void) { __asm jmp dword ptr[g_funcs + 2852] }
void __JMP_API Module32Next(void) { __asm jmp dword ptr[g_funcs + 2856] }
void __JMP_API CreateToolhelp32Snapshot(void) { __asm jmp dword ptr[g_funcs + 2860] }
void __JMP_API GetExpandedNameA(void) { __asm jmp dword ptr[g_funcs + 2864] }
void __JMP_API GetExpandedNameW(void) { __asm jmp dword ptr[g_funcs + 2868] }
void __JMP_API LZInit(void) { __asm jmp dword ptr[g_funcs + 2872] }
void __JMP_API LZCreateFileW(void) { __asm jmp dword ptr[g_funcs + 2876] }
void __JMP_API LZOpenFileA(void) { __asm jmp dword ptr[g_funcs + 2880] }
void __JMP_API LZOpenFileW(void) { __asm jmp dword ptr[g_funcs + 2884] }
void __JMP_API LZSeek(void) { __asm jmp dword ptr[g_funcs + 2888] }
void __JMP_API LZRead(void) { __asm jmp dword ptr[g_funcs + 2892] }
void __JMP_API LZCloseFile(void) { __asm jmp dword ptr[g_funcs + 2896] }
void __JMP_API LZClose(void) { __asm jmp dword ptr[g_funcs + 2900] }
void __JMP_API ClearCommError(void) { __asm jmp dword ptr[g_funcs + 2904] }
void __JMP_API SetupComm(void) { __asm jmp dword ptr[g_funcs + 2908] }
void __JMP_API EscapeCommFunction(void) { __asm jmp dword ptr[g_funcs + 2912] }
void __JMP_API GetCommMask(void) { __asm jmp dword ptr[g_funcs + 2916] }
void __JMP_API GetCommModemStatus(void) { __asm jmp dword ptr[g_funcs + 2920] }
void __JMP_API GetCommProperties(void) { __asm jmp dword ptr[g_funcs + 2924] }
void __JMP_API GetCommState(void) { __asm jmp dword ptr[g_funcs + 2928] }
void __JMP_API PurgeComm(void) { __asm jmp dword ptr[g_funcs + 2932] }
void __JMP_API SetCommBreak(void) { __asm jmp dword ptr[g_funcs + 2936] }
void __JMP_API SetCommMask(void) { __asm jmp dword ptr[g_funcs + 2940] }
void __JMP_API SetCommState(void) { __asm jmp dword ptr[g_funcs + 2944] }
void __JMP_API SetCommTimeouts(void) { __asm jmp dword ptr[g_funcs + 2948] }
void __JMP_API TransmitCommChar(void) { __asm jmp dword ptr[g_funcs + 2952] }
void __JMP_API WaitCommEvent(void) { __asm jmp dword ptr[g_funcs + 2956] }
void __JMP_API CommConfigDialogW(void) { __asm jmp dword ptr[g_funcs + 2960] }
void __JMP_API CommConfigDialogA(void) { __asm jmp dword ptr[g_funcs + 2964] }
void __JMP_API GetDefaultCommConfigW(void) { __asm jmp dword ptr[g_funcs + 2968] }
void __JMP_API GetDefaultCommConfigA(void) { __asm jmp dword ptr[g_funcs + 2972] }
void __JMP_API SetDefaultCommConfigW(void) { __asm jmp dword ptr[g_funcs + 2976] }
void __JMP_API SetDefaultCommConfigA(void) { __asm jmp dword ptr[g_funcs + 2980] }
void __JMP_API ClearCommBreak(void) { __asm jmp dword ptr[g_funcs + 2984] }
void __JMP_API GetCommConfig(void) { __asm jmp dword ptr[g_funcs + 2988] }
void __JMP_API SetCommConfig(void) { __asm jmp dword ptr[g_funcs + 2992] }
void __JMP_API GetNextVDMCommand(void) { __asm jmp dword ptr[g_funcs + 2996] }
void __JMP_API ExitVDM(void) { __asm jmp dword ptr[g_funcs + 3000] }
void __JMP_API SetVDMCurrentDirectories(void) { __asm jmp dword ptr[g_funcs + 3004] }
void __JMP_API GetVDMCurrentDirectories(void) { __asm jmp dword ptr[g_funcs + 3008] }
void __JMP_API RegisterWowExec(void) { __asm jmp dword ptr[g_funcs + 3012] }
void __JMP_API GetBinaryTypeW(void) { __asm jmp dword ptr[g_funcs + 3016] }
void __JMP_API VDMOperationStarted(void) { __asm jmp dword ptr[g_funcs + 3020] }
void __JMP_API GetBinaryType(void) { __asm jmp dword ptr[g_funcs + 3024] }
void __JMP_API GetLongPathNameA(void) { __asm jmp dword ptr[g_funcs + 3028] }
void __JMP_API FindFirstVolumeMountPointW(void) { __asm jmp dword ptr[g_funcs + 3032] }
void __JMP_API FindNextVolumeMountPointW(void) { __asm jmp dword ptr[g_funcs + 3036] }
void __JMP_API SetVolumeMountPointW(void) { __asm jmp dword ptr[g_funcs + 3040] }
void __JMP_API DeleteVolumeMountPointW(void) { __asm jmp dword ptr[g_funcs + 3044] }
void __JMP_API FindNextVolumeA(void) { __asm jmp dword ptr[g_funcs + 3048] }
void __JMP_API FindFirstVolumeMountPointA(void) { __asm jmp dword ptr[g_funcs + 3052] }
void __JMP_API FindNextVolumeMountPointA(void) { __asm jmp dword ptr[g_funcs + 3056] }
void __JMP_API GetVolumeNameForVolumeMountPointA(void) { __asm jmp dword ptr[g_funcs + 3060] }
void __JMP_API SetVolumeMountPointA(void) { __asm jmp dword ptr[g_funcs + 3064] }
void __JMP_API DeleteVolumeMountPointA(void) { __asm jmp dword ptr[g_funcs + 3068] }
void __JMP_API GetVolumePathNamesForVolumeNameA(void) { __asm jmp dword ptr[g_funcs + 3072] }
void __JMP_API FindFirstVolumeA(void) { __asm jmp dword ptr[g_funcs + 3076] }
void __JMP_API BuildCommDCBAndTimeoutsA(void) { __asm jmp dword ptr[g_funcs + 3080] }
void __JMP_API BuildCommDCBA(void) { __asm jmp dword ptr[g_funcs + 3084] }
void __JMP_API BuildCommDCBAndTimeoutsW(void) { __asm jmp dword ptr[g_funcs + 3088] }
void __JMP_API BuildCommDCBW(void) { __asm jmp dword ptr[g_funcs + 3092] }
void __JMP_API SetTapePosition(void) { __asm jmp dword ptr[g_funcs + 3096] }
void __JMP_API GetTapePosition(void) { __asm jmp dword ptr[g_funcs + 3100] }
void __JMP_API PrepareTape(void) { __asm jmp dword ptr[g_funcs + 3104] }
void __JMP_API EraseTape(void) { __asm jmp dword ptr[g_funcs + 3108] }
void __JMP_API CreateTapePartition(void) { __asm jmp dword ptr[g_funcs + 3112] }
void __JMP_API WriteTapemark(void) { __asm jmp dword ptr[g_funcs + 3116] }
void __JMP_API GetTapeParameters(void) { __asm jmp dword ptr[g_funcs + 3120] }
void __JMP_API SetTapeParameters(void) { __asm jmp dword ptr[g_funcs + 3124] }
void __JMP_API GetTapeStatus(void) { __asm jmp dword ptr[g_funcs + 3128] }
void __JMP_API OpenJobObjectW(void) { __asm jmp dword ptr[g_funcs + 3132] }
void __JMP_API TerminateJobObject(void) { __asm jmp dword ptr[g_funcs + 3136] }
void __JMP_API IsProcessInJob(void) { __asm jmp dword ptr[g_funcs + 3140] }
void __JMP_API CreateJobSet(void) { __asm jmp dword ptr[g_funcs + 3144] }
void __JMP_API CreateJobObjectA(void) { __asm jmp dword ptr[g_funcs + 3148] }
void __JMP_API OpenJobObjectA(void) { __asm jmp dword ptr[g_funcs + 3152] }
void __JMP_API CreateHardLinkW(void) { __asm jmp dword ptr[g_funcs + 3156] }
void __JMP_API CreateHardLinkA(void) { __asm jmp dword ptr[g_funcs + 3160] }
void __JMP_API GetHandleContext(void) { __asm jmp dword ptr[g_funcs + 3164] }
void __JMP_API CreateSocketHandle(void) { __asm jmp dword ptr[g_funcs + 3168] }
void __JMP_API ZombifyActCtx(void) { __asm jmp dword ptr[g_funcs + 3172] }
void __JMP_API CreateActCtxA(void) { __asm jmp dword ptr[g_funcs + 3176] }
void __JMP_API FindActCtxSectionStringA(void) { __asm jmp dword ptr[g_funcs + 3180] }
void __JMP_API SetComPlusPackageInstallStatus(void) { __asm jmp dword ptr[g_funcs + 3184] }
void __JMP_API GetComPlusPackageInstallStatus(void) { __asm jmp dword ptr[g_funcs + 3188] }
void __JMP_API BaseFlushAppcompatCache(void) { __asm jmp dword ptr[g_funcs + 3192] }
void __JMP_API BaseDumpAppcompatCache(void) { __asm jmp dword ptr[g_funcs + 3196] }
void __JMP_API BaseCleanupAppcompatCache(void) { __asm jmp dword ptr[g_funcs + 3200] }
void __JMP_API BaseCleanupAppcompatCacheSupport(void) { __asm jmp dword ptr[g_funcs + 3204] }
void __JMP_API UpdateResourceW(void) { __asm jmp dword ptr[g_funcs + 3208] }
void __JMP_API UpdateResourceA(void) { __asm jmp dword ptr[g_funcs + 3212] }
void __JMP_API EndUpdateResourceW(void) { __asm jmp dword ptr[g_funcs + 3216] }
void __JMP_API EndUpdateResourceA(void) { __asm jmp dword ptr[g_funcs + 3220] }
void __JMP_API BeginUpdateResourceW(void) { __asm jmp dword ptr[g_funcs + 3224] }
void __JMP_API BeginUpdateResourceA(void) { __asm jmp dword ptr[g_funcs + 3228] }
void __JMP_API GetConsoleAliasW(void) { __asm jmp dword ptr[g_funcs + 3232] }
void __JMP_API GetConsoleAliasA(void) { __asm jmp dword ptr[g_funcs + 3236] }
void __JMP_API GetConsoleAliasesLengthW(void) { __asm jmp dword ptr[g_funcs + 3240] }
void __JMP_API GetConsoleAliasesLengthA(void) { __asm jmp dword ptr[g_funcs + 3244] }
void __JMP_API GetConsoleAliasExesLengthW(void) { __asm jmp dword ptr[g_funcs + 3248] }
void __JMP_API GetConsoleAliasExesLengthA(void) { __asm jmp dword ptr[g_funcs + 3252] }
void __JMP_API GetConsoleAliasesW(void) { __asm jmp dword ptr[g_funcs + 3256] }
void __JMP_API GetConsoleAliasesA(void) { __asm jmp dword ptr[g_funcs + 3260] }
void __JMP_API GetConsoleAliasExesW(void) { __asm jmp dword ptr[g_funcs + 3264] }
void __JMP_API GetConsoleAliasExesA(void) { __asm jmp dword ptr[g_funcs + 3268] }
void __JMP_API ExpungeConsoleCommandHistoryW(void) { __asm jmp dword ptr[g_funcs + 3272] }
void __JMP_API ExpungeConsoleCommandHistoryA(void) { __asm jmp dword ptr[g_funcs + 3276] }
void __JMP_API SetConsoleNumberOfCommandsW(void) { __asm jmp dword ptr[g_funcs + 3280] }
void __JMP_API SetConsoleNumberOfCommandsA(void) { __asm jmp dword ptr[g_funcs + 3284] }
void __JMP_API GetConsoleCommandHistoryLengthW(void) { __asm jmp dword ptr[g_funcs + 3288] }
void __JMP_API GetConsoleCommandHistoryLengthA(void) { __asm jmp dword ptr[g_funcs + 3292] }
void __JMP_API GetConsoleCommandHistoryW(void) { __asm jmp dword ptr[g_funcs + 3296] }
void __JMP_API GetConsoleCommandHistoryA(void) { __asm jmp dword ptr[g_funcs + 3300] }
void __JMP_API SetConsoleCommandHistoryMode(void) { __asm jmp dword ptr[g_funcs + 3304] }
void __JMP_API GetConsoleTitleA(void) { __asm jmp dword ptr[g_funcs + 3308] }
void __JMP_API SetConsoleTitleA(void) { __asm jmp dword ptr[g_funcs + 3312] }
void __JMP_API GetConsoleInputExeNameW(void) { __asm jmp dword ptr[g_funcs + 3316] }
void __JMP_API AddConsoleAliasW(void) { __asm jmp dword ptr[g_funcs + 3320] }
void __JMP_API AddConsoleAliasA(void) { __asm jmp dword ptr[g_funcs + 3324] }
void __JMP_API GetConsoleInputExeNameA(void) { __asm jmp dword ptr[g_funcs + 3328] }
void __JMP_API SetConsoleInputExeNameA(void) { __asm jmp dword ptr[g_funcs + 3332] }
void __JMP_API FreeConsole(void) { __asm jmp dword ptr[g_funcs + 3336] }
void __JMP_API AllocConsole(void) { __asm jmp dword ptr[g_funcs + 3340] }
void __JMP_API AttachConsole(void) { __asm jmp dword ptr[g_funcs + 3344] }
void __JMP_API GetConsoleInputWaitHandle(void) { __asm jmp dword ptr[g_funcs + 3348] }
void __JMP_API ReadConsoleA(void) { __asm jmp dword ptr[g_funcs + 3352] }
void __JMP_API ReadConsoleW(void) { __asm jmp dword ptr[g_funcs + 3356] }
void __JMP_API RegisterConsoleVDM(void) { __asm jmp dword ptr[g_funcs + 3360] }
void __JMP_API GetConsoleHardwareState(void) { __asm jmp dword ptr[g_funcs + 3364] }
void __JMP_API SetConsoleHardwareState(void) { __asm jmp dword ptr[g_funcs + 3368] }
void __JMP_API SetConsoleKeyShortcuts(void) { __asm jmp dword ptr[g_funcs + 3372] }
void __JMP_API SetConsoleMenuClose(void) { __asm jmp dword ptr[g_funcs + 3376] }
void __JMP_API WriteConsoleInputVDMA(void) { __asm jmp dword ptr[g_funcs + 3380] }
void __JMP_API WriteConsoleInputVDMW(void) { __asm jmp dword ptr[g_funcs + 3384] }
void __JMP_API SetConsoleCursor(void) { __asm jmp dword ptr[g_funcs + 3388] }
void __JMP_API ShowConsoleCursor(void) { __asm jmp dword ptr[g_funcs + 3392] }
void __JMP_API ConsoleMenuControl(void) { __asm jmp dword ptr[g_funcs + 3396] }
void __JMP_API SetConsoleDisplayMode(void) { __asm jmp dword ptr[g_funcs + 3400] }
void __JMP_API SetConsolePalette(void) { __asm jmp dword ptr[g_funcs + 3404] }
void __JMP_API WriteConsoleInputA(void) { __asm jmp dword ptr[g_funcs + 3408] }
void __JMP_API WriteConsoleInputW(void) { __asm jmp dword ptr[g_funcs + 3412] }
void __JMP_API ReadConsoleOutputW(void) { __asm jmp dword ptr[g_funcs + 3416] }
void __JMP_API ReadConsoleOutputA(void) { __asm jmp dword ptr[g_funcs + 3420] }
void __JMP_API WriteConsoleOutputW(void) { __asm jmp dword ptr[g_funcs + 3424] }
void __JMP_API WriteConsoleOutputA(void) { __asm jmp dword ptr[g_funcs + 3428] }
void __JMP_API ReadConsoleOutputCharacterA(void) { __asm jmp dword ptr[g_funcs + 3432] }
void __JMP_API ReadConsoleOutputCharacterW(void) { __asm jmp dword ptr[g_funcs + 3436] }
void __JMP_API ReadConsoleOutputAttribute(void) { __asm jmp dword ptr[g_funcs + 3440] }
void __JMP_API WriteConsoleOutputCharacterA(void) { __asm jmp dword ptr[g_funcs + 3444] }
void __JMP_API WriteConsoleOutputCharacterW(void) { __asm jmp dword ptr[g_funcs + 3448] }
void __JMP_API WriteConsoleOutputAttribute(void) { __asm jmp dword ptr[g_funcs + 3452] }
void __JMP_API FillConsoleOutputCharacterA(void) { __asm jmp dword ptr[g_funcs + 3456] }
void __JMP_API FillConsoleOutputCharacterW(void) { __asm jmp dword ptr[g_funcs + 3460] }
void __JMP_API FillConsoleOutputAttribute(void) { __asm jmp dword ptr[g_funcs + 3464] }
void __JMP_API CreateConsoleScreenBuffer(void) { __asm jmp dword ptr[g_funcs + 3468] }
void __JMP_API InvalidateConsoleDIBits(void) { __asm jmp dword ptr[g_funcs + 3472] }
void __JMP_API PeekConsoleInputA(void) { __asm jmp dword ptr[g_funcs + 3476] }
void __JMP_API PeekConsoleInputW(void) { __asm jmp dword ptr[g_funcs + 3480] }
void __JMP_API ReadConsoleInputA(void) { __asm jmp dword ptr[g_funcs + 3484] }
void __JMP_API ReadConsoleInputW(void) { __asm jmp dword ptr[g_funcs + 3488] }
void __JMP_API ReadConsoleInputExA(void) { __asm jmp dword ptr[g_funcs + 3492] }
void __JMP_API ReadConsoleInputExW(void) { __asm jmp dword ptr[g_funcs + 3496] }
void __JMP_API GetConsoleCursorInfo(void) { __asm jmp dword ptr[g_funcs + 3500] }
void __JMP_API GetConsoleSelectionInfo(void) { __asm jmp dword ptr[g_funcs + 3504] }
void __JMP_API GetNumberOfConsoleMouseButtons(void) { __asm jmp dword ptr[g_funcs + 3508] }
void __JMP_API GetConsoleFontInfo(void) { __asm jmp dword ptr[g_funcs + 3512] }
void __JMP_API GetConsoleFontSize(void) { __asm jmp dword ptr[g_funcs + 3516] }
void __JMP_API GetCurrentConsoleFont(void) { __asm jmp dword ptr[g_funcs + 3520] }
void __JMP_API GenerateConsoleCtrlEvent(void) { __asm jmp dword ptr[g_funcs + 3524] }
void __JMP_API SetConsoleActiveScreenBuffer(void) { __asm jmp dword ptr[g_funcs + 3528] }
void __JMP_API FlushConsoleInputBuffer(void) { __asm jmp dword ptr[g_funcs + 3532] }
void __JMP_API SetConsoleScreenBufferSize(void) { __asm jmp dword ptr[g_funcs + 3536] }
void __JMP_API SetConsoleCursorPosition(void) { __asm jmp dword ptr[g_funcs + 3540] }
void __JMP_API SetConsoleCursorInfo(void) { __asm jmp dword ptr[g_funcs + 3544] }
void __JMP_API SetConsoleWindowInfo(void) { __asm jmp dword ptr[g_funcs + 3548] }
void __JMP_API ScrollConsoleScreenBufferA(void) { __asm jmp dword ptr[g_funcs + 3552] }
void __JMP_API ScrollConsoleScreenBufferW(void) { __asm jmp dword ptr[g_funcs + 3556] }
void __JMP_API SetConsoleTextAttribute(void) { __asm jmp dword ptr[g_funcs + 3560] }
void __JMP_API SetConsoleFont(void) { __asm jmp dword ptr[g_funcs + 3564] }
void __JMP_API SetConsoleIcon(void) { __asm jmp dword ptr[g_funcs + 3568] }
void __JMP_API GetConsoleCP(void) { __asm jmp dword ptr[g_funcs + 3572] }
void __JMP_API SetConsoleCP(void) { __asm jmp dword ptr[g_funcs + 3576] }
void __JMP_API SetConsoleOutputCP(void) { __asm jmp dword ptr[g_funcs + 3580] }
void __JMP_API GetConsoleKeyboardLayoutNameA(void) { __asm jmp dword ptr[g_funcs + 3584] }
void __JMP_API GetConsoleKeyboardLayoutNameW(void) { __asm jmp dword ptr[g_funcs + 3588] }
void __JMP_API GetConsoleWindow(void) { __asm jmp dword ptr[g_funcs + 3592] }
void __JMP_API GetConsoleProcessList(void) { __asm jmp dword ptr[g_funcs + 3596] }
void __JMP_API GetNumberOfConsoleFonts(void) { __asm jmp dword ptr[g_funcs + 3600] }
void __JMP_API GetNumberOfConsoleInputEvents(void) { __asm jmp dword ptr[g_funcs + 3604] }
void __JMP_API GetLargestConsoleWindowSize(void) { __asm jmp dword ptr[g_funcs + 3608] }
void __JMP_API SetConsoleLocalEUDC(void) { __asm jmp dword ptr[g_funcs + 3612] }
void __JMP_API SetConsoleCursorMode(void) { __asm jmp dword ptr[g_funcs + 3616] }
void __JMP_API GetConsoleCursorMode(void) { __asm jmp dword ptr[g_funcs + 3620] }
void __JMP_API RegisterConsoleOS2(void) { __asm jmp dword ptr[g_funcs + 3624] }
void __JMP_API SetConsoleOS2OemFormat(void) { __asm jmp dword ptr[g_funcs + 3628] }
void __JMP_API RegisterConsoleIME(void) { __asm jmp dword ptr[g_funcs + 3632] }
void __JMP_API UnregisterConsoleIME(void) { __asm jmp dword ptr[g_funcs + 3636] }
void __JMP_API GetConsoleNlsMode(void) { __asm jmp dword ptr[g_funcs + 3640] }
void __JMP_API SetConsoleNlsMode(void) { __asm jmp dword ptr[g_funcs + 3644] }
void __JMP_API GetConsoleCharType(void) { __asm jmp dword ptr[g_funcs + 3648] }
void __JMP_API SetLastConsoleEventActive(void) { __asm jmp dword ptr[g_funcs + 3652] }
void __JMP_API VDMConsoleOperation(void) { __asm jmp dword ptr[g_funcs + 3656] }
void __JMP_API EnumCalendarInfoExA(void) { __asm jmp dword ptr[g_funcs + 3660] }
void __JMP_API EnumTimeFormatsA(void) { __asm jmp dword ptr[g_funcs + 3664] }
void __JMP_API EnumDateFormatsA(void) { __asm jmp dword ptr[g_funcs + 3668] }
void __JMP_API EnumDateFormatsExA(void) { __asm jmp dword ptr[g_funcs + 3672] }
void __JMP_API EnumSystemLanguageGroupsA(void) { __asm jmp dword ptr[g_funcs + 3676] }
void __JMP_API EnumLanguageGroupLocalesA(void) { __asm jmp dword ptr[g_funcs + 3680] }
void __JMP_API EnumUILanguagesA(void) { __asm jmp dword ptr[g_funcs + 3684] }
void __JMP_API EnumSystemCodePagesA(void) { __asm jmp dword ptr[g_funcs + 3688] }
void __JMP_API GetGeoInfoA(void) { __asm jmp dword ptr[g_funcs + 3692] }
void __JMP_API SetLocaleInfoA(void) { __asm jmp dword ptr[g_funcs + 3696] }
void __JMP_API GetCalendarInfoA(void) { __asm jmp dword ptr[g_funcs + 3700] }
void __JMP_API SetCalendarInfoA(void) { __asm jmp dword ptr[g_funcs + 3704] }
void __JMP_API GetCurrencyFormatA(void) { __asm jmp dword ptr[g_funcs + 3708] }
void __JMP_API FoldStringA(void) { __asm jmp dword ptr[g_funcs + 3712] }
void __JMP_API GetCPInfoExA(void) { __asm jmp dword ptr[g_funcs + 3716] }
void __JMP_API GetStringTypeExA(void) { __asm jmp dword ptr[g_funcs + 3720] }
void __JMP_API NlsResetProcessLocale(void) { __asm jmp dword ptr[g_funcs + 3724] }
void __JMP_API IsValidLanguageGroup(void) { __asm jmp dword ptr[g_funcs + 3728] }
void __JMP_API IsValidUILanguage(void) { __asm jmp dword ptr[g_funcs + 3732] }
void __JMP_API SetCalendarInfoW(void) { __asm jmp dword ptr[g_funcs + 3736] }
void __JMP_API SetLocaleInfoW(void) { __asm jmp dword ptr[g_funcs + 3740] }
void __JMP_API EnumSystemLanguageGroupsW(void) { __asm jmp dword ptr[g_funcs + 3744] }
void __JMP_API EnumLanguageGroupLocalesW(void) { __asm jmp dword ptr[g_funcs + 3748] }
void __JMP_API EnumSystemLocalesW(void) { __asm jmp dword ptr[g_funcs + 3752] }
void __JMP_API EnumSystemCodePagesW(void) { __asm jmp dword ptr[g_funcs + 3756] }
void __JMP_API EnumCalendarInfoW(void) { __asm jmp dword ptr[g_funcs + 3760] }
void __JMP_API EnumCalendarInfoExW(void) { __asm jmp dword ptr[g_funcs + 3764] }
void __JMP_API EnumDateFormatsExW(void) { __asm jmp dword ptr[g_funcs + 3768] }
void __JMP_API GetGeoInfoW(void) { __asm jmp dword ptr[g_funcs + 3772] }
void __JMP_API EnumSystemGeoID(void) { __asm jmp dword ptr[g_funcs + 3776] }
void __JMP_API SetUserGeoID(void) { __asm jmp dword ptr[g_funcs + 3780] }
void __JMP_API FoldStringW(void) { __asm jmp dword ptr[g_funcs + 3784] }
void __JMP_API SetCPGlobal(void) { __asm jmp dword ptr[g_funcs + 3788] }
void __JMP_API GetCPInfoExW(void) { __asm jmp dword ptr[g_funcs + 3792] }
void __JMP_API IsDBCSLeadByteEx(void) { __asm jmp dword ptr[g_funcs + 3796] }
void __JMP_API GetDefaultSortkeySize(void) { __asm jmp dword ptr[g_funcs + 3800] }
void __JMP_API GetLinguistLangSize(void) { __asm jmp dword ptr[g_funcs + 3804] }
void __JMP_API ValidateLCType(void) { __asm jmp dword ptr[g_funcs + 3808] }
void __JMP_API GetCurrencyFormatW(void) { __asm jmp dword ptr[g_funcs + 3812] }
void __JMP_API DelayLoadFailureHook(void) { __asm jmp dword ptr[g_funcs + 3816] }
void __JMP_API UTUnRegister(void) { __asm jmp dword ptr[g_funcs + 3820] }
void __JMP_API _Shell_GetImageLists(void) { __asm jmp dword ptr[g_funcs + 3824] }
void __JMP_API LZStart(void) { __asm jmp dword ptr[g_funcs + 3828] }
void __JMP_API SetConsoleMaximumWindowSize(void) { __asm jmp dword ptr[g_funcs + 3832] }
void __JMP_API _RegQueryValueExW(void) { __asm jmp dword ptr[g_funcs + 3836] }
void __JMP_API wcschr(void) { __asm jmp dword ptr[g_funcs + 3840] }
void __JMP_API DbgBreakPoint(void) { __asm jmp dword ptr[g_funcs + 3844] }
void __JMP_API DbgPrint(void) { __asm jmp dword ptr[g_funcs + 3848] }
void __JMP_API DbgUiDebugActiveProcess(void) { __asm jmp dword ptr[g_funcs + 3852] }
void __JMP_API DbgUiConnectToDbg(void) { __asm jmp dword ptr[g_funcs + 3856] }
void __JMP_API DbgUiIssueRemoteBreakin(void) { __asm jmp dword ptr[g_funcs + 3860] }
void __JMP_API NtSetInformationDebugObject(void) { __asm jmp dword ptr[g_funcs + 3864] }
void __JMP_API DbgUiGetThreadDebugObject(void) { __asm jmp dword ptr[g_funcs + 3868] }
void __JMP_API DbgUiConvertStateChangeStructure(void) { __asm jmp dword ptr[g_funcs + 3872] }
void __JMP_API DbgUiWaitStateChange(void) { __asm jmp dword ptr[g_funcs + 3876] }
void __JMP_API DbgUiContinue(void) { __asm jmp dword ptr[g_funcs + 3880] }
void __JMP_API DbgUiStopDebugging(void) { __asm jmp dword ptr[g_funcs + 3884] }
void __JMP_API strncpy(void) { __asm jmp dword ptr[g_funcs + 3888] }
void __JMP_API RtlFlushSecureMemoryCache(void) { __asm jmp dword ptr[g_funcs + 3892] }
void __JMP_API NtQueryVirtualMemory(void) { __asm jmp dword ptr[g_funcs + 3896] }
void __JMP_API RtlQueryHeapInformation(void) { __asm jmp dword ptr[g_funcs + 3900] }
void __JMP_API NtTerminateProcess(void) { __asm jmp dword ptr[g_funcs + 3904] }
void __JMP_API wcsncmp(void) { __asm jmp dword ptr[g_funcs + 3908] }
void __JMP_API RtlUnhandledExceptionFilter(void) { __asm jmp dword ptr[g_funcs + 3912] }
void __JMP_API wcspbrk(void) { __asm jmp dword ptr[g_funcs + 3916] }
void __JMP_API _wcslwr(void) { __asm jmp dword ptr[g_funcs + 3920] }
void __JMP_API _strlwr(void) { __asm jmp dword ptr[g_funcs + 3924] }
void __JMP_API RtlUnwind(void) { __asm jmp dword ptr[g_funcs + 3928] }
void __JMP_API _StringCopyWorkerA(void) { __asm jmp dword ptr[g_funcs + 3932] }

char* g_exports[] = {
	"DeviceIoControl",
	"GetSystemTime",
	"GetSystemTimeAsFileTime",
	"ReadFile",
	"CreateFileA",
	"VirtualProtectEx",
	"VirtualProtect",
	"LoadLibraryExA",
	"LoadLibraryA",
	"LoadLibraryExW",
	"TerminateProcess",
	"GetStartupInfoW",
	"GetStartupInfoA",
	"ReadProcessMemory",
	"WriteProcessMemory",
	"CreateProcessW",
	"CreateProcessA",
	"SleepEx",
	"Sleep",
	"ReleaseMutex",
	"__SEH_prolog",
	"__SEH_epilog",
	"WaitForSingleObject",
	"WaitForSingleObjectEx",
	"GetTickCount",
	"CreateFileMappingW",
	"CreateFileMappingA",
	"WaitForMultipleObjectsEx",
	"SetWaitableTimer",
	"GetCurrentThreadId",
	"TlsGetValue",
	"InterlockedIncrement",
	"InterlockedDecrement",
	"InterlockedExchange",
	"InterlockedCompareExchange",
	"InterlockedExchangeAdd",
	"MulDiv",
	"GetCurrentThread",
	"GetACP",
	"GetCurrentProcessId",
	"LocalFree",
	"LocalAlloc",
	"lstrlenW",
	"VirtualAlloc",
	"VirtualAllocEx",
	"VirtualFree",
	"VirtualFreeEx",
	"CloseHandle",
	"TlsSetValue",
	"MultiByteToWideChar",
	"IsBadReadPtr",
	"IsBadWritePtr",
	"InitializeCriticalSection",
	"GetUserDefaultLCID",
	"LdrFindResource_U",
	"LdrAccessResource",
	"LoadResource",
	"SetEvent",
	"ResetEvent",
	"WaitForMultipleObjects",
	"_allmul",
	"WideCharToMultiByte",
	"CompareStringW",
	"GetThreadLocale",
	"QueryPerformanceCounter",
	"GetStringTypeW",
	"IsBadStringPtrW",
	"ActivateActCtx",
	"DeactivateActCtx",
	"CreateEventW",
	"GetQueuedCompletionStatus",
	"GetThreadPriority",
	"GetLocalTime",
	"lstrcmpiW",
	"lstrcmpW",
	"GetProcessHeap",
	"LdrUnloadDll",
	"FreeLibrary",
	"SetErrorMode",
	"FindResourceExW",
	"GetSystemWindowsDirectoryW",
	"GetWindowsDirectoryW",
	"LdrGetProcedureAddress",
	"GetProcAddress",
	"IsProcessorFeaturePresent",
	"LoadLibraryW",
	"GetVersionExW",
	"GetDriveTypeW",
	"LdrLockLoaderLock",
	"GetModuleFileNameW",
	"LdrUnlockLoaderLock",
	"GetModuleFileNameA",
	"GetModuleHandleA",
	"lstrlen",
	"lstrcpy",
	"FindResourceA",
	"GetSystemDefaultLCID",
	"GetUserDefaultLangID",
	"IsBadHugeWritePtr",
	"ReleaseSemaphore",
	"GetStringTypeExW",
	"ExitThread",
	"LdrShutdownThread",
	"SetThreadPriority",
	"FreeLibraryAndExitThread",
	"FlushFileBuffers",
	"DisconnectNamedPipe",
	"PostQueuedCompletionStatus",
	"ChangeTimerQueueTimer",
	"LockResource",
	"GetFileAttributesW",
	"IsDBCSLeadByte",
	"InitializeCriticalSectionAndSpinCount",
	"GetFullPathNameW",
	"GetCurrentDirectoryW",
	"MapViewOfFileEx",
	"MapViewOfFile",
	"UnmapViewOfFile",
	"VirtualQueryEx",
	"VirtualQuery",
	"lstrcpynW",
	"lstrcpyW",
	"lstrcmpi",
	"OpenFileMappingW",
	"OpenFileMappingA",
	"FindResourceW",
	"SizeofResource",
	"IsBadCodePtr",
	"FileTimeToSystemTime",
	"FileTimeToLocalFileTime",
	"CreateFileW",
	"GetFileSizeEx",
	"GetFileSize",
	"CompareFileTime",
	"SystemTimeToFileTime",
	"OpenConsoleW",
	"IsValidCodePage",
	"SetFilePointer",
	"GetFileInformationByHandle",
	"WriteFile",
	"GetFileType",
	"HeapDestroy",
	"lstrcatW",
	"LCMapStringW",
	"CompareStringA",
	"GetLocaleInfoA",
	"GetCurrentProcess",
	"DuplicateHandle",
	"__global_unwind2",
	"__abnormal_termination",
	"LdrLoadDll",
	"GetModuleHandleW",
	"LdrGetDllHandle",
	"GetFileAttributesExW",
	"GetVersion",
	"LdrFindResourceDirectory_U",
	"DisableThreadLibraryCalls",
	"LdrDisableThreadCalloutsForDll",
	"SearchPathW",
	"GetFileAttributesA",
	"GlobalFree",
	"GlobalAlloc",
	"GlobalUnlock",
	"GlobalLock",
	"GlobalAddAtomW",
	"CreateSemaphoreW",
	"lstrcpyn",
	"RtlEncodePointer",
	"RtlDecodePointer",
	"SetEnvironmentVariableW",
	"FindFirstFileExW",
	"FindFirstFileW",
	"FindClose",
	"FindNextFileW",
	"GetEnvironmentVariableW",
	"SetCurrentDirectoryW",
	"CreateRemoteThread",
	"CreateThread",
	"SwitchToFiber",
	"__ResourceCallEnumLangRoutine",
	"__ResourceCallEnumNameRoutine",
	"__ResourceCallEnumTypeRoutine",
	"GetPrivateProfileStringW",
	"GetVolumeInformationW",
	"wcsncpy",
	"GlobalReAlloc",
	"GetVersionExA",
	"HeapCreate",
	"GetProcessVersion",
	"GetSystemInfo",
	"TlsAlloc",
	"CreateSemaphoreA",
	"GetCPInfo",
	"GetEnvironmentStringsW",
	"GetCommandLineA",
	"GetStdHandle",
	"CreateMutexW",
	"CreateMutexA",
	"OpenMutexW",
	"OpenMutexA",
	"ProcessIdToSessionId",
	"GetSystemDefaultUILanguage",
	"ReleaseActCtx",
	"GetUserDefaultUILanguage",
	"IsDebuggerPresent",
	"OpenEventW",
	"OpenEventA",
	"WTSGetActiveConsoleSessionId",
	"GetLongPathNameW",
	"TlsFree",
	"GetFileAttributesExA",
	"FindFirstFileA",
	"GetFullPathNameA",
	"FreeEnvironmentStringsW",
	"GetEnvironmentVariableA",
	"LdrLoadAlternateResourceModule",
	"LdrUnloadAlternateResourceModule",
	"GetSystemDirectoryA",
	"NlsConvertIntegerToString",
	"BaseUpdateAppcompatCache",
	"IsWow64Process",
	"LdrCreateOutOfProcessImage",
	"LdrFindCreateProcessManifest",
	"LdrDestroyOutOfProcessImage",
	"CreateActCtxW",
	"LdrAccessOutOfProcessResource",
	"QueryActCtxW",
	"BaseInitAppcompatCache",
	"BaseCheckAppcompatCache",
	"_allshl",
	"GetCommandLineW",
	"RegisterWaitForInputIdle",
	"BaseProcessInitPostImport",
	"LdrEnumerateLoadedModules",
	"GetNlsSectionName",
	"LdrSetDllManifestProber",
	"RtlSetThreadPoolStartFunc",
	"BasepCheckWinSaferRestrictions",
	"DbgPrintEx",
	"LdrQueryImageFileExecutionOptions",
	"GetExitCodeProcess",
	"VerifyConsoleIoHandle",
	"GetConsoleMode",
	"GetConsoleOutputCP",
	"SetConsoleMode",
	"SetThreadUILanguage",
	"SetConsoleInputExeNameW",
	"SetConsoleCtrlHandler",
	"GetConsoleTitleW",
	"SetThreadLocale",
	"GetConsoleScreenBufferInfo",
	"IsValidLocale",
	"ExitProcess",
	"LdrShutdownProcess",
	"TerminateThread",
	"WriteConsoleA",
	"GetEnvironmentStrings",
	"SetFileApisToOEM",
	"SetStdHandle",
	"CloseConsoleHandle",
	"DuplicateConsoleHandle",
	"CreateProcessInternalA",
	"FreeEnvironmentStringsA",
	"CreatePipe",
	"GetPrivateProfileSectionW",
	"WritePrivateProfileStringW",
	"TermsrvAppInstallMode",
	"GetShortPathNameW",
	"MoveFileWithProgressW",
	"TransactNamedPipe",
	"CreateIoCompletionPort",
	"SetNamedPipeHandleState",
	"ConnectNamedPipe",
	"SetFileAttributesW",
	"GetOverlappedResult",
	"ReadDirectoryChangesW",
	"GetComputerNameW",
	"GetFileTime",
	"SetFileTime",
	"GetSystemDirectoryW",
	"DeleteFileA",
	"DeleteFileW",
	"SetEndOfFile",
	"FindNextChangeNotification",
	"DosDateTimeToFileTime",
	"IsBadStringPtrA",
	"UnlockFile",
	"UnlockFileEx",
	"LockFile",
	"GetTimeZoneInformation",
	"MoveFileW",
	"CreateDirectoryW",
	"GetProcessTimes",
	"GetCurrentDirectoryA",
	"_hread",
	"_llseek",
	"WriteConsoleW",
	"MoveFileExW",
	"SetEnvironmentVariableA",
	"GetSystemPowerStatus",
	"LocalSize",
	"DeleteAtom",
	"AddAtomW",
	"GetPrivateProfileIntW",
	"memmove",
	"ResumeThread",
	"SwitchToThread",
	"ExpandEnvironmentStringsA",
	"GetPrivateProfileStringA",
	"GetPrivateProfileSectionNamesA",
	"LocalLock",
	"LocalUnlock",
	"GetAtomNameW",
	"FindActCtxSectionStringW",
	"WriteProfileStringW",
	"OpenProfileUserMapping",
	"GlobalMemoryStatusEx",
	"VerifyVersionInfoW",
	"GetVolumeNameForVolumeMountPointW",
	"GetModuleHandleExW",
	"GetComputerNameExW",
	"GetVolumePathNamesForVolumeNameW",
	"PrivCopyFileExW",
	"SetHandleInformation",
	"OpenSemaphoreW",
	"CreateWaitableTimerW",
	"OpenThread",
	"GetSystemWindowsDirectoryA",
	"GetWindowsDirectoryA",
	"GetProfileStringW",
	"AddAtomA",
	"GetExitCodeThread",
	"GetSystemWow64DirectoryA",
	"GetProfileStringA",
	"GetDriveTypeA",
	"DeleteFiber",
	"ConvertFiberToThread",
	"ConvertThreadToFiber",
	"CreateFiber",
	"CreateFiberEx",
	"GetComputerNameA",
	"UnregisterWaitEx",
	"GetCurrentActCtx",
	"CancelIo",
	"LockFileEx",
	"CmdBatNotification",
	"FormatMessageA",
	"QueryPerformanceFrequency",
	"SetThreadAffinityMask",
	"GetProcessAffinityMask",
	"CreateDirectoryA",
	"FindAtomW",
	"CopyFileW",
	"GetProfileIntW",
	"SetFilePointerEx",
	"DeleteTimerQueueTimer",
	"LdrAddRefDll",
	"CreateTimerQueueTimer",
	"RegisterWaitForSingleObject",
	"CreateNamedPipeW",
	"SearchPathA",
	"OpenFile",
	"GetVolumeInformationA",
	"QueryDosDeviceW",
	"DefineDosDeviceW",
	"GetCommTimeouts",
	"FreeResource",
	"CopyFileExW",
	"CopyFileA",
	"wcsstr",
	"EnumUILanguagesW",
	"AssignProcessToJobObject",
	"ReadFileEx",
	"GetHandleInformation",
	"AddRefActCtx",
	"GetVolumePathNameW",
	"GetVolumePathNameA",
	"SystemTimeToTzSpecificLocalTime",
	"wcslen",
	"SetConsoleTitleW",
	"WriteFileGather",
	"ReadFileScatter",
	"EnumResourceLanguagesA",
	"CreateTimerQueue",
	"UnregisterWait",
	"BindIoCompletionCallback",
	"RtlSetIoCompletionCallback",
	"PulseEvent",
	"QueueUserAPC",
	"DosPathToSessionPathW",
	"GetLogicalDriveStringsA",
	"SetPriorityClass",
	"GlobalGetAtomNameW",
	"WaitNamedPipeW",
	"CloseProfileUserMapping",
	"SetProcessShutdownParameters",
	"OpenSemaphoreA",
	"SetInformationJobObject",
	"CreateJobObjectW",
	"CancelWaitableTimer",
	"CreateMailslotA",
	"CreateMailslotW",
	"SetMailslotInfo",
	"DnsHostnameToComputerNameW",
	"RtlDnsHostNameToComputerName",
	"FindVolumeClose",
	"FindNextVolumeW",
	"FindFirstVolumeW",
	"GetSystemTimeAdjustment",
	"CreateNlsSecurityDescriptor",
	"OpenDataFile",
	"InitAtomTable",
	"QueryInformationJobObject",
	"RegisterWaitForSingleObjectEx",
	"VirtualLock",
	"SetTimerQueueTimer",
	"BaseInitAppcompatCacheSupport",
	"GetNumberFormatA",
	"VerLanguageNameA",
	"VerLanguageNameW",
	"GetDiskFreeSpaceW",
	"GetDiskFreeSpaceA",
	"GetDiskFreeSpaceExA",
	"SetProcessWorkingSetSize",
	"GetDateFormatW",
	"GetTimeFormatW",
	"GetNumberFormatW",
	"CreateVirtualBuffer",
	"FreeVirtualBuffer",
	"FormatMessageW",
	"FindFirstChangeNotificationW",
	"ExpandEnvironmentStringsW",
	"FileTimeToDosDateTime",
	"GetTempPathW",
	"CreateEventA",
	"LocalReAlloc",
	"OpenProcess",
	"QueueUserWorkItem",
	"GetLogicalDrives",
	"GlobalDeleteAtom",
	"FindAtomA",
	"lstrcmp",
	"GetDiskFreeSpaceExW",
	"RaiseException",
	"FindActCtxSectionGuid",
	"GlobalMemoryStatus",
	"GlobalHandle",
	"lstrcat",
	"FindNextFileA",
	"GlobalSize",
	"LocalFileTimeToFileTime",
	"FlushInstructionCache",
	"_lclose",
	"GlobalFindAtomW",
	"SetFileAttributesA",
	"GetOEMCP",
	"GetSystemDefaultLangID",
	"FindCloseChangeNotification",
	"NlsGetCacheUpdateCount",
	"IsBadHugeReadPtr",
	"AreFileApisANSI",
	"FlushViewOfFile",
	"GetTempFileNameW",
	"GetShortPathNameA",
	"WritePrivateProfileStringA",
	"GetTempPathA",
	"MoveFileA",
	"MoveFileWithProgressA",
	"GetPrivateProfileSectionA",
	"FindResourceExA",
	"GlobalAddAtomA",
	"GlobalFindAtomA",
	"SetCurrentDirectoryA",
	"HeapCompact",
	"GetDateFormatA",
	"GetTimeFormatA",
	"GetPrivateProfileIntA",
	"GetProfileIntA",
	"_lcreat",
	"SetFileApisToANSI",
	"SignalObjectAndWait",
	"GlobalFlags",
	"ReplaceFile",
	"RemoveDirectoryW",
	"wcscpy",
	"GetNativeSystemInfo",
	"GetUserGeoID",
	"_wtol",
	"Beep",
	"GetConsoleDisplayMode",
	"EnumSystemLocalesA",
	"EnumCalendarInfoA",
	"BaseQueryModuleData",
	"ConvertDefaultLocale",
	"GetCPFileNameFromRegistry",
	"EnumDateFormatsW",
	"EnumTimeFormatsW",
	"GetStringTypeA",
	"_hwrite",
	"LCMapStringA",
	"GetCalendarInfoW",
	"SetThreadExecutionState",
	"HeapSetInformation",
	"RtlSetHeapInformation",
	"QueryMemoryResourceNotification",
	"CreateMemoryResourceNotification",
	"GetThreadContext",
	"SuspendThread",
	"ValidateLocale",
	"SetUnhandledExceptionFilter",
	"EnumResourceNamesW",
	"SetLocalTime",
	"LocalFlags",
	"LocalHandle",
	"wcscat",
	"BackupSeek",
	"BackupRead",
	"BackupWrite",
	"SetComputerNameW",
	"SetComputerNameExW",
	"SetComputerNameA",
	"GetComputerNameExA",
	"SetComputerNameExA",
	"EnumerateLocalComputerNamesW",
	"EnumerateLocalComputerNamesA",
	"DnsHostnameToComputerNameA",
	"AddLocalAlternateComputerNameW",
	"AddLocalAlternateComputerNameA",
	"RemoveLocalAlternateComputerNameW",
	"RemoveLocalAlternateComputerNameA",
	"SetLocalPrimaryComputerNameW",
	"SetLocalPrimaryComputerNameA",
	"LZCopy",
	"CopyLZFile",
	"SetTimeZoneInformation",
	"SetSystemTimeAdjustment",
	"_StringCatWorkerW",
	"SetSystemTime",
	"SetClientTimeZoneInformation",
	"_StringCchCatW",
	"TzSpecificLocalTimeToSystemTime",
	"CheckRemoteDebuggerPresent",
	"DebugBreak",
	"OutputDebugStringA",
	"DebugActiveProcess",
	"DebugBreakProcess",
	"DebugSetProcessKillOnExit",
	"GetThreadSelectorEntry",
	"OutputDebugStringW",
	"WaitForDebugEvent",
	"ContinueDebugEvent",
	"DebugActiveProcessStop",
	"CreateDirectoryExW",
	"RemoveDirectoryA",
	"CreateDirectoryExA",
	"GlobalGetAtomNameA",
	"GetAtomNameA",
	"QueryWin31IniFilesMappedToRegistry",
	"WritePrivateProfileSectionA",
	"WritePrivateProfileSectionW",
	"GetPrivateProfileSectionNamesW",
	"GetPrivateProfileStructA",
	"GetPrivateProfileStructW",
	"WritePrivateProfileStructA",
	"WritePrivateProfileStructW",
	"WriteProfileStringA",
	"GetProfileSectionA",
	"WriteProfileSectionA",
	"GetProfileSectionW",
	"WriteProfileSectionW",
	"DefineDosDeviceA",
	"QueryDosDeviceA",
	"FindFirstChangeNotificationA",
	"FindFirstFileExA",
	"WriteFileEx",
	"SetFileValidData",
	"SetFileShortNameW",
	"SetFileShortNameA",
	"PrivMoveFileIdentityW",
	"GetCompressedFileSizeW",
	"GetCompressedFileSizeA",
	"MoveFileExA",
	"ReplaceFileA",
	"CopyFileExA",
	"GetFirmwareEnvironmentVariableW",
	"SetFirmwareEnvironmentVariableW",
	"GetFirmwareEnvironmentVariableA",
	"SetFirmwareEnvironmentVariableA",
	"RegisterWowBaseHandlers",
	"GlobalFix",
	"GlobalUnfix",
	"GlobalWire",
	"GlobalUnWire",
	"VirtualUnlock",
	"AllocateUserPhysicalPages",
	"FreeUserPhysicalPages",
	"MapUserPhysicalPages",
	"MapUserPhysicalPagesScatter",
	"GetWriteWatch",
	"ResetWriteWatch",
	"_lopen",
	"GlobalCompact",
	"LocalShrink",
	"HeapExtend",
	"HeapCreateTagsW",
	"HeapQueryTagW",
	"HeapSummary",
	"HeapUsage",
	"HeapValidate",
	"GetProcessHeaps",
	"HeapLock",
	"HeapUnlock",
	"HeapWalk",
	"HeapQueryInformation",
	"GetMailslotInfo",
	"ExtendVirtualBuffer",
	"TrimVirtualBuffer",
	"VirtualBufferExceptionHandler",
	"SetSearchPathMode",
	"SetDllDirectoryW",
	"SetDllDirectoryA",
	"GetDllDirectoryW",
	"VerifyVersionInfoA",
	"UTRegister",
	"GetDllDirectoryA",
	"GetModuleHandleExA",
	"EnumResourceTypesA",
	"EnumResourceNamesA",
	"EnumResourceTypesW",
	"EnumResourceLanguagesW",
	"GetNamedPipeInfo",
	"PeekNamedPipe",
	"GetNamedPipeHandleStateW",
	"CallNamedPipeW",
	"WaitNamedPipeA",
	"CreateNamedPipeA",
	"GetNamedPipeHandleStateA",
	"CallNamedPipeA",
	"GetNumaHighestNodeNumber",
	"GetNumaProcessorNode",
	"GetNumaNodeProcessorMask",
	"GetNumaProcessorMap",
	"GetNumaAvailableMemory",
	"GetNumaAvailableMemoryNode",
	"NumaVirtualQueryNode",
	"GetLogicalDriveStringsW",
	"SetVolumeLabelW",
	"CheckNameLegalDOS8Dot3W",
	"GetTempFileNameA",
	"SetVolumeLabelA",
	"CheckNameLegalDOS8Dot3A",
	"SetSystemPowerState",
	"RequestWakeupLatency",
	"GetDevicePowerState",
	"IsSystemResumeAutomatic",
	"RequestDeviceWakeup",
	"CancelDeviceWakeupRequest",
	"SetMessageWaitingIndicator",
	"_StringCopyWorkerW",
	"CreateProcessInternalWSecure",
	"GetProcessId",
	"FatalAppExitW",
	"FatalAppExitA",
	"FatalExit",
	"GetSystemDEPPolicy",
	"GetLogicalProcessorInformation",
	"GetPriorityClass",
	"GetProcessShutdownParameters",
	"GetSystemTimes",
	"GetProcessWorkingSetSize",
	"SetProcessAffinityMask",
	"SetProcessPriorityBoost",
	"GetProcessPriorityBoost",
	"GetProcessIoCounters",
	"GetProcessHandleCount",
	"SetProcessDEPPolicy",
	"GetProcessDEPPolicy",
	"GetSystemRegistryQuota",
//	"_StringCatWorkerW",
	"_StringCbCatW",
	"WinExec",
	"LoadModule",
	"DosPathToSessionPathA",
	"OpenWaitableTimerW",
	"CreateWaitableTimerA",
	"OpenWaitableTimerA",
	"SetTermsrvAppInstallMode",
//	"FID_conflict:_StringCbCatExW",
	"_StringCatExWorkerW",
	"_StringCbCatExW",
	"SetThreadPriorityBoost",
	"GetThreadPriorityBoost",
	"SetThreadContext",
	"GetThreadTimes",
	"GetThreadIOPendingFlag",
	"SetThreadIdealProcessor",
	"DeleteTimerQueueEx",
	"DeleteTimerQueue",
	"CancelTimerQueueTimer",
	"Heap32ListFirst",
	"Heap32ListNext",
	"Heap32First",
	"Heap32Next",
	"Toolhelp32ReadProcessMemory",
	"Process32FirstW",
	"Process32First",
	"Process32NextW",
	"Process32Next",
	"Thread32First",
	"Thread32Next",
	"Module32FirstW",
	"Module32First",
	"Module32NextW",
	"Module32Next",
	"CreateToolhelp32Snapshot",
	"GetExpandedNameA",
	"GetExpandedNameW",
	"LZInit",
	"LZCreateFileW",
	"LZOpenFileA",
	"LZOpenFileW",
	"LZSeek",
	"LZRead",
	"LZCloseFile",
	"LZClose",
	"ClearCommError",
	"SetupComm",
	"EscapeCommFunction",
	"GetCommMask",
	"GetCommModemStatus",
	"GetCommProperties",
	"GetCommState",
	"PurgeComm",
	"SetCommBreak",
	"SetCommMask",
	"SetCommState",
	"SetCommTimeouts",
	"TransmitCommChar",
	"WaitCommEvent",
	"CommConfigDialogW",
	"CommConfigDialogA",
	"GetDefaultCommConfigW",
	"GetDefaultCommConfigA",
	"SetDefaultCommConfigW",
	"SetDefaultCommConfigA",
	"ClearCommBreak",
	"GetCommConfig",
	"SetCommConfig",
	"GetNextVDMCommand",
	"ExitVDM",
	"SetVDMCurrentDirectories",
	"GetVDMCurrentDirectories",
	"RegisterWowExec",
	"GetBinaryTypeW",
	"VDMOperationStarted",
	"GetBinaryType",
	"GetLongPathNameA",
	"FindFirstVolumeMountPointW",
	"FindNextVolumeMountPointW",
	"SetVolumeMountPointW",
	"DeleteVolumeMountPointW",
	"FindNextVolumeA",
	"FindFirstVolumeMountPointA",
	"FindNextVolumeMountPointA",
	"GetVolumeNameForVolumeMountPointA",
	"SetVolumeMountPointA",
	"DeleteVolumeMountPointA",
	"GetVolumePathNamesForVolumeNameA",
	"FindFirstVolumeA",
	"BuildCommDCBAndTimeoutsA",
	"BuildCommDCBA",
	"BuildCommDCBAndTimeoutsW",
	"BuildCommDCBW",
	"SetTapePosition",
	"GetTapePosition",
	"PrepareTape",
	"EraseTape",
	"CreateTapePartition",
	"WriteTapemark",
	"GetTapeParameters",
	"SetTapeParameters",
	"GetTapeStatus",
	"OpenJobObjectW",
	"TerminateJobObject",
	"IsProcessInJob",
	"CreateJobSet",
	"CreateJobObjectA",
	"OpenJobObjectA",
	"CreateHardLinkW",
	"CreateHardLinkA",
	"GetHandleContext",
	"CreateSocketHandle",
	"ZombifyActCtx",
	"CreateActCtxA",
	"FindActCtxSectionStringA",
	"SetComPlusPackageInstallStatus",
	"GetComPlusPackageInstallStatus",
	"BaseFlushAppcompatCache",
	"BaseDumpAppcompatCache",
	"BaseCleanupAppcompatCache",
	"BaseCleanupAppcompatCacheSupport",
	"UpdateResourceW",
	"UpdateResourceA",
	"EndUpdateResourceW",
	"EndUpdateResourceA",
	"BeginUpdateResourceW",
	"BeginUpdateResourceA",
	"GetConsoleAliasW",
	"GetConsoleAliasA",
	"GetConsoleAliasesLengthW",
	"GetConsoleAliasesLengthA",
	"GetConsoleAliasExesLengthW",
	"GetConsoleAliasExesLengthA",
	"GetConsoleAliasesW",
	"GetConsoleAliasesA",
	"GetConsoleAliasExesW",
	"GetConsoleAliasExesA",
	"ExpungeConsoleCommandHistoryW",
	"ExpungeConsoleCommandHistoryA",
	"SetConsoleNumberOfCommandsW",
	"SetConsoleNumberOfCommandsA",
	"GetConsoleCommandHistoryLengthW",
	"GetConsoleCommandHistoryLengthA",
	"GetConsoleCommandHistoryW",
	"GetConsoleCommandHistoryA",
	"SetConsoleCommandHistoryMode",
	"GetConsoleTitleA",
	"SetConsoleTitleA",
	"GetConsoleInputExeNameW",
	"AddConsoleAliasW",
	"AddConsoleAliasA",
	"GetConsoleInputExeNameA",
	"SetConsoleInputExeNameA",
	"FreeConsole",
	"AllocConsole",
	"AttachConsole",
	"GetConsoleInputWaitHandle",
	"ReadConsoleA",
	"ReadConsoleW",
	"RegisterConsoleVDM",
	"GetConsoleHardwareState",
	"SetConsoleHardwareState",
	"SetConsoleKeyShortcuts",
	"SetConsoleMenuClose",
	"WriteConsoleInputVDMA",
	"WriteConsoleInputVDMW",
	"SetConsoleCursor",
	"ShowConsoleCursor",
	"ConsoleMenuControl",
	"SetConsoleDisplayMode",
	"SetConsolePalette",
	"WriteConsoleInputA",
	"WriteConsoleInputW",
	"ReadConsoleOutputW",
	"ReadConsoleOutputA",
	"WriteConsoleOutputW",
	"WriteConsoleOutputA",
	"ReadConsoleOutputCharacterA",
	"ReadConsoleOutputCharacterW",
	"ReadConsoleOutputAttribute",
	"WriteConsoleOutputCharacterA",
	"WriteConsoleOutputCharacterW",
	"WriteConsoleOutputAttribute",
	"FillConsoleOutputCharacterA",
	"FillConsoleOutputCharacterW",
	"FillConsoleOutputAttribute",
	"CreateConsoleScreenBuffer",
	"InvalidateConsoleDIBits",
	"PeekConsoleInputA",
	"PeekConsoleInputW",
	"ReadConsoleInputA",
	"ReadConsoleInputW",
	"ReadConsoleInputExA",
	"ReadConsoleInputExW",
	"GetConsoleCursorInfo",
	"GetConsoleSelectionInfo",
	"GetNumberOfConsoleMouseButtons",
	"GetConsoleFontInfo",
	"GetConsoleFontSize",
	"GetCurrentConsoleFont",
	"GenerateConsoleCtrlEvent",
	"SetConsoleActiveScreenBuffer",
	"FlushConsoleInputBuffer",
	"SetConsoleScreenBufferSize",
	"SetConsoleCursorPosition",
	"SetConsoleCursorInfo",
	"SetConsoleWindowInfo",
	"ScrollConsoleScreenBufferA",
	"ScrollConsoleScreenBufferW",
	"SetConsoleTextAttribute",
	"SetConsoleFont",
	"SetConsoleIcon",
	"GetConsoleCP",
	"SetConsoleCP",
	"SetConsoleOutputCP",
	"GetConsoleKeyboardLayoutNameA",
	"GetConsoleKeyboardLayoutNameW",
	"GetConsoleWindow",
	"GetConsoleProcessList",
	"GetNumberOfConsoleFonts",
	"GetNumberOfConsoleInputEvents",
	"GetLargestConsoleWindowSize",
	"SetConsoleLocalEUDC",
	"SetConsoleCursorMode",
	"GetConsoleCursorMode",
	"RegisterConsoleOS2",
	"SetConsoleOS2OemFormat",
	"RegisterConsoleIME",
	"UnregisterConsoleIME",
	"GetConsoleNlsMode",
	"SetConsoleNlsMode",
	"GetConsoleCharType",
	"SetLastConsoleEventActive",
	"VDMConsoleOperation",
	"EnumCalendarInfoExA",
	"EnumTimeFormatsA",
	"EnumDateFormatsA",
	"EnumDateFormatsExA",
	"EnumSystemLanguageGroupsA",
	"EnumLanguageGroupLocalesA",
	"EnumUILanguagesA",
	"EnumSystemCodePagesA",
	"GetGeoInfoA",
	"SetLocaleInfoA",
	"GetCalendarInfoA",
	"SetCalendarInfoA",
	"GetCurrencyFormatA",
	"FoldStringA",
	"GetCPInfoExA",
	"GetStringTypeExA",
	"NlsResetProcessLocale",
	"IsValidLanguageGroup",
	"IsValidUILanguage",
	"SetCalendarInfoW",
	"SetLocaleInfoW",
	"EnumSystemLanguageGroupsW",
	"EnumLanguageGroupLocalesW",
	"EnumSystemLocalesW",
	"EnumSystemCodePagesW",
	"EnumCalendarInfoW",
	"EnumCalendarInfoExW",
	"EnumDateFormatsExW",
	"GetGeoInfoW",
	"EnumSystemGeoID",
	"SetUserGeoID",
	"FoldStringW",
	"SetCPGlobal",
	"GetCPInfoExW",
	"IsDBCSLeadByteEx",
	"GetDefaultSortkeySize",
	"GetLinguistLangSize",
	"ValidateLCType",
	"GetCurrencyFormatW",
	"DelayLoadFailureHook",
	"UTUnRegister",
	"_Shell_GetImageLists",
	"LZStart",
	"SetConsoleMaximumWindowSize",
	"_RegQueryValueExW",
	"wcschr",
	"DbgBreakPoint",
	"DbgPrint",
	"DbgUiDebugActiveProcess",
	"DbgUiConnectToDbg",
	"DbgUiIssueRemoteBreakin",
	"NtSetInformationDebugObject",
	"DbgUiGetThreadDebugObject",
	"DbgUiConvertStateChangeStructure",
	"DbgUiWaitStateChange",
	"DbgUiContinue",
	"DbgUiStopDebugging",
	"strncpy",
	"RtlFlushSecureMemoryCache",
	"NtQueryVirtualMemory",
	"RtlQueryHeapInformation",
	"NtTerminateProcess",
	"wcsncmp",
	"RtlUnhandledExceptionFilter",
	"wcspbrk",
	"_wcslwr",
	"_strlwr",
	"RtlUnwind",
	"_StringCopyWorkerA",
};
