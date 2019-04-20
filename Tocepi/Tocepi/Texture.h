#ifndef TEXTURE_H
#define TEXTURE_H

#include "pch.h"
#include "TZ/GameKit.hpp"
#include "SFML/Graphics.hpp"

namespace tx 
{
	class Texture
	{
	public:
		Texture();
		Texture(std::string aLocation, tz::Vector2f aScale, int someColumns, int someRows, bool anAnimationFlag);
		~Texture();

		std::string GetLocation();
		tz::Vector2f GetScale();
		int GetColumns(), GetRows();
		bool GetAnimationFlag();
		sf::Texture GetTexture();

		void
			SetLocation(std::string aLocation),
			SetScale(tz::Vector2f aScale),
			SetScale(float x, float y),
			SetColumns(int someColumns),
			SetRows(int someRows),
			SetAnimationFlag(int anAnimationFlag),
			SetTexture(sf::Texture aTexture);

	private:
		std::string myLocation;
		tz::Vector2f myScale;
		int myColumns, myRows;
		bool myAnimationFlag;
		sf::Texture myTexture;
	};
}

#endif //TEXTURE_H