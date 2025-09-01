#include "stdafx.h"
#include "Stage.h"

void Stage::Init()
{
	pos = VGet(0.0f, -5.0f, 0.0f);
	modelScale = VGet(0.05f, 0.05f, 0.05f);
}

void Stage::Load()
{
	modelHandle = MV1LoadModel("data/model/stage/Test_Frat.mv1");
	MV1SetScale(modelHandle, modelScale);
	MV1SetPosition(modelHandle, pos);
}

void Stage::Draw()
{
	MV1DrawModel(modelHandle);
}