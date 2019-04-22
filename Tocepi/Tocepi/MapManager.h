#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "pch.h"
#include "Map.h"

class MapManager
{
public:
	MapManager(std::string aTextureLocation);
	~MapManager();

private:
	std::vector<Map>* myMaps;
};

#endif //MAPMANAGER_H