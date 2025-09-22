#pragma once
#include "Character.h"
#include "StateMachine.h"
#include "PlayerStateBase.h"

// パラメータ
struct PlayerParams
{
	float JumpPower = 2.5f;		// ジャンプ力
	float Gravity = 0.08f;		// 重力
	float MoveSpeed = 0.5f;		// 移動速度
	float AngleSpeed = 0.2f;	// 移動時のモデル回転速度
};

class PayerStateBase;
class Player :public Character
{
public:
	Player(const std::string& name) : Character(name){}

	void Init() override;
	void Load() override;
	void Update() override;
	void Draw() override;

	void ChangeState(std::shared_ptr<PlayerStateBase> a_spState);

	PlayerParams params;		// パラメータ
	

private:
	StateMachine stateMachine;	// ステートマシン

	void Move(const VECTOR& moveVec);	// モデルの移動

	void UpdateAngle();			// モデルの角度更新

};