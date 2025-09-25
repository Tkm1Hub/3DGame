#pragma once
#include "PlayerStateBase.h"
class Player_Attack2State :public PlayerStateBase
{
public:
	void OnStart() override;
	void OnUpdate() override;
	void OnExit() override;

private:
	int m_frameCount = 0;
	bool m_doNextAttack = false;
};