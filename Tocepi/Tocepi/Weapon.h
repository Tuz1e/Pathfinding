#ifndef WEAPON_H
#define WEAPON_H

#include "pch.h"
#include "Object.h"
#include "File.h"
#include "TZ/GameKit.hpp"
#include "SFML/Graphics.hpp"
#include "TextureType.h"
#include <math.h>

#define PI 3.14159265358979323846

class Weapon : public Object
{
public:
	Weapon();
	Weapon(std::string aLocation, tz::Vector2f aPos);
	Weapon(std::string aLocation, float aX, float aY);
	~Weapon();

	void
		LoadWeapon(),
		Update(float& aDelta, tz::Vector2f aPos, sf::RenderWindow& aWindow),
		Draw(sf::RenderWindow& aWindow);

	std::string
		& GetDescription(),
		& GetRangeProjectileTextureLocation();
	int& GetDurability();
	float
		& GetBaseDamage(),
		& GetRotationSpeed();
	bool
		& GetRangeFlag(),
		& GetThrowableFlag(),
		& GetStunFlag();

private:
	std::string
		myProfileLocation,
		myDescription,
		myRangeProjectileTextureLocation;

	int myDurability;
	float
		myBaseDamage,
		myRotationSpeed;

	bool
		myRangeFlag,
		myThrowableFlag,
		myStunFlag;

	tz::Vector2f myPreviousMousePos;
};

#endif //WEAPON_H
