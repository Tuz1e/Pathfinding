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
	sf::Vector2f Position;
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

	//Double vector to account for multiple layers
	std::vector<std::vector<Tile>> myMap;
	int myWidth, myHeight, myLayerAmount, mySpritesheetSize;
	int mySheetHorizontalSize, mySheetVerticalSize; //x, y
	sf::Sprite* mySprite;
	std::string myTextureLocation, myMapLocation;
	sf::Texture mySpritesheet;
	std::vector<sf::IntRect> mySpriteTiles;
	float myTileDimension, myTileScale;
};

#endif //TILEMAP_H