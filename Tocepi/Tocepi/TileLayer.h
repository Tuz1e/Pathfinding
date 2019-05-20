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
		float aRenderOffset,
		float aFadeOffset);
	TileLayer(
		bool aCollisionStatement,
		bool aTrapStatement,
		bool aDoorStatement,
		bool aChestStatement,
		bool aPlayerSpawnStatement,
		bool aEnemySpawnStatement,
		bool aRenderStatement,
		float aRenderOffset,
		float aFadeOffset);
	~TileLayer();

	void
		Draw(sf::RenderWindow& aWindow, Player& aPlayer, sf::Sprite& aSprite),
		DrawCollisionBoxes(sf::RenderWindow& aWindow, Player& aPlayer);

	void
		SetCollidable(bool aStatement),
		SetTrapSpawn(bool aStatement),
		SetDoors(bool aStatement),
		SetChest(bool aStatement),
		SetPlayerSpawn(bool aStatement),
		SetEnemySpawn(bool aStatement),
		SetRenderFlag(bool aStatement),
		SetData(std::vector<Tile>& someData);

	bool
		GetCollisions(),
		GetTrapSpawns(),
		GetDoors(),
		GetLoot(),
		GetPlayerSpawns(),
		GetEnemySpawns(),
		GetRenderFlag();

	std::vector<Tile>& GetData();

private:
	bool
		myCollidableFlag,
		myTrapSpawnFlag,
		myDoorSpawnFlag,
		myChestFlag,
		myPlayerSpawnFlag,
		myEnemySpawnFlag,
		myRenderFlag;

	float
		myRenderOffset,
		myFadeOffset;

	std::vector<Tile> myData;
};

#endif //TILELAYER_H
