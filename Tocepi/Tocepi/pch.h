#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <string.h>
#include <vector>

#include "File.h"
#include "Info.h"

inline int ConvertToInt(const std::string& aConvertableStr)
{
	if (!aConvertableStr.empty())
	{
		try
		{
			return std::stoi(aConvertableStr.c_str());
		}
		catch (...) {}
	}
	return 0;
}

inline float ConvertToFloat(const std::string& aConvertableStr)
{
	if (!aConvertableStr.empty())
	{
		try
		{
			return std::stof(aConvertableStr);
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

inline void Print(std::string aStr)
{
	try
	{
		std::cout << aStr << std::endl;
	}
	catch (...) {}
}

inline void PrintWarning(std::string aStr)
{
	try
	{
		std::cout << "WARNING: " << aStr << std::endl;
	}
	catch (...) {}
}

inline int Randomize(const int& aLowAmount, const int& aHighAmount)
{
	if ((aHighAmount - aLowAmount) <= 1)
	{
		return 0;
	}

	return (aLowAmount + (rand() % aHighAmount));
}

template<typename T>
void DelPtr(T * &aPtr)
{
	if (aPtr != nullptr)
	{
		delete aPtr;
		aPtr = nullptr;
	}
}

#endif //PCH_H
