#include "stdafx.h"
#include "Player.h"

void Player::Init()
{
	modelScale = VGet(0.1f, 0.1f, 0.1f);
}

void Player::Load()
{
	modelHandle = MV1LoadModel("data/model/character/Hideron.mv1");
	MV1SetScale(modelHandle, modelScale);
	MV1SetPosition(modelHandle, pos);
}

void Player::Update()
{

}

void Player::Draw()
{
	MV1DrawModel(modelHandle);
}