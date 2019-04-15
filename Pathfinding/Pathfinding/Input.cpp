#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}

bool Input::GetJumpKey()
{
	return (sf::Keyboard::isKeyPressed(myJumpKey)) ? true : false;
}

bool Input::GetLeftKey()
{
	return (sf::Keyboard::isKeyPressed(myLeftKey)) ? true : false;
}

bool Input::GetRightKey()
{
	return (sf::Keyboard::isKeyPressed(myRightKey)) ? true : false;
}
