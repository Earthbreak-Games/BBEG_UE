// Copyright Earthbreak Games LLC 2023

#pragma once

#include "CoreMinimal.h"
#include <BBEG\BBEG_Character_Base.h>

/**
 * 
 */
class BBEG_API HitData
{
public:
	HitData();

    HitData(ABBEG_Character_Base* owner, ABBEG_Character_Base* recipient, AHitbox* hitbox, float damage)
    {
        mOwner = owner;
        mRecipient = recipient;
        mHitbox = hitbox;
        mDamage = damage;
    }

    ABBEG_Character_Base* mOwner;
    ABBEG_Character_Base* mRecipient;
    AHitbox* mHitbox;
    float mDamage;

	~HitData();
};
