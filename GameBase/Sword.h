#pragma once
#include "GameObject.h"
class Player;
class Sword :public IGameObject
{
public:
	Sword(const std::string name) :IGameObject(name){}

	void Init()override;
	void Load() override;
	void Update() override;
	void Draw() override;

	void SetOwner(std::shared_ptr<Player> player) { owner = player; }

private:
	VECTOR offsetPos = { 0.0f,0.0f,0.0f };
	VECTOR offsetRot = { 0.0f,0.0f,0.0f };
	std::shared_ptr<Player> owner = nullptr;
};