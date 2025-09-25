#include "stdafx.h"
#include "EnemySmall_StandState.h"
#include "EnemySmall.h"

void EnemySmall_StandState::OnStart()
{
	// ˆÚ“®ƒxƒNƒgƒ‹‚Ì‰Šú‰»
	m_pEnemySmall->SetMoveVec(VGet(0.0f, 0.0f, 0.0f));

}

void EnemySmall_StandState::OnUpdate()
{

}

void EnemySmall_StandState::OnExit()
{

}