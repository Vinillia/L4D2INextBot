#pragma once

cell_t Approach(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	cell_t *addr;

	pContext->LocalToPhysAddr(params[2], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	locomotion->Approach(source, sp_ctof(params[3]));
	return NULL;
}

cell_t DriveTo(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	cell_t *addr;

	pContext->LocalToPhysAddr(params[2], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	locomotion->DriveTo(source);
	return NULL;
}

cell_t ClimbUpToLedge(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	cell_t *addr, *addr01;

	pContext->LocalToPhysAddr(params[2], &addr);
	pContext->LocalToPhysAddr(params[3], &addr01);

	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));
	Vector source01(sp_ctof(addr01[0]), sp_ctof(addr01[1]), sp_ctof(addr01[2]));

	cell_t index = params[4];
	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	return locomotion->ClimbUpToLedge(source, source01, pEntity);
}

cell_t JumpAcrossGap(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	cell_t *addr, *addr01;

	pContext->LocalToPhysAddr(params[2], &addr);
	pContext->LocalToPhysAddr(params[3], &addr01);

	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));
	Vector source01(sp_ctof(addr01[0]), sp_ctof(addr01[1]), sp_ctof(addr01[2]));

	locomotion->JumpAcrossGap(source, source01);
	return NULL;
}

cell_t Jump(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	locomotion->Jump();
	return NULL;
}

cell_t IsClimbingOrJumping(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return locomotion->IsClimbingOrJumping();
}

cell_t IsClimbingUpToLedge(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return locomotion->IsClimbingUpToLedge();
}

cell_t IsScrambling(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return locomotion->IsScrambling();
}

cell_t Run(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	locomotion->Run();
	return NULL;
}

cell_t Walk(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	locomotion->Walk();
	return NULL;
}

cell_t Stop(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	locomotion->Stop();
	return NULL;
}

cell_t IsRunning(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return locomotion->IsRunning();
}

cell_t SetDesiredSpeed(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	float speed = sp_ctof(params[2]);

	locomotion->SetDesiredSpeed(speed);
	return NULL;
}

cell_t GetDesiredSpeed(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return sp_ftoc(locomotion->GetDesiredSpeed());
}

cell_t SetSpeedLimit(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	float speed = sp_ctof(params[2]);

	locomotion->SetSpeedLimit(speed);
	return NULL;
}

cell_t GetSpeedLimit(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return sp_ftoc(locomotion->GetSpeedLimit());
}

cell_t IsOnGround(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return locomotion->IsOnGround();
}

cell_t GetGround(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return gamehelpers->EntityToBCompatRef(locomotion->GetGround());
}

cell_t GetGroundNormal(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);

	cell_t *addr;
	pContext->LocalToPhysAddr(params[2], &addr);

	SET_VECTOR(addr, locomotion->GetGroundNormal());
	return NULL;
}

cell_t GetGroundSpeed(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return sp_ftoc(locomotion->GetGroundSpeed());
}

cell_t GetGroundMotionVector(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);

	cell_t *addr;
	pContext->LocalToPhysAddr(params[2], &addr);

	SET_VECTOR(addr, locomotion->GetGroundMotionVector());
	return NULL;
}

cell_t IsUsingLadder(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return locomotion->IsUsingLadder();
}

cell_t IsAscendingOrDescendingLadder(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return locomotion->IsAscendingOrDescendingLadder();
}

cell_t IsAbleToAutoCenterOnLadder(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return locomotion->IsAbleToAutoCenterOnLadder();
}

cell_t FaceTowards(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	cell_t *addr;

	pContext->LocalToPhysAddr(params[2], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	locomotion->FaceTowards(source);
	return NULL;
}

cell_t SetDesiredLean(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	cell_t *addr;

	pContext->LocalToPhysAddr(params[2], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	locomotion->SetDesiredLean(source);
	return NULL;
}

cell_t GetFeet(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);

	cell_t *addr;
	pContext->LocalToPhysAddr(params[2], &addr);

	SET_VECTOR(addr, locomotion->GetFeet());
	return NULL;
}

cell_t GetStepHeight(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return sp_ftoc(locomotion->GetStepHeight());
}

cell_t GetMaxJumpHeight(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return sp_ftoc(locomotion->GetMaxJumpHeight());
}

cell_t GetDeathDropHeight(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return sp_ftoc(locomotion->GetDeathDropHeight());
}

cell_t GetRunSpeed(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return sp_ftoc(locomotion->GetRunSpeed());
}

cell_t GetWalkSpeed(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return sp_ftoc(locomotion->GetWalkSpeed());
}

cell_t GetVelocity(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);

	cell_t *addr;
	pContext->LocalToPhysAddr(params[2], &addr);

	SET_VECTOR(addr, locomotion->GetVelocity());
	return NULL;
}

cell_t GetSpeed(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return sp_ftoc(locomotion->GetSpeed());
}

cell_t GetMotionVector(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);

	cell_t *addr;
	pContext->LocalToPhysAddr(params[2], &addr);

	SET_VECTOR(addr, locomotion->GetMotionVector());
	return NULL;
}

cell_t IsPotentiallyTraversable(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);

	cell_t *addr, *addr00;

	pContext->LocalToPhysAddr(params[2], &addr);
	pContext->LocalToPhysAddr(params[3], &addr00);

	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));
	Vector source2(sp_ctof(addr00[0]), sp_ctof(addr00[1]), sp_ctof(addr00[2]));

	float fraction = sp_ctof(params[4]);

	ILocomotion::TraverseWhenType type = (ILocomotion::TraverseWhenType)params[4];

	return locomotion->IsPotentiallyTraversable(source, source2, type, &fraction);
}

