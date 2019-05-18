#ifndef TILE_H
#define TILE_H

#include "Object.h"

//TODO: Remove Collidable Flag, it is redundant with the reformed tilemap loader

class Tile : public Object
{
public:
	Tile();
	Tile(tz::Vector2f aPos, int anID);
	Tile(tz::Vector2f aPos, int anID, bool aCollidable);
	~Tile();

	int& GetTextureID();

	void SetBoundingBox(sf::IntRect aBoundingBox);
	sf::IntRect GetBoundingBox();

protected:
	int myTextureId;
	sf::IntRect myBoundingBox;
};

#endif //TILE_H
