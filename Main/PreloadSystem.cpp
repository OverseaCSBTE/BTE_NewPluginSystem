#include "shared\Main.h"

void Preload::Init()
{
	// Message that we show to console while we're loading or loaded
	const char *msg = 
		R"(		
	%s (Version: %s)
)";
	// Send Some Basic Message To Console.
	nps.logSys.PrintToConsole(msg, ProjectName, VersionString);

	// Project Starting at Here!
	// We need identify and init gamedll
	if (!InitGameDLL())
		exit(0);

	// Register our commands
	nps.Commands.Init();

	// okay, we can connect dll to future use
}

BOOL Preload::InitGameDLL()
{
	char gameDir[MaxPathLen];
	char buf[MaxPathLen];

	reset(GameDLL);

	GetGameDir(gameDir);

	if (!getcwd(buf, sizeof(buf)))
	{
		nps.logSys.Error("Unable To Find Directory.");
		return FALSE;
	}

	sprintf(GameDLL.gamedir, "%s/%s", buf, gameDir);
	strcpy(GameDLL.name, gameDir);

	return TRUE;
}

BOOL Preload::LoadGameDLL()
{
	int iver;
	int found = 0;

	GiveEngineFunctionFN giveEngineFuncs;
	GetNewDLLFunctionsFN getAPINew;
	GetEntityAPIFN getAPI;
	GetEntityAPI2FN getAPI2;

	// Find mp
	if (!FindGameDLL())
	{
		nps.logSys.Error("Unable To Find DLL.");
		exit(0);
	}
	
	// Load mp
	if (!(GameDLL.handle = LibOpen(GameDLL.pathname)))
	{
		nps.logSys.Error("Unable To Load DLL.");
		exit(0);
	}

	// Send to engine
	if (giveEngineFuncs = (GiveEngineFunctionFN)GetAddress(GameDLL.handle, "GiveFnptrsToDll"))
		giveEngineFuncs(nps.game.enginefunc, nps.game.globals);
	else
	{
		nps.logSys.Error("Unable To Find Required Places.");
		exit(0);
	}

	return TRUE;
}

BOOL Preload::FindGameDLL()
{
	const char* knownPath = "/dlls/mp.dll";

	// dunno why metamod create 2 times
	// first is find dll path and save it
	// second is save to realpathname using first method....
	sprintf(GameDLL.pathname, "%s/%s", GameDLL.gamedir, knownPath);
	strcpy(GameDLL.realPathName, GameDLL.pathname);

	return TRUE;
}