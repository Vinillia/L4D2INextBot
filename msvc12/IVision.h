#pragma once

class IVision : INextBotComponent
{
public:
	enum FieldOfViewCheckType { USE_FOV, DISREGARD_FOV };

	virtual void Reset(void) = 0;
	virtual void Update(void) = 0;
	virtual void pad00(void) = 0;
	virtual void pad01(void) const = 0;
	virtual void GetPrimaryRecognizedThreat(void) const = 0;
	virtual float GetTimeSinceVisible(int) const = 0;
	virtual CBaseEntity* GetClosestRecognized(int) const = 0;
	virtual int  GetRecognizedCount(int, float) const = 0;
	virtual CBaseEntity* GetClosestRecognized(uintptr_t const&) const = 0;
	virtual float GetMaxVisionRange(void) const = 0;
	virtual float GetMinRecognizeTime(void) const = 0;
	virtual bool IsAbleToSee(CBaseEntity *, IVision::FieldOfViewCheckType, Vector *) const = 0;
	virtual bool IsAbleToSee(Vector const&, IVision::FieldOfViewCheckType) const = 0;
	virtual bool IsNoticed(CBaseEntity *) const = 0;
	virtual bool IsIgnored(CBaseEntity *) const = 0;
	virtual bool IsInFieldOfView(Vector const&) const = 0;
	virtual bool IsInFieldOfView(CBaseEntity *) const = 0;
	virtual float GetDefaultFieldOfView(void) const = 0;
	virtual float GetFieldOfView(void) const = 0;
	virtual void SetFieldOfView(float) = 0;
	virtual bool IsLineOfSightClear(Vector const&) const = 0;
	virtual bool IsLineOfSightClearToEntity(CBaseEntity *, Vector *) const = 0;
	virtual bool IsLookingAt(Vector const&, float) const = 0;
	virtual bool IsLookingAt(void const*, float) const = 0;

private:
	void* m_scanTimer;			// for throttling update rate

	float m_FOV;						// current FOV in degrees
	float m_cosHalfFOV;					// the cosine of FOV/2

	//std::vector<CKnownEntity > m_knownEntityVector;		// im not sure about it
	mutable HANDLE m_primaryThreat;

	float m_lastVisionUpdateTimestamp;
	void* m_notVisibleTimer[MAX_TEAMS];		// for tracking interval since last saw a member of the given team
};