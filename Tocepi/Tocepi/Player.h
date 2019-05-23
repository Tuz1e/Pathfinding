#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Input.h"
#include "Weapon.h"

#define PLAYER_CHARACTER "Content/profiles/characters/character_elf_m.xml"

#define WEAPON_DEV "Content/profiles/items/weapons/weapon_dev_sword.xml"

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
		& GetWeaponID(),
		& GetBackpackSpace();

private:
	Input myInput;
	int
		myWeaponId,
		myBackpackSpace;
	bool
		myCorrectingFlag = false,
		myMovingFlag = false;
	Weapon* myWeapon;
};

#endif //PLAYER_H
