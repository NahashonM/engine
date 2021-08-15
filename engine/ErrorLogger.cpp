#include "ErrorLogger.h"
#include <comdef.h>


void ErrorLogger::Log(std::string message)
{
	std::string final_message = "Error: " + message;

	MessageBoxA(nullptr, final_message.c_str(), "Error", MB_ICONERROR);
}


void ErrorLogger::Log(HRESULT hRes, std::string message)
{
	_com_error error(hRes);

	std::wstring final_message = L"Error: " + StringConverter::StringToWideString(message) + L"\n" + error.ErrorMessage();

	MessageBoxW(nullptr, final_message.c_str(), L"Error", MB_ICONERROR);
}
