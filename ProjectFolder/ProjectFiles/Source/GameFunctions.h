#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

#include <cstdint>
#include <cstddef>
#include <random>
#include <limits>

#include <type_traits>

namespace ModAPI {

	// Unless mentioned otherwise or named "Unused", the type can exist as a block in the world. Foliage can not be spawned through the VoxelAPI.
	enum class EBlockType : uint8_t {
		Stone,				// This is naturally occuring stone, this should never exist as block items but only as blocks. After mining it becomes "StoneMined" type.
		Grass,
		Dirt,
		Air,
		BottomStone,		// The block type that the indestructible bottom layer of the world is made of
		GrassFoliage,		// This is foliage, not a block
		TreeWood,
		Unused1,
		Unused2,
		Unused3,
		Sand,
		Invalid,
		Ore_Coal,
		Ore_Iron,
		TreeRoot,			// This is not used by the game at all
		Torch,
		Flower1,			// This is foliage, not a block
		Flower2,			// This is foliage, not a block
		T_Stick,			// This is a tool, not a block
		T_PickAxe_Stone,	// This is a tool, not a block
		T_Axe_Stone,		// This is a tool, not a block
		T_Shovel_Stone,		// This is a tool, not a block
		Nugget_Copper,		// This can only exist as an item, not as a block
		Nugget_Gold,		// This can only exist as an item, not as a block
		Nugget_Coal,		// This can only exist as an item, not as a block
		Ore_Copper,			
		Ore_Gold,
		Unused4,
		T_PickAxe_Copper,	// This is a tool, not a block
		T_Axe_Copper,		// This is a tool, not a block
		T_Shovel_Copper,	// This is a tool, not a block
		Unused5,
		TreeWoodBright,
		WoodPlankBright,
		WoodPlank,
		StoneMined,			// If you ever spawn a stone item, or add stone to the inventory, it should be of this type
		Flower3,			// This is foliage, not a block
		TorchBlue,
		DyeBlue,			// This can only exist as an item, not as a block
		Flower4,			// This is foliage, not a block
		TorchGreen,
		DyeGreen,			// This can only exist as an item, not as a block
		Compass,			// This can only exist as an item in the inventory
		Chest1,				// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		SpecialBlockObject,	// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		MeshObject,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		Wallstone,
		Flagstone,
		DyeRed,				// This can only exist as an item, not as a block
		TorchRed,
		Chair1,				// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		Chair1Birch,		// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		WoodScaffolding,
		Arrow,				// This is unused
		WallmountCopper,	// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		Cactus,				// This is foliage, not a block
		DesertGrass,		// This is foliage, not a block
		FrameWood,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		FrameGold,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		FrameCopper,		// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		T_Sledgehammer_Copper,	// This is a tool, not a block
		TorchRainbow,
		DyeRainbow,				// This can only exist as an item, not as a block
		FlowerRainbow,			// This is foliage, not a block
		DyeWhite,				// This can only exist as an item, not as a block
		BigWallstone,			// Wallstone with stones twice as large
		ModBlock,			// Use this together with the UniqueID CustomBlockID
		CrystalBlock,
		Crystal,			// This can only exist as an item, not as a block
		Furnace,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		FurnaceMoldIron,	// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		FlintStone,			// This can only exist as an item, not as a block
		DryGrass,			// This can only exist as an item, not as a block
		IngotIron,			// This can only exist as an item, not as a block
		T_PickAxe_Iron,		// This is a tool, not a block
		T_Sledgehammer_Iron,	// This is a tool, not a block
		T_Axe_Iron,				// This is a tool, not a block
		T_Shovel_Iron,			// This is a tool, not a block
		WoodStool,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		WoodTable1,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		WoodTable2,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		WoodCarafe,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		WoodBench1,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		WoodBarrel,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		WoodPost,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		MetalPod,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		WoodBench2,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		WoodBench3,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		SandbagPile,		// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		GlassBlock,
		ModBlockTransparent,// This is still unused
		GlassIngot,			// This can only exist as an item, not as a block
		LootableInventory,	// This is a special type that can't be used for anything
		RespawnTorch,		
		T_Bow,				// This is a tool, not a block
		SmoothbrainStatue,	// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		ShimmerstoneBlue,
		ShimmerstoneGold,
		ShimmerstoneWhite,
		ShimmerstoneGreen,
		StarstoneBlue,
		StarstoneGold,
		StarstoneGreen,
		ShimmertileBlue,
		ShimmertileGold,
		ShimmertileWhite,
		ShimmertileGreen,
		TorchCloaked,
		TorchCloakedBlue,
		TorchCloakedGreen,
		TorchCloakedRed,
		TorchCloakedRainbow,
		Cloakstone,
		Nugget_Cloak,		// This can only exist as an item, not as a block
		ChestShelf1,		// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		Chair2,				// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		Chair2Bright,		// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		Statue1,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		Statue2,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		CouchingPlaceSimple,	// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		CouchingPlaceFancy,		// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		StonePedestal,			// This is a mesh object, not a block. Cannot be set/get through VoxelAPI.
		WaterDecorative,
		MAX_BLOCKTYPE
	};

