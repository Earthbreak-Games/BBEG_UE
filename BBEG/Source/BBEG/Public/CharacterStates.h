// Copyright Earthbreak Games LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "Hitbox.h"

UENUM()
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
	virtual ~FBaseUnitState();

	EUnitState StateType;
	bool bCanExit = true; // Set to false during certain actions like attacks, dodge rolls, or other uninterupatble states

	virtual void Tick(float deltaTime) {}

	virtual void Enter() {}


	ABBEG_BaseUnit* BaseUnit;
};

class IdleState : public FBaseUnitState
{
public:
	IdleState(ABBEG_BaseUnit* b)
	{
		BaseUnit = b;
		StateType = EUnitState::EUS_Idle;
		Enter();
	}

	void Tick(float deltaTime) override;

	// Entering Idle State instantly kills any velocity the character has
	void Enter() override;
};



class AttackState : public FBaseUnitState
{
public:
	float timeElapsed;
	TSharedPtr<AHitbox> mHitbox;
	AttackPhase phase;

	AttackState(ABBEG_BaseUnit* b, AHitbox* h)
	{
		BaseUnit = b;
		StateType = EUnitState::EUS_Attack;
		timeElapsed = 0;
		mHitbox = TSharedPtr<AHitbox>(h);
		phase = AttackPhase::Startup;

		Enter();
	}

	void Tick(float deltaTime) override;

	// Entering Idle State instantly kills any velocity the character has
	void Enter() override;
};

class MoveState : public FBaseUnitState
{
public:
	MoveState(ABBEG_BaseUnit* b)
	{
		BaseUnit = b;
		StateType = EUnitState::EUS_Move;
		Enter();
	}

	void Tick(float deltaTime) override;

	// Entering Idle State instantly kills any velocity the character has
	void Enter() override;
};

class DodgeState : public FBaseUnitState
{
public:
	DodgeState(ABBEG_BaseUnit* b)
	{
		BaseUnit = b;
		StateType = EUnitState::EUS_Dodge;
		Enter();
	}

	void Tick(float deltaTime) override;

	// Entering Idle State instantly kills any velocity the character has
	void Enter() override;
};