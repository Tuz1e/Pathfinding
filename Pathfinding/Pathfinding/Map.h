#ifndef MAP_H
#define MAP_H

#include "TZ/GameKit.hpp"

#include "Tile.h"

#include <vector>

struct Tile 
{
	
};

class Map
{
public:
	Map();
	Map(int aTileSize, int aWindowWidth, int aWindowHeight, tz::Vector2i aStartPos, tz::Vector2i aEndPos);
	~Map();

	const Tile &getStartTile() const;
	const Tile &getExitTile() const;

private:
	int
		myTileSize,
		myHorizontalTiles,
		myWindowWidth,
		myWindowHeight;

	std::vector<Tile> myTiles;

	Tile myStartTile, myExitTile;

	bool OutOfBounds(tz::Vector2i aPos);
	bool Walkable(tz::Vector2i aPos);

	void ClearPath();

};

#endif //MAP_H