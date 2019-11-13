#ifndef Main_H
#define Main_h

// We Needed Files
#include <Windows.h>
#include <extdll.h>
#include <direct.h>

#include <cvardef.h>
#include <enginecallback.h>

#define MaxPathLen 512
#define MaxMsgLen 1024

// Some Custom Stuffs
#include "Resources/Version.h"
#include "shared/Structs.h"
#include "shared/Common.h"

ExportC void WINAPI GiveFnptrsToDll(enginefuncs_t *engine, globalvars_t *globals);

// From Commands
#include "shared/Commands.h"

// From LogSystem
void PrintToConsole(const char *fmt, ...);
void Error(const char *fmt, ...);

// From PreloadSystem
void PreloadSystem();

#endif