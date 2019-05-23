#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string aLocation, tz::Vector2f aPos) :
	myProfileLocation(aLocation)
{
	myPos = aPos;
}

Weapon::Weapon(std::string aLocation, float aX, float aY) :
	myProfileLocation(aLocation)
{
	myPos = tz::Vector2f(aX, aY);
}

Weapon::~Weapon()
{
	DelPtr(mySprite);
}

void Weapon::LoadWeapon()
{
	myDataLoader = DataLoader(myProfileLocation);
	myDataLoader.LoadTextureData(); //Loads in the texture data

	myName = myDataLoader.GetName();
	myDurability = myDataLoader.GetDataInteger("Durability"); //Gets durability
	myBaseDamage = myDataLoader.GetDataFloat("BaseDamage"); //Gets base damage
	myRangeFlag = myDataLoader.GetDataBoolean("Range"); //Gets whether or not it is range based (can shoot projectiles)
	myThrowableFlag = myDataLoader.GetDataBoolean("Throwable"); //Gets whether or not you can throw it
	myStunFlag = myDataLoader.GetDataBoolean("Stun"); //Gets whether or not it can stun anyone upon hit
	myDescription = myDataLoader.GetDataString("Description"); //Gets the description of the weapon

	if (myRangeFlag)
	{
		//If the weapon is range based, get in projectile profile location.
		//TODO: Add projectile texture loading.
		myRangeProjectileTextureLocation = myDataLoader.GetDataString("RangeProjectileTexture");
	}

	mySprite = new tx::Sprite(myDataLoader.GetTextures(), myPos, TextureType::IDLE);
	mySprite->LoadTexture();

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

void Weapon::Update(float& aDelta, tz::Vector2f aPos, sf::RenderWindow& aWindow)
{
	//Weapon movement
	sf::Vector2f tempMouseWorldPos = aWindow.mapPixelToCoords(sf::Mouse::getPosition(aWindow));
	tz::Vector2f tempMousePos = tz::Vector2f(tempMouseWorldPos.x, tempMouseWorldPos.y);

	tz::Vector2f tempPos = myPos;
	if (tz::DisBetweenVec(myPreviousMousePos, tempMousePos) > 0.1)
	{
		tempPos.X += ((tempMousePos.X - tempPos.X) * 2) * aDelta;
		tempPos.Y += ((tempMousePos.Y - tempPos.Y) * 2) * aDelta;
	}

	if (tz::DisBetweenVec(tempPos, aPos) > 15)
	{
		tempPos.X += ((aPos.X - tempPos.X) * 15) * aDelta;
		tempPos.Y += ((aPos.Y - tempPos.Y) * 15) * aDelta;
	}

	myPreviousMousePos = tempMousePos;

	//Weapon rotation
	float tempAngle = atan2((tempMousePos.Y - tempPos.Y) * -1, (tempMousePos.X - tempPos.X) * -1);
	tempAngle -= PI / 2;
	tempAngle *= (180 / PI); //Convert from radian to degrees

	//Set position of hitbox & sprite
	myPos = tempPos;

	mySprite->SetPosition(myPos);
	mySprite->GetSprite().setRotation(tempAngle);

	myBody.setPosition(sf::Vector2f(myPos.X, myPos.Y));
	myBody.setRotation(tempAngle);
}

void Weapon::Draw(sf::RenderWindow & aWindow)
{
	mySprite->Draw(aWindow);
	//DrawBody(aWindow);
}

std::string& Weapon::GetRangeProjectileTextureLocation()
{
	return myRangeProjectileTextureLocation;
}

int& Weapon::GetDurability()
{
	return myDurability;
}

float& Weapon::GetBaseDamage()
{
	return myBaseDamage;
}

float& Weapon::GetRotationSpeed()
{
	return myRotationSpeed;
}

bool& Weapon::GetRangeFlag()
{
	return myRangeFlag;
}

bool& Weapon::GetStunFlag()
{
	return myStunFlag;
}

bool& Weapon::GetThrowableFlag()
{
	return myThrowableFlag;
}

std::string& Weapon::GetDescription()
{
	return myDescription;
}
