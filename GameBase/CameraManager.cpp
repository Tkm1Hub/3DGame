#include "stdafx.h"
#include "CameraManager.h"
#include "CameraSelector.h"
#include "Player.h"

void CameraManager::Create()
{
	for (auto& objWeak : objects)
	{
		if (auto obj = objWeak.lock())
		{
			auto p = std::dynamic_pointer_cast<Player>(obj);
			if (p)
			{
				player = p;
				break;
			}
		}
	}

	// インスタンス化
	mainCamera = std::make_shared<MainCamera>();
	freeCamera = std::make_shared<FreeCamera>();

	freeCamera->SetPlayer(player);

	// カメラをリストに追加
	AddCamera(freeCamera);

	cameraSelector = std::make_shared<CameraSelector>(cameras);

}

void CameraManager::AddCamera(std::shared_ptr<VirtualCameraBase> camera)
{
	cameras.push_back(camera);
}

void CameraManager::Init()
{

}

void CameraManager::Update()
{
	for (auto& cam : cameras)
	{
		cam->Update();
	}

	cameraSelector->Update(mainCamera);
}