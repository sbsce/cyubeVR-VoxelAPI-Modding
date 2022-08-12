#pragma once

#include "GameFunctions.h"

template<class T>
constexpr auto absolute(T const& x) {
	return x < 0 ? -x : x;
}

constexpr static __forceinline uint64_t rotl(const uint64_t x, int k) {
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