	enum class ERotation : uint8_t
	{
		// Torches: the direction they point to. Only torches use these, every other block is placed unrotated with them.
		Right,
		Left,
		Forward,
		Backward,
		Up,
		Down,

		None,				// Not rotated

		// (5.8) Blocks that can be rotated: wood, planks, wallstone, big wallstone, flagstone, scaffolding, and custom blocks unless their
		// Properties.json says "AllowRotation": false. The 47 values after None are all the other ways a cube can be turned or mirrored
		// (23 turns, 24 mirror images); the most useful ones have names here, CombineRotations (below) makes all others. Each comment
		// says where the block's own X, Y and Z axes point to in the world. GetBlock and the block events give a rotated block's value.
		// Blocks that cannot be rotated are placed unrotated with these values (they get None), torches not at all (they need one of
		// the six directions).
		MirrorX = 7,		// X->-X Y->+Y Z->+Z	mirrored along X
		MirrorY = 8,		// X->+X Y->-Y Z->+Z	mirrored along Y
		TurnZ180 = 9,		// X->-X Y->-Y Z->+Z
		MirrorZ = 10,		// X->+X Y->+Y Z->-Z	mirrored along Z (upside down, mirrored)
		TurnY180 = 11,		// X->-X Y->+Y Z->-Z	upside down
		TurnX180 = 12,		// X->+X Y->-Y Z->-Z	upside down
		TurnX90 = 16,		// X->+X Y->+Z Z->-Y	a quarter turn about X: a log lying along Y
		TurnX270 = 18,		// X->+X Y->-Z Z->+Y
		TurnZ90 = 23,		// X->+Y Y->-X Z->+Z	a quarter turn about the vertical, clockwise seen from above
		TurnZ270 = 24,		// X->-Y Y->+X Z->+Z	a quarter turn about the vertical, counterclockwise seen from above
		TurnY270 = 47,		// X->+Z Y->+Y Z->-X
		TurnY90 = 50,		// X->-Z Y->+Y Z->+X	a quarter turn about Y: a log lying along X
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

