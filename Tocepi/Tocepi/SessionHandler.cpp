#include "SessionHandler.h"

//TODO: Loading screen for maps

SessionHandler::SessionHandler()
{

}



SessionHandler::~SessionHandler()
{
	DelPtr(myPlayer);
	DelPtr(myWindow);
}

void SessionHandler::Init(
	float aScreenWidth, 
	float aScreenHeight,
	float aRenderOffset,
	float aFadeOffset,
	Input& anInput,
	sf::RenderWindow& aWindow)
{
	myRenderOffset = aRenderOffset;
	myFadeOffset = aFadeOffset;
	myInput = anInput;

	myWindow = &aWindow;

	myScreen = tz::Vector2f(aScreenWidth, aScreenHeight);

	LoadMap(myMaps, aRenderOffset, aFadeOffset, anInput);

	myView = sf::View
	(
		sf::Vector2f(myPlayer->GetPosition().X, myPlayer->GetPosition().Y),
		sf::Vector2f(aScreenWidth, aScreenHeight)
	);
	myView.zoom(0.5f);
	myView.setCenter(myPlayer->GetPosition().Y, myPlayer->GetPosition().Y);
}

void SessionHandler::GetMaps(
	std::vector<Map>& someMaps, 
	float& aRenderOffset, 
	float& aFadeOffset)
{
	//Gets map profiles from folder
	std::vector<std::string> tempMaps = GetXmlFiles(MAPSLOCATION);

	for (size_t i = 0; i < tempMaps.size(); i++)
	{
		Map tempMap = Map(tempMaps[i], aRenderOffset, aFadeOffset);
		someMaps.push_back(tempMap);
	}
}

void SessionHandler::LoadMap(std::vector<Map>& someMaps, float& aRenderOffset, float& aFadeOffset, Input& anInput)
{
	//TODO: Make map loading more dynamic
	//Should only load up current map.

	GetMaps(someMaps, aRenderOffset, aFadeOffset);

	std::cout << "Map Amount: " << someMaps.size() << std::endl;

	if (someMaps.size() <= 0)
	{
		return;
	}

	someMaps[0].LoadData();

	std::vector<Tile> tempData;

	for (size_t i = 0; i < myMaps[0].GetLayers()->size(); i++)
	{
		if (myMaps[0].GetLayers()->at(i).GetPlayerSpawn())
		{
			tempData = myMaps[0].GetLayers()->at(i).GetData();

			//Sets player position to a random positition between available spawn positions
			myPlayer = new Player(tempData[Randomize(0, tempData.size() + 1)].GetPosition());
			myPlayer->Init(anInput);
		}
	}
}

void SessionHandler::Update(float& aDelta)
{
	myView.move(sf::Vector2f(myPlayer->GetVelocity().X, myPlayer->GetVelocity().Y) * aDelta);
	myPlayer->Update(aDelta, *myWindow);
	myMaps[0].Update(*myPlayer);
}

void SessionHandler::Draw(sf::RenderWindow& aWindow)
{
	aWindow.setView(myView);

	myMaps[0].Draw(aWindow, *myPlayer);

	myPlayer->Draw(aWindow, myView);
}

void SessionHandler::LateDraw(sf::RenderWindow& aWindow)
{
}
