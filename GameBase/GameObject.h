#pragma once
#include "DxLib.h"
#include <iostream>
class IGameObject
{
public:
	IGameObject(const std::string& name = ""):name(name){}
	virtual ~IGameObject() {}
	virtual void Init()		{/*�f�t�H���g�ł͉����������Ȃ�*/}
	virtual void Load()		{/*�f�t�H���g�ł͉����������Ȃ�*/}
	virtual void Update()	{/*�f�t�H���g�ł͉����������Ȃ�*/}
	virtual void Draw()		{/*�f�t�H���g�ł͉����������Ȃ�*/}

	VECTOR GetPosition() const { return pos; }
	std::string GetName() const { return name; }

protected:
	std::string name = "null";
	VECTOR pos = VGet(0.0f, 0.0f, 0.0f);
	VECTOR modelScale = VGet(0.0f, 0.0f, 0.0f);
	int modelHandle = -1;
};