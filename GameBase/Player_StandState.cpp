#include "stdafx.h"
#include "Player_StandState.h"
#include "Input.h"

void Player_StandState::OnStart()
{
	// �ړ��x�N�g���̏�����
	m_pPlayer->SetMoveVec(VGet(0.0f, 0.0f, 0.0f));

}

void Player_StandState::OnUpdate()
{
	// ���X�e�B�b�N�����͒��Ȃ�ړ�
	if (Input::GetInput().GetIsMoveLStick())
	{

	}

	// A�i�R�j�{�^���ŃW�����v
	if (Input::GetInput().GetNowFrameNewInput())
	{

	}

}

void Player_StandState::OnExit()
{

}