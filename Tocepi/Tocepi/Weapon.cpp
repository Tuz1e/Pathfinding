#include "Weapon.h"

Weapon::Weapon()
{
	PI = 3.14159265358979323846;
}

Weapon::Weapon(std::string aLocation, tz::Vector2f aPos):
	myProfileLocation(aLocation)
{
	myPos = aPos;
	PI = 3.14159265358979323846;
	myAngle = 1;
}

Weapon::Weapon(std::string aLocation, float aX, float aY):
	myProfileLocation(aLocation)
{
	myPos = tz::Vector2f(aX, aY);
	PI = 3.14159265358979323846;
	myAngle = 1;
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
	myRotationSpeed = myDataLoader.GetDataFloat("Speed"); //Gets the speed of which the weapon rotate around the player

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
	//float tempAngle = 90 * aDelta;
	//myRotationSpeed *= aDelta;
	//tempAngle *= 3.14159265358979323846 / 180; //Angle * PI/180

	//float s = sin(tempAngle);
	//float c = cos(tempAngle);

	//float xnew = aCenterPos.X * c - aCenterPos.Y * s;
	//float ynew = aCenterPos.X * s - aCenterPos.Y * c;

	//float tempRotatedX = xnew + myPos.X;
	//float tempRotatedY = ynew + myPos.Y;

	//float tempRotatedX = + cos(tempAngle) * (aPos.X - aCenterPos.X) - sin(tempAngle)
	//	* (aPos.Y - aCenterPos.Y) + aCenterPos.X;

	//float tempRotatedY = myPos.Y + sin(tempAngle) * (aPos.X - aCenterPos.X) + cos(tempAngle)
	//	* (aPos.Y - aCenterPos.Y) + aCenterPos.Y;

	//mySprite->SetPosition(tempRotatedX, tempRotatedY);
	//myPos = tz::Vector2f(tempRotatedX, tempRotatedY);
	//myBody.setPosition(tempRotatedX, tempRotatedY);

	//This worked, ish
	//myAngle = PI / 2;
	//myAngle = myAngle * (180 / PI);

	//float dx = ((10) * cos(myAngle)) - ((10) * sin(myAngle)) + aCenterPos.X;
	//float dy = ((10) * cos(myAngle)) + ((10) * sin(myAngle)) + aCenterPos.Y;



	//float tempX = aCenterPos.X * cos(myAngle);
	//float tempY = aCenterPos.Y * sin(myAngle);

	//float tempDx = tempX + aCenterPos.X * 10;
	//float tempDy = tempY + aCenterPos.Y * sin(myAngle);

	//std::cout << "Angle: " << myAngle << std::endl;
	//std::cout << "Derivative X: " << dx << " Y: " << dy << std::endl;
	//std::cout << "Weapon X: " << myPos.X << " Y: " << myPos.Y << std::endl;

	//myPos = tz::Vector2f(tempX, tempY);
	//mySprite->SetPosition(tempX, tempY);
	//myBody.setPosition(tempX, tempY);

	//If position is smaller than '15' move towards mouse, otherwise don't

	sf::Vector2f tempMouseWorldPos = aWindow.mapPixelToCoords(sf::Mouse::getPosition(aWindow));
	tz::Vector2f tempMousePos = tz::Vector2f(tempMouseWorldPos.x, tempMouseWorldPos.y);

	tz::Vector2f tempPos = myPos;

	//if (tz::DisBetweenVec(myPos, aPos) > 5)
	//{
	//	tempPos.X += ((aPos.X - myPos.X) * 2) * aDelta;
	//	tempPos.Y += ((aPos.Y - myPos.Y) * 2) * aDelta;
	//}

	//TODO: Add weapon rotation logic
	//TODO: Move weapon
	if (tz::DisBetweenVec(myPos, tempMousePos) >= 10 && (tz::DisBetweenVec(myPos, aPos) <= 5))
	{
		tempPos.X += ((tempMousePos.X - myPos.X) * 2) * aDelta;
		tempPos.Y += ((tempMousePos.Y - myPos.Y) * 2) * aDelta;
	}

	myPos = tempPos;
	
	mySprite->SetPosition(myPos);
	myBody.setPosition(sf::Vector2f(myPos.X, myPos.Y));
}

void Weapon::Draw(sf::RenderWindow& aWindow)
{
	//sf::Vector2f tempCurrentPos;
	//tempCurrentPos.x = GetBoundingBox().left;
	//tempCurrentPos.y = GetBoundingBox().top;
	//sf::Vector2i tempPos = sf::Mouse::getPosition(aWindow);
	//tempPos = sf::Vector2i(aWindow.mapPixelToCoords(tempPos, aView));

	//float dx = tempCurrentPos.x - tempPos.x;
	//float dy = tempCurrentPos.y - tempPos.y;
	//float rotation = (atan2(dy, dy)) * (180 / PI);

	//mySprite->GetSprite().setRotation(rotation);
	//myBody.setRotation(rotation);

	//float angle = atan2(sf::Mouse::getPosition(aWindow).y - myPos.Y, sf::Mouse::getPosition(aWindow).x - myPos.X);
	//angle = angle * (180 / PI);

	//if (angle < 0)
	//{
	//	angle = 360 - (-angle);
	//}

	//mySprite->GetSprite().rotate(90 + angle);
	//myBody.rotate(90 + angle);

	mySprite->Draw(aWindow);
	DrawBody(aWindow);
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
