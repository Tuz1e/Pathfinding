#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "pch.h"
#include "TZ/GameKit.hpp"
#include "SFML/Graphics.hpp"
#include "Sprite.h"
#include "DataLoader.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void 
		Init(), 
		Update(float& aDelta), 
		Draw(sf::RenderWindow& aWindow);

	virtual std::string& GetName();
	virtual tx::Sprite* GetSprite();
	virtual tz::Vector2f& GetPosition();
	virtual sf::IntRect GetBoundingBox();

	void SetPosition(tz::Vector2f aPos);

	bool GetCollidableFlag();
	bool CheckColliding(const sf::RectangleShape& anObj);

	void SetBody(sf::Vector2f aPos, sf::Color aColour, sf::Vector2f aScale, sf::Vector2f aSize);
	void SetBody(sf::Vector2f aPos, sf::Color aColour, sf::Vector2f aScale, sf::Vector2f aSize, sf::Vector2f anOrigin);
	void SetBody(sf::RectangleShape aShape);
	void DrawBody(sf::RenderWindow& aWindow);
	sf::RectangleShape& GetBody();

protected:
	std::string 
		myTextureLocation, 
		myName;
	sf::RectangleShape myBody;
	tx::Sprite* mySprite;
	tz::Vector2f myPos;
	bool myCollidableFlag = false;
	DataLoader myDataLoader;
};

#endif //GAMEOBJECT_H