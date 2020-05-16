/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod Sample Extension
 * Copyright (C) 2004-2008 AlliedModders LLC.  All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#include "msvc12/includes.h"
#include "msvc12/VMTHook.h"

CNextBotInterface g_pMe;
SMEXT_LINK(&g_pMe);

bool CNextBotInterface::SDK_OnLoad(char *error, size_t maxlen, bool late)
{
	return true;
}


void CNextBotInterface::SDK_OnAllLoaded()
{
	sharesys->AddNatives(myself, Main_Natives);
	sharesys->AddNatives(myself, Vision_Natives);
	sharesys->AddNatives(myself, Body_Natives);
	sharesys->AddNatives(myself, Locomotion_Natives);

	g_pInterfaces = std::make_unique<Interface::CInterface>();
}

void CNextBotInterface::SDK_OnUnload()
{
}

