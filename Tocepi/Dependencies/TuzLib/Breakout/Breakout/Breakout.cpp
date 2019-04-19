// Breakout.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "TZ/GameKit.hpp"

#include <iostream>

int main()
{
	tz::Vector2f tempVec = tz::Vector2f(10.0f, 10.0f);
	tz::Vector2f tempVec2 = tz::Vector2f(0.0f, 0.0f);

	if (tempVec == tempVec2) 
	{
		std::cout << "They are equal" << std::endl;
	}
	else 
	{
		std::cout << "They are not equal" << std::endl;
	}

	std::cout << "X: " << tempVec.X << " Y: " << tempVec.Y << std::endl;

	std::cout << "Distance Between Vectors: " << tz::DisBetweenVec(tempVec, tempVec2) << std::endl;

	tempVec.Normalize();

	std::cout << "Normalized X: " << tempVec.X << std::endl;
	std::cout << "Normalized Y: " << tempVec.Y << std::endl;

	std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file