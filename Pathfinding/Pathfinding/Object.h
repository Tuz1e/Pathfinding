#ifndef OBJECT_H
#define OBJECT_H

#include "GameObject.h"

class Object : public GameObject
{
public:
	Object();
	~Object();

	void SetSprite(sf::Sprite& aSprite);
};

#endif //OBJECT_H