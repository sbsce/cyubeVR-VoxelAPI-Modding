#pragma once
#include "GameFunctions.h"
typedef std::wstring wString;
using namespace ModAPI;

/*******************************************************
	These are all the game functions you can call in your code in Mod.cpp
	More functions will be added over time - if there is any functionality you would like to access, request it in the cyubeVR Discord (discord.gg/cyubeVR)
*******************************************************/


/*	
*	Print something to the log file of the game.
*	Note: You need to manually enable cyubeVR logging to see the log. For that, go to %localappdata%/cyubeVR/Saved/Config/WindowsNoEditor/Game.ini
*
*	and set
*	
*	OverrideDefault=1
*	TextLoggingEnabled=1
* 
*	You can then find the log files in %localappdata%/cyubeVR/Saved/Logs
* 
*	Example how you can call Log:																Log(L"Hi! This is text that will be logged");		
*/
	void Log(const wString& String);

/*
*	Returns the block at the coordinate your specify. You can call this with either a CoordinateInBlocks or a CoordinateInCentimeters.
* 
*	The coordinate needs to be in the area of chunks that is currently loaded in memory, otherwise the return value is invalid.
*	If you might call this further away from the player, call .IsValid() on the return value to check that. 
	The default radius that is loaded around the player is 300 meters (600 blocks).
*/
	BlockInfo GetBlock(CoordinateInBlocks At);

/*
*	Set the block at the specified coordinate. Examples how you can call SetBlock:
*
*	Setting the block at coordinate 0, 0, 0 to be Stone (native block):							SetBlock(CoordinateInBlocks(0, 0, 0), EBlockType::Stone);
*	Setting the block at coordinate 0, 0, 0 to be a custom block of the UniqueID 50000:			SetBlock(CoordinateInBlocks(0, 0, 0), 50000);
*
*	To delete a block, set it to the type EBlockType::Air
* 
*	The Rotation value is only necessary for torches. For all other types, you can ignore it.
*/
	bool SetBlock(CoordinateInBlocks At, EBlockType NativeType);
	bool SetBlock(CoordinateInBlocks At, EBlockType NativeType, ERotation Rotation);
	bool SetBlock(CoordinateInBlocks At, UniqueID CustomBlockID);
	bool SetBlock(CoordinateInBlocks At, BlockInfo BlockType);

/*
*	Set the block at the specified coordinate, and return the type it was before. 
*   If you need to both get and set a block, prefer this over calling both GetBlock and SetBlock directly after each other.
*/
	BlockInfo GetAndSetBlock(CoordinateInBlocks At, BlockInfo BlockType);

/*
*	Spawn a hint text popup with the specified text at the specified coordinate. Examples how you can call SpawnHintText:		
* 
*	Show a hint text saying "I am a hint text" at the coordinate At for 5 seconds:				SpawnHintText(At, L"I am a hint text", 5);	
*	A hint text with a new line:																SpawnHintText(At, L"First Line\nSecond Line", 5);
*	A hint text that prints the value of an int variable MyInt:									SpawnHintText(At, L"My number is: " + std::to_wstring(MyInt), 5);
* 
*	SpawnHintTextAdvanced returns a handle that you can use to later manually destroy the hint text using the DestroyHintText function.
*	If you use a DurationInSeconds of -1, the hint text will stay visible until you manually destroy it.
* 
*	SpawnHintTextAdvanced spawns a hint text exactly where you specify, while SpawnHintText spawns the hint text 20 cm above the location you specify.
*/
	void  SpawnHintText(CoordinateInCentimeters At, const wString& Text, float DurationInSeconds, float SizeMultiplier = 1, float SizeMultiplierVertical = 1);
	void* SpawnHintTextAdvanced(CoordinateInCentimeters At, const wString& Text, float DurationInSeconds, float SizeMultiplier = 1, float SizeMultiplierVertical = 1, float FontSizeMultiplier = 1);

	void  DestroyHintText(void*& Handle);

/*
*	Returns the current player location (feet location).
*/
	CoordinateInCentimeters GetPlayerLocation();

/*
*	Sets the player location (feet location). Be careful with this, if you set it to something far away, the only way for the player to ever get back to their base would
*	probably be to kill themselves.
*/
	bool SetPlayerLocation(CoordinateInCentimeters To);

/*
*	Returns the current player location (head location).
*/
	CoordinateInCentimeters GetPlayerLocationHead();

/*
*	Returns the current player view direction as a unit vector.
*
*	You can add a DirectionVectorInCentimeters (with arbitrary length) to a CoordinateInCentimeters to get a new CoordinateInCentimeters.
*/
	DirectionVectorInCentimeters GetPlayerViewDirection();

/*
*	Returns the current location of the hand of the player.
*/
	CoordinateInCentimeters GetHandLocation(bool LeftHand);

/*
*	Returns the current location of the tip of the index finger of the player.
*/
	CoordinateInCentimeters GetIndexFingerTipLocation(bool LeftHand);

/*
*	Spawn a block item (a small cube you can craft with etc).
*/
	void SpawnBlockItem(CoordinateInCentimeters At, BlockInfo Type);

