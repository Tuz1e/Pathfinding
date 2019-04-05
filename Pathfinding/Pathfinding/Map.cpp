#include "Map.h"


Map::Map()
{
}

Map::Map(int aTileSize, int aWindowWidth, int aWindowHeight, tz::Vector2i aStartPos, tz::Vector2i aEndPos)
	: myTileSize(aTileSize), myHorizontalTiles(aWindowWidth / aTileSize), myWindowWidth(aWindowWidth), myWindowHeight(aWindowHeight)
{

}

Map::~Map()
{
}

const Tile & Map::getStartTile() const
{
	return myStartTile;
}

const Tile & Map::getExitTile() const
{
	return myExitTile;
}

void Map::ClearPath()
{

}
