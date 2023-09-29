// Copyright Earthbreak Games LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BBEG_BaseUnit.generated.h"

UCLASS()
class BBEG_API ABBEG_BaseUnit : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABBEG_BaseUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// state enum
	int baseHealth = 5;
	int currHealth = 5;
	int baseDefense = 0;
	float timeSinceLastHit = 0;
	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Hit(int damage);
	void Heal(int healValue);
	int GetMaxHealth();
	int GetDefense();
	int GetMeleeAffinity();
	int GetRangedAffinity();

};
