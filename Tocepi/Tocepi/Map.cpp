#include "Map.h"

Map::Map(std::string aLocation):
	myDataLocation(aLocation)
{
}

Map::~Map()
{
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

	myScale = sf::Vector2i
	(
		myDataLoader.GetDataInteger("TileScaleX"),
		myDataLoader.GetDataInteger("TileScaleY")
	);

	myTileDimension = myDataLoader.GetDataInteger("TileDimension");
	mySheetSize = myDataLoader.GetDataInteger("TXTiles");
	myVerticalSize = myDataLoader.GetDataInteger("TXVertical");
	myHorizontalSize = myDataLoader.GetDataInteger("TXHorizontal");

	std::string tempStr;
	TileLayer tempLayer;

	for (size_t i = 0; i < myLayerAmount; i++)
	{
		tempStr = "L" + std::to_string(i);

		tempLayer = TileLayer
		(
			myDataLoader.GetDataBoolean(tempStr+"-Collision"),
			myDataLoader.GetDataBoolean(tempStr + "-TrapSpawn"),
			myDataLoader.GetDataBoolean(tempStr + "-Exit"),
			myDataLoader.GetDataBoolean(tempStr + "-Loot"),
			myDataLoader.GetDataBoolean(tempStr + "-PlayerSpawn"),
			myDataLoader.GetDataBoolean(tempStr + "-EnemySpawn")
		);

		std::string tempMapStr = GetMapData(myDataLocation);

	}
}

int& Map::GetLayersAmount()
{
	return myLayerAmount;
}

int& Map::GetTileDimension()
{
	return myTileDimension;
}

int& Map::GetVerticalSize()
{
	return myVerticalSize;
}

int& Map::GetHorizontalSize()
{
	return myHorizontalSize;
}

int& Map::GetHeight()
{
	return myHeight;
}

int& Map::GetWidth()
{
	return myWidth;
}

sf::Vector2f& Map::GetScale()
{
	return myScale;
}

std::vector<TileLayer>& Map::GetLayers()
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
