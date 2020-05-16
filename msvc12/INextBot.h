
class INextBot : INextBotEventResponder
{
public:
	virtual void pad00() = 0;
	virtual void Reset(void) = 0;
	virtual void Update(void) = 0;
	virtual void Upkeep(void) = 0;
	virtual bool IsRemovedOnReset(void) const = 0;
	virtual void pad01() = 0;
	virtual void* GetNextBotCombatCharacter(void) const = 0;
	virtual void* MySurvivorBotPointer(void) const = 0;
	virtual ILocomotion* GetLocomotionInterface(void) const = 0;
	virtual IBody* GetBodyInterface(void) const = 0;
	virtual void* GetIntentionInterface(void) const = 0;
	virtual IVision* GetVisionInterface(void) const = 0;
	virtual bool SetPosition(Vector const&) = 0;
	virtual Vector GetPosition(void) const = 0;
	virtual bool IsEnemy(CBaseEntity const*) const = 0;
	virtual bool IsFriend(CBaseEntity const*) const = 0;
	virtual bool IsSelf(CBaseEntity const*) const = 0;
	virtual bool IsAllowedToClimb(void) const = 0;
	virtual bool IsAbleToClimbOnto(CBaseEntity const*) const = 0;
	virtual bool IsAbleToBreak(CBaseEntity const*) const = 0;
	virtual bool IsAbleToBlockMovementOf(INextBot const*) const = 0;
	virtual bool ShouldTouch(CBaseEntity const*) const = 0;
	virtual void ReactToSurvivorVisibility(void) const = 0;
	virtual void ReactToSurvivorNoise(void) const = 0;
	virtual void ReactToSurvivorContact(void) const = 0;
	virtual bool IsImmobile(void) const = 0;
	virtual float GetImmobileDuration(void) const = 0;
	virtual void ClearImmobileStatus(void) = 0;
	virtual float GetImmobileSpeedThreshold(void) const = 0;
	virtual bool IsRangeLessThan(CBaseEntity *, float) const = 0;
	virtual bool IsRangeLessThan(Vector const&, float) const = 0;
	virtual bool IsRangeGreaterThan(CBaseEntity *, float) const = 0;
	virtual bool IsRangeGreaterThan(Vector const&, float) const = 0;
	virtual float GetRangeTo(CBaseEntity *) const = 0;
	virtual float GetRangeTo(Vector const&) const = 0;
	virtual float GetRangeSquaredTo(CBaseEntity *) const = 0;
	virtual float GetRangeSquaredTo(Vector const&) const = 0;
	virtual float Get2DRangeTo(Vector const&) const = 0;
	virtual float Get2DRangeTo(CBaseEntity *) const = 0;
	virtual void GetDebugIdentifier(void) const = 0;
	virtual void IsDebugFilterMatch(char const*) const = 0;
	virtual void DisplayDebugText(char const*) const = 0;

private:
	friend class INextBotComponent;
	void RegisterComponent(INextBotComponent *comp) {};		// components call this to register themselves with the bot that contains them
	INextBotComponent *m_componentList;						// the first component

	const void* m_currentPath;						// the path we most recently followed

	int m_id;
	bool m_bFlaggedForUpdate;
	int m_tickLastUpdate;

	unsigned int m_debugType;
	mutable int m_debugDisplayLine;

	Vector m_immobileAnchor;
	void* m_immobileCheckTimer;
	void* m_immobileTimer;
	void UpdateImmobileStatus(void) {};

	mutable ILocomotion *m_baseLocomotion;
	mutable IBody		*m_baseBody;
	mutable void*	*m_baseIntention;
	mutable IVision		*m_baseVision;
	//mutable IAttention	*m_baseAttention;
};