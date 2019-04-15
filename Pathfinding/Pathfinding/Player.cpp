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

	//myPos = tz::Vector2f(myPos.X + myVelocity.X * aDelta, myPos.Y + myVelocity.Y * aDelta);
	myPos = myPos + myVelocity;
	mySprite->SetPosition(myPos);
}

void Player::Draw(sf::RenderWindow& aWindow)
{
	mySprite->Draw(aWindow);
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
