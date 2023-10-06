// Copyright Earthbreak Games LLC 2023

// There will be one of these on each room
// This will encompass several facets of data needed for each room, from camera data to
// the room type, etc
// Might do room type as a child of this class and just have the generics inherited from here

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Containers/Array.h"

#include "BBEG_RoomManager_Base.generated.h"

UCLASS()
class BBEG_API ABBEG_RoomManager_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABBEG_RoomManager_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray */

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
