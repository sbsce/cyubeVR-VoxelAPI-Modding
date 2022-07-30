#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

#include <cstdint>
#include <random>
#include <limits>

#include <type_traits>

namespace ModAPI {

	enum class EBlockType : uint8_t {
		Stone,
		Grass,
		Dirt,
		Air,
		BottomStone,
		GrassFoliage,
		TreeWood,
		Unused1,
		Unused2,
		Unused3,
		Sand,
		Invalid,
		Ore_Coal,
		Ore_Iron,
		TreeRoot,
		Torch,
		Flower1,
		Flower2,
		T_Stick,
		T_PickAxe_Stone,
		T_Axe_Stone,
		T_Shovel_Stone,
		Nugget_Copper,
		Nugget_Gold,
		Nugget_Coal,
		Ore_Copper,
		Ore_Gold,
		Unused4,
		T_PickAxe_Copper,
		T_Axe_Copper,
		T_Shovel_Copper,
		Unused5,
		TreeWoodBright,
		WoodPlankBright,
		WoodPlank,
		StoneMined,
		Flower3,
		TorchBlue,
		DyeBlue,
		Flower4,
		TorchGreen,
		DyeGreen,
		Compass,
		Chest1,
		SpecialBlockObject,
		MeshObject,
		Wallstone,
		Flagstone,
		DyeRed,
		TorchRed,
		Chair1,
		Chair1Birch,
		WoodScaffolding,
		Arrow,
		WallmountCopper,
		Cactus,
		DesertGrass,
		FrameWood,
		FrameGold,
		FrameCopper,
		T_Sledgehammer_Copper,
		TorchRainbow,
		DyeRainbow,
		FlowerRainbow,
		DyeWhite,
		Unused6,
		ModBlock,
		CrystalBlock,
		Crystal,
		Furnace,
		FurnaceMoldIron,
		FlintStone,
		DryGrass,
		IngotIron,
		T_PickAxe_Iron,
		T_Sledgehammer_Iron,
		T_Axe_Iron,
		T_Shovel_Iron,
		WoodStool,
		WoodTable1,
		WoodTable2,
		WoodCarafe,
		WoodBench1,
		WoodBarrel,
		WoodPost,
		MetalPod,
		WoodBench2,
		WoodBench3,
		SandbagPile,
		GlassBlock,
		ModBlockTransparent,
		GlassIngot,
		LootableInventory,
		RespawnTorch,
		T_Bow,
		SmoothbrainStatue,
		MAX_BLOCKTYPE
	};

	enum class ERotation : uint8_t
	{
		Right,
		Left,
		Forward,
		Backward,
		Up,
		Down,

		None
	};

	struct GameVersion {
		uint32_t MajorVersion;
		uint32_t MinorVersion;
		bool IsBetaBuild;
	};

	struct SharedMemoryHandleC {
		void** Pointer;
		wchar_t* Key;
		bool Valid;
	};

	struct ScopedSharedMemoryHandle {
		void*& Pointer;
		wchar_t* Key;
		bool Valid;

		ScopedSharedMemoryHandle(const SharedMemoryHandleC& i) : Pointer(*i.Pointer), Key(i.Key), Valid(i.Valid) {}			

		~ScopedSharedMemoryHandle(); // Declared here, defined in GameAPI.cpp

		ScopedSharedMemoryHandle(ScopedSharedMemoryHandle&&) = delete;
		ScopedSharedMemoryHandle(const ScopedSharedMemoryHandle& i) = delete;
		ScopedSharedMemoryHandle& operator=(const ScopedSharedMemoryHandle& i) = delete;
	};

	struct CoordinateInCentimeters;
	struct CoordinateInBlocks;
	struct DirectionVectorInCentimeters;

	struct CoordinateInCentimeters {

		int64_t X;
		int64_t Y;
		uint16_t Z;

		constexpr CoordinateInCentimeters operator+(const CoordinateInCentimeters i) const {
			return CoordinateInCentimeters(X + i.X, Y + i.Y, Z + i.Z);
		}

