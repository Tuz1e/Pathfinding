#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Input.h"

class Player : public GameObject
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
	sf::Vector2f GetVelocity();

private:
	void LoadDefaults();
	Input myInput;

	tz::Vector2f myVelocity;
};

#endif //PLAYER_H