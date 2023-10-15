// Copyright Earthbreak Games LLC 2023


#include "Hitbox.h"
#include "DrawDebugHelpers.h"
#include "BBEG_Character_Base.h"

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, text)
#define printf(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, FString::Printf(TEXT(text), fstring))

void AHitbox::BeginPlay()
{
	Super::BeginPlay();

}

void AHitbox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (initted)
	{
		mElapsedTime += DeltaTime;
		if (mElapsedTime >= mHitboxLifetime)
		{
			Destroy();
		}
	}

	DrawDebugSphere(GetWorld(), GetActorLocation(), 25, 5, FColor::Purple, false, -1.0f, 0, 0.25f);
}

AHitbox::AHitbox()
{
	PrimaryActorTick.bCanEverTick = true;

	OnActorBeginOverlap.AddDynamic(this, &AHitbox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AHitbox::OnOverlapEnd);
	
	mProjectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	//mSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));

}

AHitbox::AHitbox(int damage, ABBEG_Character_Base* hitboxOwner, AttackType type, Alligiance alligiance, float radius, float lifetime = 0, float projectileSpeed = 0)
{
	InitHitbox(damage, hitboxOwner, type, alligiance, radius, lifetime, projectileSpeed);
}

void AHitbox::InitHitbox(int damage, ABBEG_Character_Base* hitboxOwner, AttackType type, Alligiance alligiance, float radius, float lifetime = 0, float projectileSpeed = 0)
{
	mDamage = damage;
	mType = type;
	mAlligiance = alligiance;
	mOwner = hitboxOwner;
	initted = true;
	mProjectileSpeed = projectileSpeed;
	mHitboxLifetime = lifetime;
	mProjectile->SetUpdatedComponent(RootComponent);
	mRadius = radius;
	Cast<USphereComponent>(this->GetCollisionComponent())->SetSphereRadius(mRadius);

	if (type == AttackType::Ranged)
	{
		mProjectile->InitialSpeed = mProjectileSpeed;
		mProjectile->MaxSpeed = mProjectileSpeed;
		mProjectile->ProjectileGravityScale = 0.0f;
		mProjectile->Velocity = mOwner->GetActorForwardVector() * mProjectileSpeed;
	}
	else
	{
		mProjectile->ProjectileGravityScale = 0.0f;
		mProjectile->Velocity = FVector::Zero();

	}
}

void AHitbox::OnOverlapBegin(AActor* overlappedActor, AActor* otherActor)
{
	if (otherActor && (otherActor != this))
	{
		print("Overlap Begin");
		printf("Actor has entered trigger = %s", *otherActor->GetName());
		ABBEG_Character_Base* actorCharComponent = Cast<ABBEG_Character_Base>(otherActor->GetComponentByClass(ABBEG_Character_Base::StaticClass()));

		if (actorCharComponent != nullptr)
		{
			print("Enemy");
		}
		else
		{
			print("Friendly");
		}
	}

}

void AHitbox::OnOverlapEnd(AActor* overlappedActor, AActor* otherActor)
{
	if (otherActor && (otherActor != this))
	{
		print("Overlap End");
		printf("Actor has left trigger = %s", *overlappedActor->GetName());
	}
}

bool AHitbox::HitboxAlligianceCheck(Alligiance attackHitbox, Alligiance otherHitbox)
{
	return attackHitbox != otherHitbox;
}
