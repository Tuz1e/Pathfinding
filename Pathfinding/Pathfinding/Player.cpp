#include "Player.h"



Player::Player()
{
	myPos = tz::Vector2f(0, 0);
	LoadDefaults();
}


Player::Player(tz::Vector2f aPos)
{
	myPos = aPos;
	LoadDefaults();
}

Player::Player(float x, float y)
{
	myPos = tz::Vector2f(x, y);
	LoadDefaults();
}

Player::~Player()
{
	DelPtr(mySprite);
}

void Player::Init(Input& anInput)
{
	myInput = anInput;
	mySprite->GetSprite().setOrigin(
		sf::Vector2f(
			mySprite->GetSprite().getTexture()->getSize().x / 2.0f, 
			mySprite->GetSprite().getTexture()->getSize().y / 2.0f));
}

void Player::Update(float& aDelta)
{
	myVelocity = tz::Vector2f();

	if (myInput.GetLeftKey()) 
	{
		myVelocity.X = -mySpeed.X;
	}
	else if (myInput.GetRightKey())
	{
		myVelocity.X = mySpeed.X;
	}

	if (myInput.GetUpKey())
	{
		myVelocity.Y = -mySpeed.Y;
	}
	else if (myInput.GetDownKey())
	{
		myVelocity.Y = mySpeed.Y;
	}

	myPos = myPos + myVelocity * aDelta;
	mySprite->SetPosition(myPos);
}

void Player::Draw(sf::RenderWindow& aWindow)
{
	mySprite->Draw(aWindow);

	//sf::Sprite tempSprite = mySprite->GetSprite();
	//tempSprite.setTextureRect(GetBoundingBox());
	//tempSprite.setColor(sf::Color::Red);
}

sf::Vector2f Player::GetVelocity()
{
	return sf::Vector2f(myVelocity.X, myVelocity.Y);
}

void Player::LoadDefaults()
{
	try 
	{
		mySprite = new tx::Sprite(GetFromXml(PLAYER_DEFAULT, "TX00"), myPos);

		mySprite->SetScale
		(
			tz::Vector2f
			(
				ConvertToFloat(GetFromXml(PLAYER_DEFAULT, "TX00-ScaleX")),
				ConvertToFloat(GetFromXml(PLAYER_DEFAULT, "TX00-ScaleY"))
			)
		);

		mySprite->LoadTexture(mySprite->GetScale());

		mySpeed = tz::Vector2f
		(
			ConvertToFloat(GetFromXml(PLAYER_DEFAULT, "SpeedX")),
			ConvertToFloat(GetFromXml(PLAYER_DEFAULT, "SpeedY"))
		);

		PrintLoaded("Player Defaults");
	}
	catch (...) {}
}
