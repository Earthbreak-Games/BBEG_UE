// Copyright Earthbreak Games LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BBEG.h"
#include "Components/BoxComponent.h"

#include "BBEG_StageManager_Base.generated.h"

UCLASS()
class BBEG_API ABBEG_StageManager_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABBEG_StageManager_Base();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	//UBoxComponent* OverlapVolume;

	void LoadStreamingRoom(FString testInput);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="StageManager|FloorConfig")
	int MinRoomCount = 5;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="StageManager|FloorConfig")
	int MaxRoomCount = 10;

	//UFUNCTION()
	//void OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//UPROPERTY(EditAnywhere)
	//FName LevelToLoad;

	class StageData {
	private:
		ABBEG_StageManager_Base& StageManager;
		TArray<ERoomTypes> data;

	public:
		StageData(ABBEG_StageManager_Base& StageManager) : StageManager{ StageManager } {};

		void Init()
		{
			data.Init(ERoomTypes::RE_Wall, StageManager.MaxRoomCount * StageManager.MaxRoomCount);
		}

		ERoomTypes Get(int32 X, int32 Y) const
		{
			return data[X + Y * StageManager.MaxRoomCount];
		}

		void Set(int32 X, int32 Y, ERoomTypes value)
		{
			data[X + Y * StageManager.MaxRoomCount];
		}
	};

	//UPROPERTY(BlueprintReadOnly)
	StageData StagePlan = StageData(*this);

	class WorldDirections {
	public:
		void Shuffle()
		{
			for (int32 i = data.Num() - 1; i != 0; i--)
			{
				int32 j = rand() % i;
				data.Swap(i, j);
			}
		}

	private:
		TArray<int8> data = { 0, 1, 2, 3 };
	};
};
