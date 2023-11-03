// Copyright Earthbreak Games LLC 2023

#pragma once

#include "CoreMinimal.h"

enum class EUnitState : uint8
{
	EUS_Uninitialized,
	EUS_Actionable,
	EUS_Stopped,
	EUS_Idle,
	EUS_Move,
	EUS_Attack,
	EUS_Dodge
};

class ABBEG_BaseUnit;

/**
 * 
 */
class BBEG_API FBaseUnitState
{
public:
	FBaseUnitState();
	~FBaseUnitState();

	EUnitState StateType;
	bool bCanExit = true; // Set to false during certain actions like attacks, dodge rolls, or other uninterupatble states

	virtual void Tick() {}

	virtual void Enter() {}

protected:
	ABBEG_BaseUnit* BaseUnit;
};

class IdleState : FBaseUnitState
{
public:
	IdleState(ABBEG_BaseUnit* b)
	{
		BaseUnit = b;
		StateType = EUnitState::EUS_Idle;
		Enter();
	}

	void Tick() override;

	// Entering Idle State instantly kills any velocity the character has
	void Enter() override;
};