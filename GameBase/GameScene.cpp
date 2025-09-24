#include "stdafx.h"
#include "GameScene.h"
#include "ObjectManager.h"
#include "CollisionManager.h"
#include "CameraManager.h"
#include "Input.h"
GameScene::GameScene(SceneManager& manager)
	: Scene{manager}{
	Init();
}

GameScene::~GameScene() {}

void GameScene::Init()
{
	//インスタンス化
	objectMgr = std::make_shared<ObjectManager>();
	collisionMgr = std::make_shared<CollisionManager>();

	// オブジェクトの生成
	objectMgr->Create();

	// shared_ptr -> weak_ptr に変換
	std::vector<std::weak_ptr<IGameObject>> weakObjects;
	for (auto& obj : objectMgr->GetObjects()) {
		weakObjects.push_back(obj);
	}

	// カメラマネージャーにオブジェのリストを渡す
	CameraManager::GetCameraManager().SetObjects(weakObjects);
	CameraManager::GetCameraManager().Create();

	// オブジェクトの初期化
	objectMgr->InitAll();
	objectMgr->LoadAll();

	collisionMgr->SetObjects(objectMgr->GetObjects());
	collisionMgr->Init();

}

void GameScene::Update()
{
	// 入力の更新
	Input::GetInput().Update();

	// オブジェクトの更新
	objectMgr->UpdateAll();

	// 当たり判定の更新
	collisionMgr->Update();

	// オブジェクトの位置を確定
	objectMgr->ApplyCollision();

	// カメラの更新
	CameraManager::GetCameraManager().Update();
	
}

void GameScene::Draw()const
{
	objectMgr->DrawAll();
}