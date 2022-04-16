#pragma once
#include "GameFunctions.h"
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
	void Log(const std::wstring& String);

/*
*	Returns the block at the coordinate your specify. You can call this with either a CoordinateInBlocks or a CoordinateInCentimeters.
*/
	BlockInfo GetBlock(CoordinateInBlocks At);

/*
*	Set the block at the specified coordinate. Examples how you can call SetBlock:
*
*	Setting the block at coordinate 0, 0, 0 to be Stone (native block):							SetBlock(CoordinateInBlocks(0, 0, 0), EBlockType::Stone);
*	Setting the block at coordinate 0, 0, 0 to be a custom block of the UniqueID 50000:			SetBlock(CoordinateInBlocks(0, 0, 0), 50000);
*
*	To delete a block, set it to the type EBlockType::Air
*/
	bool SetBlock(CoordinateInBlocks At, EBlockType NativeType);
	bool SetBlock(CoordinateInBlocks At, UniqueID CustomBlockID);
	bool SetBlock(CoordinateInBlocks At, BlockInfo BlockType);

/*
*	Spawn a hint text popup with the specified text at the specified coordinate.	
*/
	void SpawnHintText(CoordinateInCentimeters At, const std::wstring& Text, float DurationInSeconds, float SizeMultiplier = 1, float SizeMultiplierVertical = 1);

	// Returns the current player location
	CoordinateInCentimeters GetPlayerLocation();

	// Sets the player location. Be careful with this, if you set it to something far away, the only way for the player to ever get back to their base would
	// probably be to kill themselves
	void SetPlayerLocation(CoordinateInCentimeters To);

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


	// Returns an array of all coordinates in a certain box extent around a specific coordinate
	std::vector<CoordinateInBlocks> GetAllCoordinatesInBox(CoordinateInBlocks At, CoordinateInBlocks BoxExtent);

	// Returns an array of all coordinates in a certain radius around a specific coordinate
	std::vector<CoordinateInBlocks> GetAllCoordinatesInRadius(CoordinateInBlocks At, int32_t Radius);