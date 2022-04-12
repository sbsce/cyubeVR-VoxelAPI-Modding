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
	*ArrayIn = *ThisModUniqueIDs;
}

const float Internals::GetTickRate()
{
	return TickRate;
}

const void Internals::E_Event_BlockPlaced(const CoordinateInBlocks& At, const UniqueID& CustomBlockID)
{
	Event_BlockPlaced(At, CustomBlockID);
}

const void Internals::E_Event_BlockDestroyed(const CoordinateInBlocks& At, const UniqueID& CustomBlockID)
{
	Event_BlockDestroyed(At, CustomBlockID);
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
