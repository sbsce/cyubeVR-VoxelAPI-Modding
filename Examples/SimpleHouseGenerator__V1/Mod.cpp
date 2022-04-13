#include "GameAPI.h"

/************************************************************
	Config Variables (Set these to whatever you need. They are automatically read by the game.)
*************************************************************/

UniqueID ThisModUniqueIDs[] = { 82323470 }; // All the UniqueIDs this mod manages. Functions like Event_BlockPlaced are only called for blocks of IDs mentioned here. 

float TickRate = 1;							 // Set how many times per second Event_Tick() is called. 0 means the Event_Tick() function is never called.

/************************************************************* 
//	Functions (Run automatically be the game, you can put any code you want into them)
*************************************************************/

// Run every time a block is placed
void Event_BlockPlaced(CoordinateInBlocks At, UniqueID CustomBlockID)
{
	int Width = GetRandomInt<3, 10>();
	int Length = GetRandomInt<3, 10>();
	int WallHeight = GetRandomInt<5, 7>();
	int RoofHeight = 12;

	// First, clear the whole area of any existing blocks
	for (int x = -Width; x <= Width; x++) {
		for (int y = -Length; y <= Length; y++) {
			for (int z = 1; z <= WallHeight; z++) {
				SetBlock(At + CoordinateInBlocks(x, y, z), EBlockType::Air);
			}
		}
	}

	// Randomly choose between Flagstone or Light Processed Wood for the floor
	EBlockType FloorBlockType = GetRandomBool<2>() ? EBlockType::Flagstone : EBlockType::WoodPlankBright;

	// Now generate the floor and the walls of the house
	for (int x = -Width; x <= Width; x++) {
		for (int y = -Length; y <= Length; y++) {

			// Set the floor
			SetBlock(At + CoordinateInBlocks(x, y, 0), FloorBlockType);

			if (x == -Width || x == Width || y == -Length || y == Length) {

				// Generate Walls
				for (int z = 1; z <= WallHeight; z++) {

					// Randomly choose between wallstone and glass for the wall block here
					EBlockType WallBlockType = GetRandomBool<3>() ? EBlockType::GlassBlock : EBlockType::Wallstone;

					// If it's a corner of the wall, make it unprocessed wood
					if (abs(x) == Width && abs(y) == Length) {
						WallBlockType = EBlockType::TreeWood;
					}

					SetBlock(At + CoordinateInBlocks(x, y, z), WallBlockType);

				}

			}
		}
	}

	// Now let's generate the roof

	int TotalRoofHeight = 0;

	for (int z = WallHeight + 1; z < RoofHeight; z++) {

		int WidthHere = Width - TotalRoofHeight;
		int LengthHere = Length - TotalRoofHeight;

		TotalRoofHeight++;

		// If we reached the top of the roof, stop
		if (WidthHere < 0 || LengthHere < 0) break;

		for (int x = -WidthHere; x <= WidthHere; x++) {
			for (int y = -LengthHere; y <= LengthHere; y++) {

				SetBlock(At + CoordinateInBlocks(x, y, z), EBlockType::Air);

				if (x == -WidthHere || x == WidthHere || y == -LengthHere || y == LengthHere) {
					SetBlock(At + CoordinateInBlocks(x, y, z), EBlockType::WoodPlank);
				}

			}
		}
	}

}




// Run every time a block is destroyed
void Event_BlockDestroyed(CoordinateInBlocks At, UniqueID CustomBlockID)
{

}


// Run every time a block is hit by a tool
void Event_BlockHitByTool(CoordinateInBlocks At, UniqueID CustomBlockID, std::wstring ToolName)
{

	if (ToolName == L"T_Stick") {

	}
	else if (ToolName == L"T_Pickaxe_Stone") {

	}
	else if (ToolName == L"T_Arrow") {

	}
	else {

	}
}


// Run X times per second, as specified in the TickRate variable at the top
void Event_Tick()
{

}

// Run once when the world is loaded
void Event_OnLoad()
{
	Log(L"Now in OnLoad in this great Mod");
}