#include "Monster.h"

Monster::Monster()
{
}

Monster::Monster(
	std::string aName,
	int someHealth,
	int aVision,
	float aSpawnRate,
	float aBaseDamage,
	bool aToxicFlag,
	bool aBleedFlag,
	bool aProvokeSightFlag,
	bool aProvokeHitFlag
)
	: myVision(aVision), mySpawnRate(aSpawnRate),
	myBaseDamage(aBaseDamage), myToxicFlag(aToxicFlag), 
	myBleedFlag(aBleedFlag),
	myProvokeSightFlag(aProvokeSightFlag),
	myProvokeHitFlag(aProvokeHitFlag)
{
	myName = aName;
	myHealth = someHealth;
	myProvokedFlag = (aProvokeSightFlag) ? true : false;
	myGotHitFlag = false;
	myAliveFlag = true;
}

Monster::~Monster()
{
}

void Monster::Update(float& aDelta, tz::Vector2f& aPos)
{
	if (!myAliveFlag)
	{
		return;
	}

	if ((myGotHitFlag && myProvokeHitFlag || myProvokeSightFlag) && !myProvokedFlag)
	{
		myProvokedFlag = true;
	}

	//TODO: Turn into a method
	if (myGotHitFlag)
	{
		if (myGotHitCounter <= 0)
		{
			myGotHitFlag = false;
		}
		else
		{
			myGotHitCounter -= (1 * aDelta);
		}
	}

	if (myHasHitFlag)
	{
		if (myHasHitCounter <= 0)
		{
			myHasHitFlag = false;
		}
		else
		{
			myHasHitCounter -= (1 * aDelta);
		}
	}

	if (myProvokedFlag)
	{
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
				myProvokedFlag = false;
			}
		}
	}
	myCollidingFlag = false;
	mySprite->UpdateAnimation(aDelta);
}

void Monster::Draw(sf::RenderWindow& aWindow)
{
	if (!myAliveFlag)
	{
		return;
	}
	mySprite->Draw(aWindow);
}

void Monster::SetToxicFlag(bool aStatement)
{
	myToxicFlag = aStatement;
}

void Monster::SetBaseDamage(float aBaseDamage)
{
	myBaseDamage = aBaseDamage;
}

void Monster::SetSpawnRate(int aSpawnRate)
{
	mySpawnRate = aSpawnRate;
}

void Monster::SetHasHit(bool aStatement)
{
	myHasHitFlag = aStatement;

	if (aStatement)
	{
		myHasHitCounter = 15;
	}
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

float& Monster::GetBaseDamage()
{
	return myBaseDamage;
}

bool& Monster::GetProvokeHitFlag()
{
	return myProvokeHitFlag;
}

bool Monster::GetHasHitFlag()
{
	return myHasHitFlag;
}

int& Monster::GetVision()
{
	return myVision;
}

float& Monster::GetSpawnRate()
{
	return mySpawnRate;
}

bool& Monster::GetProvokeSightFlag()
{
	return myProvokeSightFlag;
}

bool& Monster::GetBleedFlag()
{
	return myBleedFlag;
}
