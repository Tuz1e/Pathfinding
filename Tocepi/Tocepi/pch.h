#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <string.h>
#include <vector>

#include "File.h"
#include "Info.h"

inline int ConvertToInt(const std::string& convertableStr)
{
	if (!convertableStr.empty())
	{
		try
		{
			return std::stoi(convertableStr.c_str());
		}
		catch (...) {}
	}
	return 0;
}

inline float ConvertToFloat(const std::string& convertableStr)
{
	if (!convertableStr.empty())
	{
		try
		{
			return std::stof(convertableStr);
		}
		catch (...) {}
	}
	return 0.0f;
}

inline void PrintLoaded(std::string str)
{
	try
	{
		std::cout << "Loaded in: " << str << std::endl;
	}
	catch (...) {}
}

inline void Print(std::string str)
{
	try
	{
		std::cout << str << std::endl;
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
void DelPtr(T * &ptr)
{
	if (ptr != nullptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

#endif //PCH_H
