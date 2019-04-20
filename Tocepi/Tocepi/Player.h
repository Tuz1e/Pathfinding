#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Input.h"
#include "DataLoader.h"

#define PLAYER_ELF "Content/profiles/player/player_elf.xml"

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
	bool myCorrectingFlag = false, myMovingFlag = false;
	DataLoader myDataLoader;
	TextureType myTextureType;
};

#endif //PLAYER_H