#include "includes.h"

#include <psapi.h>

using namespace Interface;

std::unique_ptr<CInterface> g_pInterfaces;


CInterface::CInterface()
{
	this->Initialize();
}

void CInterface::Initialize()
{
	//this->g_pEntityList = (IClientEntityList*)this->GetInterface("client.dll", "VClientEntityList003");
	this->g_pCvar = (ICvar*)this->GetInterface("vstdlib.dll", "VEngineCvar007");
	//this->pEngineSound = (IVEngineSound*)this->GetInterface("engine.dll", "IEngineSoundServer003");
	
	//this->pGlobalVars = **reinterpret_cast<CGlobalVars***>(((reinterpret_cast<std::uintptr_t>(GetModuleHandleA("client.dll")) + 0x46C0) + 0x2));
	//this->gameeventmanager = (IGameEventManager2*)this->GetInterface("engine.dll", "GAMEEVENTSMANAGER002");
}

typedef void* (__cdecl* tCreateInterface)(const char* name, int* returnCode);

void* CInterface::GetInterface(const char* dllname, const char* interfacename)
{
	tCreateInterface CreateInterface = (tCreateInterface)GetProcAddress(GetModuleHandle(dllname), "CreateInterface");

	int returnCode = 0;
	void* IFace = CreateInterface(interfacename, &returnCode);

	return IFace;
}

void* CInterface::follow_rel32(uintptr_t address, size_t offset)
{
	auto offsetAddr = address + offset;
	auto relative = *(uint32_t *)offsetAddr;

	return (void*)(offsetAddr + relative + sizeof(uint32_t));
}

uintptr_t CInterface::find_pattern(HMODULE module, const char* signature)
{
	static auto pattern_to_byte = [](const char* pattern) {
		auto bytes = std::vector<int>{};
		auto start = const_cast<char*>(pattern);
		auto end = const_cast<char*>(pattern) + strlen(pattern);

		for (auto current = start; current < end; ++current) {
			if (*current == '?') {
				++current;
				if (*current == '?')
					++current;
				bytes.push_back(-1);
			}
			else {
				bytes.push_back(strtoul(current, &current, 16));
			}
		}
		return bytes;
	};

	auto dosHeader = (PIMAGE_DOS_HEADER)module;
	auto ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)module + dosHeader->e_lfanew);

	auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
	auto patternBytes = pattern_to_byte(signature);
	auto scanBytes = reinterpret_cast<std::uint8_t*>(module);

	auto s = patternBytes.size();
	auto d = patternBytes.data();

	for (auto i = 0ul; i < sizeOfImage - s; ++i) 
	{
		bool found = true;
		for (auto j = 0ul; j < s; ++j) {
			if (scanBytes[i + j] != d[j] && d[j] != -1) {
				found = false;
				break;
			}
		}
		if (found) {
			return (uintptr_t)&scanBytes[i];
		}
	}
	return 0;
}

inline MODULEINFO GetModuleInfo(LPCSTR szModule)
{
	MODULEINFO modinfo = { 0 };
	HMODULE hModule = GetModuleHandleA(szModule);
	if (hModule == 0) return modinfo;
	GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
	return modinfo;
}

BOOL Match(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask == 'x' && *pData != *bMask)
			return false;
	return (*szMask) == NULL;
}


DWORD CInterface::FindPattern(LPCSTR module, const char* szSig, const char* szMask)
{
	DWORD dwAddress = (DWORD)GetModuleHandle(module);
	DWORD dwLen = GetModuleInfo(module).SizeOfImage;

	for (DWORD i = 0; i < dwLen; i++)
		if (Match((BYTE*)(dwAddress + i), (BYTE*)szSig, szMask))
			return (DWORD)(dwAddress + i);

	return 0;
}