// Copyright Earthbreak Games LLC 2023


#include "CharacterStates.h"
#include "../BBEG_BaseUnit.h"

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

void IdleState::Tick()
{
}

void IdleState::Enter()
{
	// Stop the unit
	BaseUnit->AddMovementInput(FVector::Zero(), 1.0f, true); // NB: I don't think this works cause it's just adding an additional zero rather than zeroing out the velocity
}