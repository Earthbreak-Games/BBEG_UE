// Copyright Earthbreak Games LLC 2023


#include "BBEG_Minion.h"

ABBEG_Minion::ABBEG_Minion()
{
    if (GetController())
        GetController()->SetIgnoreMoveInput(true);
}

ABBEG_Minion::~ABBEG_Minion()
{
}

void ABBEG_Minion::Mimic(FVector targetPosition)
{
    /*if (Vector3.Distance(transform.position, point.position) > mimicFollowDistance)
    {
        if (state.stateType != CharacterState.Move)
            state = new MoveState(this);
        Vector3 dir = (point.position - transform.position).normalized;
        if (PlayerCharacterManager.instance.leader.axis == Vector2.zero)
        {
            Move(new Vector2(dir.x, dir.z));
        }
        else
        {
            Move(new Vector2(dir.x, dir.z), mimicCatchupSpeedModifier);
        }
        Debug.Log(name + " lagging");

    }
    else
    {
        transform.position = point.position;
    }*/

    if (FVector::DistXY(GetActorLocation(), targetPosition) <= mimicFollowDistance)
    {
        SetActorRelativeLocation(targetPosition);
        return;
    }

    FVector dir = (targetPosition - GetActorLocation()).GetUnsafeNormal();
    // Go faster if the player isn't moving? No movement modifier stuff in yet though
    Move(dir);


}

void ABBEG_Minion::Move(FVector dir)
{
    dir.Set(dir.X, dir.Y, 0); // Z should already be 0 but just in case
    AddMovementInput(dir, 1.0f, true);
}

