#pragma once

class INextBotEventResponder
{
public:
	virtual void pad00() = 0;
	virtual void pad01() const = 0;
	virtual void pad02() const = 0;
	virtual char* GetDebugString(void) const = 0;
	virtual int OnLeaveGround(CBaseEntity* pEntity) = 0;
	virtual int OnLandOnGround(CBaseEntity* pEntity) = 0;
	virtual int OnContact(CBaseEntity *, void*) = 0;
	virtual int OnMoveToSuccess(void const*) = 0;
	virtual int OnMoveToFailure(void const*, int) = 0;
	virtual int OnStuck(void) = 0;
	virtual int OnUnStuck(void) = 0;
	virtual int OnPostureChanged(void) = 0;
	virtual int OnAnimationActivityComplete(int) = 0;
	virtual int OnAnimationActivityInterrupted(int) = 0;
	virtual int OnAnimationEvent(void*) = 0;
	virtual int OnIgnite(void) = 0;
	virtual int OnInjured(void* const&) = 0;
	virtual int OnKilled(void* const&) = 0;
	virtual int OnOtherKilled(void*, void* const&) = 0;
	virtual int OnSight(CBaseEntity* pEntity) = 0;
	virtual int OnLostSight(CBaseEntity *) = 0;
	virtual int OnThreatChanged(CBaseEntity *) = 0;
	virtual int OnSound(CBaseEntity *, Vector const&, void*) = 0;
	virtual int OnSpokeConcept(void*, void*, void*) = 0;
	virtual int OnNavAreaChanged(void*, void*) = 0;
	virtual int OnModelChanged(void) = 0;
	virtual int OnPickUp(CBaseEntity *, void*) = 0;
	virtual int OnDrop(CBaseEntity*) = 0;
	virtual int OnShoved(CBaseEntity*) = 0;
	virtual int OnBlinded(CBaseEntity*) = 0;
	virtual int OnEnteredSpit(void) = 0;
	virtual int OnHitByVomitJar(CBaseEntity *) = 0;
	virtual int OnCommandAttack(CBaseEntity *) = 0;
	virtual int OnCommandAssault(void) = 0;
	virtual int OnCommandApproach(Vector const&, float) = 0;
	virtual int OnCommandApproach(CBaseEntity *) = 0;
	virtual int OnCommandRetreat(CBaseEntity *, float) = 0;
	virtual int OnCommandPause(float) = 0;
	virtual int OnCommandResume(void) = 0;
	virtual int OnCommandString(char const*) = 0;
};