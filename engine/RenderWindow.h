#pragma once

#include <windows.h>

#include "ErrorLogger.h"
#include "StringConverter.h"

class WindowContainer;


class RenderWindow
{
public:
	///---------------------------------------------------------------------------------------------------
	/// <summary> Creates a Rendering Window </summary>
	/// <param name="winContainer"> Window Container wrapper for the window </param>
	/// <param name="hInstance"> Current Application Instance </param>
	/// <param name="winTitle"> Window Caption </param>
	/// <param name="winClass"> Name to register the window class with </param>
	/// <param name="width"> Width of the Window in pixels </param>
	/// <param name="height">  height of the Window in pixels </param>
	///---------------------------------------------------------------------------------------------------
	bool Initialize(WindowContainer* winContainer, HINSTANCE hInstance, std::string winTitle, std::string winClass, int width, int height);


	/// <summary> Non blocking window message handler </summary>
	///---------------------------------------------------------------------------------------------------
	bool ProcessMessages();
	
	~RenderWindow();


private:
	HWND			hWnd		= nullptr;
	HINSTANCE		hInstance	= nullptr;
	std::wstring	winTitle	= L"";
	std::wstring	winClass	= L"";

	int	width	= 0;
	int	height	= 0;

	bool RegisterWindowClass();

};

