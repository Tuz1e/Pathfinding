#include "TileMap.h"

//TODO: Tiling works but need to specify the location on the tilemap which is, actually TextureID

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
	//3: Tile dimensions
	//4: Map data
	std::vector<std::string> tempMapDataVec = SplitString(tempMapData, ';');

	myTextureLocation = tempMapDataVec[0];
	myWidth = ConvertToInt(tempMapDataVec[1]);
	myHeight = ConvertToInt(tempMapDataVec[2]);
	myTileDimension = ConvertToFloat(tempMapDataVec[3]);
	std::vector<std::string> tempData = SplitString(tempMapDataVec[4], ',');

	LoadTexture();

	int tempTileId = 0;
	for (size_t y = 0; y < myHeight; y++)
	{
		for (size_t x = 0; x < myWidth; x++)
		{
			Tile tempTile = 
			{ 
				tz::Vector2f(x * myTileDimension, y * myTileDimension),
				ConvertToInt(tempData[tempTileId]),
				sf::Sprite(myTexture)
			};

			myMap.push_back(tempTile);
			myMap[tempTileId].Sprite.setPosition
			(
				sf::Vector2f
				(
					myMap[tempTileId].Position.X,
					myMap[tempTileId].Position.Y
				)
			);

			//myMap[tempTileId].Sprite.setScale(sf::Vector2f(2.0, 2.0));

			tempTileId += 1;
		}
	}

	PrintLoaded("Map data");
}

void TileMap::Draw(sf::RenderWindow& aWindow)
{
	//FIX: Problem regarding tiling of int rect.
	for (size_t i = 0; i < myMap.size(); i++)
	{
		if (myMap[i].TextureID != 0)
		{
			myMap[i].Sprite.setTextureRect
			(
				sf::IntRect
				(
					myMap[i].Position.X * myTileDimension,
					myMap[i].Position.Y * myTileDimension,
					myTileDimension,
					myTileDimension
				)
			);
			aWindow.draw(myMap[i].Sprite);
		}
	}
}

void TileMap::LoadTexture()
{
	myTexture.loadFromFile(myTextureLocation);
}
