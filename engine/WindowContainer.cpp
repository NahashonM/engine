#include "WindowContainer.h"




LRESULT WindowContainer::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProcW(hWnd, msg, wParam, lParam);
}

WindowContainer::~WindowContainer()
{
}
