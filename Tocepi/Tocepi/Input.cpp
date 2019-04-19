#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}

bool Input::GetLeftKey()
{
	return (sf::Keyboard::isKeyPressed(myLeftKey)) ? true : false;
}

bool Input::GetRightKey()
{
	return (sf::Keyboard::isKeyPressed(myRightKey)) ? true : false;
}

bool Input::GetUpKey()
{
	return (sf::Keyboard::isKeyPressed(myUpKey)) ? true : false;
}

bool Input::GetDownKey()
{
	return (sf::Keyboard::isKeyPressed(myDownKey)) ? true : false;
}
