// Copyright Earthbreak Games LLC 2023


#include "BBEG_Enemy_Base.h"

// Sets default values
ABBEG_Enemy_Base::ABBEG_Enemy_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABBEG_Enemy_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABBEG_Enemy_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABBEG_Enemy_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

