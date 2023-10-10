// Copyright Earthbreak Games LLC 2023


#include "BBEG_StageManager_Base.h"

#include "Kismet/GameplayStatics.h"	// I really don't want to use this but there doesn't seem to be another way
#include "GameFramework/Character.h"// This is only here because of the above

#include "BBEG.h"	// Hopefully not a mistake

// Sets default values
ABBEG_StageManager_Base::ABBEG_StageManager_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//OverlapVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapVolume"));
	//RootComponent = OverlapVolume;


	//OverlapVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ABBEG_StageManager_Base::OverlapBegins);
}

// Called when the game starts or when spawned
void ABBEG_StageManager_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABBEG_StageManager_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void ABBEG_StageManager_Base::OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
//
//	if (OtherActor == Cast<AActor>(MyCharacter) && LevelToLoad != "")
//	{
//		FLatentActionInfo LatentInfo;
//		UGameplayStatics::LoadStreamLevel(this, LevelToLoad, true, true, LatentInfo);
//	}
//}


void ABBEG_StageManager_Base::LoadStreamingRoom(FString testInput)
{
	BBEG_DEBUG_LOG("Scene Load Called");
}