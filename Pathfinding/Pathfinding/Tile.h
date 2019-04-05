#ifndef TILE_H
#define TILE_H

#include "TZ/GameKit.hpp"

enum TileType {
	Start,
	Target,
	Path,
	Empty,
	Block
};

class Tile
{
public:
	Tile();
	~Tile();

	tz::Vector2i myPos; //Position
	tz::Vector2i myParentsPos; //Parent Position

	TileType myType;

	float myGCost, myHCost, myFCost;

};

#endif //TILE_H