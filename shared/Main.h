#ifndef Main_H
#define Main_h

// We Needed Files
#include <Windows.h>
#include <extdll.h>
#include <direct.h>

//#include <cvardef.h>
//#include <enginecallback.h>

#define MaxPathLen 512
#define MaxMsgLen 1024

// Some Custom Stuffs
#include "Resources/Version.h"
#include "shared/Structs.h"
#include "shared/Common.h"

// Our GiveFnptrsToDll, called by engine.
typedef void (WINAPI* GiveEngineFunctionFN) (enginefuncs_t* pengfuncsFromEngine, globalvars_t* pGlobals);
// Typedefs for these are provided in SDK engine/eiface.h, but I didn't
// like the names (APIFUNCTION, APIFUNCTION2, NEW_DLL_FUNCTIONS_FN).
typedef int (*GetEntityAPIFN) (DLL_FUNCTIONS* pFunctionTable, int interfaceVersion);
typedef int (*GetEntityAPI2FN) (DLL_FUNCTIONS* pFunctionTable, int* interfaceVersion);
typedef int (*GetNewDLLFunctionsFN) (NEW_DLL_FUNCTIONS* pFunctionTable, int* interfaceVersion);

inline HINSTANCE LibOpen(const char* dllFileName)
{
	return LoadLibrary(dllFileName);
}

inline FARPROC GetAddress(HINSTANCE handle, const char* string)
{
	return GetProcAddress(handle, string);
}

/*
Get engine function table from engine
So we need fuck dll in heeeere
*/
ExportC void WINAPI GiveFnptrsToDll(enginefuncs_t *engine, globalvars_t *globals);

// Every Classes Stored at here
#include "shared/Classes.h"

// This is Special cause we are Main Class
class NewPluginSystem
{
public:
	Engine* game;
public:
	CommandsSystem *Commands;
	Preload *pre;
	LogSystem *logSys;
};

extern NewPluginSystem* nps;

#endif