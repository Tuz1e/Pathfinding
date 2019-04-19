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

	SetBody
	(
		sf::Vector2f
		(
			GetBoundingBox().left,
			GetBoundingBox().top
		),
		sf::Color(220, 20, 60, 128),
		mySprite->GetSprite().getScale(),
		sf::Vector2f
		(
			GetBoundingBox().width,
			GetBoundingBox().height
		),
		mySprite->GetSprite().getOrigin()
	);
}

void Player::Update(float& aDelta)
{
	if (!myCollidingFlag)
	{
		myVelocity = tz::Vector2f();
		myCorrectingFlag = false;

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
	}
	else if (myCollidingFlag && !myCorrectingFlag)
	{
		//Not the most perfect system but it works for now
		//TODO: Fix the "bugginess" when colliding
		if (myVelocity.X > 0.0f)
		{
			myVelocity.X = -mySpeed.X;
		}
		else if (myVelocity.X < 0.0f)
		{
			myVelocity.X = mySpeed.X;
		}

		if (myVelocity.Y > 0.0f)
		{
			myVelocity.Y = -mySpeed.Y;
		}
		else if (myVelocity.Y < 0.0f)
		{
			myVelocity.Y = mySpeed.Y;
		}

		myCorrectingFlag = true;
	}
	myPos = myPos + myVelocity * aDelta;
	mySprite->SetPosition(myPos);
	myBody.setPosition(GetBoundingBox().left, GetBoundingBox().top);
	myCollidingFlag = false;
}

void Player::Draw(sf::RenderWindow& aWindow)
{
	mySprite->Draw(aWindow);
	//DrawBody(aWindow);
}

void Player::SetColliding(bool aCollisionFlag)
{
	myCollidingFlag = aCollisionFlag;
}

int& Player::GetWeaponID()
{
	return myWeaponId;
}

int& Player::GetBackpackSpace()
{
	return myBackpackSpace;
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

	myCorrectingFlag = false;
}
