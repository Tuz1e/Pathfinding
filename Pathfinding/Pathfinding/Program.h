#ifndef PROGRAM_H
#define PROGRAM_H

#include "pch.h"
#include "SFML/Graphics.hpp"
#include "Input.h"
#include "Player.h"
#include "TileMap.h"

class Program
{
public:
	Program();
	~Program();

	void Init();
	void Update(float& aDelta);
	void Draw(sf::RenderWindow& aWindow);
	void LateDraw(sf::RenderWindow& aWindow);

private:
	Player* myPlayer;
	Input myInput;
	TileMap* myMap;
	sf::View myView;
	sf::RenderWindow myWindow;

	float myRenderOffset, myFadeOffset;
};

#endif //PROGRAM_H