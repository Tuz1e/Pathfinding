#include "SessionHandler.h"

//TODO: Loading screen for maps
//TODO: Render queue to render based on Y position.

SessionHandler::SessionHandler()
{
	myMapId = 1; //Change this to change map
}

SessionHandler::~SessionHandler()
{
	DelPtr(myPlayer);
	DelPtr(myMonsterManager);
}

///<summary>
///Initialize the session
///</summary>
///<param name="aRenderOffset">The render distance from the player</param>
///<param name="aFadeOffset">The distance at which the tiles start fading</param>
void SessionHandler::Init(
	float aScreenWidth,
	float aScreenHeight,
	float aRenderOffset,
	float aFadeOffset,
	float aViewZoom,
	Input& anInput,
	sf::RenderWindow& aWindow)
{
	myRenderOffset = aRenderOffset;
	myFadeOffset = aFadeOffset;
	myInput = anInput;

	myWindow = &aWindow;

	myScreen = tz::Vector2f(aScreenWidth, aScreenHeight);

	LoadMap(myMaps, aRenderOffset, aFadeOffset);
	LoadPlayer(anInput);

	myMonsterManager = new MonsterManager(MONSTERLOCATIONS);
	LoadMonsters(Randomize(0, 100));

	SetView(myView, aViewZoom, *myPlayer, aScreenWidth, aScreenHeight);

	myMinimap.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));
}

void SessionHandler::Update(float& aDelta, sf::Event& anEvent)
{
	MouseScroll(myView, anEvent);
	myView.move
	(
		sf::Vector2f(myPlayer->GetVelocity().X, myPlayer->GetVelocity().Y) * aDelta
	);

	myMaps[myMapId].Update(*myPlayer);

	myPlayer->Update(aDelta, *myWindow);
	myMonsterManager->Update(aDelta, myPlayer->GetPosition());
}

void SessionHandler::Draw(sf::RenderWindow& aWindow)
{
	//Update/Set view
	aWindow.setView(myView);

	myMaps[myMapId].Draw(aWindow, *myPlayer);
	myPlayer->Draw(aWindow, myView);
	myMonsterManager->Draw(aWindow, myRenderOffset, myPlayer->GetPosition());
}

void SessionHandler::GetMaps(
	std::vector<TileMap>& someMaps,
	float& aRenderOffset,
	float& aFadeOffset)
{
	//Gets map profiles from folder
	std::vector<std::string> tempMaps = GetXmlFiles(MAPLOCATIONS);

	for (size_t i = 0; i < tempMaps.size(); i++)
	{
		TileMap tempMap = TileMap(tempMaps[i], aRenderOffset, aFadeOffset);
		someMaps.push_back(tempMap);
	}
}

void SessionHandler::LoadMonsters(int anAmount)
{
	std::vector<Tile> tempData;
	for (size_t i = 0; i < myMaps[myMapId].GetLayers()->size(); i++)
	{
		if (myMaps[myMapId].GetLayers()->at(i).GetEnemySpawns())
		{
			tempData = myMaps[myMapId].GetLayers()->at(i).GetData();
			break;
		}
	}

	//Makes sure there are actually supposed to spawn monsters on the map
	if (tempData.size() > 0)
	{
		myMonsterManager->LoadDefaults(anAmount);

		for (size_t i = 0; i < myMonsterManager->GetMonsters().size(); i++)
		{
			//Sets monster position to a random positition between available spawn positions
			myMonsterManager->GetMonsters()[i].SetPosition((tempData[Randomize(0, tempData.size())]).GetPosition());
		}
	}
}

void SessionHandler::MouseScroll(sf::View& aView, sf::Event& anEvent)
{
	////TODO: Zoom/Unzoom view when scrolling
	//if (anEvent.type == sf::Event::MouseWheelScrolled)
	//{
	//	if (anEvent.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
	//	{
	//		if (anEvent.MouseWheelScrolled)
	//		{
	//		}
	//	}
	//}
}

void SessionHandler::SetView(sf::View& aView, float& aViewZoom, Player& aPlayer, float& aWidth, float& aHeight)
{
	myView = sf::View
	(
		sf::Vector2f(aPlayer.GetPosition().X, aPlayer.GetPosition().Y),
		sf::Vector2f(aWidth, aHeight)
	);
	myView.zoom(aViewZoom);
	myView.setCenter(aPlayer.GetPosition().X, aPlayer.GetPosition().Y);
}

void SessionHandler::LoadPlayer(Input& anInput)
{
	std::vector<Tile> tempData;

	//Currently bound to only 1 map, should be more dynamic for use of other maps later on
	for (size_t i = 0; i < myMaps[myMapId].GetLayers()->size(); i++)
	{
		if (myMaps[myMapId].GetLayers()->at(i).GetPlayerSpawns())
		{
			tempData = myMaps[myMapId].GetLayers()->at(i).GetData();

			//Sets player position to a random positition between available spawn positions
			myPlayer = new Player(tempData[Randomize(0, tempData.size())].GetPosition());

			myPlayer->Init(anInput);
			break;
		}
	}

	if (myPlayer == NULL)
	{
		myPlayer = new Player(tz::Vector2f(200, 200));
		myPlayer->Init(anInput);
	}

	PrintLoaded("Player");
}

void SessionHandler::LoadMap(std::vector<TileMap>& someMaps, float& aRenderOffset, float& aFadeOffset)
{
	//TODO: Make map loading more dynamic
	//Should only load up current map.

	GetMaps(someMaps, aRenderOffset, aFadeOffset);

	std::cout << "Map Amount: " << someMaps.size() << std::endl;

	if (someMaps.size() <= 0)
	{
		return;
	}

	someMaps[myMapId].LoadData();

	PrintLoaded("Session map");
}

void SessionHandler::LateDraw(sf::RenderWindow& aWindow)
{
}
