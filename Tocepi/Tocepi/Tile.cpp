#include "Tile.h"



Tile::Tile() 
	: myTextureId(0)
{
	myPos = tz::Vector2f();
	myCollidableFlag = false;
}


Tile::Tile(tz::Vector2f aPos, int anID, bool aCollidable)
	: myTextureId(anID)
{
	myPos = aPos;
	myCollidableFlag = aCollidable;
}

Tile::~Tile()
{
}

int& Tile::GetTextureID()
{
	return myTextureId;
}

void Tile::SetBoundingBox(sf::IntRect aBoundingBox)
{
	myBoundingBox = aBoundingBox;
}

sf::IntRect Tile::GetBoundingBox()
{
	return myBoundingBox;
}
