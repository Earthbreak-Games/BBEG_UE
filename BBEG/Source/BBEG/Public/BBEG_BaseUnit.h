// Copyright Earthbreak Games LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "BBEG_BaseUnit.generated.h"

// Unit State forward declarations
class FBaseUnitState;

UCLASS()
class BBEG_API ABBEG_BaseUnit : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABBEG_BaseUnit();

	TSharedPtr<FBaseUnitState> State;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// State enum
	int BaseHealth = 5;
	int CurrHealth = 5;
	int BaseDefense = 0;
	float TimeSinceLastHit = 0;
	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Hit(int damage);
	void Heal(int healValue);
	UFUNCTION(BlueprintCallable)
	int GetMaxHealth();
	UFUNCTION(BlueprintCallable)
	int GetCurrentHealth();
	int GetDefense();
	int GetMeleeAffinity();
	int GetRangedAffinity();

	UFUNCTION(BlueprintCallable)
	EUnitState GetState();

	UFUNCTION(BlueprintCallable)
	void StartAttack(AHitbox* hitbox);

	UFUNCTION(BlueprintCallable)
	void Stop();

	UFUNCTION(BlueprintCallable)
	void PauseInput(); // disables movement inputs only, supposedly

	UFUNCTION(BlueprintCallable)
	void ResumeInput();
};
