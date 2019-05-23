//Tocepi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Program.h"

#include "Settings.h"

//#include <chrono>
//#include <time.h>
//#include <thread>
//#include <sys/timeb.h>
//#include <thread>
//#include <atomic>

//timeb myTb;

int main()
{
	Program tempGame;
	//bool tempRunFlag = true;

	srand(time(NULL));

	Settings tempSettings;
	tempSettings.LoadDefault(); //Load default settings

	sf::RenderWindow tempWindow(
		sf::VideoMode(
			tempSettings.GetScreen().Width,
			tempSettings.GetScreen().Height),
		tempSettings.GetTitle());
	tempWindow.setFramerateLimit(tempSettings.GetScreen().LimitFramerate);
	tempWindow.setVerticalSyncEnabled(tempSettings.GetScreen().VSync);

	float tempFps, tempLastTime;
	tempFps = tempLastTime = 0;

	sf::Clock tempClock;
	float tempDelta;

	tempGame.Init(tempWindow, tempSettings.GetScreen().FrameCounter);

	while (tempWindow.isOpen())
	{
		sf::Event tempEvent;
		while (tempWindow.pollEvent(tempEvent))
		{
			//Makes sure the game closes when X is pressed.
			if (tempEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				tempWindow.close();
			}
		}

		tempDelta = tempClock.restart().asSeconds();
		tempGame.Update(tempDelta, tempEvent);

		tempWindow.clear(sf::Color(32, 32, 32));
		tempGame.Draw(tempWindow);
		tempGame.LateDraw(tempWindow, tempFps);
		tempWindow.display();

		if (tempSettings.GetScreen().FrameCounter)
		{
			tempFps = 1.0f / (tempDelta - tempLastTime);
			tempLastTime = tempDelta;
		}
	}

	return 0;

	//auto tempNs = std::chrono::high_resolution_clock::now();
	//long tempPreviousTime =
	//	(long)std::chrono::duration_cast<std::chrono::nanoseconds>
	//	(std::chrono::system_clock::now().time_since_epoch()).count(); //Gets previous time
	//float tempNsPerTick = 1000000000 / 60.0f; //Nanoseconds per tick

	//int tempTicks = 0;
	//int tempFrames = 0;

	//long tempLastTimer = (long)std::chrono::duration_cast<std::chrono::milliseconds>
	//	(std::chrono::system_clock::now().time_since_epoch()).count();
	//float tempDelta = 0.0f;

	//Settings tempSettings;
	//tempSettings.LoadDefault();

	//sf::RenderWindow tempWindow(sf::VideoMode(tempSettings.GetScreen().Width, tempSettings.GetScreen().Height), tempSettings.GetTitle());
	//tempGame.Init();

	//while (tempRunFlag && tempWindow.isOpen())
	//{
	//	tempNs = std::chrono::high_resolution_clock::now(); //Gets current time in nanoseconds

	//	long tempNow =
	//		(long)std::chrono::duration_cast<std::chrono::nanoseconds>
	//		(std::chrono::system_clock::now().time_since_epoch()).count();
	//	tempDelta += (tempNow - tempPreviousTime) / tempNsPerTick;
	//	tempPreviousTime = tempNow;

	//	sf::Event tempEvent;
	//	while (tempWindow.pollEvent(tempEvent))
	//	{
	//		if (tempEvent.type == sf::Event::Closed) { tempWindow.close(); } //Makes sure the game closes when X is pressed.
	//	}

	//	while (tempDelta >= 1) //Update once every 1/60th second
	//	{
	//		tempTicks++;
	//		tempGame.Update(tempDelta); //Update
	//		tempDelta--;
	//	}

	//	tempFrames++; //Updates frames
	//	tempWindow.clear(sf::Color(32, 32, 32));
	//	tempGame.Draw(tempWindow);
	//	tempGame.LateDraw(tempWindow); //To render UI elements, on top of normal game ones.
	//	tempWindow.display();

	//	if ((long)std::chrono::duration_cast<std::chrono::milliseconds>
	//		(std::chrono::system_clock::now().time_since_epoch()).count() - tempLastTimer > 1000)
	//	{
	//		//printf("\n\nFPS: %i", tempFrames);
	//		//printf("\nDELTA: %f", tempDelta);
	//		tempLastTimer += 1000;
	//		tempTicks = 0;
	//		tempFrames = 0;
	//	}
	//}
}
