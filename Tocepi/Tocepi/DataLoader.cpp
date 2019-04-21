#include "DataLoader.h"

DataLoader::DataLoader() 
	: myProfileLocation(CONTENTPROFILES){}

DataLoader::DataLoader(std::string aProfileLocation)
	: myProfileLocation(aProfileLocation){}

DataLoader::~DataLoader()
{
}

void DataLoader::LoadTextureData()
{
	try
	{
		std::string tempTextureProfileLocation = GetDataString("TXP0");
		myName = GetDataString("Username");

		tx::Texture tempTexture;
		std::string tempStr;
		tz::Vector2f tempScale;
		std::string tempLine;
		for (int i = 0; i < TextureType::LENGTH; i++)
		{
			tempLine = "TX" + std::to_string(i);
			if (ExistsInXml(tempTextureProfileLocation, tempLine))
			{
				tempTexture.SetLocation(GetDataString(tempTextureProfileLocation, tempLine));

				tempTexture.SetScale
				(
					GetDataFloat(tempTextureProfileLocation, tempLine + "-ScaleX"),
					GetDataFloat(tempTextureProfileLocation, tempLine + "-ScaleY")
				);

				tempTexture.SetColumns(GetDataInteger(tempTextureProfileLocation, tempLine + "-Columns"));
				tempTexture.SetRows(GetDataInteger(tempTextureProfileLocation, tempLine + "-Rows"));
				tempTexture.SetFrames(GetDataInteger(tempTextureProfileLocation, tempLine + "-Frames"));
				tempTexture.SetAnimationFlag(GetDataBoolean(tempTextureProfileLocation, tempLine + "-Animate"));
				tempTexture.SetFramerate(GetDataFloat(tempTextureProfileLocation, tempLine + "-Framerate"));

				myTextures.push_back(tempTexture);
			}
		}
		PrintLoaded("data from " + myProfileLocation);
	}
	catch(...) {}
}

std::vector<tx::Texture>& DataLoader::GetTextures()
{
	return myTextures;
}

tz::Vector2f DataLoader::GetSpeedVec()
{
	return tz::Vector2f(GetDataFloat("SpeedX"), GetDataFloat("SpeedY"));
}

float DataLoader::GetSpeed()
{
	return GetDataFloat("Speed");
}

std::string& DataLoader::GetName()
{
	return myName;
}

std::string DataLoader::GetDataString(std::string aFindLine)
{
	return GetFromXml(myProfileLocation, aFindLine);
}

std::string DataLoader::GetDataString(std::string& aPath, std::string aFindLine)
{
	return GetFromXml(aPath, aFindLine);
}

int DataLoader::GetDataInteger(std::string aFindLine)
{
	return ConvertToInt(GetFromXml(myProfileLocation, aFindLine));
}

int DataLoader::GetDataInteger(std::string& aPath, std::string aFindLine)
{
	return ConvertToInt(GetFromXml(aPath, aFindLine));
}

float DataLoader::GetDataFloat(std::string aFindLine)
{
	return ConvertToFloat(GetFromXml(myProfileLocation, aFindLine));
}

float DataLoader::GetDataFloat(std::string& aPath, std::string aFindLine)
{
	return ConvertToFloat(GetFromXml(aPath, aFindLine));
}

bool DataLoader::GetDataBoolean(std::string aFindLine)
{
	return (ConvertToInt(GetFromXml(myProfileLocation, aFindLine)) == 1);
}

bool DataLoader::GetDataBoolean(std::string& aPath, std::string aFindLine)
{
	return (ConvertToInt(GetFromXml(aPath, aFindLine)) == 1);
}
