// Copyright Earthbreak Games LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BBEG_UnitMovement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BBEG_API UBBEG_UnitMovement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBBEG_UnitMovement();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
