#pragma once
#include "DxLib.h"
#include <iostream>
class IGameObject
{
public:
	IGameObject(const std::string& name = ""):name(name){}
	virtual ~IGameObject() {}
	virtual void Init()		{/*デフォルトでは何も実装しない*/}
	virtual void Load()		{/*デフォルトでは何も実装しない*/}
	virtual void Update()	{/*デフォルトでは何も実装しない*/}
	virtual void Draw()		{/*デフォルトでは何も実装しない*/}

	VECTOR GetPosition() const { return pos; }
	std::string GetName() const { return name; }

protected:
	std::string name = "null";
	VECTOR pos = VGet(0.0f, 0.0f, 0.0f);
	VECTOR modelScale = VGet(0.0f, 0.0f, 0.0f);
	int modelHandle = -1;
};