		constexpr bool operator==(const CoordinateInCentimeters& i) const {
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

		//constexpr CoordinateInCentimeters operator-(const CoordinateInCentimeters i) const {
		//	return CoordinateInCentimeters(*this) - i;
		//}

		constexpr bool operator==(const CoordinateInBlocks& i) const {
			return (X == i.X && Y == i.Y && Z == i.Z);
		}

		std::wstring ToString() const {
			return L"X=" + std::to_wstring(X) + L" Y=" + std::to_wstring(Y) + L" Z=" + std::to_wstring(Z);
		}

		double GetLength() const {
			return sqrt(double(X * X + Y * Y + Z * Z));
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
			Value.Z = (uint16_t)lround(Z);
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
		ERotation Rotation;							// Torches: their direction. (5.8) Other blocks: their rotation, ERotation::None if not rotated
		UniqueID CustomBlockID = 0;					// Only used if the Type is EBlockType::ModBlock

		constexpr BlockInfo() : Type(EBlockType::Invalid), Rotation(ERotation::None), CustomBlockID(0) {}

		constexpr BlockInfo(EBlockType Type_) : Type(Type_), Rotation(ERotation::None), CustomBlockID(0) {}

		constexpr BlockInfo(EBlockType Type_, ERotation Rotation_) : Type(Type_), Rotation(Rotation_), CustomBlockID(0) {}

		constexpr BlockInfo(UniqueID CustomBlockID_) : Type(EBlockType::ModBlock), Rotation(ERotation::None), CustomBlockID(CustomBlockID_) {}

		constexpr BlockInfo(UniqueID CustomBlockID_, ERotation Rotation_) : Type(EBlockType::ModBlock), Rotation(Rotation_), CustomBlockID(CustomBlockID_) {}

		constexpr BlockInfo(EBlockType Type_, ERotation Rotation_, UniqueID CustomBlockID_) : Type(Type_), Rotation(Rotation_), CustomBlockID(CustomBlockID_) {}

		bool IsValid() {
			return Type != EBlockType::Invalid;
		}
	};
	static_assert(std::is_standard_layout<BlockInfo>());
	// Mods built against older headers read and write BlockInfo with this same layout
	static_assert(sizeof(BlockInfo) == 8 && offsetof(BlockInfo, Rotation) == 1 && offsetof(BlockInfo, CustomBlockID) == 4, "the mod API's BlockInfo layout");

	// (5.8) Block rotations (ERotation::None and the 47 values after it; torch directions count as None). Each one is a signed
	// permutation matrix M that turns the block's own axes into world axes (world = M * local): GetRotationIndex(Rotation) is
	// PermutationIndex * 8 + SignBits, where row i of M has its nonzero entry in column RotationPermutations[PermutationIndex][i],
	// negative if bit i of SignBits is set.
	inline constexpr uint8_t RotationPermutations[6][3] = { { 0, 1, 2 }, { 0, 2, 1 }, { 1, 0, 2 }, { 1, 2, 0 }, { 2, 0, 1 }, { 2, 1, 0 } };

	// Whether Rotation is None or one of the 47 rotations of blocks, not a torch direction
	constexpr bool IsBlockRotation(ERotation Rotation)
	{
		return uint8_t(Rotation) >= uint8_t(ERotation::None) && uint8_t(Rotation) < uint8_t(ERotation::None) + 48;
	}

	// 0 (None) to 47, 0 for torch directions
	constexpr uint8_t GetRotationIndex(ERotation Rotation)
	{
		return IsBlockRotation(Rotation) ? uint8_t(uint8_t(Rotation) - uint8_t(ERotation::None)) : 0;
	}

	// The rotation of an index 0 to 47
	constexpr ERotation GetRotationFromIndex(uint8_t Index)
	{
		return ERotation(uint8_t(uint8_t(ERotation::None) + Index));
	}

	// A block rotated by First and then by Then. Example: CombineRotations(ERotation::TurnX90, ERotation::TurnZ90) is a log lying along
	// Y (TurnX90) turned a quarter about the vertical, so it lies along X.
	constexpr ERotation CombineRotations(ERotation First, ERotation Then)
	{
		const uint8_t A = GetRotationIndex(Then);
		const uint8_t B = GetRotationIndex(First);
		const uint8_t* PA = RotationPermutations[A / 8];
		const uint8_t* PB = RotationPermutations[B / 8];
		uint8_t P[3] = {};
		uint8_t Signs = 0;
		for (int I = 0; I < 3; ++I) {
			P[I] = PB[PA[I]];
			Signs |= uint8_t((((A >> I) ^ (B >> PA[I])) & 1) << I);
		}
		uint8_t PermutationIndex = 0;
		while (RotationPermutations[PermutationIndex][0] != P[0] || RotationPermutations[PermutationIndex][1] != P[1]) {
			++PermutationIndex;
		}
		return GetRotationFromIndex(uint8_t(PermutationIndex * 8 + Signs));
	}

	// The rotation that undoes Rotation: CombineRotations(Rotation, InverseRotation(Rotation)) is ERotation::None
	constexpr ERotation InverseRotation(ERotation Rotation)
	{
		const uint8_t A = GetRotationIndex(Rotation);
		const uint8_t* PA = RotationPermutations[A / 8];
		uint8_t P[3] = {};
		uint8_t Signs = 0;
		for (int I = 0; I < 3; ++I) {
			P[PA[I]] = uint8_t(I);
			Signs |= uint8_t(((A >> I) & 1) << PA[I]);
		}
		uint8_t PermutationIndex = 0;
		while (RotationPermutations[PermutationIndex][0] != P[0] || RotationPermutations[PermutationIndex][1] != P[1]) {
			++PermutationIndex;
		}
		return GetRotationFromIndex(uint8_t(PermutationIndex * 8 + Signs));
	}

	// Whether Rotation mirrors the block (MirrorX, MirrorY, MirrorZ and every combination of one of them with turns)
	constexpr bool IsMirrorRotation(ERotation Rotation)
	{
		const uint8_t A = GetRotationIndex(Rotation);
		const bool OddPermutation = A / 8 == 1 || A / 8 == 2 || A / 8 == 5;
		const bool OddSigns = (((A >> 0) ^ (A >> 1) ^ (A >> 2)) & 1) != 0;
		return OddPermutation != OddSigns;
	}

	// Where the offset Offset (from a block) goes when it is turned by Rotation along with that block. To build a whole structure
	// turned, set each of its blocks at Origin + RotateOffset(Turn, Offset) with the rotation CombineRotations(its own rotation, Turn).
	// RotateOffset(Rotation, CoordinateInBlocks(0, 0, 1)) is the direction the top of a block with that rotation faces.
	constexpr CoordinateInBlocks RotateOffset(ERotation Rotation, CoordinateInBlocks Offset)
	{
		const uint8_t A = GetRotationIndex(Rotation);
		const uint8_t* PA = RotationPermutations[A / 8];
		const int64_t Local[3] = { Offset.X, Offset.Y, Offset.Z };
		int64_t World[3] = {};
		for (int I = 0; I < 3; ++I) {
			World[I] = ((A >> I) & 1) ? -Local[PA[I]] : Local[PA[I]];
		}
		return CoordinateInBlocks(World[0], World[1], int16_t(World[2]));
	}

	struct BlockInfoWithLocation
	{
		BlockInfo Info;
		CoordinateInCentimeters Location;
	};
	static_assert(std::is_standard_layout<BlockInfoWithLocation>());

	typedef void (*Log_T)(const wchar_t* String);

	typedef BlockInfo(*GetBlock_T)(const ModAPI::CoordinateInBlocks& At);
	typedef bool (*SetBlock_T)(const ModAPI::CoordinateInBlocks& At, const ModAPI::BlockInfo& BlockType, ModAPI::BlockInfo& OutReplacedType);

	typedef void (*SpawnHintText_T)(const ModAPI::CoordinateInCentimeters& At, const wchar_t* Text, float DurationInSeconds, float SizeMultiplier, float SizeMultiplierVertical);
	typedef void* (*SpawnHintTextAdvanced_T)(const ModAPI::CoordinateInCentimeters& At, const wchar_t* Text, float DurationInSeconds, float SizeMultiplier, float SizeMultiplierVertical, float FontSizeMultiplier);

	typedef void (*DestroyHintText_T)(void*& Handle);

	typedef ModAPI::CoordinateInCentimeters(*GetPlayerLocation_T)();
	typedef bool (*SetPlayerLocation_T)(const ModAPI::CoordinateInCentimeters& To);

	typedef ModAPI::CoordinateInCentimeters(*GetPlayerLocationHead_T)();

	typedef ModAPI::DirectionVectorInCentimeters(*GetPlayerViewDirection_T)();
	typedef void (*SetPlayerViewDirection_T)(const ModAPI::DirectionVectorInCentimeters& To);

	typedef ModAPI::CoordinateInCentimeters(*GetHandLocation_T)(bool LeftHand);

	typedef ModAPI::CoordinateInCentimeters(*GetIndexFingerTipLocation_T)(bool LeftHand);

	typedef void (*SpawnBlockItem_T)(const ModAPI::CoordinateInCentimeters& At, const ModAPI::BlockInfo& Type);
	typedef ModAPI::BlockInfoWithLocation* (*ConsumeBlockItems_T)(const ModAPI::CoordinateInCentimeters& At, ModAPI::BlockInfo* TypeArrayIn, uint32_t TypeArrayInSize, int32_t RadiusInCentimeters, ModAPI::CoordinateInCentimeters BoxExtentInCentimeters, int32_t Amount, bool bOnlyTry, uint32_t* ArraySizeOut);

	typedef void (*AddToInventory_T)(const ModAPI::BlockInfo& Type, uint32_t Amount);
	typedef void (*RemoveFromInventory_T)(const ModAPI::BlockInfo& Type, uint32_t Amount);

	typedef const wchar_t* (*GetWorldName_T)();
	typedef uint32_t(*GetWorldSeed_T)();

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
	typedef ModAPI::GameVersion(*GetGameVersionNumber_T) ();

	typedef SharedMemoryHandleC(*GetSharedMemoryPointer_T)(const wchar_t* Key, bool CreateIfNotExist, bool WaitUntilExist);
	typedef void (*ReleaseSharedMemoryPointer_T)(ModAPI::SharedMemoryHandleC& Handle);

	typedef void (*DeleteAllTreesInArea_T)(const ModAPI::CoordinateInBlocks& At, const ModAPI::CoordinateInBlocks& BoxExtent);


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
		InternalFunction(SetPlayerViewDirection);
		InternalFunction(GetHandLocation);
		InternalFunction(GetIndexFingerTipLocation);

		InternalFunction(SpawnBlockItem);
		InternalFunction(ConsumeBlockItems);

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

		InternalFunction(DeleteAllTreesInArea);

	}

}
