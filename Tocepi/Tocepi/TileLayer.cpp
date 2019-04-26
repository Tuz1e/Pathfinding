#include "TileLayer.h"

//Copyright 2019 Pontuz Klasson

//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at

//http ://www.apache.org/licenses/LICENSE-2.0

//TODO: Logic for trap spawning
//TODO: Logic for Exit locations
//TODO: Logic for enemy spawns

TileLayer::TileLayer()
{
	
}


TileLayer::TileLayer(
	bool aCollisionStatement, 
	bool aTrapStatement, 
	bool aExitStatement,
	bool aLootStatement, 
	bool aPlayerSpawnStatement, 
	bool aEnemySpawnStatement, 
	bool aRenderStatement,
	float aRenderOffset, 
	float aFadeOffset):

	myCollidableFlag(aCollisionStatement),
	myTrapSpawnFlag(aTrapStatement),
	myExitFlag(aExitStatement),
	myLootFlag(aLootStatement),
	myPlayerSpawnFlag(aPlayerSpawnStatement),
	myEnemySpawnFlag(aEnemySpawnStatement),
	myRenderFlag(aRenderStatement),
	myRenderOffset(aRenderOffset),
	myFadeOffset(aFadeOffset) 
{}

TileLayer::~TileLayer()
{
}

void TileLayer::DrawCollisionBoxes(sf::RenderWindow& aWindow, Player& aPlayer)
{
	if (myCollidableFlag)
	{
		float tempDis;
		for (size_t i = 0; i < myData.size(); i++)
		{
			tempDis = tz::DisBetweenVec(aPlayer.GetPosition(), myData[i].GetPosition());

			if (tempDis < myFadeOffset)
			{
				myData[i].DrawBody(aWindow);
			}
		}
	}
}

void TileLayer::Draw(sf::RenderWindow& aWindow, Player& aPlayer, sf::Sprite& aSprite)
{
	float tempDis;
	sf::Color tempC;
	sf::Vector2f tempVec;

	for (size_t i = 0; i < myData.size(); i++)
	{
		tempDis = tz::DisBetweenVec(aPlayer.GetPosition(), myData[i].GetPosition());

		if (tempDis < myFadeOffset)
		{
			aSprite.setTextureRect(myData[i].GetBoundingBox());

			
			tempVec = sf::Vector2f(myData[i].GetPosition().X, myData[i].GetPosition().Y);
			aSprite.setPosition(tempVec);

			tempC = aSprite.getColor();
			tempC.a = (tempDis > myRenderOffset) ? 175 : 255;

			aSprite.setColor(tempC);
			aWindow.draw(aSprite);
		}
	}
}

#pragma region Get&Set
void TileLayer::SetCollidable(bool aStatement)
{
	myCollidableFlag = aStatement;
}

void TileLayer::SetRenderFlag(bool aStatement)
{
	myRenderFlag = aStatement;
}

void TileLayer::SetData(std::vector<Tile>& someData)
{
	myData = someData;
}

void TileLayer::SetEnemySpawn(bool aStatement)
{
	myEnemySpawnFlag = aStatement;
}

bool TileLayer::GetCollision()
{
	return myCollidableFlag;
}

bool TileLayer::GetRenderFlag()
{
	return myRenderFlag;
}

bool TileLayer::GetEnemySpawn()
{
	return myEnemySpawnFlag;
}

std::vector<Tile>& TileLayer::GetData()
{
	return myData;
}

bool TileLayer::GetPlayerSpawn()
{
	return myPlayerSpawnFlag;
}

bool TileLayer::GetLoot()
{
	return myLootFlag;
}

bool TileLayer::GetExit()
{
	return myExitFlag;
}

bool TileLayer::GetTrapSpawn()
{
	return myTrapSpawnFlag;
}

void TileLayer::SetPlayerSpawn(bool aStatement)
{
	myPlayerSpawnFlag = aStatement;
}

void TileLayer::SetExit(bool aStatement)
{
	myExitFlag = aStatement;
}

void TileLayer::SetLoot(bool aStatement)
{
	myLootFlag = aStatement;
}

void TileLayer::SetTrapSpawn(bool aStatement)
{
	myTrapSpawnFlag = aStatement;
}
#pragma endregion