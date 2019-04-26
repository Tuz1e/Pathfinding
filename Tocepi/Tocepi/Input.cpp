#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}

bool Input::GetLeftKeyPressed()
{
	if (sf::Keyboard::isKeyPressed(myLeftKey) && myLockedKey != myLeftKey)
	{
		myPreviousKey = myLeftKey;
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::KeyLocked(sf::Keyboard::Key aKey)
{
	return (aKey == myLockedKey) ? true : false;
}

bool Input::GetRightKeyPressed()
{
	if (sf::Keyboard::isKeyPressed(myRightKey) && myLockedKey != myRightKey)
	{
		myPreviousKey = myRightKey;
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::GetUpKeyPressed()
{
	if (sf::Keyboard::isKeyPressed(myUpKey) && myLockedKey != myUpKey)
	{
		myPreviousKey = myUpKey;
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::GetDownKeyPressed()
{
	if (sf::Keyboard::isKeyPressed(myDownKey) && myLockedKey != myDownKey)
	{
		myPreviousKey = myDownKey;
		return true;
	}
	else
	{
		return false;
	}
}

void Input::SetLockKey(sf::Keyboard::Key aKey)
{
	myLockedKey = aKey;
}

sf::Keyboard::Key Input::GetPreviousKey()
{
	return myPreviousKey;
}

sf::Keyboard::Key Input::GetLockedKey()
{
	return myLockedKey;
}

sf::Keyboard::Key Input::GetDownKey()
{
	return myDownKey;
}

sf::Keyboard::Key Input::GetUpKey()
{
	return myUpKey;
}

sf::Keyboard::Key Input::GetRightKey()
{
	return myRightKey;
}

sf::Keyboard::Key Input::GetLeftKey()
{
	return myLeftKey;
}
