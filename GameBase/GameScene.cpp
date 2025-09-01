#include "stdafx.h"
#include "GameScene.h"
#include "ObjectManager.h"
#include "CameraSelector.h"

GameScene::GameScene(SceneManager& manager)
	: Scene{manager}{
	Init();
}

GameScene::~GameScene() {}

void GameScene::Init()
{
	objectMgr = std::make_shared<ObjectManager>();
	cameraSelector = std::make_shared<CameraSelector>();

	objectMgr->Create();

	objectMgr->InitAll();

	objectMgr->LoadAll();

	freeCamera = std::dynamic_pointer_cast<FreeCamera>(objectMgr->FindObject("FreeCamera"));
	mainCamera = std::dynamic_pointer_cast<MainCamera>(objectMgr->FindObject("MainCamera"));

	cameraSelector->SetFreeCamera(freeCamera);

	cameraSelector->SetMainCamera(mainCamera);
}

void GameScene::Update()
{
	objectMgr->UpdateAll();
	
	cameraSelector->Update();
}

void GameScene::Draw()const
{
	objectMgr->DrawAll();
}
