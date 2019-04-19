#ifndef ENTITY_H
#define ENTITY_H

#include "GameObject.h"

class Entity : public GameObject
{
public:
	Entity();
	~Entity();

	virtual tz::Vector2f 
		&GetVelocity(), 
		&GetSpeed();
	sf::IntRect GetBoundingBox();

protected:
	tz::Vector2f 
		myVelocity, 
		mySpeed;
	bool myCollidingFlag = false;
};

#endif //ENTITY_H