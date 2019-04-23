#ifndef TILELAYER_H
#define TILELAYER_H

#include "pch.h"
#include "Tile.h"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "TZ/GameKit.hpp"

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
		bool aEnemySpawnStatement,
		float aRenderOffset,
		float aFadeOffset);
	~TileLayer();

	void 
		Draw(sf::RenderWindow& aWindow, Player& aPlayer, sf::Sprite& aSprite),
		DrawCollisionBoxes(sf::RenderWindow& aWindow, Player& aPlayer);

	void
		SetCollidable(bool aStatement),
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
		myCollidableFlag,
		myTrapSpawnFlag,
		myExitFlag,
		myLootFlag,
		myPlayerSpawnFlag,
		myEnemySpawnFlag;

	float 
		myRenderOffset,
		myFadeOffset;

	std::vector<Tile> myData;
};

#endif //TILELAYER_H