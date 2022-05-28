#include "Internals.h"

#include "Mod.cpp"

#include "GameAPI.cpp"

#define RegisterFunction(FunctionName)  InternalFunctions::I_##FunctionName = (##FunctionName##_T) GetProcAddress(app, #FunctionName);		\
										if (!InternalFunctions::I_##FunctionName) {															\
											std::string ErrorString = GetLastErrorAsString();												\
											__debugbreak();																					\
										};


void Internals::Init()
{
	std::cout << "Loaded!" << std::endl;

	app = GetModuleHandle(nullptr);

	if (!app) {
		std::string ErrorString = GetLastErrorAsString();
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

	std::string ErrorString = GetLastErrorAsString();

	if (!InternalFunctions::I_Log) __debugbreak();

	Event_OnLoad();
}

const char* Internals::GetName()
{
	return "DefaultName";
}

const uint32_t Internals::GetAPIVersionNumber()
{
	return 1;
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

const void Internals::E_Event_BlockHitByTool(const CoordinateInBlocks& At, const UniqueID& CustomBlockID, const wchar_t* ToolName, const CoordinateInCentimeters& ExactHitLocation, bool ToolHeldByHandLeft)
{	
	Event_BlockHitByTool(At, CustomBlockID, ToolName, ExactHitLocation, ToolHeldByHandLeft);
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

const void Internals::E_Event_AnyBlockPlaced(const CoordinateInBlocks& At, const BlockInfo& Type, const bool& Moved)
{
	Event_AnyBlockPlaced(At, Type, Moved);
}

const void Internals::E_Event_AnyBlockDestroyed(const CoordinateInBlocks& At, const BlockInfo& Type, const bool& Moved)
{
	Event_AnyBlockDestroyed(At, Type, Moved);
}

const void Internals::E_Event_AnyBlockHitByTool(const CoordinateInBlocks& At, const BlockInfo& Type, const wchar_t* ToolName, const CoordinateInCentimeters& ExactHitLocation, bool ToolHeldByHandLeft)
{
	Event_AnyBlockHitByTool(At, Type, ToolName, ExactHitLocation, ToolHeldByHandLeft);
}
