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
	VECTOR nextPos = VAdd(pos,VScale(moveVec, params.MoveSpeed));

	MV1SetPosition(modelHandle, nextPos);
}