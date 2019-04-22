#include "TileLayer.h"



TileLayer::TileLayer()
{
}


TileLayer::TileLayer(bool aCollisionStatement, bool aTrapStatement, bool aExitStatement, bool aLootStatement, bool aPlayerSpawnStatement, bool aEnemySpawnStatement):
	myCollision(aCollisionStatement),
	myTrapSpawn(aTrapStatement),
	myExit(aExitStatement),
	myLoot(aLootStatement),
	myPlayerSpawn(aPlayerSpawnStatement),
	myEnemySpawn(aEnemySpawnStatement)
{
}

TileLayer::~TileLayer()
{
}

void TileLayer::SetCollision(bool aStatement)
{
	myCollision = aStatement;
}

void TileLayer::SetData(std::vector<Tile>& someData)
{
	myData = someData;
}

void TileLayer::SetEnemySpawn(bool aStatement)
{
	myEnemySpawn = aStatement;
}

bool TileLayer::GetCollision()
{
	return myCollision;
}

bool TileLayer::GetEnemySpawn()
{
	return myEnemySpawn;
}

std::vector<Tile>& TileLayer::GetData()
{
	return myData;
}

bool TileLayer::GetPlayerSpawn()
{
	return myPlayerSpawn;
}

bool TileLayer::GetLoot()
{
	return myLoot;
}

bool TileLayer::GetExit()
{
	return myExit;
}

bool TileLayer::GetTrapSpawn()
{
	return myTrapSpawn;
}

void TileLayer::SetPlayerSpawn(bool aStatement)
{
	myPlayerSpawn = aStatement;
}

void TileLayer::SetExit(bool aStatement)
{
	myExit = aStatement;
}

void TileLayer::SetLoot(bool aStatement)
{
	myLoot = aStatement;
}

void TileLayer::SetTrapSpawn(bool aStatement)
{
	myTrapSpawn = aStatement;
}
