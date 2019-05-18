#ifndef MAP_H
#define MAP_H

//Copyright 2019 Pontuz Klasson

//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at

//http://www.apache.org/licenses/LICENSE-2.0

#include "SFML/Graphics.hpp"
#include "TileLayer.h"
#include "DataLoader.h"
#include "Player.h"

class Map
{
public:
	Map(std::string aLocation, float aRenderOffset, float aFadeOffset);
	~Map();

	void
		LoadData(),
		Update(Player& aPlayer),
		Draw(sf::RenderWindow& aWindow, Player& aPlayer);

	int
		& GetLayersAmount(),
		& GetWidth(),
		& GetHeight(),
		& GetHorizontalSize(),
		& GetVerticalSize();

	float
		& GetTileDimension(),
		& GetScale();;

	std::string
		& GetTextureLocation(),
		& GetLocation();

	bool& GetLoadedFlag();

	std::vector<TileLayer>* GetLayers();

private:
	void
		LoadSheetData(std::vector<sf::IntRect>* someTextureTiles),
		LoadSprite(sf::Sprite& aSprite, sf::Texture* aSheet),
		SetColliders(std::vector<Tile>* aLayer, sf::Sprite& aSprite);

	std::vector<Tile>
		GetTileData(std::vector<std::string>* someData),
		CleanData(std::vector<Tile>& aLayer);

	int
		myLayerAmount,
		myWidth,
		myHeight,
		mySheetHorizontalSize,
		mySheetVerticalSize,
		mySheetSize;

	float
		myTileScale,
		myTileDimension,
		myRenderOffset,
		myFadeOffset;
	std::string
		myName,
		myTextureLocation,
		myDataLocation;

	bool myLoadedFlag = false;

	sf::Texture mySheet;
	sf::Sprite* mySprite;
	std::vector<sf::IntRect>* myTextureTiles;
	std::vector<TileLayer>* myLayers;
	DataLoader myDataLoader;
};

#endif //MAP_H
