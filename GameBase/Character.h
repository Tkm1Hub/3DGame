#pragma once
#include "GameObject.h"

class Character :public IGameObject
{
public:
	Character(const std::string& name):IGameObject(name){}
protected:
	// 定数
	static constexpr float	FallUpPower = 0.05f;			// 足を踏み外した時のジャンプ力

	// キャラクター用変数
	VECTOR moveVec = VGet(0.0f, 0.0f, 0.0f);				// 移動ベクトル
	VECTOR targetMoveDirection = VGet(0.0f, 0.0f, 0.0f);	// モデルが向くべき方向のベクトル
	float angle = 0.0f;										// モデルの角度
	float currentMoveSpeed = 0.0f;							// 現在の移動速度
	float currentJumpPower = 0.0f;							// Y軸方向の速度
};