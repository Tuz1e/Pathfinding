#ifndef MAP_H
#define MAP_H

#include "TileLayer.h"
#include "DataLoader.h"

class Map
{
public:
	Map(std::string aLocation);
	~Map();

	void LoadData();

	int
		&GetLayersAmount(),
		&GetWidth(),
		&GetHeight(),
		&GetTileDimension(),
		&GetHorizontalSize(),
		&GetVerticalSize();

	std::string 
		&GetTextureLocation(),
		&GetLocation();

	sf::Vector2f& GetScale();

	std::vector<TileLayer>& GetLayers();

private:
	int 
		myLayerAmount, 
		myWidth, 
		myHeight,
		myTileDimension,
		myHorizontalSize,
		myVerticalSize,
		mySheetSize;

	sf::Vector2i myScale;
	std::string 
		myName,
		myTextureLocation,
		myDataLocation;

	std::vector<TileLayer> myLayers;

	DataLoader myDataLoader;
};

#endif //MAP_H