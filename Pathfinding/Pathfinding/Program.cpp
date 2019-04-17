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
	myMap = new TileMap(MAP);
	myMap->LoadMapData();

	myPlayer = new Player(100.0f, 100.0f);
	myPlayer->Init(myInput);

	myView = sf::View(sf::FloatRect(200.0f, 200.0f, 300.0f, 200.0f));
	//myView.setSize(1200.0f, 800.0f);
	//myView2 = sf::View(sf::Vector2f(350.0f, 300.0f), sf::Vector2f(300.0f, 200.0f));
	myView.setCenter(myPlayer->GetPosition().X, myPlayer->GetPosition().Y);
}

void Program::Update(float& aDelta)
{
	myPlayer->Update(aDelta);
}

void Program::Draw(sf::RenderWindow& aWindow)
{
	myMap->Draw(aWindow);
	myPlayer->Draw(aWindow);

	//myView.move(5.0f, 0);
	aWindow.setView(myView);
}

void Program::LateDraw(sf::RenderWindow& aWindow)
{
}
