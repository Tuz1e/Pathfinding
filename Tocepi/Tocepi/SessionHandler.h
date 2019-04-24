#ifndef SESSIONHANDLER_H
#define SESSIONHANDLER_H

#include <vector>

#include "Info.h"
#include "Map.h"

class SessionHandler
{
public:
	SessionHandler();
	~SessionHandler();

	void
		Init(float aScreenWidth, 
			float aScreenHeight, 
			float aRenderOffset, 
			float aFadeOffset,
			Input& anInput,
			sf::RenderWindow& aWindow),
		Update(float& aDelta),
		Draw(sf::RenderWindow& aWindow),
		LateDraw(sf::RenderWindow& aWindow);

private:
	void GetMaps(
			std::vector<Map>& someMaps, 
			float& aRenderOffset,
			float& aFadeOffset),
		LoadMap(
			std::vector<Map>& someMaps,
			float& aRenderOffset,
			float& aFadeOffset,
			Input& anInput);

	float 
		myRenderOffset, 
		myFadeOffset;

	tz::Vector2f myScreen;

	std::vector<Map> myMaps;
	Player* myPlayer;
	sf::View myView;
	sf::RenderWindow* myWindow;
	Input myInput;
};

#endif //SESSIONHANDLER_H