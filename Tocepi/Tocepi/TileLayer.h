#ifndef TILELAYER_H
#define TILELAYER_H

//Copyright 2019 Pontuz Klasson

//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at

//http ://www.apache.org/licenses/LICENSE-2.0

#include "pch.h"
#include "Tile.h"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "TZ/GameKit.hpp"

#define COLLIDABLE "Collision"
#define TRAPSPAWN "TrapSpawn"
#define DOOR "Door"
#define CHESTSPAWN "Chest"
#define PLAYERSPAWN "PlayerSpawn"
#define ENEMYSPAWN "EnemySpawn"
#define RENDERABLE "Renderable"

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
