#ifndef TILEMAP_H
#define TILEMAP_H

#include "pch.h"
#include "File.h"
#include "Info.h"
#include "TZ/GameKit.hpp"
#include "SFML/Graphics.hpp"
#include "Sprite.h"
#include "Player.h"
#include "Tile.h"

class TileMap
{
public:
	TileMap(std::string aMapLocation, float aRenderOffset, float aFadeOffset);
	~TileMap();

	void
		LoadMapData(),
		Update(Player& aPlayer),
		Draw(sf::RenderWindow& aWindow, Player& aPlayer);

private:
	void
		LoadSprite(),
		LoadSheetData(std::vector<sf::IntRect>* someTextureTiles),
		CleanMapData(std::vector<std::vector<Tile>>* aMap),
		SetColliders(std::vector<std::vector<Tile>>* aMap);

	sf::Vector2f GetSFVector(tz::Vector2f aPos);

	std::vector<Tile> LoadMap(std::vector<std::vector<std::string>>* someMapData);
	bool IsCollidable(std::vector<std::string>& someData);

	//Double vector to account for multiple layers
	std::vector<std::vector<Tile>>* myMap;
	int myWidth, myHeight, myLayerAmount, mySheetSize, myRenderOffset, myFadeOffset;
	int mySheetHorizontalSize, mySheetVerticalSize; //x, y
	sf::Sprite* mySprite;
	std::string mySheetLocation, myMapLocation;
	sf::Texture mySheet;
	std::vector<sf::IntRect> myTextureTiles;
	float myMapTileDimension, myMapTileScale;
	std::vector<Tile> myCollidableTiles;
};

#endif //TILEMAP_H