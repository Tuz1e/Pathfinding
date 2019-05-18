#include "Settings.h"

Settings::Settings()
{
}

Settings::~Settings()
{
}

void Settings::LoadDefault()
{
	myTitle = GetFromXml(GAMEINFO, "Title");

	myScreen.Width = ConvertToInt(GetFromXml(DEFAULT_SETTINGS, "SS_Width"));
	myScreen.Height = ConvertToInt(GetFromXml(DEFAULT_SETTINGS, "SS_Height"));
	myScreen.AspectWidth = ConvertToInt(GetFromXml(DEFAULT_SETTINGS, "SAR_Width"));
	myScreen.AspectHeight = ConvertToInt(GetFromXml(DEFAULT_SETTINGS, "SAR_Height"));

	myScreen.Fullscreen = ((ConvertToInt(GetFromXml(DEFAULT_SETTINGS, "Fullscreen"))) == 1) ? true : false;
	myScreen.FrameCounter = ((ConvertToInt(GetFromXml(DEFAULT_SETTINGS, "FrameCounter"))) == 1) ? true : false;
}

Screen Settings::GetScreen()
{
	return myScreen;
}

std::string Settings::GetTitle()
{
	return myTitle;
}
