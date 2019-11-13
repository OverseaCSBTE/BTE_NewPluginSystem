#ifndef Structs_h
#define Structs_h

struct engine_t
{
	enginefuncs_t *engineFuncs;
	globalvars_t *globalVars;
	enginefuncs_t *modifiedFuncs;
	//EngineInfo
};

typedef struct 
{
	DLL_FUNCTIONS *dllAPI;
	NEW_DLL_FUNCTIONS *newAPI;
}gamedll_funcs_t;

typedef struct gamedll_s
{
	char name[64];						// From gamedir
	const char *desc;					// Game Desc
	char gamedir[MaxPathLen];			// Game Path | Game Dir
	char pathname[MaxPathLen];			// Game Dll Path
	const char *file;					// GameDll File Name
	char realPathName[MaxPathLen];		// ??
	HINSTANCE handle;
	gamedll_funcs_t funcs;
}gamedll_t;

#endif