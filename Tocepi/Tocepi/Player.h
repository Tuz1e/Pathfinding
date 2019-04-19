#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Input.h"

class TileMap;

class Player : public Entity
{
public:
	Player();
	Player(tz::Vector2f aPos);
	Player(float x, float y);
	~Player();

	void
		Init(Input& anInput),
		Update(float& aDelta),
		Draw(sf::RenderWindow& aWindow);

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

	bool myCorrectingFlag;
};

#endif //PLAYER_H