
class IBody : INextBotComponent
{
public:
	enum LookAtPriorityType
	{
		BORING,
		INTERESTING,				// last known enemy location, dangerous sound location
		IMPORTANT,					// a danger
		CRITICAL,					// an active threat to our safety
		MANDATORY					// nothing can interrupt this look at - two simultaneous look ats with this priority is an error
	};

	enum PostureType
	{
		STAND,
		CROUCH,
		SIT,
		CRAWL,
		LIE
	};

	enum ArousalType
	{
		NEUTRAL,
		ALERT,
		INTENSE
	};
public:
	virtual void Reset(void) = 0;
	virtual void Update(void) = 0;
	virtual void pad00(void) = 0;
	virtual void pad01(void) const = 0;
	virtual void SetPosition(Vector const&) = 0;
	virtual Vector GetEyePosition(void) const = 0;
	virtual Vector GetViewVector(void) const = 0;
	virtual void AimHeadTowards(Vector const&, IBody::LookAtPriorityType, float, void*, char const*, bool, float) = 0;
	virtual void AimHeadTowards(CBaseEntity *, IBody::LookAtPriorityType, float, void*, char const*, bool, float) = 0;
	virtual bool IsHeadAimingOnTarget(void) const = 0;
	virtual bool IsHeadSteady(void) const = 0;
	virtual float GetHeadSteadyDuration(void) const = 0;
	virtual float GetMaxHeadAngularVelocity(void) const = 0;
	virtual bool StartActivity(Activity, unsigned int) = 0;
	virtual int SelectAnimationSequence(Activity) const = 0;
	virtual Activity GetActivity(void) const = 0;
	virtual bool IsActivity(Activity) const = 0;
	virtual bool HasActivityType(unsigned int) const = 0;
	virtual void SetDesiredPosture(IBody::PostureType) = 0;
	virtual PostureType GetDesiredPosture(void) const = 0;
	virtual bool IsDesiredPosture(IBody::PostureType) const = 0;
	virtual bool IsInDesiredPosture(void) const = 0;
	virtual PostureType GetActualPosture(void) const = 0;
	virtual bool IsActualPosture(IBody::PostureType) const = 0;
	virtual bool IsPostureMobile(void) const = 0;
	virtual bool IsPostureChanging(void) const = 0;
	virtual void SetArousal(IBody::ArousalType) = 0;
	virtual ArousalType GetArousal(void) const = 0;
	virtual bool IsArousal(IBody::ArousalType) const = 0;
	virtual float GetHullWidth(void) const = 0;
	virtual float GetHullHeight(void) const = 0;
	virtual float GetStandHullHeight(void) const = 0;
	virtual float GetCrouchHullHeight(void) const = 0;
	virtual const Vector GetHullMins(void) const = 0;
	virtual const Vector GetHullMaxs(void) const = 0;
	virtual unsigned int GetSolidMask(void) const = 0;
	virtual void* GetEntity(void) = 0;
};