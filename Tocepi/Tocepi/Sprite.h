#ifndef SPRITE_H
#define SPRITE_H

#include "pch.h"
#include "SFML/Graphics.hpp"
#include "TZ/GameKit.hpp"
#include "TextureType.h"
#include "Texture.h"

//ROWS: Horizontal/Sideways
//COLUMNS: Vertical/Down

enum FlipView
{
	Left,
	Right
};

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
			SetScale(float x, float y),
			Draw(sf::RenderWindow& aWindow),
			UpdateAnimation(float& aDelta),			
			SetPosition(tz::Vector2f& aPos),
			SetPosition(float aX, float aY);

		void LoadTexture();

		sf::Sprite &GetSprite();
		tz::Vector2f GetOrigin();
		tz::Vector2f 
			GetPosition(), 
			GetScale();
		sf::IntRect GetFrame();

		TextureType& GetCurrentTextureType();

		void SetTexture(TextureType aType);
		void Flip(FlipView aSide);

	private:
		void SetAnimation();

		sf::Sprite mySprite;
		tz::Vector2f myPos, myScale;
		sf::Texture myTexture;

		std::vector<tx::Texture> myTextures;

		TextureType myTextureType;

		tz::Vector2f myCurrentFrame;
		int myColumns, myRows;
		float myFramerate;

		bool myLoadedFlag = false, myAnimationFlag = false;
		int myTextureWidth, myTextureHeight;
	};
}

#endif //SPRITE_H