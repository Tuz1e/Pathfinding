#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::Init()
{
}

void GameObject::Update(float aDelta)
{
}

void GameObject::Draw(sf::RenderWindow& aWindow)
{
}

std::string GameObject::GetName()
{
	return myName;
}

int GameObject::GetWeaponID()
{
	return myWeaponId;
}

int GameObject::GetBackpackSpace()
{
	return myBackpackSpace;
}

tx::Sprite GameObject::GetSprite()
{
	return mySprite;
}
