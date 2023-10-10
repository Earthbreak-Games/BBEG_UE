// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#define BBEG_DEBUG_LOG(text) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT(text))

UENUM(BlueprintType)
enum class ERoomTypes : uint8
{
	RE_Starting		UMETA(DisplayName="Starting"),
	RE_Combat		UMETA(DisplayName="Combat"),
	RE_DCombat		UMETA(DisplayName="Dangerous Combat"),
	RE_DubDeal		UMETA(DisplayName="Dubious Deal"),
	RE_SafeRoom		UMETA(DisplayName="Safe Room"),
	RE_Shop			UMETA(DisplayName="Shop"),
	RE_BossEnt		UMETA(DisplayName="Boss Entrance"),
	RE_Boss			UMETA(DisplayName="Boss Room")
};