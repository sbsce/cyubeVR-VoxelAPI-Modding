This is the official repository for the cyubeVR Voxel API, an easy way to create blocks with custom behavior in cyubeVR.

How to start using this:

# Step 1: Click the "Download ZIP" download button here in GitHub

![TutorialDownload](https://user-images.githubusercontent.com/38058738/162877620-ae9bda17-17b5-4d7e-a864-e696389de2c0.png)

# Step 2: Extract the downloaded ZIP somewhere

# Step 3:

In the extracted folder, go into the folder "ProjectFolder". Then double click the "Code.sln" file.

For this, you do need to have Visual Studio 2022 installed. It's a free software. If you have not yet installed, [simply CLICK HERE and download and install it.](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&cid=2030&passive=false)

If you have it correctly installed, double-clicking the Code.sln will show you this screen:

![TutorialVSScreen](https://user-images.githubusercontent.com/38058738/162878542-485f6720-2978-4e6f-aaa4-f6019590f265.png)

# Step 4: Open the two relevant files

There are two source files you need to edit and look at. They are called "Mod.cpp" and "GameAPI.h". You can open them like this:

![TutorialOpenFiles](https://user-images.githubusercontent.com/38058738/162879058-d19ee0a9-8638-4104-80b6-e54172c52fa6.gif)

# Step 5: Now Write your code in the Mod.cpp

This was all that was required to set this up. The only file you ever have to edit is the `Mod.cpp` file. The `GameAPI.h` is useful as a read-only file to see which functions you can call to interact with the game.

The `Mod.cpp` file contains some variables and functions. You don't need to add any new variables or functions to the file - simply put your code into one of the existing `Event_` functions.

For example, if you want to create a custom block that spawns a hint text when it is placed, look for the `Event_BlockPlaced` function in the `Mod.cpp`, and put in this code:



# ---------------------------------------------------

# How to

# Step 6:

Enter the 
