#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "pch.h"
#include "SFML/Graphics.hpp"
#include "Sprite.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void 
		Init(), 
		Update(float& aDelta), 
		Draw(sf::RenderWindow& aWindow);

	std::string GetName();
	int& GetWeaponID(), &GetBackpackSpace();
	tx::Sprite* GetSprite();
	tz::Vector2f& GetPosition();

protected:
	std::string 
		myTextureLocation, 
		myName;
	int 
		myWeaponId, 
		myBackpackSpace;
	tx::Sprite* mySprite;
	tz::Vector2f myPos, mySpeed;
};

#endif //GAMEOBJECT_H