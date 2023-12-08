// Copyright Earthbreak Games LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerSphere.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include <Components\SphereComponent.h>
#include "Hitbox.generated.h"

/**
 * 
 */

UENUM()
enum class AttackPhase : uint8
{
	Startup,
	Active,
	Endlag
};

UENUM(BlueprintType)
enum class Alligiance : uint8 
{
	Friendly,
	Enemy,
};

UENUM(BlueprintType)
enum class AttackType : uint8
{
	Melee,
	Ranged
};


UCLASS()
class BBEG_API AHitbox : public ATriggerSphere
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	bool initted;

public:

	virtual void Tick(float DeltaTime) override;

	AHitbox();

	~AHitbox();

	AHitbox(int damage, ABBEG_BaseUnit* hitboxOwner, AttackType type, Alligiance alligiance, float radius, float lifetime, float projectileSpeed);

	UFUNCTION(BlueprintCallable, category = "Hitbox Functions")
	void InitHitbox(int damage, ABBEG_BaseUnit* hitboxOwner, AttackType type, Alligiance alligiance,
		float radius, float lifetime, float projectileSpeed,
		float startupTime, float activeTime, float endlagTime);

	UFUNCTION()
	void OnOverlapBegin(class AActor* overlappedActor, class AActor* otherActor);
	
	UFUNCTION()
	void OnOverlapEnd(class AActor* overlappedActor, class AActor* otherActor);

	// Checks alligiance of the attack and colliding hitbox to determine if damage calculation should be done
	UFUNCTION(BlueprintCallable, category = "Hitbox Functions")
	static bool HitboxAlligianceCheck(Alligiance attackHitbox, Alligiance otherHitbox);

	UFUNCTION(BlueprintCallable, category = "Hitbox Functions")
	float GetTotalAttackTime();

	void StartupPhase();

	void ActivePhase();

	void EndLagPhase();


	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	Alligiance mAlligiance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	int mDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	AttackType mType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	float mProjectileSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	float mRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	float mStartupTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	float mActiveTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	float mEndlagTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	ABBEG_BaseUnit* mOwner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	UProjectileMovementComponent* mProjectile;

	// temporary until we get actual hitbox models made
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	USphereComponent* mSphere;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	float mHitboxLifetime;

	float mElapsedTime = 0;

	bool isActive = false;

	AttackPhase currentPhase = AttackPhase::Startup;
};
