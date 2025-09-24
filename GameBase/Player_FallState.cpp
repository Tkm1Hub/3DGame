#include "stdafx.h"
#include "Input.h"
#include "Player.h"
#include "Player_FallState.h"


void Player_FallState::OnStart()
{

}

void Player_FallState::OnUpdate()
{
	// スティックで移動
	VECTOR moveVec = m_pPlayer->GetMoveInput();
	m_pPlayer->SetMoveVec(moveVec);

	// 重力を適応
	float currentJumpPower = m_pPlayer->GetCurrentJumpPower();
	currentJumpPower -= m_pPlayer->GetParams().Gravity;
	m_pPlayer->SetJumpPower(currentJumpPower);
}

void Player_FallState::OnExit()
{

}