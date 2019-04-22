#ifndef TILELAYER_H
#define TILELAYER_H

#include "pch.h"
#include "Tile.h"

class TileLayer
{
public:
	TileLayer();
	TileLayer(
		bool aCollisionStatement, 
		bool aTrapStatement, 
		bool aExitStatement, 
		bool aLootStatement, 
		bool aPlayerSpawnStatement,
		bool aEnemySpawnStatement);
	~TileLayer();

	void
		SetCollision(bool aStatement),
		SetTrapSpawn(bool aStatement),
		SetExit(bool aStatement),
		SetLoot(bool aStatement),
		SetPlayerSpawn(bool aStatement),
		SetEnemySpawn(bool aStatement),
		SetData(std::vector<Tile>& someData);

	bool 
		GetCollision(),
		GetTrapSpawn(),
		GetExit(),
		GetLoot(),
		GetPlayerSpawn(),
		GetEnemySpawn();

	std::vector<Tile>& GetData();

private:
	bool
		myCollision,
		myTrapSpawn,
		myExit,
		myLoot,
		myPlayerSpawn,
		myEnemySpawn;

	std::vector<Tile> myData;
};

#endif //TILELAYER_H