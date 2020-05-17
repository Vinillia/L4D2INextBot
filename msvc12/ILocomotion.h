#pragma once

class ILocomotion : INextBotComponent
{
public:
	enum TraverseWhenType
	{
		IMMEDIATELY,		// the entity will not block our motion - we'll carry right through
		EVENTUALLY			// the entity will block us until we spend effort to open/destroy it
	};

	virtual	void Reset(void) = 0;
	virtual void Update(void) = 0;
	virtual void pad00(void) = 0;
	virtual	void pad01(void) const = 0;
	virtual void Approach(Vector const&, float) = 0;
	virtual void DriveTo(Vector const&) = 0;
	virtual bool ClimbUpToLedge(Vector const&, Vector const&, CBaseEntity const*) = 0;
	virtual void JumpAcrossGap(Vector const&, Vector const&) = 0;
	virtual void Jump(void) = 0;
	virtual bool IsClimbingOrJumping(void) const = 0;
	virtual bool IsClimbingUpToLedge(void) const = 0;
	virtual bool IsJumpingAcrossGap(void) const = 0;
	virtual bool IsScrambling(void) const = 0;
	virtual void Run(void) = 0;
	virtual void Walk(void) = 0;
	virtual void Stop(void) = 0;
	virtual bool IsRunning(void) const = 0;
	virtual void SetDesiredSpeed(float) = 0;
	virtual float GetDesiredSpeed(void) const = 0;
	virtual void SetSpeedLimit(float) = 0;
	virtual float GetSpeedLimit(void) const = 0;
	virtual bool IsOnGround(void) const = 0;
	virtual CBaseEntity* GetGround(void) const = 0;
	virtual const Vector & GetGroundNormal(void) const = 0;
	virtual float GetGroundSpeed(void) const = 0;
	virtual const Vector & GetGroundMotionVector(void) const = 0;
	virtual void ClimbLadder(void const*, void const*) = 0;
	virtual void DescendLadder(void const*, void const*) = 0;
	virtual bool IsUsingLadder(void) const = 0;
	virtual bool IsAscendingOrDescendingLadder(void) const = 0;
	virtual bool IsAbleToAutoCenterOnLadder(void) const = 0;
	virtual void FaceTowards(Vector const&) = 0;
	virtual void SetDesiredLean(Vector const&) = 0;
	virtual const Vector GetDesiredLean(void) const = 0;
	virtual const Vector & GetFeet(void) const = 0;
	virtual float GetStepHeight(void) const = 0;
	virtual float GetMaxJumpHeight(void) const = 0;
	virtual float GetDeathDropHeight(void) const = 0;
	virtual float GetRunSpeed(void) const = 0;
	virtual float GetWalkSpeed(void) const = 0;
	virtual const Vector& GetVelocity(void) const = 0;
	virtual float GetSpeed(void) const = 0;
	virtual const Vector& GetMotionVector(void) const = 0;
	virtual bool IsAreaTraversable(void const*) const = 0;
	virtual float GetTraversableSlopeLimit(void) const = 0;
	virtual bool IsPotentiallyTraversable(Vector const&, Vector const&, ILocomotion::TraverseWhenType, float *) const = 0;
	virtual bool HasPotentialGap(Vector const&, Vector const&, float *) const = 0;
	virtual bool IsGap(Vector const&, Vector const&) const = 0;
	virtual bool IsEntityTraversable(CBaseEntity *, ILocomotion::TraverseWhenType) const = 0;
	virtual bool IsStuck(void) const = 0;
	virtual float GetStuckDuration(void) const = 0;
	virtual void ClearStuckStatus(char const*) = 0;
	virtual bool IsAttemptingToMove(void) const = 0;
	virtual const Vector & GetLastApproachPosition(void) const = 0;
	virtual void AdjustPosture(Vector const&) = 0;

private:
	Vector m_motionVector;
	Vector m_groundMotionVector;
	float m_speed;
	float m_groundSpeed;

	// stuck monitoring
	bool m_isStuck;									// if true, we are stuck
	void* m_stuckTimer;						// how long we've been stuck
	void* m_stillStuckTimer;				// for resending stuck events
	Vector m_stuckPos;								// where we got stuck
	void* m_moveRequestTimer;
};