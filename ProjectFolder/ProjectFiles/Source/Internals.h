#pragma once

#include <iostream>

#include "windows.h"

#include "GameFunctions.h"

#include <vector>

using namespace ModAPI;

namespace Internals
{

	extern "C"
	{
		_declspec(dllexport) void Init();

		_declspec(dllexport) const char* GetName();

        _declspec(dllexport) const uint32_t GetAPIVersionNumber();

		_declspec(dllexport) const uint32_t GetModUniqueIDsNum();
		_declspec(dllexport) const void GetModUniqueIDs(UniqueID* ArrayIn);

		_declspec(dllexport) const float GetTickRate();

        _declspec(dllexport) const void E_Event_BlockPlaced(const CoordinateInBlocks& At, const UniqueID& CustomBlockID, const bool& Moved);

        _declspec(dllexport) const void E_Event_BlockDestroyed(const CoordinateInBlocks& At, const UniqueID& CustomBlockID, const bool& Moved);

        _declspec(dllexport) const void E_Event_BlockHitByTool(const CoordinateInBlocks& At, const UniqueID& CustomBlockID, const wchar_t* ToolName, const CoordinateInCentimeters& ExactHitLocation, bool ToolHeldByHandLeft);

		_declspec(dllexport) const void E_Event_Tick();

		_declspec(dllexport) const void E_Event_OnLoad(const bool& CreatedNewWorld);
        
        _declspec(dllexport) const void E_Event_OnExit();

        _declspec(dllexport) const void E_Event_AnyBlockPlaced(const CoordinateInBlocks& At, const BlockInfo& Type, const bool& Moved);

        _declspec(dllexport) const void E_Event_AnyBlockDestroyed(const CoordinateInBlocks& At, const BlockInfo& Type, const bool& Moved);

        _declspec(dllexport) const void E_Event_AnyBlockHitByTool(const CoordinateInBlocks& At, const BlockInfo& Type, const wchar_t* ToolName, const CoordinateInCentimeters& ExactHitLocation, bool ToolHeldByHandLeft);

	}

	HINSTANCE app;	
}








//Returns the last Win32 error, in string format. Returns an empty string if there is no error.
std::string GetLastErrorAsString()
{
    //Get the error message ID, if any.
    DWORD errorMessageID = ::GetLastError();
    if (errorMessageID == 0) {
        return std::string(); //No error message has been recorded
    }

    LPSTR messageBuffer = nullptr;

    //Ask Win32 to give us the string version of that message ID.
    //The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

    //Copy the error message into a std::string.
    std::string message(messageBuffer, size);

    //Free the Win32's string's buffer.
    LocalFree(messageBuffer);

    return message;
}
