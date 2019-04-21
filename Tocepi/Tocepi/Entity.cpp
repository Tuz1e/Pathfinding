#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

tz::Vector2f& Entity::GetVelocity()
{
	return myVelocity;
}

tz::Vector2f& Entity::GetSpeed()
{
	return mySpeed;
}

sf::IntRect Entity::GetBoundingBox()
{
	return sf::IntRect(
		myPos.X,
		myPos.Y + (mySprite->GetFrame().height * 0.75f),
		mySprite->GetFrame().width,
		mySprite->GetFrame().height * 0.25f);
}
