#include "shared/Main.h"

void GameDLLInit(void)
{

}

int DispatchSpawn(edict_t* pent)
{
	return 0;
}

void DispatchThink(edict_t* pent)
{

}

void DispatchUse(edict_t* pentUsed, edict_t* pentOther)
{

}

void DispatchTouch(edict_t* pentTouched, edict_t* pentOther)
{

}

void DispatchSave(edict_t* pent, SAVERESTOREDATA* pSaveData)
{

}

void DispatchBlocked(edict_t* pentBlocked, edict_t* pentOther)
{

}

void DispatchKeyValue(edict_t* pentKeyvalue, KeyValueData* pkvd)
{

}

int DispatchRestore(edict_t* pent, SAVERESTOREDATA* pSaveData, int globalEntity)
{
	return 0;
}

void DispatchObjectCollsionBox(edict_t* pent)
{

}

void SaveReadFields(SAVERESTOREDATA* pSaveData, const char* pname, void* pBaseData, TYPEDESCRIPTION* pFields, int fieldCount)
{

}

void SaveWriteFields(SAVERESTOREDATA* pSaveData, const char* pname, void* pBaseData, TYPEDESCRIPTION* pFields, int fieldCount)
{

}

static DLL_FUNCTIONS gFunctionTable =
{
	GameDLLInit,				//pfnGameInit
	DispatchSpawn,				//pfnSpawn
	DispatchThink,				//pfnThink
	DispatchUse,				//pfnUse
	DispatchTouch,				//pfnTouch
	DispatchBlocked,			//pfnBlocked
	DispatchKeyValue,			//pfnKeyValue
	DispatchSave,				//pfnSave
	DispatchRestore,			//pfnRestore
	DispatchObjectCollsionBox,	//pfnAbsBox

	SaveWriteFields,			//pfnSaveWriteFields
	SaveReadFields,				//pfnSaveReadFields
};
