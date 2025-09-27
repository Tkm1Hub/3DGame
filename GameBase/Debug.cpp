#include "stdafx.h"
#include "Debug.h"
#include "Input.h"
#include "Player.h"
#include "EnemySmall.h"
#include "ObjectManager.h"

void Debug::Update()
{
	bool nowF1 = (CheckHitKey(KEY_INPUT_F1) != 0);
	if (nowF1 && !prevF1)
	{
		isDebugMode = !isDebugMode;
	}

	prevF1 = nowF1;
}
void Debug::Draw()
{
	// F1‚ª‰Ÿ‚³‚ê‚Ä‚¢‚È‚©‚Á‚½‚ç‘ŠúƒŠƒ^[ƒ“
	if (!isDebugMode) return;

	for (auto obj : owner)
	{
		if (obj->GetIsCollisionEnabled())
		{
			DrawCapsule(obj);
		}
	}
}


void Debug::DrawCapsule(const std::shared_ptr<IGameObject>& obj)
{
	DrawCapsule3D(VGet(obj->GetPosition().x, obj->GetPosition().y + obj->GetHitRadius(), obj->GetPosition().z)
		, VGet(obj->GetPosition().x, obj->GetPosition().y + obj->GetHitHeight(), obj->GetPosition().z)
		, obj->GetHitRadius(), 8, GetColor(0, 255, 0), GetColor(255, 255, 255), FALSE);
}