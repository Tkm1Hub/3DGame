#include "stdafx.h"
#include "Sword.h"
#include "Player.h"

void Sword::Init()
{
	modelScale = VGet(0.005f, 0.005f, 0.005f);
}

void Sword::Load()
{
	modelHandle = MV1LoadModel("data/model/item/Heat-KatanaV2.mv1");
	MV1SetScale(modelHandle, modelScale);
}

void Sword::Update()
{
    // 手の行列を取得（位置+回転）
    MATRIX handMat = owner->GetHandMatrix();

    // 武器用のスケール行列を作成
    MATRIX scaleMat = MGetScale(modelScale);

    // 行列を合成（スケール → 手の行列）
    MATRIX finalMat = MMult(scaleMat, handMat);

    // 武器にセット
    MV1SetMatrix(modelHandle, finalMat);
}

void Sword::Draw()
{
	MV1DrawModel(modelHandle);
}