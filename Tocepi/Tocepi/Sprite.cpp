#include "Sprite.h"

tx::Sprite::Sprite()
{
}
tx::Sprite::Sprite(Texture aTexture, tz::Vector2f& aPos, TextureType aType):
	myPos(aPos),
	myTextureType(aType)
{
	myTextures.push_back(aTexture);
}
tx::Sprite::Sprite(std::vector<Texture> someTextures, tz::Vector2f& aPos, TextureType aType): 
	myTextures(someTextures), 
	myPos(aPos), 
	myTextureType(aType) 
{}

tx::Sprite::Sprite(sf::Sprite& aSprite)
{
	mySprite = aSprite;
	myLoadedFlag = true;
	myTextureWidth = aSprite.getTextureRect().width;
	myTextureHeight = aSprite.getTextureRect().height;
}

tx::Sprite::~Sprite()
{
}

void tx::Sprite::LoadTexture()
{
	if (!myLoadedFlag)
	{
		sf::Texture tempTxtr;
		for (size_t i = 0; i < myTextures.size(); i++)
		{
			tempTxtr.loadFromFile(myTextures[i].GetLocation());
			myTextures[i].SetTexture(tempTxtr);
		}

		SetTexture(myTextureType);

		myLoadedFlag = true;
	}
}

void tx::Sprite::SetAnimation(int someColumns, int someRows)
{
	//TODO: Animator logic
}

void tx::Sprite::UpdateAnimation()
{
}

sf::Sprite& tx::Sprite::GetSprite()
{
	return mySprite;
}

tz::Vector2f tx::Sprite::GetPosition()
{
	return myPos;
}

tz::Vector2f tx::Sprite::GetScale()
{
	return myScale;
}

sf::IntRect tx::Sprite::GetFrame()
{
	if (myLoadedFlag && !myAnimationFlag)
	{
		return mySprite.getTextureRect();
	}
	else if (myLoadedFlag && myAnimationFlag)
	{
		return myFrames[myCurrentFrame];
	}

	return sf::IntRect();
}

void tx::Sprite::SetTexture(TextureType aType)
{
	//TODO: Scale correctly when switching to another texture

	myTextureType = aType;
	myTexture = myTextures[aType].GetTexture();
	mySprite.setTexture(myTexture);
	mySprite.setPosition(myPos.X, myPos.Y);
	mySprite.setScale(
		myTextures[aType].GetScale().X,
		myTextures[aType].GetScale().X
	);

	myTextureWidth = mySprite.getTextureRect().width;
	myTextureHeight = mySprite.getTextureRect().height;
}

void tx::Sprite::SetScale(tz::Vector2f aScale)
{
	if (myLoadedFlag) 
	{
		mySprite.setScale(sf::Vector2f(aScale.X, aScale.Y));
	}
	myScale = aScale;
}

void tx::Sprite::SetPosition(tz::Vector2f& aPos)
{
	mySprite.setPosition(sf::Vector2f(aPos.X, aPos.Y));
}

void tx::Sprite::Draw(sf::RenderWindow& aWindow)
{
	aWindow.draw(mySprite);
}
