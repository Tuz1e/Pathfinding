#ifndef INPUT_H
#define INPUT_H

#include "SFML/Window/Keyboard.hpp"

class Input
{
public:
	Input();
	~Input();

	bool GetJumpKey(), GetLeftKey(), GetRightKey();

private:
	sf::Keyboard::Key myJumpKey = sf::Keyboard::Space;
	sf::Keyboard::Key myLeftKey = sf::Keyboard::A;
	sf::Keyboard::Key myRightKey = sf::Keyboard::D;
};

#endif //INPUT_H