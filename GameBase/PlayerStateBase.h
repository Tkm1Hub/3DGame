#pragma once
#include "StateBase.h"
#include "Player.h"
class PlayerStateBase : public StateBase
{
public:
	void SetOwner(Player* a_pPlayer)
	{
		m_pPlayer = a_pPlayer;
	}

protected:
	Player* m_pPlayer = nullptr;
};