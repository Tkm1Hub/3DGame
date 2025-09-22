#include "stdafx.h"
#include "GameScene.h"
#include "ObjectManager.h"
#include "CameraManager.h"
#include "Input.h"
GameScene::GameScene(SceneManager& manager)
	: Scene{manager}{
	Init();
}

GameScene::~GameScene() {}

void GameScene::Init()
{
	objectMgr = std::make_shared<ObjectManager>();

	objectMgr->Create();

	// shared_ptr -> weak_ptr ‚É•ÏŠ·
	std::vector<std::weak_ptr<IGameObject>> weakObjects;
	for (auto& obj : objectMgr->GetObjects()) {
		weakObjects.push_back(obj);
	}

	CameraManager::GetCameraManager().SetObjects(weakObjects);
	CameraManager::GetCameraManager().Create();

	objectMgr->InitAll();

	objectMgr->LoadAll();

}

void GameScene::Update()
{
	Input::GetInput().Update();
	objectMgr->UpdateAll();
	CameraManager::GetCameraManager().Update();
	
}

void GameScene::Draw()const
{
	objectMgr->DrawAll();
}