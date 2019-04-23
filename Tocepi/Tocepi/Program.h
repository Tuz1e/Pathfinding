#ifndef PROGRAM_H
#define PROGRAM_H

#include "pch.h"
#include "SFML/Graphics.hpp"
#include "Input.h"
#include "Player.h"
#include "Map.h"

//TODO: Main menu
//TODO: Pause Screen
//TODO: Item/Weapon manager

class Program
{
public:
	Program();
	~Program();

	void Init(sf::RenderWindow& aWindow);
	void Update(float& aDelta);
	void Draw(sf::RenderWindow& aWindow);
	void LateDraw(sf::RenderWindow& aWindow);

private:
	Player* myPlayer;
	Input myInput;
	Map* myMap;
	sf::View myView;
	sf::RenderWindow* myWindow;
};

#endif //PROGRAM_H