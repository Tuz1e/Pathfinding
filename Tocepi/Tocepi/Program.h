#ifndef PROGRAM_H
#define PROGRAM_H

#include "pch.h"
#include "SFML/Graphics.hpp"
#include "Input.h"
#include "Player.h"
#include "Map.h"
#include "SessionHandler.h"

//TODO: Main menu
//TODO: Pause Screen
//TODO: Item/Weapon manager

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

	void Init(sf::RenderWindow& aWindow);
	void Update(float& aDelta, sf::Event& anEvent);
	void Draw(sf::RenderWindow& aWindow);
	void LateDraw(sf::RenderWindow& aWindow);

	void InitSession(SessionHandler& aSession, sf::RenderWindow& aWindow);

private:
	SessionHandler mySession;
	Input myInput;
	GameState myState;
};

#endif //PROGRAM_H
