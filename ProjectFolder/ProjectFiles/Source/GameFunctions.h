#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

#include <cstdint>
#include <random>
#include <limits>

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

	struct CoordinateInCentimetersC {
		int64_t X;
		int64_t Y;
		uint16_t Z;
	};

	struct DirectionVectorInCentimetersC {
		float X;
		float Y;
		float Z;
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

		operator CoordinateInCentimetersC()
		{ 
			CoordinateInCentimetersC Value;
			Value.X = X;
			Value.Y = Y;
			Value.Z = Z;
			return Value;
		}

		std::wstring ToString() const {
			return L"X=" + std::to_wstring(X) + L" Y=" + std::to_wstring(Y) + L" Z=" + std::to_wstring(Z);
		}

		constexpr CoordinateInCentimeters() : X(0), Y(0), Z(0) {}
		constexpr CoordinateInCentimeters(int64_t X_, int64_t Y_, uint16_t Z_) : X(X_), Y(Y_), Z(Z_) {}
		constexpr CoordinateInCentimeters(const CoordinateInCentimetersC C) : X(C.X), Y(C.Y), Z(C.Z) {};

		constexpr CoordinateInCentimeters(CoordinateInBlocks CIB);

	};

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

		constexpr CoordinateInBlocks() : X(0), Y(0), Z(0) {}
		constexpr CoordinateInBlocks(int64_t X_, int64_t Y_, int16_t Z_) : X(X_), Y(Y_), Z(Z_) {}

		constexpr CoordinateInBlocks(CoordinateInCentimeters CIM);

	};

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

		std::wstring ToString() const {
			return L"X=" + std::to_wstring(X) + L" Y=" + std::to_wstring(Y) + L" Z=" + std::to_wstring(Z);
		}

		operator DirectionVectorInCentimetersC()
		{
			DirectionVectorInCentimetersC Value;
			Value.X = X;
			Value.Y = Y;
			Value.Z = Z;
			return Value;
		}

		operator CoordinateInCentimeters()
		{
			CoordinateInCentimeters Value;
			Value.X = lround(X);
			Value.Y = lround(Y);
			Value.Z = (uint16_t) lround(Z);
			return Value;
		}

		constexpr DirectionVectorInCentimeters() : X(0), Y(0), Z(0) {}
		constexpr DirectionVectorInCentimeters(float X_, float Y_, float Z_) : X(X_), Y(Y_), Z(Z_) {}

	};

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

		EBlockType Type;
		ERotation Rotation;			// Only used for torches
		UniqueID CustomBlockID;		// Only used if the Type is EBlockType::ModBlock

		constexpr BlockInfo() : Type(EBlockType::Invalid), Rotation(ERotation::None), CustomBlockID(0) {}

		constexpr BlockInfo(EBlockType Type_) : Type(Type_), Rotation(ERotation::None), CustomBlockID(0) {}

		constexpr BlockInfo(EBlockType Type_, ERotation Rotation_) : Type(Type_), Rotation(Rotation_), CustomBlockID(0) {}

		constexpr BlockInfo(UniqueID CustomBlockID_) : Type(EBlockType::ModBlock), Rotation(ERotation::None), CustomBlockID(CustomBlockID_) {}

		constexpr BlockInfo(EBlockType Type_, ERotation Rotation_, UniqueID CustomBlockID_) : Type(Type_), Rotation(Rotation_), CustomBlockID(CustomBlockID_) {}

	};

	struct BlockInfoC {
		EBlockType Type;
		ERotation Rotation;
		UniqueID CustomBlockID;
	};

	typedef void (*Log_T)(const wchar_t* String);

	typedef BlockInfoC(*GetBlock_T)(CoordinateInBlocks At);

	typedef bool (*SetBlock_T)(CoordinateInBlocks At, BlockInfo BlockType);

	typedef void (*SpawnHintText_T)(ModAPI::CoordinateInCentimeters At, const wchar_t* Text, float DurationInSeconds, float SizeMultiplier, float SizeMultiplierVertical);

	typedef ModAPI::CoordinateInCentimetersC(*GetPlayerLocation_T)();

	typedef ModAPI::DirectionVectorInCentimetersC(*GetPlayerViewDirection_T)();

	typedef const wchar_t* (*GetWorldName_T)();

	namespace InternalFunctions {

		inline Log_T I_Log;

		inline GetBlock_T I_GetBlock;

		inline SetBlock_T I_SetBlock;

		inline SpawnHintText_T I_SpawnHintText;

		inline GetPlayerLocation_T I_GetPlayerLocation;

		inline GetPlayerViewDirection_T I_GetPlayerViewDirection;

		inline GetWorldName_T I_GetWorldName;

	}





}
