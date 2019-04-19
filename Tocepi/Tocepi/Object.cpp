#include "Object.h"



Object::Object()
{
}


Object::~Object()
{
}

void Object::SetSprite(sf::Sprite& aSprite)
{
	mySprite = new tx::Sprite(aSprite);
}
