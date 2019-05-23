#ifndef SETTINGS_H
#define SETTINGS_H

#include "pch.h"

struct Screen
{
	int Width, Height;
	int AspectWidth, AspectHeight;
	int LimitFramerate;
	bool Fullscreen, FrameCounter, VSync;
};

class Settings
{
public:
	Settings();
	~Settings();

	void LoadDefault();

	Screen GetScreen();
	std::string GetTitle();

private:
	Screen myScreen;
	std::string myTitle;
};

#endif //SETTINGS_H
