#include "GameAPI.h"

#include <cstdint>
#include <random>
#include <limits>
#include <filesystem>

void Log(const wString& String)
{
	InternalFunctions::I_Log(String.c_str());
}

BlockInfo GetBlock(CoordinateInBlocks At)
{
	return InternalFunctions::I_GetBlock(At);
}

bool SetBlock(CoordinateInBlocks At, BlockInfo BlockType)
{
	BlockInfo BlockTypeOut;
	return InternalFunctions::I_SetBlock(At, BlockType, BlockTypeOut);
}

BlockInfo GetAndSetBlock(CoordinateInBlocks At, BlockInfo BlockType)
{
	BlockInfo BlockTypeOut;
	InternalFunctions::I_SetBlock(At, BlockType, BlockTypeOut);
	return BlockTypeOut;
}

void SpawnHintText(CoordinateInCentimeters At, const wString& Text, float DurationInSeconds, float SizeMultiplier, float SizeMultiplierVertical)
{
	return InternalFunctions::I_SpawnHintText(At, Text.c_str(), DurationInSeconds, SizeMultiplier, SizeMultiplierVertical);
}

void* SpawnHintTextAdvanced(CoordinateInCentimeters At, const wString& Text, float DurationInSeconds, float SizeMultiplier, float SizeMultiplierVertical, float FontSizeMultiplier)
{
	return InternalFunctions::I_SpawnHintTextAdvanced(At, Text.c_str(), DurationInSeconds, SizeMultiplier, SizeMultiplierVertical, FontSizeMultiplier);
}

void DestroyHintText(void*& Handle)
{
	return InternalFunctions::I_DestroyHintText(Handle);
}

bool SetBlock(CoordinateInBlocks At, EBlockType NativeType)
{
	return SetBlock(At, BlockInfo(NativeType));
}

bool SetBlock(CoordinateInBlocks At, EBlockType NativeType, ERotation Rotation)
{
	return SetBlock(At, BlockInfo(NativeType, Rotation));
}

bool SetBlock(CoordinateInBlocks At, UniqueID CustomBlockID)
{
	return SetBlock(At, BlockInfo(CustomBlockID));
}


CoordinateInCentimeters GetPlayerLocation()
{
	return InternalFunctions::I_GetPlayerLocation();
}

bool SetPlayerLocation(CoordinateInCentimeters To)
{
	return InternalFunctions::I_SetPlayerLocation(To);
}

CoordinateInCentimeters GetPlayerLocationHead()
{
	return InternalFunctions::I_GetPlayerLocationHead();
}

DirectionVectorInCentimeters GetPlayerViewDirection()
{
	return InternalFunctions::I_GetPlayerViewDirection();
}

CoordinateInCentimeters GetHandLocation(bool LeftHand)
{
	return InternalFunctions::I_GetHandLocation(LeftHand);
}

CoordinateInCentimeters GetIndexFingerTipLocation(bool LeftHand)
{
	return InternalFunctions::I_GetIndexFingerTipLocation(LeftHand);
}

void SpawnBlockItem(CoordinateInCentimeters At, BlockInfo Type)
{
	return InternalFunctions::I_SpawnBlockItem(At, Type);
}

void AddToInventory(BlockInfo Type, int Amount)
{
	return InternalFunctions::I_AddToInventory(Type, Amount);
}

void RemoveFromInventory(BlockInfo Type, int Amount)
{
	return InternalFunctions::I_RemoveFromInventory(Type, Amount);
}

wString GetWorldName()
{
	return wString(InternalFunctions::I_GetWorldName());
}

uint32_t GetWorldSeed()
{
	return InternalFunctions::I_GetWorldSeed();
}

float GetTimeOfDay()
{
	return InternalFunctions::I_GetTimeOfDay();
}

void SetTimeOfDay(float NewTime)
{
	return InternalFunctions::I_SetTimeOfDay(NewTime);
}

bool IsCurrentlyNight()
{
	float Time = GetTimeOfDay();
	return (Time < 600 || Time > 1800);
}

void PlayHapticFeedbackOnHand(bool LeftHand, float DurationSeconds, float Frequency, float Amplitude)
{
	return InternalFunctions::I_PlayHapticFeedbackOnHand(LeftHand, DurationSeconds, Frequency, Amplitude);
}

float GetPlayerHealth()
{
	return InternalFunctions::I_GetPlayerHealth();
}

float SetPlayerHealth(float NewHealth, bool Offset)
{
	return InternalFunctions::I_SetPlayerHealth(NewHealth, Offset);
}

std::vector<BlockInfoWithLocation> ConsumeBlockItems(CoordinateInCentimeters At, std::vector<BlockInfo> Type, int RadiusInCentimeters, CoordinateInCentimeters BoxExtentInCentimeters, int Amount, bool bOnlyTry)
{
	uint32_t ArraySizeOut;
	BlockInfoWithLocation* ReturnArray = InternalFunctions::I_ConsumeBlockItems(At, Type.data(), (uint32_t) Type.size(), RadiusInCentimeters, BoxExtentInCentimeters, Amount, bOnlyTry, &ArraySizeOut);

	auto ret = std::vector<BlockInfoWithLocation>(ReturnArray, ReturnArray + ArraySizeOut);

	HeapFree(GetProcessHeap(), 0, ReturnArray);

	return ret;
}

