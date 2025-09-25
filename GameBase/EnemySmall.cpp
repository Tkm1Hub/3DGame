#include "stdafx.h"
#include "EnemySmall.h"

void EnemySmall::Init()
{
	modelScale = VGet(0.1f, 0.1f, 0.1f);
	isStageCollisionEnabled = true;
	isCollisionEnabled = true;
	isShadowEnabled = true;
}

void EnemySmall::Load()
{
	// ƒ‚ƒfƒ‹ƒnƒ“ƒhƒ‹Žæ“¾
	modelHandle = MV1LoadModel("data/model/character/robot.mv1");
	MV1SetScale(modelHandle, modelScale);
	MV1SetPosition(modelHandle, params.InitPos);
}

void EnemySmall::Update()
{

}

void EnemySmall::Draw()
{

}

