#include "DataLoader.h"

DataLoader::DataLoader() 
	: myProfileLocation(CONTENTPROFILES){}

DataLoader::DataLoader(std::string aProfileLocation)
	: myProfileLocation(aProfileLocation){}

DataLoader::~DataLoader()
{
}

void DataLoader::LoadData()
{
	try
	{
		std::string tempTextureProfileLocation = GetFromXml(myProfileLocation, "TXP0");
		myName = GetFromXml(myProfileLocation, "Username");
		mySpeed = tz::Vector2f
		(
			ConvertToFloat(GetFromXml(myProfileLocation, "SpeedX")),
			ConvertToFloat(GetFromXml(myProfileLocation, "SpeedY"))
		);

		tx::Texture tempTexture;
		std::string tempStr;
		tz::Vector2f tempScale;
		for (int i = 0; i < TextureType::LENGTH; i++)
		{
			if (ExistsInXml(tempTextureProfileLocation, "TX" + std::to_string(i)))
			{
				tempTexture.SetLocation(GetFromXml(tempTextureProfileLocation, "TX" + std::to_string(i)));

				tempScale.X = ConvertToFloat(GetFromXml(tempTextureProfileLocation, "TX" + std::to_string(i) + "-ScaleX"));
				std::cout << tempStr << std::endl;

				tempScale.Y = ConvertToFloat(
					GetFromXml(tempTextureProfileLocation, "TX" + std::to_string(i) + "-ScaleY"));

				tempTexture.SetScale
				(
					ConvertToFloat(GetFromXml(tempTextureProfileLocation, "TX" + std::to_string(i) + "-ScaleY")),
					ConvertToFloat(GetFromXml(tempTextureProfileLocation, "TX" + std::to_string(i) + "-ScaleX"))
				);

				tempTexture.SetColumns(
					ConvertToInt(
						GetFromXml(
							tempTextureProfileLocation, "TX" + std::to_string(i) + "-Column")
					));

				tempTexture.SetRows(
					ConvertToInt(
						GetFromXml(
							tempTextureProfileLocation, "TX" + std::to_string(i) + "-Row")));
				tempTexture.SetAnimationFlag(
					(
						ConvertToInt(
							GetFromXml(
								tempTextureProfileLocation, "TX" + std::to_string(i) + "-Animate")
						) == 1));

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

tz::Vector2f& DataLoader::GetSpeed()
{
	return mySpeed;
}

std::string& DataLoader::GetName()
{
	return myName;
}
