#include "shared\Main.h"

gamedll_t GameDLL;

// Starting Function
void PreloadSystem()
{
	const char *msg = 
		R"(		
	%s (Version: %s)
)";
	// Send Some Basic Message To Console.
	PrintToConsole(msg, ProjectName, VersionString);

	// Project Starting at Here!
	// We need identify and init gamedll
	if (!InitGameDLL())
		exit(0);


}

// As Metamod.cpp Said, 1.1.1.1 Version of CS or Half-life,
// It returns argument of game instead of path
// As I checked on engine 3266, we are using 1.1.2.6
// And we not fucking on old system (If we want... we change it)
// So we just using new method on it.
BOOL InitGameDLL()
{
	char gameDir[MaxPathLen];
	char buf[MaxPathLen];

	reset(GameDLL);

	GetGameDir(gameDir);

	if (!getcwd(buf, sizeof(buf)))
	{
		Error("Unable To Find Directory.");
		return FALSE;
	}

	sprintf(GameDLL.gamedir, "%s/%s", buf, gameDir);
	strcpy(GameDLL.name, gameDir);

	return TRUE;
}