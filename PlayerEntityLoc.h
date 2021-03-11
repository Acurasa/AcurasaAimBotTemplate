
#include <Windows.h>
#include <cstdint>
#include "offfsets.h"
#include <math.h>
#include "Vector3.h"
class PlayerEntityloc 
{
private:
	PlayerEntityloc();

public:
	static PlayerEntityloc* Get()
	{
		static uint32_t clientModule = (uint32_t)(GetModuleHandle(L"client.dll"));
		static PlayerEntityloc* playerloc = (PlayerEntityloc*)(clientModule + hazedumper::signatures::dwLocalPlayer);

		return playerloc;
	}
	Vector3* GetViewOffset()
	{
		return (Vector3*)(*(uintptr_t*)this + hazedumper::netvars::m_vecViewOffset);
	}
	Vector3* GetOrigin()
	{
		return (Vector3*)(*(uintptr_t*)this + hazedumper::netvars::m_vecOrigin);
	}
	int* GetTeam()
	{
		return(int*)(*(uintptr_t*)this + hazedumper::netvars::m_iTeamNum);
	}
	int* GetHealth()
	{
		return(int*)(*(uintptr_t*)this + hazedumper::netvars::m_iHealth);
	}
	float GetDistance(Vector3* other)
	{
		Vector3* myPos = GetOrigin();
		Vector3 delta = Vector3(other->x - myPos->x, other->y - myPos->y, other->z - myPos->z);
		return sqrt(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
	}
	void AimAt(Vector3 target)//here
	{
		static uint32_t engineModule = (uint32_t)GetModuleHandle(L"engine.dll");
		static Vector3* viewAngles = (Vector3*)(*(uint32_t*)(engineModule + hazedumper::signatures::dwClientState_ViewAngles)+ hazedumper::signatures::dwClientState_ViewAngles);


		Vector3 origin = *GetOrigin();
		Vector3 vievOffset = *GetViewOffset();
		Vector3* myPos = &(origin + vievOffset);
		double PI = 3.14159265358;
		Vector3 deltaVec = { target.x - myPos->x,target.y - myPos->y,target.z - myPos->z };
		float deltaVecLength = sqrt(deltaVec.x * deltaVec.x + deltaVec.y * deltaVec.y + deltaVec.z * deltaVec.z);
		float pitch = -asin(deltaVec.z / deltaVecLength) * (180 / PI);
		float yaw = atan2(deltaVec.y, deltaVec.x) * (180 / PI);
		if (pitch >= -89 && pitch <= 89 && yaw >= -180 && yaw <= 180)
		{
			viewAngles->x = pitch;
			viewAngles->y = yaw;
		}
		

	}
	
};
