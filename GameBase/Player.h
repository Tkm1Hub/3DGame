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
	float HitRadius = 3.0f;		// 当たり判定半径
	float HitHeight = 16.5f;	// 当たり判定高さ
	VECTOR InitPos = { 0.0f,0.0f,0.0f };	// 初期座標
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

	const float GetHitRadius() const override { return params.HitRadius; }
	const float GetHitHeight() const override { return params.HitHeight; }

	void OnHitRoof() override;       // 天井に当たった時
	void OnHitFloor() override;      // 床に当たった時
	void OnFall() override;          // 落下が確定したとき

	PlayerParams params;		// パラメータ
	VECTOR GetMoveInput();		// スティックによる移動ベクトルの取得
	const PlayerParams GetParams() const { return params; }

private:
	StateMachine stateMachine;	// ステートマシン

	void Move();	// モデルの移動

	void UpdateAngle();			// モデルの角度更新

};