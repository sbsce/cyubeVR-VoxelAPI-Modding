#include "GameAPI.h"

#include <cstdint>
#include <random>
#include <limits>

void Log(const wString& String)
{
	InternalFunctions::I_Log(String.c_str());
}

BlockInfo GetBlock(CoordinateInBlocks At)
{
	BlockInfoC Type = InternalFunctions::I_GetBlock(At);
	return *((BlockInfo*)(&Type));
}

bool SetBlock(CoordinateInBlocks At, BlockInfo BlockType)
{
	return InternalFunctions::I_SetBlock(At, BlockType);
}

void SpawnHintText(CoordinateInCentimeters At, const wString& Text, float DurationInSeconds, float SizeMultiplier, float SizeMultiplierVertical)
{
	return InternalFunctions::I_SpawnHintText(At, Text.c_str(), DurationInSeconds, SizeMultiplier, SizeMultiplierVertical);
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

DirectionVectorInCentimeters GetPlayerViewDirection()
{
	DirectionVectorInCentimetersC Type = InternalFunctions::I_GetPlayerViewDirection();
	return*((DirectionVectorInCentimeters*)(&Type));
}

wString GetWorldName()
{
	return wString(InternalFunctions::I_GetWorldName());
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

template<class T>
constexpr auto absolute(T const& x) {
	return x < 0 ? -x : x;
}

static __forceinline uint64_t rotl(const uint64_t x, int k) {
	return (x << k) | (x >> (64 - k));
}

static std::random_device rd;
static std::mt19937 rng(rd());
static uint64_t xors_s[2] = { std::uniform_int_distribution<uint64_t>(0, UINT64_MAX)(rng), std::uniform_int_distribution<uint64_t>(0, UINT64_MAX)(rng) };

__forceinline uint64_t xoroshiro128p(void) {
	const uint64_t s0 = xors_s[0];
	uint64_t s1 = xors_s[1];
	const uint64_t result = s0 + s1;

	s1 ^= s0;
	xors_s[0] = rotl(s0, 24) ^ s1 ^ (s1 << 16); // a, b
	xors_s[1] = rotl(s1, 37); // c

	return result;
}

template<uint64_t TrueOneInN>
bool GetRandomBool()
{
	static constexpr uint64_t AboveThisTrue = UINT64_MAX - (UINT64_MAX / TrueOneInN);

	return xoroshiro128p() > AboveThisTrue;
}

template<int32_t Min, int32_t Max>
int32_t GetRandomInt()
{
	static_assert(Max > Min, "Called GetRandomInt with Min larger than Max");
	static_assert(Max != INT32_MAX, "GetRandomInt Max can't be INT32_MAX. Please reduce Max by at least one");

	static constexpr uint32_t TotalSpan = int64_t(Max) - int64_t(Min);
	static constexpr uint32_t DivideBy = (UINT32_MAX / (TotalSpan + 1)) + 1;

	if constexpr (TotalSpan == UINT32_MAX) return int32_t(xoroshiro128p());
	if constexpr (Min == Max) return Min;

	return int32_t(uint32_t(xoroshiro128p()) / DivideBy) + Min;
}

int main() 
{
	
}