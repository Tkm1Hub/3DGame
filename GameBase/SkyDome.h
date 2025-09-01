#pragma once
#include "GameObject.h"

class SkyDome : public IGameObject
{
public:
	SkyDome(const std::string&name):IGameObject(name){}

	void Init() override;
	void Load() override;
	void Draw() override;

private:
	VECTOR scale = VGet(0.8f, 0.8f, 0.8f);
};