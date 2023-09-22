// Copyright Earthbreak Games LLC 2023


#include "BBEG_Character.h"

// Sets default values
ABBEG_Character::ABBEG_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABBEG_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABBEG_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABBEG_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

