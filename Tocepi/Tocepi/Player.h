#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Input.h"
#include "Weapon.h"

#define PLAYER_ELF "Content/profiles/characters/character_elf.xml"

#define WEAPON_DEV "Content/profiles/items/weapons/weapon_sword_of_camelot.xml"

class Player : public Entity
{
public:
	Player();
	Player(tz::Vector2f aPos);
	Player(float x, float y);
	~Player();

	void
		Init(Input& anInput),
		Update(float& aDelta, sf::RenderWindow& aWindow),
		Draw(sf::RenderWindow& aWindow, sf::View& aView);

	Weapon* GetWeapon();
	void SetColliding(bool aCollisionFlag);

	int 
		&GetWeaponID(), 
		&GetBackpackSpace();

private:
	void LoadDefaults();

	Input myInput;
	int
		myWeaponId,
		myBackpackSpace;
	bool 
		myCorrectingFlag = false, 
		myMovingFlag = false;
	TextureType myTextureType;
	Weapon* myWeapon;
};

#endif //PLAYER_H