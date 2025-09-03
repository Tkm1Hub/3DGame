#pragma once
#include "Character.h"
#include "StateMachine.h"

// �p�����[�^
struct PlayerParams
{
	float JumpPower = 2.5f;		// �W�����v��
	float Gravity = 0.08f;		// �d��
};

class Player :public Character
{
public:
	Player(const std::string& name) : Character(name){}

	void Init() override;
	void Load() override;
	void Update() override;
	void Draw() override;

	PlayerParams params;		// �p�����[�^
	

private:
	StateMachine stateMachine;	// �X�e�[�g�}�V��

};