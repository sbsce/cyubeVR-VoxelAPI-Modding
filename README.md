This is the official repository for the cyubeVR Voxel API, an easy way to create blocks with custom behavior in cyubeVR.

How to start using this:

# Step 1: Click the "Download ZIP" download button here in GitHub

![TutorialDownload](https://user-images.githubusercontent.com/38058738/162877620-ae9bda17-17b5-4d7e-a864-e696389de2c0.png)

# Step 2: Extract the downloaded ZIP somewhere

# Step 3:

In the extracted folder, go into the folder `ProjectFolder`. Then double click the `Code.sln` file.

For this, you do need to have Visual Studio 2022 installed. It's a free software. If you have not yet installed, [simply CLICK HERE and download and install it.](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&cid=2030&passive=false)

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

Then go into the `[GameInstallDirectory]/cyubeVR/Mods/APIMods` folder and create a new folder there, called `MyGreatMod__V1`. You can call that folder anything you want, just make sure the name has has `__V1` at the end. 

Inside of that newly created folder, paste in your `Code.dll` file. That's all!

With the example from above, whenever the custom block with the UniqueID `82323470` is placed, it will now look like this in the game:

![TutorialResult](https://user-images.githubusercontent.com/38058738/162883157-a5b7fb65-68dc-42ba-a7eb-b33d51e0ea4d.gif)
