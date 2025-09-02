#include "stdafx.h"
#include "GameScene.h"
#include "ObjectManager.h"
#include "CameraManager.h"
GameScene::GameScene(SceneManager& manager)
	: Scene{manager}{
	Init();
}

GameScene::~GameScene() {}

void GameScene::Init()
{
	objectMgr = std::make_shared<ObjectManager>();
	cameraMgr = std::make_shared<CameraManager>();

	objectMgr->Create();

	// shared_ptr -> weak_ptr ‚É•ÏŠ·
	std::vector<std::weak_ptr<IGameObject>> weakObjects;
	for (auto& obj : objectMgr->GetObjects()) {
		weakObjects.push_back(obj);
	}

	cameraMgr->SetObjects(weakObjects);

	cameraMgr->Create();


	objectMgr->InitAll();

	objectMgr->LoadAll();

}

void GameScene::Update()
{
	objectMgr->UpdateAll();
	cameraMgr->Update();
	
}

void GameScene::Draw()const
{
	objectMgr->DrawAll();
}
