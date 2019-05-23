#ifndef MONSTER_H
#define MONSTER_H

#include "Entity.h"

class Monster : public Entity
{
public:
	Monster();
	~Monster();

	void
		SetDirection(tz::Vector2f& aPos),
		Update(float& aDelta) override,
		Draw(sf::RenderWindow& aWindow) override;

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
		myProvokeSight,
		myProvokeHit;
	int myVision;
	float mySpawnRate;
};

#endif //MONSTER_H
