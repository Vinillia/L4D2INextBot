#pragma once

class INextBotEventResponder
{
public:
	virtual void pad00() = 0;
	virtual void pad01() const = 0;
	virtual void pad02() const = 0;
	virtual char* GetDebugString(void) const = 0;
	virtual void OnLeaveGround(CBaseEntity* pEntity) = 0;
	virtual void OnLandOnGround(CBaseEntity* pEntity) = 0;
	virtual void OnContact(CBaseEntity *, void*) = 0;
	virtual void OnMoveToSuccess(void const*) = 0;
	virtual void OnMoveToFailure(void const*, int) = 0;
	virtual void OnStuck(void) = 0;
	virtual void OnUnStuck(void) = 0;
	virtual void OnPostureChanged(void) = 0;
	virtual void OnAnimationActivityComplete(int) = 0;
	virtual void OnAnimationActivityInterrupted(int) = 0;
	virtual void OnAnimationEvent(void*) = 0;
	virtual void OnIgnite(void) = 0;
	virtual void OnInjured(void* const&) = 0;
	virtual void OnKilled(void* const&) = 0;
	virtual void OnOtherKilled(void*, void* const&) = 0;
	virtual void OnSight(CBaseEntity* pEntity) = 0;
	virtual void OnLostSight(CBaseEntity *) = 0;
	virtual void OnThreatChanged(CBaseEntity *) = 0;
	virtual void OnSound(CBaseEntity *, Vector const&, void*) = 0;
	virtual void OnSpokeConcept(void*, void*, void*) = 0;
	virtual void OnNavAreaChanged(void*, void*) = 0;
	virtual void OnModelChanged(void) = 0;
	virtual void OnPickUp(CBaseEntity *, void*) = 0;
	virtual void OnDrop(CBaseEntity*) = 0;
	virtual void OnShoved(CBaseEntity*) = 0;
	virtual void OnBlinded(CBaseEntity*) = 0;
	virtual void OnEnteredSpit(void) = 0;
	virtual void OnHitByVomitJar(CBaseEntity *) = 0;
	virtual void OnCommandAttack(CBaseEntity *) = 0;
	virtual void OnCommandAssault(void) = 0;
	virtual void OnCommandApproach(Vector const&, float) = 0;
	virtual void OnCommandApproach(CBaseEntity *) = 0;
	virtual void OnCommandRetreat(CBaseEntity *, float) = 0;
	virtual void OnCommandPause(float) = 0;
	virtual void OnCommandResume(void) = 0;
	virtual void OnCommandString(char const*) = 0;
};