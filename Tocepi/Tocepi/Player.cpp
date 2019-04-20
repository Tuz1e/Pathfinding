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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
		{
			mySprite->SetTexture(TextureType::IDLE);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
		{
			mySprite->SetTexture(TextureType::RUN);
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
	mySprite->UpdateAnimation(aDelta); //Update the animation
	myCollidingFlag = false;

	//std::cout << "Player X: " << myPos.X << " Y: " << myPos.Y << std::endl;
	//std::cout << "Sprite X: " << mySprite->GetPosition().X << " Y: " << mySprite->GetPosition().Y << std::endl;
	//std::cout << "Body X: " << myBody.getPosition().x << " Y: " << myBody.getPosition().y << std::endl;

}

void Player::Draw(sf::RenderWindow& aWindow)
{
	
	mySprite->Flip
	(
		((sf::Mouse::getPosition(aWindow).x) < (aWindow.getSize().x/2))
		? FlipView::Left : FlipView::Right
	);

	std::cout << "Mouse X: " << sf::Mouse::getPosition(aWindow).x << " Y: " << sf::Mouse::getPosition(aWindow).y << std::endl;
	std::cout << "Sprite X: " << mySprite->GetSprite().getPosition().x << " Y: " << mySprite->GetSprite().getPosition().y << std::endl;

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
