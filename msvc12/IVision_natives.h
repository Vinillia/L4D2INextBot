#pragma once

cell_t GetTimeSinceVisible(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);
	int team = params[2];

	return sp_ftoc(body->GetTimeSinceVisible(team));
}

cell_t GetClosestRecognized(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);
	int team = params[2];

	return gamehelpers->EntityToBCompatRef(body->GetClosestRecognized(team));
}

cell_t GetRecognizedCount(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);
	int team = params[2];
	float range = sp_ctof(params[3]);

	return body->GetRecognizedCount(team, range);
}

cell_t GetMaxVisionRange(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);
	return sp_ftoc(body->GetMaxVisionRange());
}

cell_t GetMinRecognizeTime(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);
	return sp_ftoc(body->GetMinRecognizeTime());
}

cell_t IsAbleToSeeV(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);

	cell_t index = params[2];
	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	IVision::FieldOfViewCheckType type = (IVision::FieldOfViewCheckType)params[3];

	cell_t *addr;

	pContext->LocalToPhysAddr(params[4], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	bool ret = body->IsAbleToSee(pEntity, type, &source);
	SET_VECTOR(addr, source);

	return ret;
}

cell_t IsAbleToSeeE(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);

	IVision::FieldOfViewCheckType type = (IVision::FieldOfViewCheckType)params[3];

	cell_t *addr;

	pContext->LocalToPhysAddr(params[2], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	return body->IsAbleToSee(source, type);
}

cell_t IsNoticed(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);

	cell_t index = params[2];
	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	return body->IsNoticed(pEntity);
}

cell_t IsIgnored(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);

	cell_t index = params[2];
	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	return body->IsIgnored(pEntity);
}

cell_t IsInFieldOfViewE(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);

	cell_t index = params[2];
	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	return body->IsInFieldOfView(pEntity);
}

cell_t IsInFieldOfViewV(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);

	cell_t *addr;

	pContext->LocalToPhysAddr(params[2], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	return body->IsInFieldOfView(source);
}

cell_t GetDefaultFieldOfView(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);
	return sp_ftoc(body->GetDefaultFieldOfView());
}

cell_t GetFieldOfView(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);
	return sp_ftoc(body->GetFieldOfView());
}

cell_t SetFieldOfView(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);
	body->SetFieldOfView(sp_ctof(params[2]));
	return NULL;
}

cell_t IsLineOfSightClear(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);

	cell_t *addr;

	pContext->LocalToPhysAddr(params[2], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	return body->IsLineOfSightClear(source);
}

cell_t IsLineOfSightClearToEntity(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);

	cell_t index = params[3];
	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	cell_t *addr;
	pContext->LocalToPhysAddr(params[2], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	bool ret = body->IsLineOfSightClearToEntity(pEntity, &source);
	SET_VECTOR(addr, source);

	return ret;
}

cell_t IsLookingAt(IPluginContext *pContext, const cell_t *params)
{
	IVision* body = (IVision*)(params[1]);

	cell_t *addr;
	pContext->LocalToPhysAddr(params[2], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	return body->IsLookingAt(source, sp_ctof(params[3]));
}

const sp_nativeinfo_t Vision_Natives[] =
{
	{"Vision_GetTimeSinceVisible",	GetTimeSinceVisible},
	{"Vision_GetClosestRecognized",	GetClosestRecognized},
	{"Vision_GetRecognizedCount",	GetRecognizedCount},
	{"Vision_GetMaxVisionRange",	GetMaxVisionRange},
	{"Vision_GetMinRecognizeTime",	GetMinRecognizeTime},
	{"Vision_IsAbleToSeeE",	IsAbleToSeeE},
	{"Vision_IsAbleToSeeV",	IsAbleToSeeV},
	{"Vision_IsNoticed",	IsNoticed},
	{"Vision_IsIgnored",	IsIgnored},
	{"Vision_IsInFieldOfViewE",	IsInFieldOfViewE},
	{"Vision_IsInFieldOfViewV",	IsInFieldOfViewV},
	{"Vision_GetDefaultFieldOfView",	GetDefaultFieldOfView},
	{"Vision_GetFieldOfView",	GetFieldOfView},
	{"Vision_SetFieldOfView",	SetFieldOfView},
	{"Vision_IsLineOfSightClear",	IsLineOfSightClear},
	{"Vision_IsLineOfSightClearToEntity",	IsLineOfSightClearToEntity},
	{"Vision_IsLookingAt",	IsLookingAt},
	{NULL,			NULL},
};