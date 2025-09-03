#pragma once
#include "Character.h"
class StateMachine;
class Player :public Character
{
public:
	Player(const std::string& name) : Character(name){}

	void Init() override;
	void Load() override;
	void Update() override;
	void Draw() override;

private:
	// �X�e�[�g�}�V��
};