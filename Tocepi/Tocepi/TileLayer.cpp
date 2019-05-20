#include "TileLayer.h"

//TODO: Logic for trap spawning
//TODO: Logic for Exit locations
//TODO: Logic for enemy spawns

TileLayer::TileLayer()
{
	myCollidableFlag = false;
	myEnemySpawnFlag = false;
	myChestFlag = false;
	myTrapSpawnFlag = false;
	myDoorSpawnFlag = false;
}

TileLayer::TileLayer(float aRenderOffset, float aFadeOffset)
	: myRenderOffset(aRenderOffset), myFadeOffset(aFadeOffset)
{
	myCollidableFlag = false;
	myTrapSpawnFlag = false;
	myDoorSpawnFlag = false;
	myChestFlag = false;
	myPlayerSpawnFlag = false;
	myEnemySpawnFlag = false;
	myRenderFlag = false;
}

TileLayer::TileLayer(
	bool aCollisionStatement,
	bool aTrapStatement,
	bool aDoorStatement,
	bool aChestStatement,
	bool aPlayerSpawnStatement,
	bool aEnemySpawnStatement,
	bool aRenderStatement,
	float aRenderOffset,
	float aFadeOffset) :

	myCollidableFlag(aCollisionStatement),
	myTrapSpawnFlag(aTrapStatement),
	myDoorSpawnFlag(aDoorStatement),
	myChestFlag(aChestStatement),
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

		if (myFadeOffset > 0 && myRenderOffset > 0)
		{
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
		else
		{
			aSprite.setTextureRect(myData[i].GetBoundingBox());
			tempVec = sf::Vector2f(myData[i].GetPosition().X, myData[i].GetPosition().Y);
			aSprite.setPosition(tempVec);
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

bool TileLayer::GetCollisions()
{
	return myCollidableFlag;
}

bool TileLayer::GetRenderFlag()
{
	return myRenderFlag;
}

bool TileLayer::GetEnemySpawns()
{
	return myEnemySpawnFlag;
}

std::vector<Tile>& TileLayer::GetData()
{
	return myData;
}

bool TileLayer::GetPlayerSpawns()
{
	return myPlayerSpawnFlag;
}

bool TileLayer::GetLoot()
{
	return myChestFlag;
}

bool TileLayer::GetDoors()
{
	return myDoorSpawnFlag;
}

bool TileLayer::GetTrapSpawns()
{
	return myTrapSpawnFlag;
}

void TileLayer::SetPlayerSpawn(bool aStatement)
{
	myPlayerSpawnFlag = aStatement;
}

void TileLayer::SetDoors(bool aStatement)
{
	myDoorSpawnFlag = aStatement;
}

void TileLayer::SetChest(bool aStatement)
{
	myChestFlag = aStatement;
}

void TileLayer::SetTrapSpawn(bool aStatement)
{
	myTrapSpawnFlag = aStatement;
}
#pragma endregion
