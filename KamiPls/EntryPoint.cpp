#include <Windows.h>

extern void Main(void);

DWORD WINAPI DllWork(LPVOID lpThreadParameter)
{
	Main();
	return true;
}

::BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		::HANDLE hThread = nullptr;
		if ((hThread = ::CreateThread(nullptr, 0, &DllWork, hModule, 0, nullptr)) == nullptr)
		{
			return FALSE;
		}
		CloseHandle(hThread);
	}
	return TRUE;
}

BOOL WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCommandLine, int nCmdShow)
{
	Main();
}
