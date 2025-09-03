#pragma once
#include "Character.h"
#include "StateMachine.h"

// パラメータ
struct PlayerParams
{
	float JumpPower = 2.5f;		// ジャンプ力
	float Gravity = 0.08f;		// 重力
};

class Player :public Character
{
public:
	Player(const std::string& name) : Character(name){}

	void Init() override;
	void Load() override;
	void Update() override;
	void Draw() override;

	PlayerParams params;		// パラメータ
	

private:
	StateMachine stateMachine;	// ステートマシン

};