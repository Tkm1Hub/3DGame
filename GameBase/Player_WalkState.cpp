#include "stdafx.h"
#include "Player_WalkState.h"
#include "Player_StandState.h"
#include "CameraManager.h"
#include "Player.h"
#include "Input.h"

void Player_WalkState::OnStart()
{

}

void Player_WalkState::OnUpdate()
{
	// 移動ベクトルを初期化
	VECTOR moveVec = VGet(0.0f, 0.0f, 0.0f);

	// カメラの前方向ベクトルを取得
	VECTOR camForward = CameraManager::GetCameraManager().GetMainCamera()->GetForward();

	// カメラの横方向ベクトルを取得
	VECTOR camRight = VCross(camForward, VGet(0.0f, 1.0f, 0.0f));
	camRight = VNorm(camRight);

	// 左スティックの数値を取得
	float stickX = Input::GetInput().GetLeftStickX();
	float stickY = Input::GetInput().GetLeftStickY();

	// スティック入力をカメラの向きに変換した移動ベクトルを作成
	moveVec = VAdd(VScale(camRight, stickX), VScale(camForward, stickY));
	moveVec = VNorm(moveVec);

	m_pPlayer->SetMoveVec(moveVec);

	// スティック入力がない場合Standに戻る
	if (!Input::GetInput().GetIsMoveLStick())
	{
		auto spStandState = std::make_shared<Player_StandState>();
		m_pPlayer->ChangeState(spStandState);
		return;
	}
}

void Player_WalkState::OnExit()
{

}

