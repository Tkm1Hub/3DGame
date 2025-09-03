#include "stdafx.h"
#include "Player_StandState.h"
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

	}

	// A（３）ボタンでジャンプ
	if (Input::GetInput().GetNowFrameNewInput())
	{

	}

}

void Player_StandState::OnExit()
{

}