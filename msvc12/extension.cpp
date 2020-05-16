#pragma once

#include "extension.h"
#include "includes.h"

CNextBotInterface g_pINextBot;
SMEXT_LINK(&g_pINextBot);

bool CNextBotInterface::SDK_OnLoad(char* error, size_t lenght, bool late)
{
	return true;
}

void CNextBotInterface::SDK_OnAllLoaded()
{
	sharesys->RegisterLibrary(myself, "INextBotInterface");
	sharesys->AddNatives(myself, Vision_Natives);
	sharesys->AddNatives(myself, Locomotion_Natives);
	sharesys->AddNatives(myself, Body_Natives);
	sharesys->AddNatives(myself, Main_Natives);
}

void CNextBotInterface::SDK_OnUnload()
{

}