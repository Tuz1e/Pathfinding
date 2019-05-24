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
	void ModifyHealth(float& someDamage);
	void LoadDefaults(std::string aLocation = "");

	void SetHit(float someDamage);
	
	bool &GetAliveFlag();

	float& GetHealth();

protected:
	tz::Vector2f
		myVelocity,
		mySpeed;
	TextureType myTextureType;
	std::string myProfileLocation;
	float 
		myHealth, 
		myGotHitCounter;
	bool 
		myCollidingFlag = false,
		myToxicInfectedFlag,
		myBleedingFlag;

	bool 
		myAliveFlag, 
		myGotHitFlag = false;
};

#endif //ENTITY_H
