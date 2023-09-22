// Copyright Epic Games, Inc. All Rights Reserved.

#include "BBEGPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "BBEGCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

ABBEGPlayerController::ABBEGPlayerController()
{
	bShowMouseCursor = false;
	DefaultMouseCursor = EMouseCursor::Default;
	//CachedDestination = FVector::ZeroVector;
}

void ABBEGPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void ABBEGPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		EnhancedInputComponent->BindAction(UpAction, ETriggerEvent::Triggered, this, &ABBEGPlayerController::OnInputUp);
		EnhancedInputComponent->BindAction(DownAction, ETriggerEvent::Triggered, this, &ABBEGPlayerController::OnInputDown);
		EnhancedInputComponent->BindAction(LeftAction, ETriggerEvent::Triggered, this, &ABBEGPlayerController::OnInputLeft);
		EnhancedInputComponent->BindAction(RightAction, ETriggerEvent::Triggered, this, &ABBEGPlayerController::OnInputRight);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ABBEGPlayerController::OnInputDown()
{
	GetCharacter()->AddMovementInput(FVector(-1, 0, 0), MoveSpeed);
}

void ABBEGPlayerController::OnInputUp()
{
	GetCharacter()->AddMovementInput(FVector(1, 0, 0), MoveSpeed);
}

void ABBEGPlayerController::OnInputLeft()
{
	GetCharacter()->AddMovementInput(FVector(0, -1, 0), MoveSpeed);
}

void ABBEGPlayerController::OnInputRight()
{
	GetCharacter()->AddMovementInput(FVector(0, 1, 0), MoveSpeed);
}