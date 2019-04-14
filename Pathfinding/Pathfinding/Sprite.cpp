#include "Sprite.h"



tx::Sprite::Sprite()
{
}


tx::Sprite::~Sprite()
{
}

void tx::Sprite::SetAnimation(int someColumns, int someRows)
{
}

void tx::Sprite::UpdateAnimation()
{
}

sf::Sprite tx::Sprite::GetSprite()
{
	return mySprite;
}

tz::Vector2f tx::Sprite::GetPosition()
{
	return myPos;
}

std::string tx::Sprite::GetTextureLocation()
{
	return myTextureLocation;
}
