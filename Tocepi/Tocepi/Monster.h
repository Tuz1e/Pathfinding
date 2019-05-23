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
		SetSpawnRate(int aSpawnRate);

	bool SetDestination(tz::Vector2f& aPos);

	bool
		& GetToxicFlag(),
		& GetBleedFlag(),
		& GetProvokeSight(),
		& GetProvokeHit();

	int& GetVision();
	float& GetSpawnRate();

private:
	tz::Vector2f myDestination;
	bool
		myToxicFlag,
		myBleedFlag,
		myProvokeSightFlag,
		myProvokeHitFlag,
		myProvokedFlag,
		myGotHitFlag;
	int myVision;
	float mySpawnRate;
};

#endif //MONSTER_H
