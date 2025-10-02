#pragma once
#include "Character.h"
#include "StateMachine.h"

// パラメータ
struct EnemySmall_Params
{
	float Gravity = 0.08f;		// 重力
	float DamageSpeed = 3.0f;	// ダメージ中ノックバックの速度
	float HitRadius = 4.0f;		// 当たり判定半径
	float HitHeight = 14.0f;	// 当たり判定高さ
	VECTOR InitPos = { 0.0f,0.0f,30.0f };	// 初期座標
};

class Player;
class EnemySmallStateBase;
class EnemySmall :public Character
{
public:
	EnemySmall(const std::string& name):Character(name){}

	void Init() override;
	void Load() override;
	void Update() override;
	void Draw() override;

<<<<<<< HEAD
<<<<<<< HEAD
	void SetKnockBackDir(VECTOR dir) { knockBackDirection = dir; }
	VECTOR GetKnockBackDir()const { return knockBackDirection; }
=======
	void SetPlayer(std::shared_ptr<Player> player) { player = m_pPlayer; }

>>>>>>> parent of 87dd04a (9/30)
=======
	void SetPlayer(std::shared_ptr<Player> player) { player = m_pPlayer; }

>>>>>>> parent of 87dd04a (9/30)
	void SetDamageFlag(bool flag) { isDamage = flag; }
	const bool GetDamageFlag() const { return isDamage; }

	VECTOR GetDirectionToPlayer();

	void ChangeState(std::shared_ptr<EnemySmallStateBase> a_spState);


	const float GetHitRadius() const override { return params.HitRadius; }
	const float GetHitHeight() const override { return params.HitHeight; }

	void OnHitRoof() override;       // 天井に当たった時
	void OnHitFloor() override;      // 床に当たった時
	void OnFall() override;          // 落下が確定したとき

	const EnemySmall_Params GetParams() const { return params; }
private:
	std::shared_ptr<Player> m_pPlayer = nullptr;	// プレイヤーのポインタ
	EnemySmall_Params params;	// パラメータ
	StateMachine stateMachine;	// ステートマシン

	VECTOR knockBackDirection = { 0.0f,0.0f,0.0f };	// ノックバックベクトル

	bool isDamage = false;

	void Move();
};