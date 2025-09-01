#pragma once
#include "GameObject.h"

class MainCamera;
class SkyDome;
class Stage;
class Player;
class FreeCamera;
class ObjectManager
{
public:
	void Create();
	void AddObject(std::shared_ptr<IGameObject> obj);
	std::shared_ptr<IGameObject> FindObject(std::string name);
	void InitAll();
	void LoadAll();
	void UpdateAll();
	void DrawAll();

	const std::vector<std::shared_ptr<IGameObject>>& GetObjects() const { return objects; }

private:
	std::vector<std::shared_ptr<IGameObject>> objects;

	std::shared_ptr<MainCamera> camera = nullptr;
	std::shared_ptr<FreeCamera> freeCamera = nullptr;
	std::shared_ptr<SkyDome> skyDome = nullptr;
	std::shared_ptr<Stage> stage = nullptr;
	std::shared_ptr<Player> player = nullptr;
};