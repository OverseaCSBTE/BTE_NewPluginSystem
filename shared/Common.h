#ifndef Common_h
#define Common_h

extern enginefuncs_t gEngine;
extern gamedll_t GameDLL;

#define reset(a) memset(&a, 0, sizeof(a))

#define ExportC extern "C" __declspec(dllexport)

#define ServerPrint (*gEngine.pfnServerPrint)
#define GetGameDir (*gEngine.pfnGetGameDir)

#endif