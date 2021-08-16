#include "WindowContainer.h"


#define NTH_BIT(_value_, _bit_) ((_value_ >> _bit_) & 0x1)



WPARAM MapKey(WPARAM wParam, LPARAM lParam) {
	switch (wParam) {
	case VK_RMENU:
	default:
		return wParam;
	}
}


LRESULT WindowContainer::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{

		case WM_CHAR:
		{
			if ((lParam & 0x40000000) &&					// Previous State
				!keyboard.IsCharsOnAutoRepeat())			// Repeated Key with AutoRepeat off
				return 0;

			keyboard.OnChar(static_cast<unsigned char>(wParam));
			return 0;
		}

		case WM_KILLFOCUS:
			keyboard.OnLostFocus();
			break;

		case WM_SYSKEYDOWN:
		case WM_KEYDOWN:
		{
			if ((lParam & 0x40000000) &&					// Previous State
				!keyboard.IsEventOnAutoRepeat())			// Repeated Key with AutoRepeat off
				return 0;

			WPARAM key;

			switch (wParam) {								// Extended Keys
				case VK_MENU: key = (lParam & 0x1000000) ? VK_RMENU : VK_LMENU; break;
				case VK_SHIFT: if(!(key = MapVirtualKeyW((lParam & 0x00ff0000) >> 16, MAPVK_VSC_TO_VK_EX))) key = VK_LSHIFT; break;
				case VK_CONTROL: key = (lParam & 0x1000000) ? VK_RCONTROL : VK_LCONTROL; break;
				default: key = wParam;
			}

			keyboard.OnKeyPressed(key);
			return 0;
		}

		case WM_SYSKEYUP:
		case WM_KEYUP:
		{
			WPARAM key;

			switch (wParam) {								// Remap Extended Keys
				case VK_MENU: key = (lParam & 0x1000000) ? VK_RMENU : VK_LMENU; break;
				case VK_SHIFT: if (!(key = MapVirtualKeyW((lParam & 0x00ff0000) >> 16, MAPVK_VSC_TO_VK_EX))) key = VK_LSHIFT; break;
				case VK_CONTROL: key = (lParam & 0x1000000) ? VK_RCONTROL : VK_LCONTROL; break;
				default: key = wParam;
			}

			keyboard.OnKeyReleased(key);
			return 0;
		}


		default:
			return DefWindowProcW(hWnd, msg, wParam, lParam);
	}
}

WindowContainer::~WindowContainer()
{
}
