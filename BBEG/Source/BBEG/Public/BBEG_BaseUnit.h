// Copyright Earthbreak Games LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/Image.h"
#include "Hitbox.h"
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

	// This variable exists so we can prepare a state change on the next frame
	// We can't overwrite the state from within the state code or else the object will get destroyed too early
	// If is valid check passes, this will overwrite State and become null again
	TSharedPtr<FBaseUnitState> PendingState; 


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// State enum
	int BaseHealth = 5;
	int CurrHealth = 5;
	int BaseDefense = 0;
	float TimeSinceLastHit = 0;
	
	//class UImage;
	//UTexture2D charPortrait;

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
	void ForceMove(FVector dir);

	UFUNCTION(BlueprintCallable)
	void Dodge(FVector dir);

	UFUNCTION(BlueprintCallable)
	void Stop();

	UFUNCTION(BlueprintCallable)
	void PauseInput(); // disables movement inputs only, supposedly

	UFUNCTION(BlueprintCallable)
	void ResumeInput();

	UFUNCTION(BlueprintCallable)
	void SwitchState(EUnitState newState, AHitbox* hitbox = nullptr);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
	Alligiance alligiance;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterInfo")
	float turningSpeed;
};
