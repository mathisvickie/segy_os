#include "nt.h"
#include "string.h"
#include <intrin.h>

void* NtGetModuleHandle(const short* wModule)
{
	char* pPEB = (char*)__readfsdword(0x30);
	PLDR_DATA_TABLE_ENTRY pModuleList = *(PLDR_DATA_TABLE_ENTRY*)(*(int*)(pPEB + 0x0C) + 0x0C);

	while (pModuleList->DllBase)
	{
		if (!wcscmp(pModuleList->BaseDllName.Buffer, wModule))
			return pModuleList->DllBase;

		pModuleList = (PLDR_DATA_TABLE_ENTRY)(pModuleList->InLoadOrderLinks.Flink);
	}
	return 0;
}

void* NtGetProcAddress(unsigned char* pModule, const char* szProcedure)
{
	IMAGE_DOS_HEADER *idhDosHeader = (IMAGE_DOS_HEADER *)(pModule);

	if (idhDosHeader->e_magic == 0x5A4D)
	{
		IMAGE_NT_HEADERS32 *inhNtHeader = (IMAGE_NT_HEADERS32 *)(pModule + idhDosHeader->e_lfanew);

		if (inhNtHeader->Signature == 0x4550)
		{
			IMAGE_EXPORT_DIRECTORY *iedExportDirectory = (IMAGE_EXPORT_DIRECTORY *)(pModule + inhNtHeader->OptionalHeader.DataDirectory[0].VirtualAddress);

			for (register unsigned int uiIter = 0; uiIter < iedExportDirectory->NumberOfNames; ++uiIter)
			{
				char *szNames = (char *)(pModule + ((unsigned long *)(pModule + iedExportDirectory->AddressOfNames))[uiIter]);

				if (!strcmp(szNames, szProcedure))
				{
					unsigned short usOrdinal = ((unsigned short *)(pModule + iedExportDirectory->AddressOfNameOrdinals))[uiIter];
					return (void*)(pModule + ((unsigned long *)(pModule + iedExportDirectory->AddressOfFunctions))[usOrdinal]);
				}
			}
		}
	}
	return 0;
}
