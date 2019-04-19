#ifndef INPUT_H
#define INPUT_H

#include "SFML/Window/Keyboard.hpp"

class Input
{
public:
	Input();
	~Input();

	bool GetLeftKey(), GetRightKey(), GetUpKey(), GetDownKey();

private:
	sf::Keyboard::Key 
		myUpKey = sf::Keyboard::W,
		myDownKey = sf::Keyboard::S,
		myLeftKey = sf::Keyboard::A,
		myRightKey = sf::Keyboard::D;
};

#endif //INPUT_H