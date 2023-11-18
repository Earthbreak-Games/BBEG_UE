// Copyright Earthbreak Games LLC 2023


#include "CharacterStates.h"
#include "BBEG_BaseUnit.h"
#include <Kismet/GameplayStatics.h>

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, text)

/*
* Base State
*/

FBaseUnitState::FBaseUnitState()
{
	StateType = EUnitState::EUS_Uninitialized;
	BaseUnit = nullptr;
}

FBaseUnitState::~FBaseUnitState()
{
}

/*
* Idle State
*/

void IdleState::Tick(float deltaTime)
{
	//BaseUnit->GetLocalViewingPlayerController()->SetIgnoreMoveInput(false);

}

void IdleState::Enter()
{
	
	// Stop the unit (no idea how as of right now)
	BaseUnit->GetLocalViewingPlayerController()->SetIgnoreMoveInput(true);
}

void MoveState::Tick(float deltaTime)
{
	// Character class handles this part largely
}

void MoveState::Enter()
{
}

void AttackState::Tick(float deltaTime)
{
	
	timeElapsed += deltaTime;
        if (timeElapsed > mHitbox->GetTotalAttackTime())
        {
            BaseUnit->SwitchState(EUnitState::EUS_Idle);
            BaseUnit->ResumeInput();
            
            return;
        }

        if (timeElapsed > mHitbox->mActiveTime + mHitbox->mStartupTime && phase == AttackPhase::Active)
        {
            mHitbox->EndLagPhase();
            phase = AttackPhase::Endlag;
        }

        if (timeElapsed > mHitbox->mStartupTime && phase == AttackPhase::Startup)
        {
            mHitbox->ActivePhase();
            phase = AttackPhase::Active;
        }
	
}

void AttackState::Enter()
{
    BaseUnit->PauseInput();
}
