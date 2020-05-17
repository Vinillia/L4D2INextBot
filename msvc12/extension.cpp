#pragma once

#include "extension.h"
#include "includes.h"
#include "msvc12/VMTHook.h"

CNextBotInterface g_pINextBot;
SMEXT_LINK(&g_pINextBot);

bool CNextBotInterface::SDK_OnLoad(char* error, size_t lenght, bool late)
{
	sharesys->RegisterLibrary(myself, "INextBotInterface");

	sharesys->AddNatives(myself, Vision_Natives);
	sharesys->AddNatives(myself, Locomotion_Natives);
	sharesys->AddNatives(myself, Body_Natives);
	sharesys->AddNatives(myself, Main_Natives);
	return true;
}

void CNextBotInterface::SDK_OnAllLoaded()
{
}

void CNextBotInterface::SDK_OnUnload()
{

}

