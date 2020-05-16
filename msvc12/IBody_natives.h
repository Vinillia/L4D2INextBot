#pragma once

cell_t Body_SetPosition(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	cell_t *addr;

	pContext->LocalToPhysAddr(params[2], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	body->SetPosition(source);
	return NULL;
}

cell_t GetEyePosition(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);

	cell_t *addr;
	pContext->LocalToPhysAddr(params[2], &addr);

	SET_VECTOR(addr, body->GetEyePosition());
	return NULL;
}

cell_t GetViewVector(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);

	cell_t *addr;
	pContext->LocalToPhysAddr(params[2], &addr);

	SET_VECTOR(addr, body->GetViewVector());
	return NULL;
}

cell_t AimHeadTowardsVector(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);

	cell_t *addr;
	pContext->LocalToPhysAddr(params[2], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	IBody::LookAtPriorityType type = (IBody::LookAtPriorityType)params[3];
	float duration = sp_ctof(params[4]);

	char *reason;
	pContext->LocalToString(params[5], &reason);

	body->AimHeadTowards(source, type, duration, NULL, reason, false, 0.0);
	return NULL;
}

cell_t AimHeadTowardsEntity(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);

	cell_t index = params[2];
	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	IBody::LookAtPriorityType type = (IBody::LookAtPriorityType)params[3];
	float duration = sp_ctof(params[4]);

	char *reason;
	pContext->LocalToString(params[5], &reason);

	body->AimHeadTowards(pEntity, type, duration, NULL, reason, false, 0.0);
	return NULL;
}

cell_t IsHeadAimingOnTarget(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return body->IsHeadAimingOnTarget();
}

cell_t IsHeadSteady(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return body->IsHeadSteady();
}

cell_t GetHeadSteadyDuration(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return sp_ftoc(body->GetHeadSteadyDuration());
}

cell_t GetMaxHeadAngularVelocity(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return sp_ftoc(body->GetMaxHeadAngularVelocity());
}

cell_t StartActivity(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	Activity act = (Activity)(params[2]);
	int flags = params[3];

	return body->StartActivity(act, flags);
}

cell_t SelectAnimationSequence(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	Activity act = (Activity)(params[2]);

	return body->SelectAnimationSequence(act);
}

cell_t GetActivity(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return body->GetActivity();
}

cell_t IsActivity(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	Activity act = (Activity)(params[2]);

	return body->IsActivity(act);
}

cell_t HasActivityType(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	int flags = params[2];

	return body->HasActivityType(flags);
}

cell_t SetDesiredPosture(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	IBody::PostureType posture = (IBody::PostureType)params[2];

	body->SetDesiredPosture(posture);
	return NULL;
}

cell_t GetDesiredPosture(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return body->GetDesiredPosture();
}

cell_t IsDesiredPosture(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	IBody::PostureType posture = (IBody::PostureType)params[2];

	return body->IsDesiredPosture(posture);
}

cell_t IsInDesiredPosture(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return body->IsInDesiredPosture();
}

cell_t GetActualPosture(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return body->GetActualPosture();
}

cell_t IsActualPosture(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	IBody::PostureType posture = (IBody::PostureType)params[2];

	return body->IsActualPosture(posture);
}

cell_t IsPostureMobile(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return body->IsPostureMobile();
}

cell_t IsPostureChanging(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return body->IsPostureChanging();
}

cell_t SetArousal(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	IBody::ArousalType arousal = (IBody::ArousalType)params[2];

	body->SetArousal(arousal);
	return NULL;
}

cell_t GetArousal(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return body->GetArousal();
}

cell_t IsArousal(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	IBody::ArousalType arousal = (IBody::ArousalType)params[2];
	return body->IsArousal(arousal);
}

cell_t GetHullWidth(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return sp_ftoc(body->GetHullWidth());
}

cell_t GetHullHeight(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return sp_ftoc(body->GetHullHeight());
}

cell_t GetStandHullHeight(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return sp_ftoc(body->GetStandHullHeight());
}

cell_t GetCrouchHullHeight(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return sp_ftoc(body->GetCrouchHullHeight());
}

cell_t GetHullMins(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);

	cell_t *addr;
	pContext->LocalToPhysAddr(params[2], &addr);

	SET_VECTOR(addr, body->GetHullMins());
	return NULL;
}

cell_t GetHullMaxs(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);

	cell_t *addr;
	pContext->LocalToPhysAddr(params[2], &addr);

	SET_VECTOR(addr, body->GetHullMaxs());
	return NULL;
}

cell_t GetSolidMask(IPluginContext *pContext, const cell_t *params)
{
	IBody* body = (IBody*)(params[1]);
	return body->GetSolidMask();
}

const sp_nativeinfo_t Body_Natives[] =
{
	{"Body_SetPosition",	Body_SetPosition},
	{"Body_GetEyePosition",	GetEyePosition},
	{"Body_GetViewVector",	GetViewVector},
	{"Body_AimHeadTowardsVector",	AimHeadTowardsVector},
	{"Body_AimHeadTowardsEntity",	AimHeadTowardsEntity},
	{"Body_IsHeadAimingOnTarget",	IsHeadAimingOnTarget},
	{"Body_IsHeadSteady",	IsHeadSteady},
	{"Body_GetHeadSteadyDuration",	GetHeadSteadyDuration},
	{"Body_GetMaxHeadAngularVelocity",	GetMaxHeadAngularVelocity},
	{"Body_StartActivity",	StartActivity},
	{"Body_SelectAnimationSequence",	SelectAnimationSequence},
	{"Body_GetActivity",	GetActivity},
	{"Body_HasActivityType",	HasActivityType},
	{"Body_SetDesiredPosture",	SetDesiredPosture},
	{"Body_GetDesiredPosture",	GetDesiredPosture},
	{"Body_IsDesiredPosture",	IsDesiredPosture},
	{"Body_IsInDesiredPosture",	IsInDesiredPosture},
	{"Body_GetActualPosture",	GetActualPosture},
	{"Body_IsActualPosture",	IsActualPosture},
	{"Body_IsPostureMobile",	IsPostureMobile},
	{"Body_IsPostureChanging",	IsPostureChanging},
	{"Body_SetArousal",	SetArousal},
	{"Body_GetArousal",	GetArousal},
	{"Body_IsArousal",	IsArousal},
	{"Body_GetHullWidth",	GetHullWidth},
	{"Body_GetHullHeight",	GetHullHeight},
	{"Body_GetStandHullHeight",	GetStandHullHeight},
	{"Body_GetCrouchHullHeight",	GetCrouchHullHeight},
	{"Body_GetHullMins",	GetHullMins},
	{"Body_GetHullMaxs",	GetHullMaxs},
	{"Body_GetSolidMask",	GetSolidMask},
	{NULL,			NULL},
};
