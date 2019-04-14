#ifndef SPRITE_H
#define SPRITE_H

#include "pch.h"
#include "SFML/Graphics.hpp"
#include "TZ/GameKit.hpp"

namespace tx
{
	class Sprite
	{
	public:
		Sprite();
		~Sprite();

		void SetAnimation(int someColumns, int someRows);
		void UpdateAnimation();

		sf::Sprite GetSprite();
		tz::Vector2f GetPosition();
		std::string GetTextureLocation();

	private:
		std::string myTextureLocation;
		sf::Sprite mySprite;
		tz::Vector2f myPos;
	};
}

#endif //SPRITE_H