#pragma once
#include "ObjectManager.h"
#include "StageCollision.h"

class IGameObject;
class CollisionManager
{
public:
	void SetObjects(std::vector<std::shared_ptr<IGameObject>>objectsPtr)
	{
		objects = objectsPtr;
	}

	void Init();

	void Update();

private:
	std::vector<std::shared_ptr<IGameObject>>objects;
	std::shared_ptr<StageCollision> stageCollision = nullptr;

};