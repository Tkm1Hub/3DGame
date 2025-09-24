#include "stdafx.h"
#include "Player_StandState.h"
#include "Player_WalkState.h"
#include "Player_JumpState.h"
#include "Player.h"
#include "Input.h"

void Player_StandState::OnStart()
{
	// 移動ベクトルの初期化
	m_pPlayer->SetMoveVec(VGet(0.0f, 0.0f, 0.0f));

}

void Player_StandState::OnUpdate()
{
	// 左スティックが入力中なら移動
	if (Input::GetInput().GetIsMoveLStick())
	{
		auto spStandState = std::make_shared<Player_WalkState>();
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

void Player_StandState::OnExit()
{

}