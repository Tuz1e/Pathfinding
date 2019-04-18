#include "TileMap.h"

//TODO: Implement specific layers for collisions etc
//OPTIMIZE: Eats up ALOT of resources when running larger maps. 
//Could be fixed by only rendering that which are inside of the window
//TODO: Implement multithreading

TileMap::TileMap(std::string aMapLocation)
{
	myMapLocation = aMapLocation;
	myMap = new std::vector<std::vector<Tile>>();
}


TileMap::~TileMap()
{
	DelPtr(myMap);
	DelPtr(mySprite);
}

void TileMap::LoadMapData()
{
	std::string tempMapData = GetMapData(myMapLocation);

	//0: Texture Location
	//1: Map width
	//2: Map height
	//3: Tile dimension
	//4: Tile scale
	//5: Map layer amount
	//6: Spritesheet size
	//7: Spritesheet Horizontal size
	//8: Spritesheet Vertical size
	//9+: Map data
	std::vector<std::string> tempMapDataVec = SplitString(tempMapData, ';');

	mySheetLocation = tempMapDataVec[0];
	myWidth = ConvertToInt(tempMapDataVec[1]);
	myHeight = ConvertToInt(tempMapDataVec[2]);
	myMapTileDimension = ConvertToFloat(tempMapDataVec[3]);
	myMapTileScale = ConvertToFloat(tempMapDataVec[4]);
	myLayerAmount = ConvertToInt(tempMapDataVec[5]);
	mySheetSize = ConvertToInt(tempMapDataVec[6]);
	mySheetHorizontalSize = ConvertToInt(tempMapDataVec[7]);
	mySheetVerticalSize = ConvertToInt(tempMapDataVec[8]);

	std::vector<std::vector<std::string>> tempData2Dim;
	std::vector<std::string> tempData;

	for (size_t i = 9; i < tempMapDataVec.size(); i++)
	{
		tempData = SplitString(tempMapDataVec[i], ';');
		for (size_t j = 0; j < tempData.size(); j++)
		{
			tempData2Dim.push_back(SplitString(tempData[j], ','));
		}
	}

	LoadSprite();

	//Scales the dimensions to the correct proportions
	myMapTileDimension *= myMapTileScale;

	//Load spritesheet data
	LoadSheetData(&myTextureTiles);

	//Load and add map data to myMap
	myMap->push_back(LoadMap(&tempData2Dim));

	CleanMapData(myMap);

	PrintLoaded("Finished: Map data");
}

void TileMap::Draw(sf::RenderWindow& aWindow, Player& aPlayer, float& aRenderOffset, float& aFadeOffset)
{
	tz::Vector2f tempMapPos;
	float tempDis = 0;
	sf::Color tempC;
	float tempOffset = aRenderOffset / 4;

	for (size_t i = 0; i < myMap->size(); i++)
	{
		for (size_t j = 0; j < myMap->at(i).size(); j++)
		{
			tempMapPos = tz::Vector2f(myMap->at(i)[j].Position.x, myMap->at(i)[j].Position.y);
			float tempDis = tz::DisBetweenVec(aPlayer.GetPosition(), tempMapPos);

			if (tempDis < aFadeOffset)
			{
				mySprite->setTextureRect(myTextureTiles[myMap->at(i)[j].TextureID - 1]);
				mySprite->setPosition(myMap->at(i)[j].Position);

				tempC = mySprite->getColor();
				tempC.a = (tempDis > aRenderOffset) ? 190 : 255;

				mySprite->setColor(tempC);
				aWindow.draw(*mySprite);
			}

		}
	}
}

void TileMap::LoadSprite()
{
	mySheet.loadFromFile(mySheetLocation);
	mySprite = new sf::Sprite(mySheet);
	mySprite->setScale(myMapTileScale, myMapTileScale);

	PrintLoaded("Map data: sprite");
}

void TileMap::CleanMapData(std::vector<std::vector<Tile>>* aMap)
{
	for (size_t i = 0; i < aMap->size(); i++)
	{
		std::vector<Tile> tempData;
		for (size_t j = 0; j < aMap->at(i).size(); j++)
		{
			if (aMap->at(i)[j].TextureID != 0)
			{
				tempData.push_back(aMap->at(i)[j]);
			}
		}
		aMap->at(i).clear();
		aMap->at(i) = tempData;
	}

	Print("Cleaned map data");
}

void TileMap::LoadSheetData(std::vector<sf::IntRect>* someTextureTiles)
{
	for (size_t y = 0; y < mySheetVerticalSize; y++)
	{
		for (size_t x = 0; x < mySheetHorizontalSize; x++)
		{
			someTextureTiles->push_back
			(
				sf::IntRect
				(
					mySheet.getSize().x / mySheetHorizontalSize * x, // 16 * x
					mySheet.getSize().y / mySheetVerticalSize * y, // = 16 * y
					mySheet.getSize().x / mySheetHorizontalSize, // = 16
					mySheet.getSize().y / mySheetVerticalSize // = 16
				)
			);
		}
	}

	PrintLoaded("Map data: Spritesheet data");
}

std::vector<Tile> TileMap::LoadMap(std::vector<std::vector<std::string>>* someMapData)
{

	std::vector<Tile> tempMap;

	int tempTileId = 0;
	for (size_t y = 0; y < myHeight; y++)
	{
		for (size_t x = 0; x < myWidth; x++)
		{
			for (size_t i = 0; i < someMapData->size(); i++)
			{
				Tile tempTile =
				{
					sf::Vector2f(x * myMapTileDimension, y * myMapTileDimension),
					ConvertToInt(someMapData->at(i)[tempTileId]),
				};
				tempMap.push_back(tempTile);
			}

			tempTileId++;
		}
	}

	PrintLoaded("Map data: Map");
	return tempMap;
}