		constexpr CoordinateInCentimeters operator-(const CoordinateInCentimeters i) const {
			return CoordinateInCentimeters(X - i.X, Y - i.Y, Z - i.Z);
		}

		constexpr bool operator==(const CoordinateInCentimeters i) const {
			return (X == i.X && Y == i.Y && Z == i.Z);
		}

		std::wstring ToString() const {
			return L"X=" + std::to_wstring(X) + L" Y=" + std::to_wstring(Y) + L" Z=" + std::to_wstring(Z);
		}

		std::wstring ToStringMeters() const {
			return L"X=" + std::to_wstring(X/100) + L" Y=" + std::to_wstring(Y/100) + L" Z=" + std::to_wstring(Z/100);
		}

		constexpr CoordinateInCentimeters() = default;
		constexpr CoordinateInCentimeters(int64_t X_, int64_t Y_, uint16_t Z_) : X(X_), Y(Y_), Z(Z_) {}
		constexpr CoordinateInCentimeters(CoordinateInBlocks CIB);

	};
	static_assert(std::is_standard_layout<CoordinateInCentimeters>());
	static_assert(std::is_trivial<CoordinateInCentimeters>());

	struct CoordinateInBlocks {

		int64_t X;
		int64_t Y;
		int16_t Z;

		constexpr CoordinateInBlocks operator+(const CoordinateInBlocks i) const {
			return CoordinateInBlocks(X + i.X, Y + i.Y, Z + i.Z);
		}

		constexpr CoordinateInBlocks operator-(const CoordinateInBlocks i) const {
			return CoordinateInBlocks(X - i.X, Y - i.Y, Z - i.Z);
		}

		constexpr CoordinateInCentimeters operator+(const CoordinateInCentimeters i) const {
			return CoordinateInCentimeters(*this) + i;
		}

		constexpr CoordinateInCentimeters operator-(const CoordinateInCentimeters i) const {
			return CoordinateInCentimeters(*this) - i;
		}

		constexpr bool operator==(const CoordinateInBlocks i) const {
			return (X == i.X && Y == i.Y && Z == i.Z);
		}

		std::wstring ToString() const {
			return L"X=" + std::to_wstring(X) + L" Y=" + std::to_wstring(Y) + L" Z=" + std::to_wstring(Z);
		}

		double GetLength() const {
			return sqrt(X * X + Y * Y + Z * Z);
		}

		constexpr CoordinateInBlocks() = default;
		constexpr CoordinateInBlocks(int64_t X_, int64_t Y_, int16_t Z_) : X(X_), Y(Y_), Z(Z_) {}

		constexpr CoordinateInBlocks(CoordinateInCentimeters CIM);

	};
	static_assert(std::is_standard_layout<CoordinateInBlocks>());
	static_assert(std::is_trivial<CoordinateInBlocks>());

	struct DirectionVectorInCentimeters {

		float X;
		float Y;
		float Z;

		constexpr DirectionVectorInCentimeters operator+(const DirectionVectorInCentimeters i) const {
			return DirectionVectorInCentimeters(X + i.X, Y + i.Y, Z + i.Z);
		}

		constexpr DirectionVectorInCentimeters operator-(const DirectionVectorInCentimeters i) const {
			return DirectionVectorInCentimeters(X - i.X, Y - i.Y, Z - i.Z);
		}

		constexpr DirectionVectorInCentimeters operator*(const float Multiplier) const {
			return DirectionVectorInCentimeters(X * Multiplier, Y * Multiplier, Z * Multiplier);
		}

		constexpr DirectionVectorInCentimeters operator*(const DirectionVectorInCentimeters i) const {
			return DirectionVectorInCentimeters(X * i.X, Y * i.Y, Z * i.Z);
		}

		constexpr DirectionVectorInCentimeters operator/(const float Multiplier) const {
			return DirectionVectorInCentimeters(X / Multiplier, Y / Multiplier, Z / Multiplier);
		}

		constexpr DirectionVectorInCentimeters operator/(const DirectionVectorInCentimeters i) const {
			return DirectionVectorInCentimeters(X / i.X, Y / i.Y, Z / i.Z);
		}

