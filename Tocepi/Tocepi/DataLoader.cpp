#include "DataLoader.h"

DataLoader::DataLoader()
	: myProfileLocation(CONTENTPROFILES) {}

DataLoader::DataLoader(std::string aProfileLocation)
	: myProfileLocation(aProfileLocation) {}

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
	catch (...) {}
}

std::vector<tx::Texture>& DataLoader::GetTextures()
{
	return myTextures;
}

tz::Vector2f DataLoader::GetSpeedVec()
{
	return tz::Vector2f(GetDataFloat("SpeedX"), GetDataFloat("SpeedY"));
}

std::string& DataLoader::GetName()
{
	return myName;
}

std::string DataLoader::GetDataString(const std::string & aFindLine)
{
	try
	{
		return GetFromXml(myProfileLocation, aFindLine);
	}
	catch (...)
	{
		PrintWarning("Failed to get data string for line ->" + aFindLine);
		return "ERROR";
	}
}

std::string DataLoader::GetDataString(std::string & aPath, const std::string & aFindLine)
{
	try
	{
		return GetFromXml(aPath, aFindLine);
	}
	catch (...)
	{
		PrintWarning("Failed to get data string for line ->" + aFindLine);
		return "ERROR";
	}
}

int DataLoader::GetDataInteger(const std::string & aFindLine)
{
	try
	{
		return ConvertToInt(GetFromXml(myProfileLocation, aFindLine));
	}
	catch (...)
	{
		PrintWarning("Failed to get data integer for line ->" + aFindLine);
		return 0;
	}
}

int DataLoader::GetDataInteger(std::string & aPath, const std::string & aFindLine)
{
	try
	{
		return ConvertToInt(GetFromXml(aPath, aFindLine));
	}
	catch (...)
	{
		PrintWarning("Failed to get data integer for line ->" + aFindLine);
		return 0;
	}
}

float DataLoader::GetDataFloat(const std::string & aFindLine)
{
	try
	{
		return ConvertToFloat(GetFromXml(myProfileLocation, aFindLine));
	}
	catch (...)
	{
		PrintWarning("Failed to get data float for line ->" + aFindLine);
		return 0;
	}
}

float DataLoader::GetDataFloat(std::string & aPath, const std::string & aFindLine)
{
	try
	{
		return ConvertToFloat(GetFromXml(aPath, aFindLine));
	}
	catch (...)
	{
		PrintWarning("Failed to get data float for line ->" + aFindLine);
		return 0;
	}
}

bool DataLoader::GetDataBoolean(const std::string & aFindLine)
{
	try
	{
		return (ConvertToInt(GetFromXml(myProfileLocation, aFindLine)) == 1);
	}
	catch (...)
	{
		PrintWarning("Failed to get data boolean for line ->" + aFindLine);
		return false;
	}
}

bool DataLoader::GetDataBoolean(std::string & aPath, const std::string & aFindLine)
{
	try
	{
		return (ConvertToInt(GetFromXml(aPath, aFindLine)) == 1);
	}
	catch (...)
	{
		PrintWarning("Failed to get data boolean for line ->" + aFindLine);
		return false;
	}
}
