#include "stdafx.h"
#include "GameScene.h"
#include "ObjectManager.h"

GameScene::GameScene(SceneManager& manager)
	: Scene{manager}{
	Init();
}

GameScene::~GameScene() {}

void GameScene::Init()
{
	objectMgr = std::make_shared<ObjectManager>();

	objectMgr->Create();

	objectMgr->InitAll();

	objectMgr->LoadAll();
}

void GameScene::Update()
{
	objectMgr->UpdateAll();
}

void GameScene::Draw()const
{
	objectMgr->DrawAll();
}
