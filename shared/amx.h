#ifndef AMX_H
#define AMX_H

#define NativeCall
#define ArraySize(array) (sizeof(array) / sizeof((array)[0]))
#define Callback __cdecl

#define UserNum     4

struct AMX;
typedef int (NativeCall* AMX_Native)(struct AMX* amx, int* params);
typedef int (Callback* AMX_NativeFilter)(struct AMX* amx, int index);
typedef int (Callback* AMX_Callback)(struct AMX* amx, int index, int* result, int* params);
typedef int (Callback* AMX_Debug)(struct AMX* amx);

typedef struct AMX
{
	unsigned char* base;
	unsigned char* data;
	AMX_Callback callback;
	AMX_Debug debug;
	int cip;
	int frm;
	int hea;
	int hlw;
	int stk;
	int flags;

	void* usertags[UserNum];

	void* userdata[UserNum];

	int error;

	int paramcount;

	int pri;
	int alt;
	int reset_stk;
	int reset_hea;
	int sysreq;

	int relocSize;
	long codeSize;
} AMX;

typedef struct AMXHeader
{
	int size;
	unsigned short magic;
	char fileVer;
	char amxVer;
};
#endif