// Copyright Earthbreak Games LLC 2023


#include "BBEG_RoomManager_Base.h"

// Sets default values
ABBEG_RoomManager_Base::ABBEG_RoomManager_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABBEG_RoomManager_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABBEG_RoomManager_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}