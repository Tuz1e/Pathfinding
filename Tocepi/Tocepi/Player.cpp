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
	//if (!myCollidingFlag)
	//{
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
		{
			mySprite->SetTexture(TextureType::IDLE);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::X))
		{
			mySprite->SetTexture(TextureType::RUN);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C))
		{
			mySprite->SetTexture(TextureType::HIT);
		}
	//}
	//else if (myCollidingFlag && !myCorrectingFlag)
	//{
	//	//Not the most perfect system but it works for now
	//	//TODO: Fix the "bugginess" when colliding
	//	if (myVelocity.X > 0.0f)
	//	{
	//		myVelocity.X = -mySpeed.X;
	//	}
	//	else if (myVelocity.X < 0.0f)
	//	{
	//		myVelocity.X = mySpeed.X;
	//	}

	//	if (myVelocity.Y > 0.0f)
	//	{
	//		myVelocity.Y = -mySpeed.Y;
	//	}
	//	else if (myVelocity.Y < 0.0f)
	//	{
	//		myVelocity.Y = mySpeed.Y;
	//	}

	//	myCorrectingFlag = true;
	//}
	myPos = myPos + myVelocity * aDelta;
	mySprite->SetPosition(myPos);
	myBody.setPosition(GetBoundingBox().left, GetBoundingBox().top);
	myCollidingFlag = false;
}

void Player::Draw(sf::RenderWindow& aWindow)
{
	mySprite->Draw(aWindow);
	DrawBody(aWindow);
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
	myTextureType = TextureType::IDLE;
	myDataLoader = DataLoader(PLAYER_ELF);
	myDataLoader.LoadData();

	mySprite = new tx::Sprite(myDataLoader.GetTextures(), myPos, myTextureType);
	mySprite->LoadTexture();
	mySpeed = myDataLoader.GetSpeed();

	PrintLoaded("Player defaults");
}
