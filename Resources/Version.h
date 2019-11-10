#ifndef Version_H
#define Version_H

#define Author "NekoMeow"

#define VersionDword 1,0,0,0
#define VersionBase "1.0.0.0"

#if _DEBUG
#define VersionString VersionBase "-dev"
#else
#define VersionString VersionBase
#endif

#endif
