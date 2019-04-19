#include "Program.h"

Program::Program()
{
}


Program::~Program()
{
	DelPtr(myPlayer);
	DelPtr(myMap);
}

void Program::Init()
{
	myMap = new TileMap(MAP, 65.0f, 90.0f);
	myMap->LoadMapData();

	myPlayer = new Player(100.0f, 100.0f);
	myPlayer->Init(myInput);

	myView = sf::View
	(
		sf::Vector2f(myPlayer->GetPosition().X, myPlayer->GetPosition().Y),
		sf::Vector2f(1280, 720)
	);
	myView.zoom(0.5);
	//myView.setSize(1200.0f, 800.0f);
	//myView2 = sf::View(sf::Vector2f(350.0f, 300.0f), sf::Vector2f(300.0f, 200.0f));
	myView.setCenter(myPlayer->GetPosition().X, myPlayer->GetPosition().Y);
}

void Program::Update(float& aDelta)
{
	myView.move(sf::Vector2f(myPlayer->GetVelocity().X, myPlayer->GetVelocity().Y) * aDelta);
	myMap->Update(*myPlayer);
	myPlayer->Update(aDelta);
}

void Program::Draw(sf::RenderWindow& aWindow)
{
	aWindow.setView(myView);


	myMap->Draw(aWindow, *myPlayer);
	myPlayer->Draw(aWindow);
}

void Program::LateDraw(sf::RenderWindow& aWindow)
{
}
