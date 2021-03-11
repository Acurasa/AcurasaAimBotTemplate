#pragma once
#include "Windows.h"
#include "TlHelp32.h"
#include "AnyPlayer.h"

template <class T>
T RPM(DWORD address)
{
	HANDLE SOMEFUCKINHANDLELETMECOMPILEALREADY;
	T read;
	ReadProcessMemory(mem::SOMEFUCKINHANDLELETMECOMPILEALREADY, (DWORD*)address, &read, sizeof(T), 0);
	return read;
}
