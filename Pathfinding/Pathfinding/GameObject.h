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

	void Init();
	void Update(float aDelta);
	void Draw(sf::RenderWindow& aWindow);

	std::string GetName();
	int GetWeaponID();
	int GetBackpackSpace();
	tx::Sprite GetSprite();

private:
	std::string myTextureLocation, myName;
	int myWeaponId, myBackpackSpace;
	tx::Sprite mySprite;
};

#endif //GAMEOBJECT_H