#include "Monster.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::Update(float& aDelta)
{
}

void Monster::Draw(sf::RenderWindow& aWindow)
{
}

void SetDirection(tz::Vector2f& aPos)
{
}

bool& Monster::GetToxicFlag()
{
	return myToxicFlag;
}

bool& Monster::GetProvokeHit()
{
	return myProvokeHit;
}

int& Monster::GetVision()
{
	return myVision;
}

float& Monster::GetSpawnRate()
{
	return mySpawnRate;
}

bool& Monster::GetProvokeSight()
{
	return myProvokeSight;
}

bool& Monster::GetBleedFlag()
{
	return myBleedFlag;
}
