#ifndef ENTITY_H
#define ENTITY_H

#include "GameObject.h"

class Entity : public GameObject
{
public:
	Entity();
	~Entity();

	virtual tz::Vector2f
		& GetVelocity(),
		& GetSpeed();
	sf::IntRect GetBoundingBox();

	float& GetHealth();
	void ModifyHealth(float& someDamage);
	void LoadDefaults(std::string aLocation = "");

protected:
	tz::Vector2f
		myVelocity,
		mySpeed;
	TextureType myTextureType;
	std::string myProfileLocation;
	float myHealth;
	bool myCollidingFlag = false,
		myToxicInfectedFlag,
		myBleedingFlag;
};

#endif //ENTITY_H
