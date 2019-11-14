#ifndef Common_h
#define Common_h

extern enginefuncs_t gEngine;
extern gamedll_t GameDLL;

#define reset(a) memset(&a, 0, sizeof(a))
#define compare(a, b) strcmp(a, b)

#define hlsdkExport __stdcall
#define DLLEXPORT __declspec(dllexport)
#define ExportC extern "C" DLLEXPORT
#endif