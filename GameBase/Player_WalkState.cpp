#include "stdafx.h"
#include "Player_WalkState.h"
#include "Player_StandState.h"
#include "Player_JumpState.h"
#include "CameraManager.h"
#include "Player.h"
#include "Input.h"

void Player_WalkState::OnStart()
{

}

void Player_WalkState::OnUpdate()
{
	VECTOR moveVec = m_pPlayer->GetMoveInput();

	m_pPlayer->SetMoveVec(moveVec);

	// スティック入力がない場合Standに戻る
	if (!Input::GetInput().GetIsMoveLStick())
	{
		auto spStandState = std::make_shared<Player_StandState>();
		m_pPlayer->ChangeState(spStandState);
		return;
	}

	// A（３）ボタンでジャンプ
	if (Input::GetInput().GetNowFrameNewInput() & PAD_INPUT_A)
	{
		auto spJumpState = std::make_shared<Player_JumpState>();
		m_pPlayer->ChangeState(spJumpState);
	}
}

void Player_WalkState::OnExit()
{

}

