# cyubeVR VoxelAPI Modding

This is the official repository for the cyubeVR VoxelAPI, an easy way to programmatically interact with the voxel world in cyubeVR, requiring very little setup from you. It requires no knowledge of UE4 or any other game engine (if you instead want to do UE4 Blueprint Modding of cyubeVR, go [here](https://www.youtube.com/watch?v=MvVLacyToX0&list=PL6kr-0TUTN58n8QrQoFVq4JI-HZj4eDbY&index=1)). 

One of the possible applications of this VoxelAPI Modding is creating "Generator Blocks" - custom blocks that, when placed in the game, procedurally generate structures like a house, or a tree made of blocks, or maybe a whole Titanic replica if you want to! Another example would be using this system to spawn custom ore blocks into the ground, by simply replacing some stone blocks in the ground with your own custom ore block.

You only need to know some very basic programming to use this. If you have ever done any programming in your life, you will be able to understand it. The programming language used is C++, but you do not need any C++ knowledge for this - if you have used any C/C#/Python/Java/Javascript/PHP/Go/Swift, that will suffice, you will quickly get used to the Syntax of this. It is designed to be as easy to use as possible. If you have any questions about anything, you will quickly get help in the #Modding channel in the [official cyubeVR Discord](https://discord.gg/cyubeVR).

---------------------------

Here is an example of what you might do with this. A block that, when placed, procedurally generates a simple, randomly sized house:

![PlaceHouseBlock](https://user-images.githubusercontent.com/38058738/163169898-d87b6653-a6c4-4b51-aff0-0f065be19cc2.gif)

(Both the source code, and the compiled mod ready to be put into your game, for that example is in the `Examples` folder, called `SimpleHouseGenerator__V1`.)

---------------------------

The way the cyubeVR VoxelAPI works is that there are several `Event_` functions automatically called by the game for any loaded VoxelAPI mod. You put in your own code in one (or multiple) of those `Event_` functions, and you are able to call functions interacting with the game, like `SetBlock` or `GetBlock`. 

These are the `Event_` functions currently available to be used:

```cpp
Event_BlockPlaced(CoordinateInBlocks At, UniqueID CustomBlockID);

Event_BlockDestroyed(CoordinateInBlocks At, UniqueID CustomBlockID);

Event_BlockHitByTool(CoordinateInBlocks At, UniqueID CustomBlockID, std::wstring ToolName);

Event_Tick();
```

These are the functions currently available for you to call to interact with the game:

```cpp
void Log(const std::wstring& String);

BlockInfo GetBlock(CoordinateInBlocks At);

bool SetBlock(CoordinateInBlocks At, EBlockType NativeType);

bool SetBlock(CoordinateInBlocks At, UniqueID CustomBlockID);

bool SetBlock(CoordinateInBlocks At, BlockInfo BlockType);

void SpawnHintText(CoordinateInCentimeters At, const std::wstring& Text, float DurationInSeconds, float SizeMultiplier = 1, float SizeMultiplierVertical = 1);

CoordinateInCentimeters GetPlayerLocation();

void SetPlayerLocation(CoordinateInCentimeters To);
```

And these are some convenience functions currently available to be called:

```cpp
template<uint64_t TrueOneInN> bool GetRandomBool();

template<int32_t Min, int32_t Max> int32_t GetRandomInt();

std::vector<CoordinateInBlocks> GetAllCoordinatesInBox(CoordinateInBlocks At, CoordinateInBlocks BoxExtent;

std::vector<CoordinateInBlocks> GetAllCoordinatesInRadius(CoordinateInBlocks At, int32_t Radius);
```

More functions to interact with the game can be added at request, so if there is something you would like to have access to that is not yet available, feel free to request it in the #Modding channel in the [official cyubeVR Discord](https://discord.gg/cyubeVR) or open an issue here on this repository.

Of course, you also have access to the whole C/C++ standard library and any other C/C++ library you might want to include in your code.

# How to start using this:

# Step 1: Click the "Download ZIP" download button here in GitHub

![TutorialDownload](https://user-images.githubusercontent.com/38058738/162877620-ae9bda17-17b5-4d7e-a864-e696389de2c0.png)

# Step 2: Extract the downloaded ZIP somewhere

# Step 3:

In the extracted folder, go into the folder `ProjectFolder`. Then double click the `Code.sln` file.

For this, you do need to have Visual Studio 2022 installed. It's a free software. If you have not yet installed, [simply CLICK HERE and download and install it.](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&cid=2030&passive=false). During installation, when it asks you what "Workloads" should be installed, select "Desktop development with C++".

If you have it correctly installed, double-clicking the `Code.sln` will show you this screen:

![TutorialVSScreen](https://user-images.githubusercontent.com/38058738/162878542-485f6720-2978-4e6f-aaa4-f6019590f265.png)

# Step 4: Open the two relevant files

There are two source files you need to edit and look at. They are called `Mod.cpp` and `GameAPI.h`. You can open them like this:

![TutorialOpenFiles](https://user-images.githubusercontent.com/38058738/162879058-d19ee0a9-8638-4104-80b6-e54172c52fa6.gif)

# Step 5: Write your code in the Mod.cpp

This was all that was required to set this up. The only file you ever have to edit is the `Mod.cpp` file. The `GameAPI.h` is useful as a read-only file to see which functions you can call to interact with the game.

The `Mod.cpp` file contains some variables and functions. You don't need to add any new variables or functions to the file - simply put in the correct UniqueID into the variable at the top, and then write some code in one (or multiple) of the existing `Event_` functions.

For example, let's say you want to create a custom block that spawns a hint text when it is placed. First, [create the custom block using the normal procedure for creating custom blocks for cyubeVR](https://steamcommunity.com/app/619500/discussions/3/1640917625019543783/). Then fill in the `ThisModUniqueIDs` variable at the top of `Mod.cpp` with the UniqueID of your block. If your block has the UniqueID `82323470`, it has to look like this:

```cpp
UniqueID ThisModUniqueIDs[] = { 82323470 }; // All the UniqueIDs this mod manages. Functions like Event_BlockPlaced are only called for blocks of IDs mentioned here. 
```

Then look for the `Event_BlockPlaced` function in the `Mod.cpp`, and put in the code for spawning the hint text:

```cpp
// Run every time a block is placed
void Event_BlockPlaced(CoordinateInBlocks At, UniqueID CustomBlockID)
{
	SpawnHintText(At + CoordinateInBlocks(0, 0, 1), L"I am a block and I was placed!", 5);
}
```

This will spawn a hint text saying "I am a block and I was placed!" above the block that was just placed, and the hint text will stay for 5 seconds.

# Step 6: Get it into the game

To get your custom code into the the game, just press F7 while you are in Visual Studio. This will generate a new file in the `ProjectFolder`. That new file is called `Code.dll`. It contains the compiled code you just wrote! 

Then go into the `[GameInstallDirectory]/cyubeVR/Mods/APIMods` folder and create a new folder there, called `MyGreatMod__V1`. You can call that folder anything you want, just make sure the name has `__V1` at the end. 

Inside of that newly created folder, paste in your `Code.dll` file. That's all!

With the example from above, whenever the custom block with the UniqueID `82323470` is placed, it will now look like this in the game:

![TutorialResult](https://user-images.githubusercontent.com/38058738/162883157-a5b7fb65-68dc-42ba-a7eb-b33d51e0ea4d.gif)
