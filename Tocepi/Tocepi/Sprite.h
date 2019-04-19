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
		Sprite(std::string aTextureLocation, tz::Vector2f& aPos);
		Sprite(sf::Sprite& aSprite);
		~Sprite();

		void
			SetScale(tz::Vector2f aScale),
			Draw(sf::RenderWindow& aWindow),
			UpdateAnimation(),
			SetAnimation(int someColumns, int someRows),
			LoadTexture(tz::Vector2f aScale),
			SetPosition(tz::Vector2f& aPos);

		sf::Sprite &GetSprite();
		tz::Vector2f 
			GetPosition(), 
			GetScale();
		std::string GetTextureLocation();
		sf::IntRect GetFrame();

	private:
		std::string myTextureLocation = "";
		sf::Sprite mySprite;
		tz::Vector2f myPos, myScale;
		sf::Texture myTexture;
		bool myLoadedFlag = false, myAnimationFlag = false;
		int myCurrentFrame, myTextureWidth, myTextureHeight;
		std::vector<sf::IntRect> myFrames;
	};
}

#endif //SPRITE_H