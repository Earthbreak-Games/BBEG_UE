// Copyright Earthbreak Games LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerSphere.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Hitbox.generated.h"

/**
 * 
 */

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

	AHitbox(int damage, ABBEG_Character_Base* owner, AttackType type, Alligiance alligiance, float projectileLifetime = 0, float projectileSpeed = 0);

	UFUNCTION(BlueprintCallable, category = "Hitbox Functions")
	void InitHitbox(int damage, ABBEG_Character_Base* owner, AttackType type, Alligiance alligiance, float projectileLifetime = 0, float projectileSpeed = 0);

	UFUNCTION()
	void OnOverlapBegin(class AActor* overlappedActor, class AActor* otherActor);
	
	UFUNCTION()
	void OnOverlapEnd(class AActor* overlappedActor, class AActor* otherActor);

	// Checks alligiance of the attack and colliding hitbox to determine if damage calculation should be done
	UFUNCTION(BlueprintCallable, category = "Hitbox Functions")
	static bool HitboxAlligianceCheck(Alligiance attackHitbox, Alligiance otherHitbox);

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	Alligiance mAlligiance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	int mDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	AttackType mType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	float mProjectileSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	ABBEG_Character_Base* mOwner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	UProjectileMovementComponent* mProjectile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox Properties")
	float mProjectileLifetime;

	float mProjectileElapsedTime = 0;
};
