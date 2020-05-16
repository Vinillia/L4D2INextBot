#pragma once


namespace Interface
{
	class CInterface
	{
		public:
			CInterface();

			CGlobalVars* pGlobalVars;
			IClientEntityList* g_pEntityList;
			ICvar* g_pCvar;
			IVEngineSound* pEngineSound;
			//IGameEventManager2* gameeventmanager;

			void* follow_rel32(uintptr_t address, size_t offset);
			uintptr_t find_pattern(HMODULE module, const char* signature);
			DWORD FindPattern(LPCSTR module, const char* szSig, const char* szMask);

		private:
			void* GetInterface(const char* dllname, const char* interfacename);
			void Initialize();
	};
};

extern std::unique_ptr<Interface::CInterface> g_pInterfaces;