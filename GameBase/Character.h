#pragma once
#include "GameObject.h"

class Character :public IGameObject
{
public:
	Character(const std::string& name):IGameObject(name){}
protected:
	// �萔
	static constexpr float	FallUpPower = 0.05f;			// ���𓥂݊O�������̃W�����v��

	// �L�����N�^�[�p�ϐ�
	VECTOR moveVec = VGet(0.0f, 0.0f, 0.0f);				// �ړ��x�N�g��
	VECTOR targetMoveDirection = VGet(0.0f, 0.0f, 0.0f);	// ���f���������ׂ������̃x�N�g��
	float angle = 0.0f;										// ���f���̊p�x
	float currentMoveSpeed = 0.0f;							// ���݂̈ړ����x
	float currentJumpPower = 0.0f;							// Y�������̑��x
};