// Copyright Earthbreak Games LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BBEG_BaseUnit.h"

#include "BBEG_Enemy_Base.generated.h"

UCLASS()
class BBEG_API ABBEG_Enemy_Base : public ABBEG_BaseUnit
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABBEG_Enemy_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
