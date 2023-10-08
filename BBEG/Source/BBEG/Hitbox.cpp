// Copyright Earthbreak Games LLC 2023


#include "Hitbox.h"
#include "DrawDebugHelpers.h"
#include "BBEG_Character_Base.h"

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, text)
#define printf(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, FString::Printf(TEXT(text), fstring))

void AHitbox::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugSphere(GetWorld(), GetActorLocation(), 5, 5, FColor::Purple, true, -1, 0, 5);
}

void AHitbox::Tick(float DeltaTime)
{
	if (mType == AttackType::Ranged && initted)
	{
		mProjectileElapsedTime += DeltaTime;
		if (mProjectileElapsedTime >= mProjectileLifetime)
		{
			Destroy();
		}
	}
}

AHitbox::AHitbox()
{
	OnActorBeginOverlap.AddDynamic(this, &AHitbox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AHitbox::OnOverlapEnd);
}

AHitbox::AHitbox(int damage, ABBEG_Character_Base* owner, AttackType type, Alligiance alligiance, float projectileLifetime = 0, float projectileSpeed = 0)
{
	InitHitbox(damage, owner, type, alligiance, projectileLifetime, projectileSpeed);
}

void AHitbox::InitHitbox(int damage, ABBEG_Character_Base* owner, AttackType type, Alligiance alligiance, float projectileLifetime = 0, float projectileSpeed = 0)
{
	mDamage = damage;
	mType = type;
	mAlligiance = alligiance;
	initted = true;

	if (type == AttackType::Ranged)
	{
		mProjectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		mProjectile->SetUpdatedComponent(RootComponent);
		mProjectile->InitialSpeed = mProjectileSpeed;
		mProjectile->MaxSpeed = mProjectileSpeed;
		mProjectile->ProjectileGravityScale = 0.0f;
		mProjectile->Velocity = mOwner->GetActorForwardVector() * mProjectileSpeed;
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
