#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include "pch.h"
#include "TZ/GameKit.hpp"
#include "Info.h"
#include "File.h"
#include "TextureType.h"
#include "Texture.h"

class DataLoader
{
public:
	DataLoader();
	DataLoader(std::string aProfileLocation);
	~DataLoader();

	void LoadTextureData();

	std::vector<tx::Texture>& GetTextures();
	std::string& GetName();

	std::string GetDataString(const std::string& aFindLine);
	std::string GetDataString(std::string& aPath, const std::string& aFindLine);

	int GetDataInteger(const std::string& aFindLine);
	int GetDataInteger(std::string& aPath, const std::string& aFindLine);

	float GetDataFloat(const std::string& aFindLine);
	float GetDataFloat(std::string& aPath, const std::string& aFindLine);

	bool GetDataBoolean(const std::string& aFindLine);
	bool GetDataBoolean(std::string& aPath, const std::string& aFindLine);

	tz::Vector2f GetSpeedVec();

private:
	std::vector<tx::Texture> myTextures;
	std::string myProfileLocation, myName;
};

#endif //TEXTURELOADER_H
