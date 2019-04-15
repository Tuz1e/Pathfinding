#include "Program.h"

Program::Program()
{
}


Program::~Program()
{
	DelPtr(myPlayer);
}

void Program::Init()
{
	myMap = new TileMap(MAP);
	myMap->LoadMapData();

	myPlayer = new Player(100.0f, 100.0f);
	myPlayer->Init(myInput);
}

void Program::Update(float& aDelta)
{
	myPlayer->Update(aDelta);
}

void Program::Draw(sf::RenderWindow& aWindow)
{
	myMap->Draw(aWindow);
	myPlayer->Draw(aWindow);
}

void Program::LateDraw(sf::RenderWindow& aWindow)
{
}
