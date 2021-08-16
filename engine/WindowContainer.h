#pragma once


#include "RenderWindow.h"
#include "Keyboard/Keyboard.h"


class WindowContainer
{
protected:
	RenderWindow renderWindow;
	Keyboard keyboard;

public:
	
	LRESULT WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	~WindowContainer();
};

