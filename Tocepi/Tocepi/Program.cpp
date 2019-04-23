#include "Program.h"

Program::Program()
{
}


Program::~Program()
{
	DelPtr(myPlayer);
	DelPtr(myMap);
}

void Program::Init(sf::RenderWindow& aWindow)
{
	myWindow = &aWindow;

	myMap = new Map(TESTMAP, 65.0f, 90.0f);
	myMap->LoadData();

	myPlayer = new Player(125.0f, 125.0f);
	myPlayer->Init(myInput);

	myView = sf::View
	(
		sf::Vector2f(myPlayer->GetPosition().X, myPlayer->GetPosition().Y),
		sf::Vector2f(1280, 720)
	);
	myView.zoom(0.5);
	myView.setCenter(myPlayer->GetPosition().X, myPlayer->GetPosition().Y);
}

void Program::Update(float& aDelta)
{
	myView.move(sf::Vector2f(myPlayer->GetVelocity().X, myPlayer->GetVelocity().Y) * aDelta);
	myPlayer->Update(aDelta, *myWindow);
	myMap->Update(*myPlayer);
	//myMap->Update(*myPlayer);
}

void Program::Draw(sf::RenderWindow& aWindow)
{
	aWindow.setView(myView);


	//myMap->Draw(aWindow, *myPlayer);
	myMap->Draw(aWindow, *myPlayer);

	myPlayer->Draw(aWindow, myView);
}

void Program::LateDraw(sf::RenderWindow& aWindow)
{
}
