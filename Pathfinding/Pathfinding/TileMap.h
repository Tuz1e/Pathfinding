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
	sf::Sprite Sprite;
};

class TileMap
{
public:
	TileMap(std::string aMapLocation);
	~TileMap();

	void LoadMapData();
	void Draw(sf::RenderWindow& aWindow);

private:
	void LoadTexture();

	std::vector<Tile> myMap;
	int myWidth, myHeight;
	tx::Sprite* mySprite;
	std::string myTextureLocation, myMapLocation;
	sf::Texture myTexture;
	float myTileDimension;
};

#endif //TILEMAP_H