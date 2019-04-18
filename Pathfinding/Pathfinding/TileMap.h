#ifndef TILEMAP_H
#define TILEMAP_H

#include "pch.h"
#include "File.h"
#include "Info.h"
#include "TZ/GameKit.hpp"
#include "SFML/Graphics.hpp"
#include "Sprite.h"
#include "Player.h"

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
	void Draw(sf::RenderWindow& aWindow, Player& aPlayer, float& aRenderOffset, float& aFadeOffset);

private:
	void 
		LoadSprite(), 
		LoadSheetData(std::vector<sf::IntRect>* someTextureTiles),
		CleanMapData(std::vector<std::vector<Tile>>* aMap);

	std::vector<Tile> LoadMap(std::vector<std::vector<std::string>>* someMapData);

	//Double vector to account for multiple layers
	std::vector<std::vector<Tile>>* myMap;
	int myWidth, myHeight, myLayerAmount, mySheetSize;
	int mySheetHorizontalSize, mySheetVerticalSize; //x, y
	sf::Sprite* mySprite;
	std::string mySheetLocation, myMapLocation;
	sf::Texture mySheet;
	std::vector<sf::IntRect> myTextureTiles;
	float myMapTileDimension, myMapTileScale;
};

#endif //TILEMAP_H