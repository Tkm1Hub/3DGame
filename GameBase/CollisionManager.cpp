#include "stdafx.h"
#include "CollisionManager.h"

void CollisionManager::Init()
{
	stageCollision = std::make_shared<StageCollision>();

	// ステージモデルのハンドルを渡す
	for (auto obj : objects)
	{
		if (obj->GetName() == "Stage")
		{
			int modelHandle = obj->GetModelHandle();
			stageCollision->SetStageCollision(modelHandle);
		}
	}
}

void CollisionManager::Update()
{
	for (auto obj : objects)
	{
		if (obj->GetIsStageCollisionEnabled())
		{
			VECTOR nextPos = stageCollision->CheckCollision(*obj, obj->GetNextPosition());
			obj->SetNextPosition(nextPos);
		}
	}
}