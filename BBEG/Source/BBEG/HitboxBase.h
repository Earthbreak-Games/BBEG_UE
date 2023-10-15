// Copyright Earthbreak Games LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BBEG_Character_Base.h"
#include "Engine/TriggerBox.h"
#include "HitboxBase.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BBEG_API UHitboxBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHitboxBase(ABBEG_Character_Base owner);
	UHitboxBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY()
	ABBEG_Character_Base* mOwner;
	
	int damage;
	int radius;
	int lifetime;

};
