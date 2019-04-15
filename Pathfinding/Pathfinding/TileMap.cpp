#include "TileMap.h"



TileMap::TileMap(std::string aMapLocation)
{
	myMapLocation = aMapLocation;
}


TileMap::~TileMap()
{
	DelPtr(mySprite);
}

void TileMap::LoadMapData()
{
	std::string tempMapData = GetMap(myMapLocation);

	//0: Texture Location
	//1: Map width
	//2: Map height
	//3: Map data and texture
	std::vector<std::string> tempMapDataVec = SplitString(tempMapData, ';');

	myTextureLocation = tempMapDataVec[0];
	myWidth = ConvertToInt(tempMapDataVec[1]);
	myHeight = ConvertToInt(tempMapDataVec[2]);
	std::vector<std::string> tempData = SplitString(tempMapDataVec[3], ',');

	//myMap.resize(myWidth * myHeight);

	LoadTexture();


	//TODO: The map are tiling them incorrectly, it is not taking their size into account regarding their position
	int tempTileId = 0;
	for (size_t i = 0; i < myHeight; i++)
	{
		for (size_t j = 0; j < myWidth; j++)
		{
			Tile tempTile = 
			{ 
				tz::Vector2f(i, j),
				ConvertToInt(tempData[tempTileId]),
				sf::Sprite(myTexture)
			};
			//myMap[tempTile].Position = tz::Vector2f(i, j);
			//myMap[tempTileId].TextureID = ConvertToInt(tempMapDataVec[tempTileId]);

			//myMap[tempTileId].Sprite = sf::Sprite(myTexture);
			myMap.push_back(tempTile);
			myMap[tempTileId].Sprite.setPosition
			(
				sf::Vector2f
				(
					myMap[tempTileId].Position.X,
					myMap[tempTileId].Position.Y
				)
			);

			myMap[tempTileId].Sprite.setScale(sf::Vector2f(2.0, 2.0));

			tempTileId += 1;
		}
	}

	PrintLoaded("Map data");
}

void TileMap::Draw(sf::RenderWindow& aWindow)
{
	for (size_t i = 0; i < myMap.size(); i++)
	{
		aWindow.draw(myMap[i].Sprite);
	}
}

void TileMap::LoadTexture()
{
	myTexture.loadFromFile(myTextureLocation);
}
