#ifndef INPUT_H
#define INPUT_H

#include "SFML/Window/Keyboard.hpp"

class Input
{
public:
	Input();
	~Input();

	bool GetLeftKeyPressed(), GetRightKeyPressed(), GetUpKeyPressed(), GetDownKeyPressed(),
		KeyLocked(sf::Keyboard::Key aKey);

	void SetLockKey(sf::Keyboard::Key aKey);

	sf::Keyboard::Key
		GetLeftKey(),
		GetRightKey(),
		GetUpKey(),
		GetDownKey(),
		GetPreviousKey(),
		GetLockedKey();

private:
	sf::Keyboard::Key
		myUpKey = sf::Keyboard::W,
		myDownKey = sf::Keyboard::S,
		myLeftKey = sf::Keyboard::A,
		myRightKey = sf::Keyboard::D,
		myPreviousKey = sf::Keyboard::N,
		myLockedKey = sf::Keyboard::N;
};

#endif //INPUT_H
