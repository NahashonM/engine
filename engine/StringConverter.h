#pragma once
#include <string>

class StringConverter
{
public:

	static std::wstring StringToWideString(std::string str);
	static std::string WideStringToString(std::wstring wstr);

};

