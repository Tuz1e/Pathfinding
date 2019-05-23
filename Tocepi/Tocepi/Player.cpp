#include "Player.h"

Player::Player()
{
	myPos = tz::Vector2f(0, 0);
}

Player::Player(tz::Vector2f aPos)
{
	myPos = aPos;
}

Player::Player(float x, float y)
{
	myPos = tz::Vector2f(x, y);
}

Player::~Player()
{
	DelPtr(mySprite);
}

void Player::Init(Input& anInput)
{
	LoadDefaults(PLAYER_CHARACTER);
	myInput = anInput;

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

	myWeapon = new Weapon(WEAPON_DEV, myPos);
	myWeapon->LoadWeapon();
}

void Player::Update(float& aDelta, sf::RenderWindow& aWindow)
{
	//FIX: Player getting stuck in walls when colliding

	if (!myCollidingFlag)
	{
		myVelocity = tz::Vector2f();
		myCorrectingFlag = false;

		if (myInput.GetLeftKeyPressed())
		{
			myVelocity.X = -mySpeed.X;
			myMovingFlag = true;
		}
		else if (myInput.GetRightKeyPressed())
		{
			myVelocity.X = mySpeed.X;
			myMovingFlag = true;
		}

		if (myInput.GetUpKeyPressed())
		{
			myVelocity.Y = -mySpeed.Y;
			myMovingFlag = true;
		}
		else if (myInput.GetDownKeyPressed())
		{
			myVelocity.Y = mySpeed.Y;
			myMovingFlag = true;
		}

		if (myMovingFlag && mySprite->GetCurrentTextureType() != TextureType::RUN)
		{
			mySprite->SetTexture(TextureType::RUN);
		}
		else if (!myMovingFlag && mySprite->GetCurrentTextureType() != TextureType::IDLE)
		{
			mySprite->SetTexture(TextureType::IDLE);
		}
	}
	else if (myCollidingFlag && !myCorrectingFlag)
	{
		//Not the most perfect system but it works for now
		//FIX: Buggy when colliding

		if (myVelocity.X != 0.0f || myVelocity.Y != 0.0f)
		{
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
		}

		myCorrectingFlag = true;
	}
	SetPosition(myPos + (myVelocity * aDelta));
	myBody.setPosition(GetBoundingBox().left, GetBoundingBox().top);
	mySprite->UpdateAnimation(aDelta); //Update the animation
	myWeapon->Update(aDelta, myPos, aWindow);
	myCollidingFlag = false;
	myMovingFlag = false;
}

void Player::Draw(sf::RenderWindow & aWindow, sf::View & aView)
{
	mySprite->Flip
	(
		((sf::Mouse::getPosition(aWindow).x) < (aWindow.getSize().x / 2))
		? FlipView::Left : FlipView::Right
	);
	myWeapon->Draw(aWindow);
	mySprite->Draw(aWindow);
	DrawBody(aWindow);
}

Weapon * Player::GetWeapon()
{
	return myWeapon;
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
