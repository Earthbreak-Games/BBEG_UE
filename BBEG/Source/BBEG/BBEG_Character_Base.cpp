// Fill out your copyright notice in the Description page of Project Settings.

#include "BBEG_Character_Base.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "BBEG.h"

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

	// Enhanced Input Action Bindings
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	UEnhancedInputLocalPlayerSubsystem* InputSystem = GEngine->GetFirstLocalPlayerController(GetWorld())->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

	// add is null checks when switching from raw pointers
	InputSystem->AddMappingContext(defaultMappingContext, 0);

	enhancedInputComponent->BindAction(inputMelee, ETriggerEvent::Triggered, this, &ABBEG_Character_Base::EI_TriggerMelee);
	enhancedInputComponent->BindAction(inputMove, ETriggerEvent::Triggered, this, &ABBEG_Character_Base::EI_TriggerMove);
	enhancedInputComponent->BindAction(inputRanged, ETriggerEvent::Triggered, this, &ABBEG_Character_Base::EI_TriggerRanged);
}

// Input Functions
void ABBEG_Character_Base::EI_TriggerMove(const FInputActionValue& value)
{
	const FVector2D moveVector = value.Get<FVector2D>();
	const FRotator moveRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);

	// make this a bp variable
	const float deadzone = 0.05f;

	// Axis 1
	if (moveVector.X > deadzone || moveVector.X < -deadzone)
	{
		const FVector directionVector = moveRotation.RotateVector(FVector::RightVector);
		AddMovementInput(directionVector, moveVector.X);
	}

	// Axis 2
	if (moveVector.Y > deadzone || moveVector.Y < -deadzone)
	{
		const FVector directionVector = moveRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(directionVector, moveVector.Y);
	}
}

//void ABBEG_Character_Base::EI_TriggerMelee()
//{
//	BBEG_DEBUG_LOG("Melee Firing");
//}
//
//void ABBEG_Character_Base::EI_TriggerRanged()
//{
//	BBEG_DEBUG_LOG("Ranged Firing");
//}