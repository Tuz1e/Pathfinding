#include "TileMap.h"

//TODO: Chunk loading

TileMap::TileMap(std::string aLocation, float aRenderOffset, float aFadeOffset) :
	myDataLocation(aLocation),
	myRenderOffset(aRenderOffset),
	myFadeOffset(aFadeOffset)
{
	myDataLoader = DataLoader(myDataLocation);
	myName = myDataLoader.GetDataString("Username");
}

TileMap::~TileMap()
{
	DelPtr(mySprite);
	DelPtr(myTextureTiles);
	DelPtr(myLayers);
}

void TileMap::LoadData()
{
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
	//TileLayer tempLayer;
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
		tempTiles.clear();

		tempStr = "L" + std::to_string(i);

		myLayers->push_back(
			TileLayer
			(
				myDataLoader.GetDataBoolean(tempStr + "-Collision"),
				myDataLoader.GetDataBoolean(tempStr + "-TrapSpawn"),
				myDataLoader.GetDataBoolean(tempStr + "-Door"),
				myDataLoader.GetDataBoolean(tempStr + "-Chest"),
				myDataLoader.GetDataBoolean(tempStr + "-PlayerSpawn"),
				myDataLoader.GetDataBoolean(tempStr + "-EnemySpawn"),
				myDataLoader.GetDataBoolean(tempStr + "-Renderable"),
				myRenderOffset,
				myFadeOffset
			)
		);

		tempTiles = GetTileData(&tempData2Dim[i]);
		tempTiles = CleanData(tempTiles);
		SetColliders(&tempTiles, *mySprite);

		myLayers->at(i).SetData(tempTiles);
	}
}

void TileMap::Update(Player & aPlayer)
{
	for (size_t i = 0; i < myLayers->size(); i++)
	{
		if (myLayers->at(i).GetCollisions())
		{
			for (size_t u = 0; u < myLayers->at(i).GetData().size(); u++)
			{
				if (myLayers->at(i).GetData()[u].CheckColliding(aPlayer.GetBody()))
				{
					aPlayer.SetColliding(true);
				}
			}
		}
	}
}

void TileMap::Draw(sf::RenderWindow & aWindow, Player & aPlayer)
{
	for (size_t i = 0; i < myLayers->size(); i++)
	{
		if (myLayers->at(i).GetRenderFlag())
		{
			myLayers->at(i).Draw(aWindow, aPlayer, *mySprite);
		}
		//myLayers->at(i).DrawCollisionBoxes(aWindow, aPlayer);
	}
}

void TileMap::LoadSheetData(std::vector<sf::IntRect> * someTextureTiles)
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

	PrintLoaded("Map data: Spritesheet data for Map->" + myName);
}

std::vector<Tile> TileMap::CleanData(std::vector<Tile> & aLayer)
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

void TileMap::SetColliders(std::vector<Tile> * aLayer, sf::Sprite & aSprite)
{
	for (size_t i = 0; i < aLayer->size(); i++)
	{
		aLayer->at(i).SetBody
		(
			sf::Vector2f(aLayer->at(i).GetPosition().X, aLayer->at(i).GetPosition().Y),
			sf::Color(220, 20, 60, 128), //Crimson
			mySprite->getScale(),
			sf::Vector2f
			(
				myTextureTiles->at(aLayer->at(i).GetTextureID() - 1).width,
				myTextureTiles->at(aLayer->at(i).GetTextureID() - 1).height

			)
		);
	}

	PrintLoaded("Map data: Colliders for map->" + myName);
}

void TileMap::LoadSprite(sf::Sprite & aSprite, sf::Texture * aSheet)
{
	aSheet->loadFromFile(myTextureLocation);
	aSprite = sf::Sprite(*aSheet);
	aSprite.setScale(myTileScale, myTileScale);

	PrintLoaded("Map data: sprite for map->" + myName);
}

std::vector<Tile> TileMap::GetTileData(std::vector<std::string> * someData)
{
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

	PrintLoaded("Map data: Tile data for map->" + myName);

	return tempData;
}

#pragma region Get&Set

int& TileMap::GetLayersAmount()
{
	return myLayerAmount;
}

float& TileMap::GetTileDimension()
{
	return myTileDimension;
}

int& TileMap::GetVerticalSize()
{
	return mySheetVerticalSize;
}

int& TileMap::GetHorizontalSize()
{
	return mySheetHorizontalSize;
}

int& TileMap::GetHeight()
{
	return myHeight;
}

int& TileMap::GetWidth()
{
	return myWidth;
}

float& TileMap::GetScale()
{
	return myTileScale;
}

std::vector<TileLayer>* TileMap::GetLayers()
{
	return myLayers;
}

std::string& TileMap::GetTextureLocation()
{
	return myTextureLocation;
}

std::string& TileMap::GetLocation()
{
	return myDataLocation;
}

bool& TileMap::GetLoadedFlag()
{
	return myLoadedFlag;
}

#pragma endregion
