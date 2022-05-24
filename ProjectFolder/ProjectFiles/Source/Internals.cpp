#include "Internals.h"

#include "Mod.cpp"

#include "GameAPI.cpp"

#define RegisterFunction(Name)  InternalFunctions::I_##Name = (##Name##_T) GetProcAddress(app, #Name);		\
								if (!InternalFunctions::I_##Name) {											\
									std::string ErrorString = GetLastErrorAsString();						\
									__debugbreak();															\
								};


void Internals::Init()
{
	std::cout << "Loaded!" << std::endl;

	app = GetModuleHandle(nullptr);

	if (!app) {
		__debugbreak();
	}

	RegisterFunction(Log);

	RegisterFunction(GetBlock);
	RegisterFunction(SetBlock);

	RegisterFunction(SpawnHintText);

	RegisterFunction(GetPlayerLocation);
	RegisterFunction(SetPlayerLocation);
	RegisterFunction(GetPlayerLocationHead);
	RegisterFunction(GetPlayerViewDirection);

	RegisterFunction(GetHandLocation);
	RegisterFunction(GetIndexFingerTipLocation);

	RegisterFunction(SpawnBlockItem);

	RegisterFunction(AddToInventory);
	RegisterFunction(RemoveFromInventory);

	RegisterFunction(GetWorldName);

	RegisterFunction(GetTimeOfDay);
	RegisterFunction(SetTimeOfDay);

	RegisterFunction(PlayHapticFeedbackOnHand);

	RegisterFunction(GetPlayerHealth);
	RegisterFunction(SetPlayerHealth);

	RegisterFunction(SpawnBPModActor);

	RegisterFunction(SaveModDataString);
	RegisterFunction(LoadModDataString);
	RegisterFunction(SaveModData);
	RegisterFunction(LoadModData);

	RegisterFunction(GetThisModSaveFolderPath);

	RegisterFunction(GetGameVersionNumber);

	RegisterFunction(GetSharedMemoryPointer);
	RegisterFunction(ReleaseSharedMemoryPointer);

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
