#pragma once


#include "RenderWindow.h"


class WindowContainer
{
protected:
	RenderWindow renderWindow;

public:
	
	LRESULT WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	~WindowContainer();
};

