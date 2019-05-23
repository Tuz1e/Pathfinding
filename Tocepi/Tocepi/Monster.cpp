#include "Monster.h"

Monster::Monster()
{
}

Monster::Monster(
	std::string aName,
	int someHealth,
	int aVision,
	float aSpawnRate,
	bool aToxicFlag,
	bool aBleedFlag,
	bool aProvokeSightFlag,
	bool aProvokeHitFlag
)
	: myVision(aVision), mySpawnRate(aSpawnRate),
	myToxicFlag(aToxicFlag), myBleedFlag(aBleedFlag),
	myProvokeSightFlag(aProvokeSightFlag),
	myProvokeHitFlag(aProvokeHitFlag)
{
	myName = aName;
	myHealth = someHealth;
	myProvokedFlag = false;
	myGotHitFlag = false;
}

Monster::~Monster()
{
}

void Monster::Update(float& aDelta, tz::Vector2f& aPos)
{
	if ((myProvokeSightFlag || myProvokeHitFlag) && !myProvokedFlag)
	{
		myProvokedFlag = true;
	}

	if (myProvokedFlag)
	{
		//TODO: Monster move logic

		if (SetDestination(aPos))
		{
			SetPosition(myPos + (myDestination * mySpeed * aDelta));
			myBody.setPosition(GetBoundingBox().left, GetBoundingBox().top);

			if (myTextureType != TextureType::RUN)
			{
				myTextureType = TextureType::RUN;
				mySprite->SetTexture(myTextureType);
			}
		}
		else
		{
			if (myTextureType != TextureType::IDLE)
			{
				myTextureType = TextureType::IDLE;
				mySprite->SetTexture(myTextureType);
			}
		}
	}
	myCollidingFlag = false;
	mySprite->UpdateAnimation(aDelta);
}

void Monster::Draw(sf::RenderWindow& aWindow)
{
	mySprite->Draw(aWindow);
}

void Monster::SetToxicFlag(bool aStatement)
{
	myToxicFlag = aStatement;
}

void Monster::SetSpawnRate(int aSpawnRate)
{
	mySpawnRate = aSpawnRate;
}

void Monster::SetVisionFlag(int aVision)
{
	myVision = aVision;
}

void Monster::SetProvokeHitFlag(bool aStatement)
{
	myProvokeHitFlag = aStatement;
}

void Monster::SetProvokeSightFlag(bool aStatement)
{
	myProvokeSightFlag = aStatement;
}

void Monster::SetBleedFlag(bool aStatement)
{
	myBleedFlag = aStatement;
}

bool Monster::SetDestination(tz::Vector2f& aPos)
{
	if (tz::DisBetweenVec(myPos, aPos) <= myVision || myVision == 0)
	{
		myDestination = aPos - myPos;

		//If myDestination does not equal vector2f().zero
		if (myDestination != tz::Vector2f())
		{
			myDestination.Normalize();
		}
		return true;
	}
	return false;
}

bool& Monster::GetToxicFlag()
{
	return myToxicFlag;
}

bool& Monster::GetProvokeHit()
{
	return myProvokeHitFlag;
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
	return myProvokeSightFlag;
}

bool& Monster::GetBleedFlag()
{
	return myBleedFlag;
}
