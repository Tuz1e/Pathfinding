#include "Texture.h"

tx::Texture::Texture() :
	myLocation(""),
	myScale(tz::Vector2f()),
	myColumns(0),
	myRows(0),
	myAnimationFlag(false)
{}

tx::Texture::Texture(std::string aLocation, tz::Vector2f aScale, int someColumns, int someRows, int someFrames, bool anAnimationFlag, float aFramerate) :
	myLocation(aLocation),
	myScale(aScale),
	myColumns(someColumns),
	myRows(someRows),
	myFrames(someFrames),
	myAnimationFlag(anAnimationFlag),
	myFramerate(aFramerate)
{}

tx::Texture::~Texture()
{
}

std::string tx::Texture::GetLocation()
{
	return myLocation;
}

tz::Vector2f tx::Texture::GetScale()
{
	return myScale;
}

int tx::Texture::GetColumns()
{
	return myColumns;
}

int tx::Texture::GetFrames()
{
	return myFrames;
}

int tx::Texture::GetRows()
{
	return myRows;
}

bool tx::Texture::GetAnimationFlag()
{
	return myAnimationFlag;
}

sf::Texture tx::Texture::GetTexture()
{
	return myTexture;
}

float tx::Texture::GetFramerate()
{
	return myFramerate;
}

void tx::Texture::SetLocation(std::string aLocation)
{
	myLocation = aLocation;
}

void tx::Texture::SetFramerate(float aFramerate)
{
	myFramerate = aFramerate;
}

void tx::Texture::SetFrames(int someFrames)
{
	myFrames = someFrames;
}

void tx::Texture::SetScale(float aX, float aY)
{
	myScale = tz::Vector2f(aX, aY);
}

void tx::Texture::SetTexture(sf::Texture aTexture)
{
	myTexture = aTexture;
}

void tx::Texture::SetAnimationFlag(int anAnimationFlag)
{
	myAnimationFlag = anAnimationFlag;
}

void tx::Texture::SetRows(int someRows)
{
	myRows = someRows;
}

void tx::Texture::SetColumns(int someColumns)
{
	myColumns = someColumns;
}

void tx::Texture::SetScale(tz::Vector2f aScale)
{
	myScale = aScale;
}
