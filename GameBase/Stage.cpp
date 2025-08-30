#include "stdafx.h"
#include "Stage.h"

void Stage::Init()
{
	pos = VGet(0.0f, -5.0f, 0.0f);
}

void Stage::Load()
{
	modelHandle = MV1LoadModel("data/model/stage/Test_Fast.mv1");
	MV1SetPosition(modelHandle, pos);
}

void Stage::Draw()
{
	MV1DrawModel(modelHandle);
}