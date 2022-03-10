#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <winreg.h>
#include <stdio.h>

#define CountLaunch 3
#define reg_parm "AppInfo123\\COUNT"
#define HkeY HKEY_CURRENT_USER

int CreateCatalog() {
	HKEY h = NULL;
	DWORD NEW;
	if (RegCreateKeyEx(HkeY, TEXT(reg_parm), 0, NULL, REG_OPTION_VOLATILE,
		KEY_WRITE, NULL, &h, &NEW) != ERROR_SUCCESS){
		printf("Could not create the registry key.");
		return(2);
	}
	if (NEW == 1) {
		RegSetValueEx(h, L"C", NULL, REG_SZ, L"1", 4);
		RegCloseKey(h);
		return(1);
	}
	else {
		RegCloseKey(h);
		return(0);
	}
} //Создаем

int OpenCatalog() {
	HKEY h;
	RegOpenKeyEx(HkeY, TEXT(reg_parm), NULL, KEY_ALL_ACCESS, &h);
	return(h);
} //Открываем

int GetValue(HKEY h) {
	int size = 260;
	char tmpBuff[4] = { NULL };
	RegQueryValueEx(h, L"C", NULL, NULL, (LPBYTE)tmpBuff, &size);
	int count = atoi(tmpBuff);
	RegCloseKey(h);
	return(count);
} //Считываем

int SetValue(HKEY h, int Count) {
	char tmpBuff[4] = { NULL };
	_itoa(Count, tmpBuff, 4);
	RegSetValueEx(h, L"C", NULL, REG_SZ, (LPBYTE)tmpBuff, 4);
	RegCloseKey(h);
} //Записываем


int main() {
	HKEY h = NULL;
	int Count = NULL;
	h = CreateCatalog();
	if (h == 1) 
		printf_s("Program launched for the first time.\n");
	else
		printf_s("The program has already run on this computer.\n");

	h = NULL;

	h = OpenCatalog();
	Count = GetValue(h);
	if (Count < CountLaunch) {
		++Count;
		h = OpenCatalog();
		SetValue(h, Count);
	}
	return(0);
}