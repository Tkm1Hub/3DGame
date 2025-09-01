#include "stdafx.h"
#include "CameraSelector.h"
#include "FreeCamera.h"
#include "MainCamera.h"

void CameraSelector::SetObjects(const std::vector<std::shared_ptr<IGameObject>>& objectsPtr)
{
	objects = objectsPtr;
}

void CameraSelector::Update()
{
	VECTOR nextPos = VGet(0.0f, 0.0f, 0.0f);
	VECTOR nextTarget = VGet(0.0f, 0.0f, 0.0f);

	nextPos = freeCamera->GetPosition();
	nextTarget = freeCamera->GetTarget();

	mainCamera->SetCameraPositionAndTarget(nextPos, nextTarget);
	
}