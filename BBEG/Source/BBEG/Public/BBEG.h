// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#define BBEG_DEBUG_LOG(text) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT(text))
#define BBEG_DEBUG_LOG2(text) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, text)

UENUM(BlueprintType)
enum class ERoomTypes : uint8
{
	RE_Wall			UMETA(DisplayName="Wall/NOT SET"),
	RE_Starting		UMETA(DisplayName="Starting"),
	RE_Combat		UMETA(DisplayName="Combat"),
	RE_DCombat		UMETA(DisplayName="Dangerous Combat"),
	RE_DubDeal		UMETA(DisplayName="Dubious Deal"),
	RE_SafeRoom		UMETA(DisplayName="Safe Room"),
	RE_Shop			UMETA(DisplayName="Shop"),
	RE_BossEnt		UMETA(DisplayName="Boss Entrance"),
	RE_Boss			UMETA(DisplayName="Boss Room"),
};

UENUM(BlueprintType)
enum class ERoomSizes : uint8
{
	SE_Small		UMETA(DisplayName="Small"),
	SE_Medium		UMETA(DisplayName="Medium"),
	SE_Large		UMETA(DisplayName="Large"),
	SE_XL			UMETA(DisplayName="Extra-Large")
};