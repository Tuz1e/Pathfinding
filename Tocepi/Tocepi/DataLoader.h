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

	void LoadData();

	std::vector<tx::Texture>& GetTextures();

	tz::Vector2f& GetSpeed();

	std::string& GetName();

private:
	tz::Vector2f mySpeed;
	std::vector<tx::Texture> myTextures;
	std::string myProfileLocation, myName;
};

#endif //TEXTURELOADER_H