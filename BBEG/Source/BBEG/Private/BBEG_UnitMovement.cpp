// Copyright Earthbreak Games LLC 2023


#include "BBEG_UnitMovement.h"

// Sets default values for this component's properties
UBBEG_UnitMovement::UBBEG_UnitMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBBEG_UnitMovement::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBBEG_UnitMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

