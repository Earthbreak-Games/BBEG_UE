// Fill out your copyright notice in the Description page of Project Settings.

#include "BBEG_Character_Base.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "BBEG.h"
#include "Kismet/KismetMathLibrary.h"

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

void ABBEG_Character_Base::SetupMinionMimicPoints(FVector pos0, FVector pos1, FVector pos2)
{
	mimicPoints[0] = pos0;
	mimicPoints[1] = pos1;
	mimicPoints[2] = pos2;

}

FVector ABBEG_Character_Base::GetMimicPointWorldPosition(int index)
{
	if (index < mimicPoints->Length())
	{
		return mimicPoints[index];
	}
	return FVector::Zero();
}

// Input Functions
void ABBEG_Character_Base::EI_TriggerMove(const FInputActionValue& value)
{
	const FVector2D moveVector = value.Get<FVector2D>();
	const FRotator moveRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
	//BBEG_DEBUG_LOG2(FString::SanitizeFloat(moveVector.X) + " " + FString::SanitizeFloat(moveVector.Y));

	// make this a bp variable
	const float deadzone = 0.05f;
	APlayerCameraManager* PlayerCamera = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;

	PlayerCamera->GetCameraRotation().Yaw;

	float totalRotation = 0;

	float targetAngle = (UKismetMathLibrary::DegAtan2(moveVector.X, moveVector.Y)
		+ PlayerCamera->GetCameraRotation().Euler().Z);
	FVector moveDir = FQuat::MakeFromEuler(FVector(0, 0, targetAngle)) * FVector::ForwardVector;
	AddMovementInput(moveDir);

	SetActorRotation(FRotator::MakeFromEuler(FVector(GetActorRotation().Euler().X, GetActorRotation().Euler().Y, targetAngle)));

	//AddActorWorldRotation(FRotator::MakeFromEuler(FVector(GetActorRotation().Euler().X, GetActorRotation().Euler().Y, totalRotation)));
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