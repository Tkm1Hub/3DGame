#include "stdafx.h"
#include "EnemySmall.h"
#include "EnemySmallDamageState.h"
#include "EnemySmall_StandState.h"

void EnemySmall_DamageState::OnStart()
{
	m_moveSpeed = m_pEnemySmall->GetParams().DamageSpeed;
	m_moveVec = CulcKnockBackVector();

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
<<<<<<< HEAD
<<<<<<< HEAD
	// 方向をmoveVecに保存
	m_pEnemySmall->SetMoveVec(m_pEnemySmall->GetKnockBackDir());
	
=======
	// ノックバック方向ベクトルを設定
	m_pEnemySmall->SetMoveVec(m_moveVec);

>>>>>>> parent of 87dd04a (9/30)
=======
	// ノックバック方向ベクトルを設定
	m_pEnemySmall->SetMoveVec(m_moveVec);

>>>>>>> parent of 87dd04a (9/30)
	if (m_frameCount > 25)
	{
		auto spStandState = std::make_shared<EnemySmall_StandState>();
		m_pEnemySmall->ChangeState(spStandState);
	}
}

void EnemySmall_DamageState::OnExit()
{

}

VECTOR EnemySmall_DamageState::CulcKnockBackVector()
{
	// 敵からプレイヤーへの方向ベクトルを取得
	VECTOR KnockBackDirection = m_pEnemySmall->GetDirectionToPlayer();
	// 方向を反転
	KnockBackDirection = VScale(KnockBackDirection, -1.0f);

	return KnockBackDirection;
}