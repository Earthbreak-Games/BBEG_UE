// Fill out your copyright notice in the Description page of Project Settings.


#include "BBEG_Character_Base.h"

// Sets default values
ABBEG_Character_Base::ABBEG_Character_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABBEG_Character_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABBEG_Character_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABBEG_Character_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