		std::wstring ToString() const {
			return L"X=" + std::to_wstring(X) + L" Y=" + std::to_wstring(Y) + L" Z=" + std::to_wstring(Z);
		}

		operator CoordinateInCentimeters()
		{
			CoordinateInCentimeters Value;
			Value.X = lround(X);
			Value.Y = lround(Y);
			Value.Z = (uint16_t) lround(Z);
			return Value;
		}

		constexpr DirectionVectorInCentimeters() = default;
		constexpr DirectionVectorInCentimeters(float X_, float Y_, float Z_) : X(X_), Y(Y_), Z(Z_) {}

	};
	static_assert(std::is_standard_layout<DirectionVectorInCentimeters>());
	static_assert(std::is_trivial<DirectionVectorInCentimeters>());

	constexpr int64_t round_custom(double x)
	{
		if (x < 0.0)
			return (int64_t)(x - 0.5);
		else
			return (int64_t)(x + 0.5);
	}

	constexpr CoordinateInCentimeters::CoordinateInCentimeters(const CoordinateInBlocks CIB) : X(CIB.X * 50), Y(CIB.Y * 50), Z(CIB.Z * 50) {};

	constexpr CoordinateInBlocks::CoordinateInBlocks(const CoordinateInCentimeters CIM) : X(round_custom(double(CIM.X) / 50)), Y(round_custom(double(CIM.Y) / 50)), Z(int16_t(round_custom(double(CIM.Z) / 50))) {};


	typedef uint32_t UniqueID;

	struct BlockInfo 
	{

		EBlockType Type = EBlockType::Invalid;
		ERotation Rotation;							// Only used for torches
		UniqueID CustomBlockID = 0;					// Only used if the Type is EBlockType::ModBlock

		constexpr BlockInfo() : Type(EBlockType::Invalid), Rotation(ERotation::None), CustomBlockID(0) {}

		constexpr BlockInfo(EBlockType Type_) : Type(Type_), Rotation(ERotation::None), CustomBlockID(0) {}

		constexpr BlockInfo(EBlockType Type_, ERotation Rotation_) : Type(Type_), Rotation(Rotation_), CustomBlockID(0) {}

		constexpr BlockInfo(UniqueID CustomBlockID_) : Type(EBlockType::ModBlock), Rotation(ERotation::None), CustomBlockID(CustomBlockID_) {}

		constexpr BlockInfo(EBlockType Type_, ERotation Rotation_, UniqueID CustomBlockID_) : Type(Type_), Rotation(Rotation_), CustomBlockID(CustomBlockID_) {}

		bool IsValid() {
			return Type != EBlockType::Invalid;
		}
	};
	static_assert(std::is_standard_layout<BlockInfo>());


	typedef void (*Log_T)(const wchar_t* String);

	typedef BlockInfo (*GetBlock_T)(const ModAPI::CoordinateInBlocks& At);
	typedef bool (*SetBlock_T)(const ModAPI::CoordinateInBlocks& At, const ModAPI::BlockInfo& BlockType, ModAPI::BlockInfo& OutReplacedType);

	typedef void (*SpawnHintText_T)(const ModAPI::CoordinateInCentimeters& At, const wchar_t* Text, float DurationInSeconds, float SizeMultiplier, float SizeMultiplierVertical);
	typedef void* (*SpawnHintTextAdvanced_T)(const ModAPI::CoordinateInCentimeters& At, const wchar_t* Text, float DurationInSeconds, float SizeMultiplier, float SizeMultiplierVertical, float FontSizeMultiplier);
	
	typedef void (*DestroyHintText_T)(void*& Handle);

	typedef ModAPI::CoordinateInCentimeters (*GetPlayerLocation_T)();
	typedef bool (*SetPlayerLocation_T)(const ModAPI::CoordinateInCentimeters& To);

	typedef ModAPI::CoordinateInCentimeters(*GetPlayerLocationHead_T)();

	typedef ModAPI::DirectionVectorInCentimeters (*GetPlayerViewDirection_T)();

