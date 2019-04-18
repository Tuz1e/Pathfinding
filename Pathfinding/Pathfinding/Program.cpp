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
	myRenderOffset = 75.0f;
	myFadeOffset = myRenderOffset + 25.0f;
	myMap = new TileMap(MAP);
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
	myView.move(myPlayer->GetVelocity() * aDelta);
	myPlayer->Update(aDelta);
}

void Program::Draw(sf::RenderWindow& aWindow)
{
	aWindow.setView(myView);


	myMap->Draw(aWindow, *myPlayer, myRenderOffset, myFadeOffset);
	myPlayer->Draw(aWindow);
}

void Program::LateDraw(sf::RenderWindow& aWindow)
{
}
