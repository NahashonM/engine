#include "StringConverter.h"



std::wstring StringConverter::StringToWideString(std::string str)
{
	return std::wstring(str.begin(), str.end());
}



std::string StringConverter::WideStringToString(std::wstring wstr)
{
	return std::string(wstr.begin(), wstr.end());
}