#include "shared\Main.h"

// My Class
NewPluginSystem nps;
enginefuncs_t gEngine;
gamedll_t GameDLL;

// Required DLL entry point
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{

	}
	else if (fdwReason == DLL_PROCESS_DETACH)
	{

	}
	return TRUE;
}

extern "C" __declspec(dllexport) void GiveFnptrsToDll(enginefuncs_t * pengfuncsFromEngine, globalvars_t * pGlobals)
{
	//memcpy(&g_engfuncs, pengfuncsFromEngine, sizeof(enginefuncs_t));
	nps.game.enginefunc = pengfuncsFromEngine;
	nps.game.globals = pGlobals;
	//gpGlobals = pGlobals;

	nps.pre.Init();
}

/*
void WINAPI GiveFnptrsToDll(enginefuncs_t *enginefunc, globalvars_t *globals)
{
	nps->game->enginefunc = enginefunc;
	nps->game->globals = globals;

	nps->pre->Init();
}
*/