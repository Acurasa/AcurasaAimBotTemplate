// dllmain.cpp : Defines the entry point for the DLL application.

#include <Windows.h>
#include <iostream>
#include "AcurasaCore.h"

DWORD WINAPI OnDllAttach(PVOID base)
{
    while (!(GetAsyncKeyState(VK_DELETE & 0x800)))
    {
        Run();
        Sleep(1);
    }
    FreeLibraryAndExitThread(static_cast<HMODULE>(base), 0);
}





BOOL WINAPI DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)OnDllAttach, hModule, NULL, nullptr);
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

