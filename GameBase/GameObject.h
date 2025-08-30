#pragma once
#include "DxLib.h"
#include <iostream>
class IGameObject
{
public:
	IGameObject(const std::string& name = ""):name(name){}
	virtual ~IGameObject() = default;
	virtual void Init() abstract;
	virtual void Load() abstract;
	virtual void Update() abstract;
	virtual void Draw() abstract;

	VECTOR GetPosition() const { return pos; }
	std::string GetName() const { return name; }

protected:
	std::string name = "null";
	VECTOR pos = VGet(0.0f, 0.0f, 0.0f);
	int modelHandle = -1;
};