#include "shared/Main.h"

cvar_t npsDebug = { "nps_Debug", "0", FCVAR_EXTDLL, 0, NULL };
cvar_t npsVer = { "nps_Version", VersionString, FCVAR_EXTDLL, 0, NULL };

void CommandsSystem::Init()
{
	nps.game.enginefunc->pfnCVarRegister(&npsDebug);
	CvarReg(&npsDebug);
	CvarReg(&npsVer);

	//AddServerCommand("nps", nps->Commands->Main);
}

// Our Commands System
void CommandsSystem::Main()
{
	// Read Commands Arguments
	const char* args = CommandArgv(1);

	// Start Compare Args, if failed show help
	if (compare(args, "version"))
		return;
	else if (compare(args, "xxx"))
		return;
	else
		CommandsSystem().Help();
}

// Compare First... Make sure this at lowest
// Because user input unsupported function, so we need a information
// about our commands
void CommandsSystem::Help()
{

}
