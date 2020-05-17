#pragma once

cell_t GetINextBot(IPluginContext *pContext, const cell_t *params)
{
	cell_t number = params[1];

	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(number));

	return (DWORD)pEntity + 16480;
}

cell_t GetInterface(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);
	uint8_t type = params[2];

	switch (type)
	{
	case 1:
		return (cell_t)bot->GetBodyInterface();
	case 2:
		return (cell_t)bot->GetVisionInterface();
	case 3:
		return (cell_t)bot->GetLocomotionInterface();
	}

	return NULL;
}

cell_t SetPosition(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);
	cell_t *addr;

	pContext->LocalToPhysAddr(params[2], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	return bot->SetPosition(source);
}

cell_t GetPosition(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);

	cell_t *addr;
	pContext->LocalToPhysAddr(params[2], &addr);

	SET_VECTOR(addr, bot->GetPosition());
	return NULL;
}

cell_t IsEnemy(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);

	cell_t index = params[2];

	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));
	return bot->IsEnemy(pEntity);
}

cell_t IsFriend(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);

	cell_t index = params[2];

	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));
	return bot->IsFriend(pEntity);
}

cell_t IsSelf(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);

	cell_t index = params[2];

	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));
	return bot->IsSelf(pEntity);
}

cell_t IsAllowedToClimb(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);
	return bot->IsAllowedToClimb();
}

cell_t IsAbleToClimbOnto(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);

	cell_t index = params[2];

	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	return bot->IsAbleToClimbOnto(pEntity);
}

cell_t IsAbleToBreak(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);

	cell_t index = params[2];

	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	return bot->IsAbleToBreak(pEntity);
}

cell_t IsAbleToBlockMovementOf(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);
	INextBot* target = (INextBot*)(params[2]);

	return bot->IsAbleToBlockMovementOf(target);
}

cell_t ReactToSurvivorVisibility(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);
	bot->ReactToSurvivorVisibility();
	return NULL;
}

cell_t ReactToSurvivorNoise(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);
	bot->ReactToSurvivorNoise();
	return NULL;
}

cell_t ReactToSurvivorContact(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);
	bot->ReactToSurvivorContact();
	return NULL;
}

cell_t IsImmobile(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);
	return bot->IsImmobile();
}

cell_t GetImmobileDuration(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);
	return sp_ftoc(bot->GetImmobileDuration());
}

cell_t ClearImmobileStatus(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);
	bot->ClearImmobileStatus();
	return NULL;
}

cell_t GetImmobileSpeedThreshold(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);
	return sp_ftoc(bot->GetImmobileSpeedThreshold());
}

cell_t IsRangeLessThan(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);

	cell_t index = params[2];
	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	float then = sp_ctof(params[3]);

	return bot->IsRangeLessThan(pEntity, then);
}

cell_t IsRangeGreaterThan(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);

	cell_t index = params[2];
	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	float then = sp_ctof(params[3]);

	return bot->IsRangeGreaterThan(pEntity, then);
}

cell_t GetRangeTo(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);

	cell_t index = params[2];
	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	return sp_ftoc(bot->GetRangeTo(pEntity));
}

cell_t GetRangeSquaredTo(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);

	cell_t index = params[2];
	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	return sp_ftoc(bot->GetRangeSquaredTo(pEntity));
}

cell_t Get2DRangeTo(IPluginContext *pContext, const cell_t *params)
{
	INextBot* bot = (INextBot*)(params[1]);

	cell_t index = params[2];
	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	return sp_ftoc(bot->Get2DRangeTo(pEntity));
}

const sp_nativeinfo_t Main_Natives[] =
{
	{"NextBot_GetINextBot",	GetINextBot},
	{"NextBot_GetInterface",	GetInterface},
	{"NextBot_SetPosition",	SetPosition},
	{"NextBot_GetPosition",	GetPosition},
	{"NextBot_IsEnemy",	IsEnemy},
	{"NextBot_IsFriend",	IsFriend},
	{"NextBot_IsSelf",	IsSelf},
	{"NextBot_IsAllowedToClimb",	IsAllowedToClimb},
	{"NextBot_IsAbleToClimbOnto",	IsAbleToClimbOnto},
	{"NextBot_IsAbleToBreak",	IsAbleToBreak},
	{"NextBot_IsAbleToBlockMovementOf",	IsAbleToBlockMovementOf},
	{"NextBot_ReactToSurvivorVisibility",	ReactToSurvivorVisibility},
	{"NextBot_ReactToSurvivorNoise",	ReactToSurvivorNoise},
	{"NextBot_ReactToSurvivorContact",	ReactToSurvivorContact},
	{"NextBot_IsImmobile",	IsImmobile},
	{"NextBot_GetImmobileDuration",	GetImmobileDuration},
	{"NextBot_ClearImmobileStatus",	ClearImmobileStatus},
	{"NextBot_GetImmobileSpeedThreshold",	GetImmobileSpeedThreshold},
	{"NextBot_IsRangeLessThan",	IsRangeLessThan},
	{"NextBot_IsRangeGreaterThan",	IsRangeGreaterThan},
	{"NextBot_GetRangeTo",	GetRangeTo},
	{"NextBot_GetRangeSquaredTo",	GetRangeSquaredTo},
	{"NextBot_Get2DRangeTo",	Get2DRangeTo},
	{NULL,			NULL},
};
