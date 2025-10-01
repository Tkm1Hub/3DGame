#pragma once
#include "GameObject.h"

class MainCamera;
class SkyDome;
class Stage;
class Player;
class EnemySmall;
class FreeCamera;
class Sword;
class ObjectManager
{
private:
	//コンストラクタを非公開にする
	ObjectManager() {}

	// コピーコンストラクタと代入演算子を削除
	ObjectManager(const ObjectManager&) = delete;
	ObjectManager& operator=(const ObjectManager&) = delete;

	//プライベートデストラクタ
	~ObjectManager() {}


public:
	// インスタンスを取得するためのメソッド
	static ObjectManager& GetObjectMgr()
	{
		static ObjectManager instance;      // 静的変数としてインスタンスを定義
		return instance;
	}

	void Create();
	void AddObject(std::shared_ptr<IGameObject> obj);
	std::shared_ptr<IGameObject> FindObject(std::string name);
	void InitAll();
	void LoadAll();
	void UpdateAll();
	void ApplyCollision();
	void DrawAll();

	const std::vector<std::shared_ptr<IGameObject>>& GetObjects() const { return objects; }

private:
	std::vector<std::shared_ptr<IGameObject>> objects;

	std::shared_ptr<SkyDome> skyDome = nullptr;
	std::shared_ptr<Stage> stage = nullptr;
	std::shared_ptr<Player> player = nullptr;
	std::shared_ptr<EnemySmall> enemySmall = nullptr;
	std::shared_ptr<Sword> sword = nullptr;
};