/*
*	Add or remove one or multiple items to/from the inventory. 
*/
	void AddToInventory(BlockInfo Type, int Amount);
	void RemoveFromInventory(BlockInfo Type, int Amount);

/*
*	Get the name of the currently loaded world.
*/
	wString GetWorldName();

/*
*	Get the seed of the currently loaded world.
*/
	uint32_t GetWorldSeed();

/*
*	Get the current time of day. Returns a float between 0 and 2400. 0 and 2400 are the identical time, midnight. 1200 is mid-day.
*/
	float GetTimeOfDay();

/*
*	Set the current time of day. A float between 0 and 2400, same format as returned by GetTimeOfDay().
*/
	void SetTimeOfDay(float NewTime);

/*
*	A simple function to return if it's currently night in the world.
*/
	bool IsCurrentlyNight();

/*
*	Play haptic feedback on one of the motion controllers.
*/
	void PlayHapticFeedbackOnHand(bool LeftHand, float DurationSeconds, float Frequency, float Amplitude);

/*
*	Get, set, reduce or increase the health of the player. Player health is a float between 0 and 1. 
*	If Offset in SetPlayerHealth is set to true, the health gets reduced/increased by the amount you specify. SetPlayerHealth returns the new health. 
*/
	float GetPlayerHealth();
	float SetPlayerHealth(float NewHealth, bool Offset);

/*
*	Spawn a UE4 BP Mod Actor. This makes it possible to spawn custom particle effects, sound effects, and really anything that UE4 can spawn.
*
*	To learn how to create such a UE4 BP Actor, take a look at this playlist: https://www.youtube.com/playlist?list=PL6kr-0TUTN58n8QrQoFVq4JI-HZj4eDbY
*/
	void SpawnBPModActor(CoordinateInCentimeters At, const wString& ModName, const wString& ActorName);

/*
*	USe SaveModDataString to save a persistent string to the save files of the currently active world, that you can later load using LoadModDataString.
*/
	void SaveModDataString(wString ModName, wString StringIn);
	bool LoadModDataString(wString ModName, wString& StringOut);

/*
*	Use SaveModData to save persistent binary data to the save files of the currently active world, that you can later load using LoadModData.
*/
	void SaveModData(wString ModName, const std::vector<uint8_t>& Data);
	std::vector<uint8_t> LoadModData(wString ModName);

/*
*	Returns the path where this mod is installed. Most likely in some Steam Workshop directory deep in some Steam folder hierarchy.
*	Expect this to be reset every time the mod gets updated, so it makes no sense to write any non-temporary data here. Only use it to read files you might be shipping with your mod.
*/
	const wString& GetThisModInstallFolderPath();

/*
*	Returns the path where you should write save files to, if you for some reason can not just use the SaveModDataString or SaveModData functions.
*	If you can, always prefer to use the provided save functions (SaveModDataString or SaveModData) instead of manually writing save files.
*/
	wString GetThisModSaveFolderPath(wString ModName);

/*
*	Returns a path for global mod data that is shared between different worlds. Usually, this is the wrong path to use, you should not use this for regular save files.
*	If you want to make a mod that transfers data from one world to another,
*	you would use this path, as the GetThisModSaveFolderPath function above returns a different path for each world.
*/
	wString GetThisModGlobalSaveFolderPath(wString ModName);

/*
*	Returns the version number of the game. The GameVersion type contains the major and the minor version number as individual integers, and a bool IsBetaBuild.
*/
	GameVersion GetGameVersionNumber();

/*
*	Returns a random bool with a certain chance to be TRUE. This function is very fast (~5 CPU cycles).
*
*	Example for returning TRUE on average every 10th time:										GetRandomBool<10>();
*/
	template<uint64_t TrueOneInN> bool GetRandomBool();

/*
*	Returns a random int value between MIN and MAX (inclusive). This function is very fast (~5 CPU cycles).
*
*	Example for returning a random int between 0 and 5:											GetRandomInt<0, 5>();
*/
	template<int32_t Min, int32_t Max> int32_t GetRandomInt();

/*
*	Returns an array of all coordinates in a certain box extent or radius around a specific coordinate
*/
	std::vector<CoordinateInBlocks> GetAllCoordinatesInBox(CoordinateInBlocks At, CoordinateInBlocks BoxExtent);
	std::vector<CoordinateInBlocks> GetAllCoordinatesInRadius(CoordinateInBlocks At, int32_t Radius);	

/*
*	Get a handle to memory that you want to share between multiple different mods. If you don't know what this does, you most likely never need to use it. 
*	The handle automatically aquires a lock on the memory it points to, and releases it when going out of scope.
*	ScopedSharedMemoryHandle.Pointer is a reference to a void pointer, which you can cast and set to any type you need.
* 
*	If you set either CreateIfNotExist or WaitUntilExist to true, then the returned handle is guaranteed to be valid, and you don't need to check if it is valid.
*	If both CreateIfNotExist and WaitUntilExist are false, you need to check if Handle.Valid == true before accessing the pointer in it. Handle.Valid will be false then if the key does not exist.
*/
	ScopedSharedMemoryHandle GetSharedMemoryPointer(wString Key, bool CreateIfNotExist, bool WaitUntilExist);
