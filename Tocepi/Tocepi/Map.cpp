#include "Map.h"

Map::Map(std::string aLocation, float aRenderOffset, float aFadeOffset):
	myDataLocation(aLocation), 
	myRenderOffset(aRenderOffset),
	myFadeOffset(aFadeOffset)
{
}

Map::~Map()
{
	DelPtr(mySprite);
	DelPtr(myTextureTiles);
	DelPtr(myLayers);
}

void Map::LoadData()
{
	myDataLoader = DataLoader(myDataLocation);

	myName = myDataLoader.GetDataString("Username");
	myLayerAmount = myDataLoader.GetDataInteger("Layers");
	myWidth = myDataLoader.GetDataInteger("Width");
	myHeight = myDataLoader.GetDataInteger("Height");
	myDataLocation = myDataLoader.GetDataString("Data");
	myTextureLocation = myDataLoader.GetDataString("TX");
	myTileScale = myDataLoader.GetDataFloat("TileScale");
	myTileDimension = myDataLoader.GetDataFloat("TileDimension");
	mySheetSize = myDataLoader.GetDataInteger("TXTiles");
	mySheetVerticalSize = myDataLoader.GetDataInteger("TXVertical");
	mySheetHorizontalSize = myDataLoader.GetDataInteger("TXHorizontal");

	//Scaling the tile dimensions correctly to ensure their position is also set correctly later on.
	myTileDimension *= myTileScale;

	std::string tempStr;
	TileLayer tempLayer;
	std::vector<std::vector<std::string>> tempData2Dim;
	std::vector<Tile> tempTiles;

	std::string tempMapStr = GetMapData(myDataLocation);
	std::vector<std::string> tempData = SplitString(tempMapStr, ';');

	//Set pointers
	myTextureTiles = new std::vector<sf::IntRect>();
	myLayers = new std::vector<TileLayer>();
	mySprite = new sf::Sprite();

	mySprite->setScale(myTileScale, myTileScale);

	LoadSprite(*mySprite, &mySheet);
	LoadSheetData(myTextureTiles);

	for (size_t j = 0; j < tempData.size(); j++)
	{
		tempData2Dim.push_back(SplitString(tempData[j], ','));
	}

	for (size_t i = 0; i < tempData2Dim.size(); i++)
	{
		//TODO: Load in map layer
		tempTiles.clear();

		tempStr = "L" + std::to_string(i);

		tempLayer = TileLayer
		(
			myDataLoader.GetDataBoolean(tempStr+"-Collision"),
			myDataLoader.GetDataBoolean(tempStr + "-TrapSpawn"),
			myDataLoader.GetDataBoolean(tempStr + "-Exit"),
			myDataLoader.GetDataBoolean(tempStr + "-Loot"),
			myDataLoader.GetDataBoolean(tempStr + "-PlayerSpawn"),
			myDataLoader.GetDataBoolean(tempStr + "-EnemySpawn"),
			myRenderOffset,
			myFadeOffset
		);

		tempTiles = GetTileData(&tempData2Dim[i]);

		//TODO: Set tile body if collidable

		tempTiles = CleanData(tempTiles);

		SetColliders(&tempTiles, *mySprite);	

		tempLayer.SetData(tempTiles);

		myLayers->push_back(tempLayer);
	}
}

void Map::Update(Player& aPlayer)
{
	//TODO: Map update logic including collision
}

void Map::Draw(sf::RenderWindow& aWindow, Player& aPlayer)
{
	for (size_t i = 0; i < myLayers->size(); i++)
	{
		myLayers->at(i).Draw(aWindow, aPlayer, *mySprite);
		myLayers->at(i).DrawCollisionBoxes(aWindow, aPlayer);
	}
}

void Map::LoadSheetData(std::vector<sf::IntRect>* someTextureTiles)
{
	for (size_t y = 0; y < mySheetVerticalSize; y++)
	{
		for (size_t x = 0; x < mySheetHorizontalSize; x++)
		{
			someTextureTiles->push_back
			(
				sf::IntRect
				(
					mySheet.getSize().x / mySheetHorizontalSize * x,
					mySheet.getSize().y / mySheetVerticalSize * y,
					mySheet.getSize().x / mySheetHorizontalSize,
					mySheet.getSize().y / mySheetVerticalSize
				)
			);
		}
	}

	PrintLoaded("Map data: Spritesheet data for Map->"+myName);
}

std::vector<Tile> Map::CleanData(std::vector<Tile>& aLayer)
{
	std::vector<Tile> tempData;
	for (size_t i = 0; i < aLayer.size(); i++)
	{
		if (aLayer[i].GetTextureID() != 0)
		{
			tempData.push_back(aLayer[i]);
		}
	}
	return tempData;
}

void Map::SetColliders(std::vector<Tile>* aLayer, sf::Sprite& aSprite)
{
	//TODO: Set colliders

	for (size_t i = 0; i < aLayer->size(); i++)
	{
		aLayer->at(i).SetBody
		(
			sf::Vector2f(aLayer->at(i).GetPosition().X, aLayer->at(i).GetPosition().Y),
			sf::Color(220, 20, 60, 128), //Crimson
			mySprite->getScale(),
			sf::Vector2f
			(
				myTextureTiles->at(aLayer->at(i).GetTextureID()-1).width,
				myTextureTiles->at(aLayer->at(i).GetTextureID()-1).height

			)
		);
	}

	PrintLoaded("Map data: Colliders for map->" + myName);
}

void Map::LoadSprite(sf::Sprite& aSprite, sf::Texture* aSheet)
{
	aSheet->loadFromFile(myTextureLocation);
	aSprite = sf::Sprite(*aSheet);
	aSprite.setScale(myTileScale, myTileScale);

	PrintLoaded("Map data: sprite for map->"+myName);
}

std::vector<Tile> Map::GetTileData(std::vector<std::string>* someData)
{
	//TODO: Get tile data logic

	std::vector<Tile> tempData;
	Tile tempTile;
	int tempTileId = 0;
	for (size_t y = 0; y < myHeight; y++)
	{
		for (size_t x = 0; x < myWidth; x++)
		{
			tempTile = Tile
			(
				tz::Vector2f(x * myTileDimension, y * myTileDimension),
				ConvertToInt(someData->at(tempTileId))
			);

			//To not load in tiles without a texture, would take up unnecessary amounts of resources
			if (tempTile.GetTextureID() != 0)
			{
				tempTile.SetBoundingBox(myTextureTiles->at(ConvertToInt(someData->at(tempTileId)) - 1));
			}
			tempData.push_back(tempTile);
			tempTileId++;
		}
	}

	PrintLoaded("Map data: Tile data for map->"+myName);

	return tempData;
}

#pragma region Get&Set

int& Map::GetLayersAmount()
{
	return myLayerAmount;
}

float& Map::GetTileDimension()
{
	return myTileDimension;
}

int& Map::GetVerticalSize()
{
	return mySheetVerticalSize;
}

int& Map::GetHorizontalSize()
{
	return mySheetHorizontalSize;
}

int& Map::GetHeight()
{
	return myHeight;
}

int& Map::GetWidth()
{
	return myWidth;
}

float& Map::GetScale()
{
	return myTileScale;
}

std::vector<TileLayer>* Map::GetLayers()
{
	return myLayers;
}

std::string& Map::GetTextureLocation()
{
	return myTextureLocation;
}

std::string& Map::GetLocation()
{
	return myDataLocation;
}

#pragma endregion