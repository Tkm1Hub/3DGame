#include "stdafx.h"
#include "ObjectManager.h"
#include "MainCamera.h"
#include "SkyDome.h"
#include "Stage.h"
void ObjectManager::Create()
{
	camera = std::make_shared<MainCamera>("Camera");
	skyDome = std::make_shared<SkyDome>("SkyDome");
	stage = std::make_shared<Stage>("Stage");

	AddObject(camera);
	AddObject(skyDome);
	AddObject(stage);
}

void ObjectManager::AddObject(std::shared_ptr<IGameObject> obj)
{
	objects.push_back(obj);
}

/// <summary>
/// �I�u�W�F�N�g�𖼑O�Ō�������
/// </summary>
/// <param name="name"></param>
/// <returns></returns>
std::shared_ptr<IGameObject> ObjectManager::FindObject(std::string name)
{
	for (auto obj : objects) {
		if (obj->GetName() == name) {
			return obj;
		}
	}
	return nullptr;
}

/// <summary>
/// �I�u�W�F�N�g�̏�����
/// </summary>
void ObjectManager::InitAll()
{
	for (auto obj : objects)
	{
		obj->Init();
	}
}

/// <summary>
/// ���f���Ȃǂ̃��[�h
/// </summary>
void ObjectManager::LoadAll()
{
	for (auto obj : objects)
	{
		obj->Load();
	}
}

/// <summary>
/// �I�u�W�F�N�g�̍X�V
/// </summary>
void ObjectManager::UpdateAll()
{
	for (auto obj : objects)
	{
		obj->Update();
	}
}

/// <summary>
/// �I�u�W�F�N�g�̕`��
/// </summary>
void ObjectManager::DrawAll()
{
	for (auto obj : objects)
	{
		obj->Draw();
	}
}