

#include "WindowContainer.h"



bool RenderWindow::Initialize(WindowContainer *winContainer, HINSTANCE hInstance, std::string winTitle, std::string winClass, int width, int height)
{
	this->winTitle = StringConverter::StringToWideString(winTitle);
	this->winClass = StringConverter::StringToWideString(winClass);

	this->width = width;
	this->height = height;
	this->hInstance = hInstance;

	if (!RegisterWindowClass()) {
		ErrorLogger::Log("Failed to Register Window Class");
		exit(-1);
	}

	this->hWnd = CreateWindowExW(NULL, this->winClass.c_str(), this->winTitle.c_str(),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, nullptr, nullptr, hInstance, winContainer);

	if (!this->hWnd) {
		ErrorLogger::Log(GetLastError(), "Failed to Create Window for " + winTitle);
		UnregisterClassW(this->winClass.c_str(), this->hInstance);
		exit(-1);
	}

	ShowWindow(this->hWnd, SW_SHOW);
	SetForegroundWindow(this->hWnd);
	SetFocus(this->hWnd);

	return false;
}





bool RenderWindow::ProcessMessages()
{
	if (!IsWindow(this->hWnd)) 
		return false;

	MSG msg;
	if (PeekMessage(&msg, nullptr, NULL, NULL, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}


///---------------------------------------------------------------------------------------------------
///<summary>
/// Routes a Message to its respective WindowContainer Object's Message Handler
///</summary>
///---------------------------------------------------------------------------------------------------
LRESULT CALLBACK WndProcRouter(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CLOSE:
		{
			DestroyWindow(hWnd);
			return 0;
		}

		default:
		{
			WindowContainer *winContainer = reinterpret_cast<WindowContainer*>(GetWindowLongPtrW(hWnd, GWLP_USERDATA));

			winContainer->WndProc(hWnd, msg, wParam, lParam);
		}
	}
}


///---------------------------------------------------------------------------------------------------
///<summary>
/// Temporary Message Procedure. Once a WM_NCCREATE Message is received
///		It switches the window message handler to  WndProcRouter which routes the messages to the
///			appropriate window container Message handler
///</summary>
///---------------------------------------------------------------------------------------------------
LRESULT CALLBACK TmpWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
		case WM_NCCREATE: 
		{

			WindowContainer* winContainer = reinterpret_cast<WindowContainer*>(reinterpret_cast<CREATESTRUCTW*>(lParam)->lpCreateParams);

			if (!winContainer) {
				ErrorLogger::Log("Critical Error: Null pointer to WindowContainer During WM_NCCREATE!!!");
				exit(-1);
			}
			
			SetWindowLongPtrW(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(winContainer));
			SetWindowLongPtrW(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(WndProcRouter));

			return WndProcRouter(hWnd, msg, wParam, lParam);
		}
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}


///--------------------------------------------------------
///<summary> Register Window Class </summary>
///--------------------------------------------------------
bool RenderWindow::RegisterWindowClass()
{
	WNDCLASSEXW wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEXW));

	wc.cbSize = sizeof(WNDCLASSEXW);
	wc.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
	wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
	wc.lpszClassName = winClass.c_str();
	wc.lpfnWndProc = TmpWndProc;
	wc.hInstance = hInstance;

	if (RegisterClassExW(&wc))
		return true;

	return false;
}




RenderWindow::~RenderWindow()
{
	if (hWnd) {
		if (IsWindow(hWnd)) {
			DestroyWindow(hWnd);
			UnregisterClassW(this->winClass.c_str(), this->hInstance);
		}

		hWnd = nullptr;
	}
}
