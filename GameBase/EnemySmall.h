#pragma once
#include "Character.h"

// パラメータ
struct EnemySmall_Params
{
	float HitRadius = 3.0f;		// 当たり判定半径
	float HitHeight = 14.0f;	// 当たり判定高さ
	VECTOR InitPos = { 0.0f,0.0f,30.0f };	// 初期座標
};

class EnemySmall :public Character
{
public:
	EnemySmall(const std::string& name):Character(name){}

	void Init() override;
	void Load() override;
	void Update() override;
	void Draw() override;

	const float GetHitRadius() const override { return params.HitRadius; }
	const float GetHitHeight() const override { return params.HitHeight; }

	void OnHitRoof() override;       // 天井に当たった時
	void OnHitFloor() override;      // 床に当たった時
	void OnFall() override;          // 落下が確定したとき


private:
	EnemySmall_Params params;	// パラメータ
};