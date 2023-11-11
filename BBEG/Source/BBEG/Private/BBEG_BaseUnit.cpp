// Copyright Earthbreak Games LLC 2023


#include "BBEG_BaseUnit.h"
#include "Buff.h"
#include "CharacterStates.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ABBEG_BaseUnit::ABBEG_BaseUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	State = TSharedPtr<FBaseUnitState>(new FBaseUnitState());

}

// Called when the game starts or when spawned
void ABBEG_BaseUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABBEG_BaseUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	State->Tick(DeltaTime);
	
	
}

// Called to bind functionality to input
void ABBEG_BaseUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABBEG_BaseUnit::Hit(int damage)
{
	if (damage < 0)
	{
		damage = 0;
	}
	CurrHealth -= damage;
	TimeSinceLastHit = 0;
	
	if (CurrHealth <= 0)
	{
		//character death
	}
}

void ABBEG_BaseUnit::Heal(int healValue)
{
	CurrHealth += healValue;
	if (CurrHealth > GetMaxHealth())
	{
		CurrHealth = GetMaxHealth();
	}
}

int ABBEG_BaseUnit::GetMaxHealth()
{
	int maxHealthBuffTotal = 0;
	//Iterate through active buffs and add up total buffed health

	return maxHealthBuffTotal + BaseHealth;
}

int ABBEG_BaseUnit::GetCurrentHealth()
{
	return CurrHealth;
}

int ABBEG_BaseUnit::GetDefense()
{
	int defenseBuffTotal = 0;
	//Iterate through active buffs and add up total buffed defense

	return defenseBuffTotal;
}

int ABBEG_BaseUnit::GetMeleeAffinity()
{
	int meleeAffinityBuffTotal = 0;
	//Iterate through active buffs and add up total buffed melee affinity

	return meleeAffinityBuffTotal;
}

int ABBEG_BaseUnit::GetRangedAffinity()
{
	int rangedAffinityBuffTotal = 0;
	//Iterate through active buffs and add up total buffed ranged affinity

	return rangedAffinityBuffTotal;
}

EUnitState ABBEG_BaseUnit::GetState()
{
	return State.Get()->StateType;
}

void ABBEG_BaseUnit::StartAttack(AHitbox* hitbox)
{
	State = TSharedPtr<AttackState>(new AttackState(this, hitbox));
}

void ABBEG_BaseUnit::Stop()
{
	GetCharacterMovement()->Velocity = FVector(0, 0, 0);

}

void ABBEG_BaseUnit::PauseInput()
{
	GetLocalViewingPlayerController()->SetIgnoreMoveInput(true);

}

void ABBEG_BaseUnit::ResumeInput()
{
	GetLocalViewingPlayerController()->SetIgnoreMoveInput(false);
}
