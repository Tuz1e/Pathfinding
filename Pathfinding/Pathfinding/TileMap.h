#ifndef TILEMAP_H
#define TILEMAP_H

#include "pch.h"
#include "File.h"
#include "Info.h"
#include "TZ/GameKit.hpp"
#include "SFML/Graphics.hpp"
#include "Sprite.h"

struct Tile
{
	tz::Vector2f Position;
	int TextureID;
};

class TileMap
{
public:
	TileMap(std::string aMapLocation);
	~TileMap();

	void LoadMapData();
	void Draw(sf::RenderWindow& aWindow);

private:
	void SetSprite();

	//Double vector to account for layers
	std::vector<std::vector<Tile>> myMap;
	int myWidth, myHeight, myLayerAmount;
	sf::Sprite* mySprite;
	std::string myTextureLocation, myMapLocation;
	sf::Texture myTexture;
	float myTileDimension, myTileScale;
};

#endif //TILEMAP_H