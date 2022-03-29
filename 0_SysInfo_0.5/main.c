#define _CRT_SECURE_NO_WARNINGS
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")

#include <conio.h>
#include <intrin.h>
#include <stdio.h>
#include <assert.h>
#include <windows.h> 
#include <lm.h>
#include <winreg.h>
#include <time.h>

int PrintInfo(char* Mass) {
	for (int i = 0; i < 100; ++i) {
		printf("%c", Mass[i]);
	}
	printf("\n");
}


int wmain(int argc, wchar_t* argv[]) {
	int size = 100;
	char VerBios[100] = { NULL };
	char RelBios[100] = { NULL };
	char Manufact[100] = { NULL };
	char ManufactProduct[100] = { NULL };

	struct tm* ptr;
	time_t lt;

	lt = time(NULL);
	ptr = localtime(&lt);
	printf(asctime(ptr));


	HKEY h;
	RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"HARDWARE\\DESCRIPTION\\System\\BIOS", NULL, KEY_READ, &h);
	RegQueryValueEx(h, L"BaseBoardVersion", NULL, NULL, (LPBYTE)VerBios, &size);
	RegQueryValueEx(h, L"BIOSReleaseDate", NULL, NULL, (LPBYTE)RelBios, &size);
	RegQueryValueEx(h, L"BIOSReleaseDate", NULL, NULL, (LPBYTE)RelBios, &size);
	RegQueryValueEx(h, L"SystemManufacturer", NULL, NULL, (LPBYTE)Manufact, &size);
	RegQueryValueEx(h, L"SystemManufacturer", NULL, NULL, (LPBYTE)Manufact, &size);
	RegQueryValueEx(h, L"SystemProductName", NULL, NULL, (LPBYTE)ManufactProduct, &size);
	RegQueryValueEx(h, L"SystemProductName", NULL, NULL, (LPBYTE)ManufactProduct, &size);
	RegCloseKey(h);
	printf("Ver. BIOS: ");
	PrintInfo(VerBios);
	printf("DATE rel. BIOS: ");
	PrintInfo(RelBios);
	printf("Name PC: ");
	PrintInfo(Manufact);
	printf("Model PC: ");
	PrintInfo(ManufactProduct);



	LPUSER_INFO_0 pBuf = NULL;
	LPUSER_INFO_0 pTmpBuf;
	DWORD dwLevel = 0;
	DWORD dwPrefMaxLen = MAX_PREFERRED_LENGTH;
	DWORD dwEntriesRead = 0;
	DWORD dwTotalEntries = 0;
	DWORD dwResumeHandle = 0;
	DWORD i;
	DWORD dwTotalCount = 0;
	NET_API_STATUS nStatus;
	LPTSTR pszServerName = NULL;

	if (argc > 2) {
		fwprintf(stderr, L"Usage: %s [\\\\ServerName]\n", argv[0]);
		exit(1);
	}
	if (argc == 2)
		pszServerName = (LPTSTR)argv[1];
	wprintf(L"\nUser account on %s: \n", pszServerName);
	do {
		nStatus = NetUserEnum((LPCWSTR)pszServerName,
			dwLevel,
			FILTER_NORMAL_ACCOUNT,
			(LPBYTE*)&pBuf,
			dwPrefMaxLen,
			&dwEntriesRead,
			&dwTotalEntries,
			&dwResumeHandle);

		if ((nStatus == NERR_Success) || (nStatus == ERROR_MORE_DATA)) {
			if ((pTmpBuf = pBuf) != NULL) {

				for (i = 0; (i < dwEntriesRead); i++) {
					assert(pTmpBuf != NULL);

					if (pTmpBuf == NULL) {
						fprintf(stderr, "An access violation has occurred\n");
						break;
					}
					wprintf(L"\t-- %s\n", pTmpBuf->usri0_name);
					pTmpBuf++;
					dwTotalCount++;
				}
			}
		}
		else
			fprintf(stderr, "A system error has occurred: %d\n", nStatus);
		if (pBuf != NULL) {
			NetApiBufferFree(pBuf);
			pBuf = NULL;
		}
	} while (nStatus == ERROR_MORE_DATA);
	if (pBuf != NULL)
		NetApiBufferFree(pBuf);
	fprintf(stderr, "\nTotal of %d entries enumerated\n\n", dwTotalCount);

	char NAMEcpu[100] = { NULL };
	RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", NULL, KEY_READ, &h);
	RegQueryValueEx(h, L"ProcessorNameString", NULL, NULL, (LPBYTE)NAMEcpu, &size);
	RegQueryValueEx(h, L"ProcessorNameString", NULL, NULL, (LPBYTE)NAMEcpu, &size);
	RegCloseKey(h);
	printf("Processor PC: ");
	printf("\n");
	PrintInfo(NAMEcpu);

	SYSTEM_INFO siSysInfo;
	GetSystemInfo(&siSysInfo);
	printf("Hardware information: \n");
	printf("  OEM ID: %u\n", siSysInfo.dwOemId);
	printf("  Number of processors: %u\n",
		siSysInfo.dwNumberOfProcessors);
	printf("  Page size: %u\n", siSysInfo.dwPageSize);
	printf("  Processor type: %u\n", siSysInfo.dwProcessorType);
	printf("  Minimum application address: %lx\n",
		siSysInfo.lpMinimumApplicationAddress);
	printf("  Maximum application address: %lx\n",
		siSysInfo.lpMaximumApplicationAddress);
	printf("  Active processor mask: %u\n",
		siSysInfo.dwActiveProcessorMask);


	return 0;
}
