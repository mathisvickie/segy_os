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
