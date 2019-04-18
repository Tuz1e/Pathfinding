#include "GameObject.h"

//TODO: Bounding Box

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
	DelPtr(mySprite);
}

void GameObject::Init()
{
}

void GameObject::Update(float& aDelta)
{
}

void GameObject::Draw(sf::RenderWindow& aWindow)
{
}

std::string GameObject::GetName()
{
	return myName;
}

int& GameObject::GetWeaponID()
{
	return myWeaponId;
}

int& GameObject::GetBackpackSpace()
{
	return myBackpackSpace;
}

tx::Sprite* GameObject::GetSprite()
{
	return mySprite;
}

tz::Vector2f& GameObject::GetPosition()
{
	return myPos;
}

sf::IntRect GameObject::GetBoundingBox()
{
	return mySprite->GetFrame();
}
