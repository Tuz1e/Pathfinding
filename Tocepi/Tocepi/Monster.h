#ifndef MONSTER_H
#define MONSTER_H

#include "Entity.h"

class Monster : public Entity
{
public:
	Monster();
	Monster(
		std::string aName,
		int someHealth,
		int aVision,
		float aSpawnRate,
		float aBaseDamage,
		bool aToxicFlag,
		bool aBleedFlag,
		bool aProvokeSightFlag,
		bool aProvokeHitFlag
	);
	~Monster();

	void
		Update(float& aDelta, tz::Vector2f& aPos),
		Draw(sf::RenderWindow& aWindow) override;

	void SetToxicFlag(bool aStatement),
		SetBleedFlag(bool aStatement),
		SetProvokeSightFlag(bool aStatement),
		SetProvokeHitFlag(bool aStatement),
		SetVisionFlag(int aVision),
		SetSpawnRate(int aSpawnRate),
		SetBaseDamage(float aBaseDamage);

	void SetHasHit(bool aStatement);

	bool SetDestination(tz::Vector2f& aPos);

	bool
		& GetToxicFlag(),
		& GetBleedFlag(),
		& GetProvokeSightFlag(),
		& GetProvokeHitFlag();

	bool GetHasHitFlag();

	int& GetVision();
	float
		& GetSpawnRate(),
		& GetBaseDamage();

private:
	tz::Vector2f myDestination;
	bool
		myToxicFlag,
		myBleedFlag,
		myProvokeSightFlag,
		myProvokeHitFlag,
		myProvokedFlag,
		myGotHitFlag,
		myHasHitFlag;
	int myVision;
	float
		mySpawnRate, 
		myHasHitCounter,
		myBaseDamage;
};

#endif //MONSTER_H
