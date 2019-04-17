#include "TileMap.h"

//UNDONE: Tiling works but need to specify the location on the tilemap which is, actually TextureID
//TODO: Scale up the sprites a bit
//TODO: Implement specific layers for collisions etc
//OPTIMIZE: Eats up ALOT of resources when running larger maps.
//Could be fixed by having one sprite instead of width*height amount.

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
	//4: Tile scale
	//5: Map layer amount
	//6: Spritesheet size
	//7: Spritesheet Horizontal size
	//8: Spritesheet Vertical size
	//6+: Map data
	std::vector<std::string> tempMapDataVec = SplitString(tempMapData, ';');

	myTextureLocation = tempMapDataVec[0];
	myWidth = ConvertToInt(tempMapDataVec[1]);
	myHeight = ConvertToInt(tempMapDataVec[2]);
	myTileDimension = ConvertToFloat(tempMapDataVec[3]);
	myTileScale = ConvertToFloat(tempMapDataVec[4]);
	myLayerAmount = ConvertToInt(tempMapDataVec[5]);
	mySpritesheetSize = ConvertToInt(tempMapDataVec[6]);
	mySheetHorizontalSize = ConvertToInt(tempMapDataVec[7]);
	mySheetVerticalSize = ConvertToInt(tempMapDataVec[8]);

	//std::vector<std::string> tempData = SplitString(tempMapDataVec[6], ',');
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

	SetSprite();

	myTileDimension *= myTileScale;

	std::vector<Tile> tempMap;

	int tempTileId = 0;
	for (size_t y = 0; y < myHeight; y++)
	{
		for (size_t x = 0; x < myWidth; x++)
		{
			for (size_t i = 0; i < tempData2Dim.size(); i++)
			{
				Tile tempTile =
				{
					sf::Vector2f(x * myTileDimension, y * myTileDimension),
					ConvertToInt(tempData2Dim[i][tempTileId]),
				};
				tempMap.push_back(tempTile);
			}

			tempTileId += 1;
		}
	}

	tempTileId = 0;
	for (size_t y = 0; y < mySheetVerticalSize; y++)
	{
		for (size_t x = 0; x < mySheetHorizontalSize; x++)
		{
			mySpriteTiles.push_back
			(
				sf::IntRect
				(
					mySpritesheet.getSize().x / mySheetHorizontalSize * x, // 16 * x
					mySpritesheet.getSize().y / mySheetVerticalSize * y, // = 16 * y
					mySpritesheet.getSize().x / mySheetHorizontalSize, // = 16
					mySpritesheet.getSize().y / mySheetVerticalSize // = 16
				)
			);

			tempTileId++;
		}
	}

	std::cout << "X: " << mySpritesheet.getSize().x << " || Y: " << mySpritesheet.getSize().y << std::endl;

	myMap.push_back(tempMap);
	PrintLoaded("Map data");
}

void TileMap::Draw(sf::RenderWindow& aWindow)
{
	int temp = 0;
	for (size_t i = 0; i < myMap.size(); i++)
	{
		for (size_t j = 0; j < myMap[i].size(); j++)
		{
			if (myMap[i][j].TextureID != 0)
			{
				mySprite->setTextureRect
				(
					//sf::IntRect
					//(
					//	myMap[i][j].Position.X * myTileDimension,
					//	myMap[i][j].Position.Y * myTileDimension,
					//	myTileDimension,
					//	myTileDimension)
					//mySpriteTiles[myMap[i][j].TextureID - 1]
					mySpriteTiles[myMap[i][j].TextureID-1]
				);
				mySprite->setPosition(myMap[i][j].Position);
				aWindow.draw(*mySprite);
			}
		}
	}
}

void TileMap::SetSprite()
{
	mySpritesheet.loadFromFile(myTextureLocation);
	mySprite = new sf::Sprite(mySpritesheet);
	mySprite->setScale(myTileScale, myTileScale);
}
