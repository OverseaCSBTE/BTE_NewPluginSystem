#ifndef Classes_h
#define Classes_h

// Too late realized class style is nicer than exposed function name

class Preload
{
public:
	// We Can Load Anything about our self stuffs and handle it
	void Init();
	// As Metamod.cpp Said, 1.1.1.1 Version of CS or Half-life,
	// It returns argument of game instead of path
	// As I checked on engine 3266, we are using 1.1.2.6
	// And we not fucking on old system (If we want... we change it)
	// So we just using new method on it.
	BOOL InitGameDLL();
	BOOL LoadGameDLL();
	BOOL FindGameDLL();
};

class LogSystem
{
public:
	void PrintToConsole(const char* fmt, ...);
	void Error(const char* fmt, ...);
};

class CommandsSystem
{
public:
	// While preloading done preprocess, we can register our commands and cvars :D
	void Init();
	static void Main();

public:
	void Help();	// Compare First... Make sure this at lowest
};

class Engine
{
public:
	enginefuncs_t* enginefunc;
	globalvars_t* globals;
};

#endif