#include "stdafx.h"
#include <windows.h> 
#include <iostream>

using namespace std;

int main()
{
	HANDLE hProcess;
	HANDLE hThread;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DWORD dwProcessId = 0;
	DWORD deThreadId = 0;
	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));
	BOOL bCreateProcess = CreateProcess(
	L"C:\\Users\\Phillip\\Desktop\\ProcessSpawn\\Debug\\ProcessSpawn.exe",
		NULL,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi);
	if (bCreateProcess == FALSE)
	{
		cout << "Create Process Failed & Error No :" << GetLastError() << endl;
	}

	cout << "Create Process Successful" << endl;
	cout << "Process ID : " << pi.dwThreadId << endl;
	cout << "GetProcessID :" << GetProcessId(pi.hProcess) << endl;
	cout << "GetThreadID :" << GetThreadId(pi.hThread) << endl;

	WaitForSingleObject(pi.hProcess, INFINITE);

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	system("PAUSE");
	return 0;
}