void SpawnBPModActor(CoordinateInCentimeters At, const wString& ModName, const wString& ActorName)
{
	return InternalFunctions::I_SpawnBPModActor(At, ModName.c_str(), ActorName.c_str());
}

void SaveModDataString(wString ModName, wString StringIn)
{
	return InternalFunctions::I_SaveModDataString(ModName.c_str(), StringIn.c_str());
}

bool LoadModDataString(wString ModName, wString& StringOut)
{
	wchar_t* StringOutT;

	bool success = InternalFunctions::I_LoadModDataString(ModName.c_str(), StringOutT);

	if (!success) return false;

	StringOut = std::wstring(StringOutT);

	HeapFree(GetProcessHeap(), 0, StringOutT);

	return true;
}

void SaveModData(wString ModName, const std::vector<uint8_t>& Data)
{
	return InternalFunctions::I_SaveModData(ModName.c_str(), (uint8_t*) Data.data(), Data.size());
}

std::vector<uint8_t> LoadModData(wString ModName)
{
	uint64_t ArraySize;
	uint8_t* Data = InternalFunctions::I_LoadModData(ModName.c_str(), &ArraySize);

	std::vector<uint8_t> DataOut(ArraySize);
	
	memcpy(&DataOut[0], Data, ArraySize);

	HeapFree(GetProcessHeap(), 0, Data);

	return DataOut;
}


/*******************************************************
	Useful functions
*******************************************************/


std::vector<CoordinateInBlocks> GetAllCoordinatesInBox(CoordinateInBlocks At, CoordinateInBlocks BoxExtent)
{
	std::vector<CoordinateInBlocks> ReturnCoordinates;
	
	for (int64_t x = -BoxExtent.X; x < BoxExtent.X; x++) {
		for (int64_t y = -BoxExtent.Y; y < BoxExtent.Y; y++) {
			for (int16_t z = -BoxExtent.Z; z < BoxExtent.Z; z++) {

				CoordinateInBlocks Offset = CoordinateInBlocks(x, y, z);

				if ( ((int32_t(At.Z) + int32_t(Offset.Z)) >= 0) && ((int32_t(At.Z) + int32_t(Offset.Z)) <= 800)) {
					ReturnCoordinates.push_back(At + Offset);				
				}
			}
		}
	}

	return ReturnCoordinates;
}

std::vector<CoordinateInBlocks> GetAllCoordinatesInRadius(CoordinateInBlocks At, int32_t Radius)
{
	std::vector<CoordinateInBlocks> ReturnCoordinates;

	for (int64_t x = -Radius; x < Radius; x++) {
		for (int64_t y = -Radius; y < Radius; y++) {
			for (int16_t z = -Radius; z < Radius; z++) {

				CoordinateInBlocks Offset = CoordinateInBlocks(x, y, z);

				if (((int32_t(At.Z) + int32_t(Offset.Z)) >= 0) && ((int32_t(At.Z) + int32_t(Offset.Z)) <= 800)) {
					if (Offset.GetLength() <= Radius) {
						ReturnCoordinates.push_back(At + Offset);
					}
				}
			}
		}
	}

	return ReturnCoordinates;
}



#pragma warning(disable:6386)
wString GetThisModInstallFolderPathInternal()
{
	wchar_t path[MAX_PATH];
	HMODULE hm = NULL;

	if (GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
		GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
		(LPCWSTR)&GetAllCoordinatesInRadius, &hm) == 0)
	{
		return std::wstring(L"Error");
	}
	if (GetModuleFileNameW(hm, path, sizeof(path)) == 0)
	{
		return std::wstring(L"Error");
	}

	std::wstring StringToReturn = std::wstring(path);
	StringToReturn = StringToReturn.substr(0, StringToReturn.find_last_of(L"\\/"));

	StringToReturn += L"\\";

	return StringToReturn;
}
#pragma warning(default:6386)

const wString& GetThisModInstallFolderPath()
{
	static const std::wstring Path = GetThisModInstallFolderPathInternal();

	return Path;
}

wString GetThisModSaveFolderPath(wString ModName)
{
	wchar_t StringOut[1000];
	InternalFunctions::I_GetThisModSaveFolderPath(ModName.c_str(), StringOut);

	std::filesystem::create_directories(wString(StringOut));

	return wString(StringOut);
}

wString GetThisModGlobalSaveFolderPath(wString ModName)
{
	wchar_t StringOut[1000];
	InternalFunctions::I_GetThisModGlobalSaveFolderPath(ModName.c_str(), StringOut);

	std::filesystem::create_directories(wString(StringOut));

	return wString(StringOut);
}

GameVersion GetGameVersionNumber()
{
	static GameVersion VersionNumber = InternalFunctions::I_GetGameVersionNumber();
	return VersionNumber;
}

ScopedSharedMemoryHandle GetSharedMemoryPointer(wString Key, bool CreateIfNotExist, bool WaitUntilExist)
{
	return ScopedSharedMemoryHandle(InternalFunctions::I_GetSharedMemoryPointer(Key.c_str(), CreateIfNotExist, WaitUntilExist));
}

ScopedSharedMemoryHandle::~ScopedSharedMemoryHandle() 
{
	if (Valid) {
		SharedMemoryHandleC HandleC;
		HandleC.Pointer = &Pointer;
		HandleC.Key = Key;
		HandleC.Valid = Valid;

		InternalFunctions::I_ReleaseSharedMemoryPointer(HandleC);
	}
}


int main() 
{

}