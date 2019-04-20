#ifndef SPRITE_H
#define SPRITE_H

#include "pch.h"
#include "SFML/Graphics.hpp"
#include "TZ/GameKit.hpp"
#include "TextureType.h"
#include "Texture.h"

namespace tx
{
	class Sprite
	{
	public:
		Sprite();
		Sprite(tx::Texture aTexture, tz::Vector2f& aPos, TextureType aType);
		Sprite(std::vector<tx::Texture> someTextures, tz::Vector2f& aPos, TextureType aType);
		Sprite(sf::Sprite& aSprite);
		~Sprite();

		void
			SetScale(tz::Vector2f aScale),
			Draw(sf::RenderWindow& aWindow),
			UpdateAnimation(),
			SetAnimation(int someColumns, int someRows),			
			SetPosition(tz::Vector2f& aPos);

		void LoadTexture();

		sf::Sprite &GetSprite();
		tz::Vector2f 
			GetPosition(), 
			GetScale();
		sf::IntRect GetFrame();

		void SetTexture(TextureType aType);

	private:
		sf::Sprite mySprite;
		tz::Vector2f myPos, myScale;
		sf::Texture myTexture;

		std::vector<tx::Texture> myTextures;

		TextureType myTextureType;

		bool myLoadedFlag = false, myAnimationFlag = false;
		int myCurrentFrame, myTextureWidth, myTextureHeight;
		std::vector<sf::IntRect> myFrames;
	};
}

#endif //SPRITE_H