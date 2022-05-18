#include "Internals.h"

#include "Mod.cpp"

#include "GameAPI.cpp"

void Internals::Init()
{
	std::cout << "Loaded!" << std::endl;

	app = GetModuleHandle(nullptr);

	if (!app) {
		__debugbreak();
	}

	InternalFunctions::I_Log = (Log_T) GetProcAddress(app, "Log");

	InternalFunctions::I_GetBlock = (GetBlock_T) GetProcAddress(app, "GetBlock");

	InternalFunctions::I_SetBlock = (SetBlock_T) GetProcAddress(app, "SetBlock");

	InternalFunctions::I_SpawnHintText = (SpawnHintText_T) GetProcAddress(app, "SpawnHintText");

	InternalFunctions::I_GetPlayerLocation = (GetPlayerLocation_T) GetProcAddress(app, "GetPlayerLocation");

	InternalFunctions::I_SetPlayerLocation = (SetPlayerLocation_T) GetProcAddress(app, "SetPlayerLocation");

	InternalFunctions::I_GetPlayerLocationHead = (GetPlayerLocationHead_T)GetProcAddress(app, "GetPlayerLocationHead");

	InternalFunctions::I_GetPlayerViewDirection = (GetPlayerViewDirection_T) GetProcAddress(app, "GetPlayerViewDirection");

	InternalFunctions::I_GetHandLocation = (GetHandLocation_T) GetProcAddress(app, "GetHandLocation");
	InternalFunctions::I_GetIndexFingerTipLocation = (GetIndexFingerTipLocation_T) GetProcAddress(app, "GetIndexFingerTipLocation");

	InternalFunctions::I_SpawnBlockItem = (SpawnBlockItem_T) GetProcAddress(app, "SpawnBlockItem");

	InternalFunctions::I_AddToInventory = (AddToInventory_T) GetProcAddress(app, "AddToInventory");
	InternalFunctions::I_RemoveFromInventory = (RemoveFromInventory_T) GetProcAddress(app, "RemoveFromInventory");

	InternalFunctions::I_GetWorldName = (GetWorldName_T) GetProcAddress(app, "GetWorldName");

	InternalFunctions::I_GetTimeOfDay = (GetTimeOfDay_T) GetProcAddress(app, "GetTimeOfDay");

	InternalFunctions::I_SetTimeOfDay = (SetTimeOfDay_T) GetProcAddress(app, "SetTimeOfDay");


	InternalFunctions::I_PlayHapticFeedbackOnHand = (PlayHapticFeedbackOnHand_T) GetProcAddress(app, "PlayHapticFeedbackOnHand");

	InternalFunctions::I_SpawnBPModActor = (SpawnBPModActor_T) GetProcAddress(app, "SpawnBPModActor");


	std::string ErrorString = GetLastErrorAsString();

	if (!InternalFunctions::I_Log) __debugbreak();

	Event_OnLoad();
}

const char* Internals::GetName()
{
	return "DefaultName";
}

const uint32_t Internals::GetModUniqueIDsNum()
{
	return sizeof(ThisModUniqueIDs) / sizeof(*ThisModUniqueIDs);
}

const void Internals::GetModUniqueIDs(UniqueID* ArrayIn)
{
	memcpy(ArrayIn, ThisModUniqueIDs, sizeof(ThisModUniqueIDs));
}

const float Internals::GetTickRate()
{
	return TickRate;
}

const void Internals::E_Event_BlockPlaced(const CoordinateInBlocks& At, const UniqueID& CustomBlockID, const bool& Moved)
{
	Event_BlockPlaced(At, CustomBlockID, Moved);
}

const void Internals::E_Event_BlockDestroyed(const CoordinateInBlocks& At, const UniqueID& CustomBlockID, const bool& Moved)
{
	Event_BlockDestroyed(At, CustomBlockID, Moved);
}

const void Internals::E_Event_BlockHitByTool(const CoordinateInBlocks& At, const UniqueID& CustomBlockID, const wchar_t* ToolName)
{	
	Event_BlockHitByTool(At, CustomBlockID, ToolName);
}

const void Internals::E_Event_Tick()
{
	Event_Tick();
}

const void Internals::E_Event_OnLoad()
{
	Event_OnLoad();
}

const void Internals::E_Event_OnExit()
{
	Event_OnExit();
}

const void Internals::E_Event_AnyBlockPlaced(const CoordinateInBlocks& At, const BlockInfoC& Type, const bool& Moved)
{
	Event_AnyBlockPlaced(At, *((BlockInfo*)&Type), Moved);
}

const void Internals::E_Event_AnyBlockDestroyed(const CoordinateInBlocks& At, const BlockInfoC& Type, const bool& Moved)
{
	Event_AnyBlockDestroyed(At, *((BlockInfo*)&Type), Moved);
}

const void Internals::E_Event_AnyBlockHitByTool(const CoordinateInBlocks& At, const BlockInfoC& Type, const wchar_t* ToolName)
{
	Event_AnyBlockHitByTool(At, *((BlockInfo*)&Type), ToolName);
}