	typedef ModAPI::CoordinateInCentimeters (*GetHandLocation_T)(bool LeftHand);

	typedef ModAPI::CoordinateInCentimeters (*GetIndexFingerTipLocation_T)(bool LeftHand);

	typedef void (*SpawnBlockItem_T)(const ModAPI::CoordinateInCentimeters& At, const ModAPI::BlockInfo& Type);

	typedef void (*AddToInventory_T)(const ModAPI::BlockInfo& Type, uint32_t Amount);
	typedef void (*RemoveFromInventory_T)(const ModAPI::BlockInfo& Type, uint32_t Amount);

	typedef const wchar_t* (*GetWorldName_T)();
	typedef uint32_t (*GetWorldSeed_T)();

	typedef float (*GetTimeOfDay_T)();
	typedef void (*SetTimeOfDay_T)(float NewTime);

	typedef void (*PlayHapticFeedbackOnHand_T)(bool LeftHand, float DurationSeconds, float Frequency, float Amplitude);

	typedef float (*GetPlayerHealth_T)();
	typedef float (*SetPlayerHealth_T)(float NewHealth, bool Offset);

	typedef void (*SpawnBPModActor_T)(const ModAPI::CoordinateInCentimeters& At, const wchar_t* ModName, const wchar_t* ActorName);

	typedef void (*SaveModDataString_T)(const wchar_t* ModName, const wchar_t* StringIn);
	typedef bool (*LoadModDataString_T)(const wchar_t* ModName, wchar_t*& StringOut);

	typedef void (*SaveModData_T)(const wchar_t* ModName, uint8_t* Data, uint64_t ArraySize);
	typedef uint8_t* (*LoadModData_T)(const wchar_t* ModName, uint64_t* ArraySizeOut);

	typedef void (*GetThisModSaveFolderPath_T) (const wchar_t* ModName, wchar_t* PathOut);
	typedef void (*GetThisModGlobalSaveFolderPath_T) (const wchar_t* ModName, wchar_t* PathOut);
	typedef ModAPI::GameVersion (*GetGameVersionNumber_T) ();

	typedef SharedMemoryHandleC (*GetSharedMemoryPointer_T)(const wchar_t* Key, bool CreateIfNotExist, bool WaitUntilExist);
	typedef void (*ReleaseSharedMemoryPointer_T)(ModAPI::SharedMemoryHandleC& Handle);


	namespace InternalFunctions {

		#define InternalFunction(FunctionName) inline FunctionName##_T I_##FunctionName

		InternalFunction(Log);

		InternalFunction(GetBlock);
		InternalFunction(SetBlock);

		InternalFunction(SpawnHintText);
		InternalFunction(SpawnHintTextAdvanced);
		InternalFunction(DestroyHintText);

		InternalFunction(GetPlayerLocation);
		InternalFunction(SetPlayerLocation);

		InternalFunction(GetPlayerLocationHead);
		InternalFunction(GetPlayerViewDirection);
		InternalFunction(GetHandLocation);
		InternalFunction(GetIndexFingerTipLocation);

		InternalFunction(SpawnBlockItem);

		InternalFunction(AddToInventory);
		InternalFunction(RemoveFromInventory);

		InternalFunction(GetWorldName);
		InternalFunction(GetWorldSeed);

		InternalFunction(GetTimeOfDay);
		InternalFunction(SetTimeOfDay);

		InternalFunction(PlayHapticFeedbackOnHand);

		InternalFunction(GetPlayerHealth);
		InternalFunction(SetPlayerHealth);

		InternalFunction(SpawnBPModActor);

		InternalFunction(SaveModDataString);
		InternalFunction(LoadModDataString);
		InternalFunction(SaveModData);
		InternalFunction(LoadModData);

		InternalFunction(GetThisModSaveFolderPath);
		InternalFunction(GetThisModGlobalSaveFolderPath);
		InternalFunction(GetGameVersionNumber);

		InternalFunction(GetSharedMemoryPointer);
		InternalFunction(ReleaseSharedMemoryPointer);

	}

}
