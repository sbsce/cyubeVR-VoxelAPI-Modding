#include "GameAPI.h"

/************************************************************
	Config Variables (Set these to whatever you need. They are automatically read by the game.)
*************************************************************/

UniqueID ThisModUniqueIDs[] = { 0 }; // All the UniqueIDs this mod manages. Functions like Event_BlockPlaced are only called for blocks of IDs mentioned here. 

float TickRate = 1;							 // Set how many times per second Event_Tick() is called. 0 means the Event_Tick() function is never called.

/************************************************************* 
//	Functions (Run automatically by the game, you can put any code you want into them)
*************************************************************/

// Run every time a block is placed
void Event_BlockPlaced(CoordinateInBlocks At, UniqueID CustomBlockID, bool Moved)
{
	
}




// Run every time a block is destroyed
void Event_BlockDestroyed(CoordinateInBlocks At, UniqueID CustomBlockID, bool Moved)
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

}

// Run once when the world is exited
void Event_OnExit()
{
	
}

/*******************************************************

	For all the available game functions you can call, look at the GameAPI.h file

*******************************************************/