cell_t HasPotentialGap(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);

	cell_t *addr, *addr00;

	pContext->LocalToPhysAddr(params[2], &addr);
	pContext->LocalToPhysAddr(params[3], &addr00);

	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));
	Vector source2(sp_ctof(addr00[0]), sp_ctof(addr00[1]), sp_ctof(addr00[2]));

	float fraction = sp_ctof(params[4]);

	return locomotion->HasPotentialGap(source, source2, &fraction);
}

cell_t IsGap(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);

	cell_t *addr, *addr00;

	pContext->LocalToPhysAddr(params[2], &addr);
	pContext->LocalToPhysAddr(params[3], &addr00);

	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));
	Vector source2(sp_ctof(addr00[0]), sp_ctof(addr00[1]), sp_ctof(addr00[2]));

	return locomotion->IsGap(source, source2);
}

cell_t IsEntityTraversable(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);

	cell_t index = params[2];
	CBaseEntity* pEntity = gamehelpers->ReferenceToEntity(gamehelpers->IndexToReference(index));

	ILocomotion::TraverseWhenType type = (ILocomotion::TraverseWhenType)params[4];

	return locomotion->IsEntityTraversable(pEntity, type);
}

cell_t IsStuck(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return locomotion->IsStuck();
}

cell_t GetStuckDuration(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return sp_ftoc(locomotion->GetStuckDuration());
}

cell_t ClearStuckStatus(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	char* reason;
	pContext->LocalToString(params[2], &reason);

	locomotion->ClearStuckStatus(reason);
	return NULL;
}

cell_t IsAttemptingToMove(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);
	return locomotion->IsAttemptingToMove();
}

cell_t AdjustPosture(IPluginContext *pContext, const cell_t *params)
{
	ILocomotion* locomotion = (ILocomotion*)(params[1]);

	cell_t *addr;

	pContext->LocalToPhysAddr(params[2], &addr);
	Vector source(sp_ctof(addr[0]), sp_ctof(addr[1]), sp_ctof(addr[2]));

	locomotion->AdjustPosture(source);
	return NULL;
}

const sp_nativeinfo_t Locomotion_Natives[] =
{
	{"Locomotion_Approach",	Approach},
	{"Locomotion_DriveTo",	DriveTo},
	{"Locomotion_ClimbUpToLedge",	ClimbUpToLedge},
	{"Locomotion_JumpAcrossGap",	JumpAcrossGap},
	{"Locomotion_Jump",	Jump},
	{"Locomotion_IsClimbingOrJumping",	IsClimbingOrJumping},
	{"Locomotion_IsClimbingUpToLedge",	IsClimbingUpToLedge},
	{"Locomotion_Run",	Run},
	{"Locomotion_Walk",	Walk},
	{"Locomotion_Stop",	Stop},
	{"Locomotion_IsRunning",	IsRunning},
	{"Locomotion_SetDesiredSpeed",	SetDesiredSpeed},
	{"Locomotion_GetDesiredSpeed",	GetDesiredSpeed},
	{"Locomotion_SetSpeedLimit",	SetSpeedLimit},
	{"Locomotion_GetSpeedLimit",	GetSpeedLimit},
	{"Locomotion_IsOnGround",	IsOnGround},
	{"Locomotion_GetGround",	GetGround},
	{"Locomotion_GetGroundNormal",	GetGroundNormal},
	{"Locomotion_GetGroundSpeed",	GetGroundSpeed},
	{"Locomotion_GetGroundMotionVector",	GetGroundMotionVector},
	{"Locomotion_IsUsingLadder",	IsUsingLadder},
	{"Locomotion_IsAscendingOrDescendingLadder",	IsAscendingOrDescendingLadder},
	{"Locomotion_IsAbleToAutoCenterOnLadder",	IsAbleToAutoCenterOnLadder},
	{"Locomotion_FaceTowards",	FaceTowards},
	{"Locomotion_SetDesiredLean",	SetDesiredLean},
	{"Locomotion_GetFeet",	GetFeet},
	{"Locomotion_GetStepHeight",	GetStepHeight},
	{"Locomotion_GetMaxJumpHeight",	GetMaxJumpHeight},
	{"Locomotion_GetDeathDropHeight",	GetDeathDropHeight},
	{"Locomotion_GetRunSpeed",	GetRunSpeed},
	{"Locomotion_GetWalkSpeed",	GetWalkSpeed},
	{"Locomotion_GetVelocity",	GetVelocity},
	{"Locomotion_GetSpeed",	GetSpeed},
	{"Locomotion_GetMotionVector",	GetMotionVector},
	{"Locomotion_IsPotentiallyTraversable",	IsPotentiallyTraversable},
	{"Locomotion_HasPotentialGap",	HasPotentialGap},
	{"Locomotion_IsEntityTraversable",	IsEntityTraversable},
	{"Locomotion_IsStuck",	IsStuck},
	{"Locomotion_GetMotionVector",	GetMotionVector},
	{"Locomotion_GetStuckDuration",	GetStuckDuration},
	{"Locomotion_ClearStuckStatus",	ClearStuckStatus},
	{"Locomotion_IsAttemptingToMove",	IsAttemptingToMove},
	{"Locomotion_GetMotionVector",	GetMotionVector},
	{"Locomotion_IsGap",	IsGap},
	{"Locomotion_AdjustPosture",	AdjustPosture},
	{NULL,			NULL},
};