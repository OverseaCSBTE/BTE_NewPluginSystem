#include "shared\Main.h"

// Extern from Common.h | Main.h
enginefuncs_t gEngine;
// Pure Clean and Original EngineFuncs
enginefuncs_t gEnginefuncs;
globalvars_t *gGlobals;
engine_t Engine;

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD fdwReason, LPVOID lpvReserved)
{
	return TRUE;
}

/*
Get engine function table from engine
So we need fuck dll in heeeere
*/
void WINAPI GiveFnptrsToDll(enginefuncs_t *enginefunc, globalvars_t *globals)
{
	gGlobals = globals;
	Engine.engineFuncs = &gEnginefuncs;
	Engine.globalVars = globals;

	PreloadSystem();
}