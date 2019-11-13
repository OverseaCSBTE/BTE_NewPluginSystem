#include "shared/Main.h"

cvar_t npsDebug = { "nps_Debug", "0", FCVAR_EXTDLL, 0, NULL };
cvar_t npsVer = { "nps_Version", VersionString, FCVAR_EXTDLL, 0, NULL };

// While preloading done preprocess, we can register our commands and cvars :D
void PreRegisterConsoleCommands()
{
	CvarReg(&npsDebug);
	CvarReg(&npsVer);

	AddServerCommand("nps", NPS_Main);
}

void NPS_Main()
{

}