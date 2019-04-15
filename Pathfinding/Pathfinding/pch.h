#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <string.h>
#include <vector>

#include "File.h"
#include "Info.h"

inline int ConvertToInt(const std::string& aConvertableString)
{
	if (!aConvertableString.empty())
	{
		try
		{
			return std::stoi(aConvertableString.c_str());
		}
		catch (...) {}
	}
	return 0;
}

inline float ConvertToFloat(const std::string& aConvertableString) 
{
	if (!aConvertableString.empty()) 
	{
		try 
		{
			return std::stof(aConvertableString);
		}
		catch (...) {}
	}
	return 0.0f;
}

inline void PrintLoaded(std::string aStr) 
{
	try
	{
		std::cout << "Loaded in: " << aStr << std::endl;
	}
	catch (...) {}
}

template<typename T>
void DelPtr(T*& ptr) 
{
	delete ptr;
	ptr = nullptr;
}

#endif //PCH_H