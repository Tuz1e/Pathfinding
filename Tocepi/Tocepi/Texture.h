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
		Texture(std::string aLocation, tz::Vector2f aScale, int someColumns, int someRows, int someFrames, bool anAnimationFlag, float aFramerate);
		~Texture();

		std::string GetLocation();
		tz::Vector2f GetScale();
		int
			GetColumns(),
			GetRows(),
			GetFrames();
		bool GetAnimationFlag();
		sf::Texture GetTexture();
		float GetFramerate();

		void
			SetLocation(std::string aLocation),
			SetScale(tz::Vector2f aScale),
			SetScale(float x, float y),
			SetColumns(int someColumns),
			SetRows(int someRows),
			SetFrames(int someFrames),
			SetAnimationFlag(int anAnimationFlag),
			SetTexture(sf::Texture aTexture),
			SetFramerate(float aFramerate);

	private:
		std::string myLocation;
		tz::Vector2f myScale;
		int myColumns, myRows, myFrames;
		bool myAnimationFlag;
		sf::Texture myTexture;
		float myFramerate;
	};
}

#endif //TEXTURE_H
