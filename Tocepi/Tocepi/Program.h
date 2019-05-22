#ifndef PROGRAM_H
#define PROGRAM_H

#include "pch.h"
#include "SFML/Graphics.hpp"
#include "Input.h"
#include "Player.h"
#include "TileMap.h"
#include "SessionHandler.h"

//TODO: Main menu
//TODO: Pause Screen
//TODO: Item/Weapon manager

//TODO: ID System for monsters, items, for easier identification
//Would require some better way to create the profile files.

enum GameState
{
	MENU,
	SESSION,
	OPTIONS
};

class Program
{
public:
	Program();
	~Program();

	void Init(sf::RenderWindow& aWindow, bool aFrameCFlag);
	void Update(float& aDelta, sf::Event& anEvent);
	void Draw(sf::RenderWindow& aWindow);
	void LateDraw(sf::RenderWindow& aWindow, float& someFps);

	void InitSession(SessionHandler& aSession, sf::RenderWindow& aWindow);

private:
	SessionHandler mySession;
	Input myInput;
	GameState myState;
	sf::Font myBaseFont;
	sf::Text myText;
	bool myFrameCFlag;
	int myCounter;
};

#endif //PROGRAM_H
