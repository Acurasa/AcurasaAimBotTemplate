#pragma once
#include "Windows.h"
#include "TlHelp32.h"
#include "AnyPlayer.h"

template <class T>
T RPM(DWORD address)
{
	HANDLE SOMEFUCKINHANDLELETMECOMPILEALREADY=NULL;
	T read;
	ReadProcessMemory(SOMEFUCKINHANDLELETMECOMPILEALREADY, (DWORD*)address, &read, sizeof(T), 0);
	return read;
}
