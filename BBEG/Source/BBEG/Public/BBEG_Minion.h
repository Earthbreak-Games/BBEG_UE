// Copyright Earthbreak Games LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "BBEG_BaseUnit.h"
#include "BBEG_Minion.generated.h"
/**
 * 
 */
UCLASS()
class BBEG_API ABBEG_Minion : public ABBEG_BaseUnit
{
    GENERATED_BODY()

public:
	ABBEG_Minion();
	~ABBEG_Minion();

    UFUNCTION(BlueprintCallable)
    void Mimic(FVector targetPosition);
	// dumping variables from unity build here
	/*
	[SerializeField] float followDistance;
    [SerializeField] float brakingDrag; //How much the minion's speed is reduced when in braking range but 
    [SerializeField] float catchupDistance;
    [SerializeField] float catchupSpeedModifier;

    [SerializeField] float mimicFollowDistance;
    [SerializeField] float mimicBrakingDrag;
    [SerializeField] float mimicCatchupDistance;
    [SerializeField] float mimicCatchupSpeedModifier;

    [SerializeField] public bool isStray; // Hasn't joined party yet
    [SerializeField] Rarity rarity;
	*/

    UFUNCTION(BlueprintCallable)
    void Move(FVector dir);

    UPROPERTY(EditAnywhere)
    float followDistance;

    UPROPERTY(EditAnywhere)
    float brakingDrag;

    UPROPERTY(EditAnywhere)
    float catchupDistance;

    UPROPERTY(EditAnywhere)
    float catchupSpeedModifier;

    UPROPERTY(EditAnywhere, Category = "Mimic Properties")
    float mimicFollowDistance;

    float mimicBrakingDrag;
    float mimicCatchupDistance;
    float mimicCatchupSpeedModifier;
};
