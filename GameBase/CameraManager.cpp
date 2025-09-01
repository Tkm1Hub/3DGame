#include "stdafx.h"
#include "CameraManager.h"
#include "FreeCamera.h"

void CameraManager::Create()
{
	freeCamera = std::make_shared<FreeCamera>();
}

void CameraManager::AddCamera(std::shared_ptr<VirtualCameraBase> camera)
{
	cameras.push_back(camera);
}