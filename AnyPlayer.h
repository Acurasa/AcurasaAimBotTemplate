#pragma once
#include <Windows.h>
#include <cstdint>
#include "offfsets.h"
#include "Vector3.h"
#include "Header.h"
class Player
{
private:
	Player();
public:
	static int* GetMaxPlayer()
	{
		static uint32_t moduleBase = (uintptr_t)GetModuleHandle(L"engine.dll");
		return (int*)(*(uint32_t*)(moduleBase + hazedumper::signatures::dwClientState) + hazedumper::signatures::dwClientState_MaxPlayer);
	}
	static Player* GetPlayer(int index)
	{
		static uint32_t moduleBase = (uint32_t)(GetModuleHandle(L"client.dll"));
		static uint32_t entityList = moduleBase + hazedumper::signatures::dwEntityList;

		return (Player*)(entityList + index * 0x10);
	}
	int* GetHealth()
	{
		return(int*)(*(uintptr_t*)this + hazedumper::netvars::m_iHealth);
	}
	int* GetTeam()
	{
		return(int*)(*(uintptr_t*)this + hazedumper::netvars::m_iTeamNum);
	}
	Vector3* GetOrigin()
	{
		return (Vector3*)(*(uintptr_t*)this + hazedumper::netvars::m_vecOrigin);
	}
	Vector3* GetViewOffset()
	{
		return (Vector3*)(*(uintptr_t*)this + hazedumper::netvars::m_vecViewOffset);
	}
	
	Vector3 GetBonePos(int boneId)
	{
		DWORD Bonebase = RPM<DWORD>(*(uint32_t*)(*(uint32_t*)this + hazedumper::netvars::m_dwBoneMatrix));
		//VirtualProtect((BYTE*)hazedumper::netvars::m_dwBoneMatrix, hazedumper::netvars::m_dwBoneMatrix, PAGE_EXECUTE_READWRITE, &oldprotect);
		//uint32_t boneMatrix = *(uint32_t*)(*(uint32_t*)this + hazedumper::netvars::m_dwBoneMatrix); // HERE
		Vector3 bonePos;
		bonePos.x = *(float*)(Bonebase + 0x30 * boneId + 0x0c);
		bonePos.y = *(float*)(Bonebase + 0x30 * boneId + 0x1c);
		bonePos.z = *(float*)(Bonebase + 0x30 * boneId + 0x2c);
		return bonePos;
	}
};