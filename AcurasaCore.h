#include "PlayerEntityLoc.h"
#include "AnyPlayer.h"


Player* GetClosestEnemy()
{
	PlayerEntityloc* localplayer = PlayerEntityloc::Get();

	float closestDistance = 1000000;
	int closeDistanceIndex = -1;

	for (int i = 1; i < *Player::GetMaxPlayer(); i++)
	{
		Player* currentPlayer = Player::GetPlayer(i);

		if (!currentPlayer || !(*(uint32_t*)currentPlayer) || (uint32_t)currentPlayer == (uint32_t)localplayer)
			continue;
		if (*currentPlayer->GetTeam() == *localplayer->GetTeam())
			continue;
		if (*currentPlayer->GetHealth() < 1 || *localplayer->GetHealth() < 1)
			continue;
		
				//here
				float currentDistance = localplayer->GetDistance(currentPlayer->GetOrigin());
				if (currentDistance < closestDistance)
				{
					closestDistance = currentDistance;
					closeDistanceIndex = i;
				}

			}
			if (closestDistance == -1)
			{
				return 0;
			}
			
		return Player::GetPlayer(closeDistanceIndex);
	
}



void Run()
{
	Player* closestEnemy = GetClosestEnemy();
	if (closestEnemy)
	{
		PlayerEntityloc::Get()->AimAt(closestEnemy->GetBonePos(8)); ///HERE!!HERE!!HERE!!HERE!!
	}
}

