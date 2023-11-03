// Copyright Earthbreak Games LLC 2023


#include "CharacterStates.h"
#include <BBEG\BBEG_BaseUnit.h>

CharacterStates::CharacterStates()
{
}

CharacterStates::~CharacterStates()
{
}

enum class UnitState : uint8
{
    Actionable,
    Stopped,
    Idle,
    Move,
    Attack,
    Dodge
};


class BaseUnitState
{
public:
    UnitState stateType;
    bool canExit = true; // Set to false during certain actions, such as attacks, dodge rolls, or other states that can't be interrupted

    virtual void Update() {}

    virtual void FixedUpdate() {}

    virtual void Enter() {}

protected:
    ABBEG_BaseUnit* baseUnit;



};

class IdleState : BaseUnitState
{
public:

    IdleState(ABBEG_BaseUnit* b)
    {
        baseUnit = b;
        stateType = UnitState::Idle;
        Enter();
    }

    // Entering idle state instantly kills any velocity the character may have had
    void Enter() override
    {
        // Stop the unit
        // baseUnit.rgd.velocity = Vector3.zero;
        baseUnit->AddMovementInput(FVector::Zero(), 1.0f, true);

    }

    void FixedUpdate() override
    {
    }

    void Update() override
    {

    }



};
/*
class MoveState : BaseUnitState
{
public:

    MoveState(ABBEG_BaseUnit* b)
    {
        baseUnit = b;
        stateType = UnitState::Move;
        Enter();
    }



    void Enter() override
    {
    }

    void Update() override
    {
        // Unused
        Integrate();
        
    }

    // done up to here - unsure if adding zero vector to movement will stop units
    // movement is largely handled by character, not sure how much control we have over it

    public void Integrate()
    {

        if (baseUnit->GetPendingMovementInputVector() == FVector::Zero())
        {
            //Debug.Log("Moving, Axis = 0 0");
            baseUnit->AddMovementInput(FVector::Zero(), 1.0f, true);

            return;
        }
        float targetAngle = Mathf.Atan2(c.axis.x, c.axis.y) * Mathf.Rad2Deg + Camera.main.transform.eulerAngles.y;
        Vector3 moveDir = Quaternion.Euler(0f, targetAngle, 0f) * Vector3.forward;

        float angle = Mathf.SmoothDampAngle(c.transform.eulerAngles.y, targetAngle, ref c.turnSmoothVelocity, c.turnSmoothTime);

        if (Physics.Raycast(c.transform.position, moveDir, out RaycastHit hitInfo, 0.75f))
        {
            if (hitInfo.collider.gameObject.layer == LayerMask.NameToLayer("Default"))
                moveDir = Vector3.ProjectOnPlane(moveDir, hitInfo.normal);
        }

        c.transform.rotation = Quaternion.Euler(c.transform.eulerAngles.x, angle, c.transform.eulerAngles.z);
        c.rgd.velocity = moveDir * (c.GetMoveSpeed() * c.moveSpeedModifier); //?
    }

    public override void FixedUpdate()
    {
        //Integrate();

    }
}

public class AttackState : CharacterBaseState
{
    bool canMove;
    float timeElapsed;
    AttackPhase phase;
    Attack attack;
    public AttackState(Character c, bool canMove = false)
    {
        base.c = c;
        stateType = CharacterState.Attack;
        this.canMove = canMove;
        phase = AttackPhase.Startup;
        timeElapsed = 0;
        attack = c.meleeAttack;
        Enter();
    }

    public AttackState(Character c, Attack atk, bool canMove = false)
    {
        base.c = c;
        stateType = CharacterState.Attack;
        this.canMove = canMove;
        phase = AttackPhase.Startup;
        attack = atk;
        timeElapsed = 0;
        Enter();
    }

    public override void Enter()
    {
        c.hitbox = attack.GenerateHitbox(c);
        c.hitbox.StartupPhase();
        c.rgd.velocity = Vector2.zero;

    }


    public override void Update()
    {
        timeElapsed += Time.deltaTime;
        if (timeElapsed > attack.totalTimeInSeconds)
        {
            c.state = new IdleState(c);

            c.Move(c.axis);
            return;
        }

        if (timeElapsed > attack.activeTimeInSeconds + attack.startupInSeconds && phase == AttackPhase.Active)
        {
            c.hitbox.CooldownPhase();
            phase = AttackPhase.Cooldown;
        }

        if (timeElapsed > attack.startupInSeconds && phase == AttackPhase.Startup)
        {
            c.hitbox.ActivePhase();
            phase = AttackPhase.Active;
        }

    }

    public void Integrate()
    {
        if (!canMove)
            return;

        if (c.axis == Vector2.zero)
        {
            Debug.Log("Attacking, Axis = 0 0");
            c.rgd.velocity = Vector2.zero;
            return;
        }
        float targetAngle = Mathf.Atan2(c.axis.x, c.axis.y) * Mathf.Rad2Deg + Camera.main.transform.eulerAngles.y;
        Vector3 moveDir = Quaternion.Euler(0f, targetAngle, 0f) * Vector3.forward;

        float angle = Mathf.SmoothDampAngle(c.transform.eulerAngles.y, targetAngle, ref c.turnSmoothVelocity, c.turnSmoothTime);



        c.transform.rotation = Quaternion.Euler(c.transform.eulerAngles.x, angle, c.transform.eulerAngles.z);
        c.rgd.velocity = moveDir * (c.moveSpeed * c.moveSpeedModifier); //?
    }

    public override void FixedUpdate()
    {
        Integrate();
    }
}

public class DodgeState : CharacterBaseState
{
    Vector2 dir;
    float timeElapsed;
    public DodgeState(Character c, Vector2 _dir)
    {
        base.c = c;
        stateType = CharacterState.Dodge;
        dir = _dir;
        timeElapsed = 0;

        Enter();
    }
    public override void Enter()
    {
        c.transform.forward = new Vector3(c.axis.x, 0, c.axis.y);
        c.invulnerable = true;
    }

    public override void FixedUpdate()
    {
    }

    public override void Update()
    {
        Integrate();

        if (c.dodgeInvulDuration <= timeElapsed)
        {
            c.invulnerable = false;
        }

        if (c.dodgeDuration <= timeElapsed)
        {
            c.invulnerable = false;
            c.transform.forward = new Vector3(dir.x, 0, dir.y);
            c.state = new IdleState(c);
        }
    }

    public void Integrate()
    {
        timeElapsed += Time.deltaTime;

        float targetAngle = Mathf.Atan2(dir.x, dir.y) * Mathf.Rad2Deg + Camera.main.transform.eulerAngles.y;
        Vector3 moveDir = Quaternion.Euler(0f, targetAngle, 0f) * Vector3.forward;

        float angle = Mathf.SmoothDampAngle(c.transform.eulerAngles.y, targetAngle, ref c.turnSmoothVelocity, c.turnSmoothTime);

        c.transform.rotation = Quaternion.Euler(c.transform.eulerAngles.x, c.transform.eulerAngles.y + (360 / (c.dodgeDuration / Time.deltaTime)), c.transform.eulerAngles.z);
        c.rgd.velocity = moveDir * (c.GetMoveSpeed() * c.GetMoveSpeedModifier() * c.dodgeSpeedMultiplier); //?


    }

    // Failsafe to remove invulnerability in the event of unexpected interruptions
    ~DodgeState()
    {
        //c.transform.forward = dir;
        c.invulnerable = false;
    }

}
    */
