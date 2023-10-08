// Copyright Earthbreak Games LLC 2023


#include "HitboxBase.h"

// Sets default values for this component's properties
UHitboxBase::UHitboxBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.

	// ...
}


UHitboxBase::UHitboxBase(ABBEG_Character_Base owner)
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UHitboxBase::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	
}



// Called every frame
void UHitboxBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

