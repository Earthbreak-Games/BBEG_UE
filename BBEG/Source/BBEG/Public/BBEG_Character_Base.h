// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "BBEG_BaseUnit.h"

#include "Hitbox.h"
#include "BBEG_Character_Base.generated.h"

UCLASS(Blueprintable)
class BBEG_API ABBEG_Character_Base : public ABBEG_BaseUnit
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABBEG_Character_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Input functions
	void EI_TriggerMove(const FInputActionValue& value);
	UFUNCTION(BlueprintImplementableEvent, Category="BBEG|Input Triggers", meta=(DisplayName = "Melee Trigger"))
	void EI_TriggerMelee();
	UFUNCTION(BlueprintImplementableEvent, Category = "BBEG|Input Triggers", meta = (DisplayName = "Ranged Trigger"))
	void EI_TriggerRanged();
	UFUNCTION(BlueprintImplementableEvent, Category = "BBEG|Input Triggers", meta = (DisplayName = "Dodge Trigger"))
	void EI_TriggerDodge();

	FVector mimicPoints[3];

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void SetupMinionMimicPoints(FVector pos0, FVector pos1, FVector pos2);

	UFUNCTION(BlueprintCallable)
	FVector GetMimicPointWorldPosition(int index);
	
	


	// Enhanced Input Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputMappingContext* defaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* inputJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* inputMelee;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* inputRanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* inputMove;

	
};
