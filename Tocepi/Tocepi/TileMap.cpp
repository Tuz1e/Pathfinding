#include "TileMap.h"

//OPTIMIZE: Eats up A LOT of resources when running larger maps. 
//TODO: Implement multithreading

TileMap::TileMap(std::string aMapLocation, float aRenderOffset, float aFadeOffset)
{
	myMapLocation = aMapLocation;
	myMap = new std::vector<std::vector<Tile>>();
	myRenderOffset = aRenderOffset;
	myFadeOffset = aFadeOffset;
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

	SetColliders(myMap);

	PrintLoaded("Finished: Map data");
}

void TileMap::Update(Player& aPlayer)
{
	for (size_t i = 0; i < myMap->size(); i++)
	{
		for (size_t j = 0; j < myMap->at(i).size(); j++)
		{
			if (tz::DisBetweenVec(aPlayer.GetPosition(), myMap->at(i)[j].GetPosition()) < myFadeOffset)
			{
				if (myMap->at(i)[j].GetCollidableFlag())
				{
					if (aPlayer.CheckColliding(myMap->at(i)[j].GetBody()))
					{
						//std::cout << "COLLISION" << std::endl;
						aPlayer.SetColliding(true);
					}
				}
			}

		}
	}
}

void TileMap::Draw(sf::RenderWindow& aWindow, Player& aPlayer)
{
	float tempDis = 0;
	sf::Color tempC;

	for (size_t i = 0; i < myMap->size(); i++)
	{
		for (size_t j = 0; j < myMap->at(i).size(); j++)
		{
			tempDis = tz::DisBetweenVec(aPlayer.GetPosition(), myMap->at(i)[j].GetPosition());

			if (tempDis < myFadeOffset)
			{
				mySprite->setTextureRect(myMap->at(i)[j].GetBoundingBox());
				mySprite->setPosition(GetSFVector(myMap->at(i)[j].GetPosition()));

				tempC = mySprite->getColor();
				tempC.a = (tempDis > myRenderOffset) ? 175 : 255;

				mySprite->setColor(tempC);
				aWindow.draw(*mySprite);
				//if (myMap->at(i)[j].GetCollidableFlag())
				//{
				//	myMap->at(i)[j].DrawBody(aWindow);
				//}
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

void TileMap::SetColliders(std::vector<std::vector<Tile>>* aMap)
{
	for (size_t i = 0; i < aMap->size(); i++)
	{
		for (size_t j = 0; j < aMap->at(i).size(); j++)
		{
			aMap->at(i)[j].SetBody
			(
				GetSFVector(aMap->at(i)[j].GetPosition()),
				sf::Color(220, 20, 60, 128),
				mySprite->getScale(),
				sf::Vector2f
				(
					myTextureTiles[myMap->at(i)[j].GetTextureID() - 1].width,
					myTextureTiles[myMap->at(i)[j].GetTextureID() - 1].height
				)

			);
		}
	}
}

void TileMap::CleanMapData(std::vector<std::vector<Tile>>* aMap)
{
	for (size_t i = 0; i < aMap->size(); i++)
	{
		std::vector<Tile> tempData;
		for (size_t j = 0; j < aMap->at(i).size(); j++)
		{
			if (aMap->at(i)[j].GetTextureID() != 0)
			{
				tempData.push_back(aMap->at(i)[j]);
			}
		}
		aMap->at(i).clear();
		aMap->at(i) = tempData;
	}

	Print("Cleaned map data");
}

sf::Vector2f TileMap::GetSFVector(const tz::Vector2f& aPos)
{
	return sf::Vector2f(aPos.X, aPos.Y);
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
				Tile tempTile = Tile
				(
					tz::Vector2f(x * myMapTileDimension, y * myMapTileDimension),
					ConvertToInt(someMapData->at(i)[tempTileId]),
					IsCollidable(someMapData->at(i))
				);
				if (tempTile.GetTextureID() != 0)
				{
					tempTile.SetBoundingBox(myTextureTiles[ConvertToInt(someMapData->at(i)[tempTileId]) - 1]);
				}

				tempMap.push_back(tempTile);
			}

			tempTileId++;
		}
	}

	PrintLoaded("Map data: Map");
	return tempMap;
}

bool TileMap::IsCollidable(std::vector<std::string>& someData)
{
	return (SplitString(someData[0], ':')[0] == "1");
}
