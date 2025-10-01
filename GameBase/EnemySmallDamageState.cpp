#include "stdafx.h"
#include "EnemySmall.h"
#include "EnemySmallDamageState.h"
#include "EnemySmall_StandState.h"

void EnemySmall_DamageState::OnStart()
{
	m_moveSpeed = m_pEnemySmall->GetParams().DamageSpeed;
}

void EnemySmall_DamageState::OnUpdate()
{
	m_frameCount++;

	m_moveSpeed -= 0.2f;
	if (m_moveSpeed < 0.0f)
	{
		m_moveSpeed = 0.0f;
	}
	// ノックバック速度を設定
	m_pEnemySmall->SetMoveSpeed(m_moveSpeed);
	// 方向をmoveVecに保存
	m_pEnemySmall->SetMoveVec(m_pEnemySmall->GetKnockBackDir());
	
	if (m_frameCount > 25)
	{
		auto spStandState = std::make_shared<EnemySmall_StandState>();
		m_pEnemySmall->ChangeState(spStandState);
	}
}

void EnemySmall_DamageState::OnExit()
{
	m_pEnemySmall->SetDamageFlag(false);
}
