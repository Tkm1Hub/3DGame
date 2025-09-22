#include "stdafx.h"
#include "Player.h"
#include "Player_StandState.h"

void Player::Init()
{
	modelScale = VGet(0.1f, 0.1f, 0.1f);
	auto spStandState = std::make_shared<Player_StandState>();
	ChangeState(spStandState);
}

void Player::Load()
{
	modelHandle = MV1LoadModel("data/model/character/Hideron.mv1");
	MV1SetScale(modelHandle, modelScale);
	MV1SetPosition(modelHandle, pos);
}

void Player::Update()
{
	// ステートの更新
	stateMachine.Update();

	// モデルの移動
	Move(moveVec);

	// モデルの方向更新
	UpdateAngle();
}

void Player::Draw()
{
	MV1DrawModel(modelHandle);
}

void Player::ChangeState(std::shared_ptr<PlayerStateBase> a_spState)
{
	a_spState->SetOwner(this);
	stateMachine.ChangeState(a_spState);
}

void Player::Move(const VECTOR& moveVec)
{
	pos = VAdd(pos,VScale(moveVec, params.MoveSpeed));

	MV1SetPosition(modelHandle, pos);
}

void Player::UpdateAngle()
{
	// プレイヤーの移動方向にモデルの方向を近づける
	float targetAngle;			// 目標角度
	float difference;			// 目標角度と現在の角度との差
	float speed = params.AngleSpeed;	// 角度変更速度

	if (VSize(moveVec) != 0.0f)
	{
		targetMoveDirection = VNorm(moveVec);
	}

	// 目標の方向ベクトルから角度値を算出する
	targetAngle = static_cast<float>(atan2(targetMoveDirection.x, targetMoveDirection.z));

	// 目標の角度と現在の角度との差を割り出す
	// 最初は単純に引き算
	difference = targetAngle - angle;

	// ある方向からある方向の差が１８０度以上になることは無いので
	// 差の値が１８０度以上になっていたら修正する
	if (difference < -DX_PI_F)
	{
		difference += DX_TWO_PI_F;
	}
	else if (difference > DX_PI_F)
	{
		difference -= DX_TWO_PI_F;
	}

	// 角度の差が０に近づける
	if (difference > 0.0f)
	{
		// 差がプラスの場合は引く
		difference -= speed;
		if (difference < 0.0f)
		{
			difference = 0.0f;
		}
	}
	else
	{
		// 差がマイナスの場合は足す
		difference += speed;
		if (difference > 0.0f)
		{
			difference = 0.0f;
		}
	}

	// モデルの角度を更新
	angle = targetAngle - difference;

	MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle + DX_PI_F, 0.0f));
}