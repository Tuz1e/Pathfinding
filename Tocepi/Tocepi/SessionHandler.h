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
			float aViewZoom,
			Input& anInput,
			sf::RenderWindow& aWindow),
		Update(float& aDelta, sf::Event& anEvent),
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
			float& aFadeOffset),
		LoadPlayer(Input& anInput),
		SetView(sf::View& aView, float& aViewZoom, Player& aPlayer, float& aWidth, float& aHeight),
		MouseScroll(sf::View& aView, sf::Event& anEvent);

	float
		myRenderOffset,
		myFadeOffset,
		myViewZoom;

	tz::Vector2f myScreen;

	std::vector<Map> myMaps;
	Player* myPlayer;
	sf::View
		myView,
		myMinimap;
	sf::RenderWindow* myWindow;
	int myMapId;
	Input myInput;
};

#endif //SESSIONHANDLER_H
