#include "stdafx.h"
#include "Input.h"
#include "Player.h"
#include "Player_FallState.h"
#include "Player_JumpState.h"

void Player_JumpState::OnStart()
{
	// ジャンプ力を加算
	m_pPlayer->SetJumpPower(m_pPlayer->GetParams().JumpPower);
	
	// ジャンプフラグを更新
	m_pPlayer->SetIsJumping(true);
}

void Player_JumpState::OnUpdate()
{
	// スティックで移動
	VECTOR moveVec = m_pPlayer->GetMoveInput();
	m_pPlayer->SetMoveVec(moveVec);

	// 重力を適応
	float currentJumpPower = m_pPlayer->GetCurrentJumpPower();
	currentJumpPower -= m_pPlayer->GetParams().Gravity;
	m_pPlayer->SetJumpPower(currentJumpPower);

	// ジャンプ力が０以下だと落下中
	if (m_pPlayer->GetCurrentJumpPower() < 0.0f)
	{
		auto spFallState = std::make_shared<Player_FallState>();
		m_pPlayer->ChangeState(spFallState);
	}
}

void Player_JumpState::OnExit()
{

}