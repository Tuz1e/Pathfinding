#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <filesystem>

inline std::string GetFromXml(const std::string& aPath, const std::string& aFindLine)
{
	std::string tempLine; //The line to return
	std::ifstream tempIn(aPath);
	while (std::getline(tempIn, tempLine))
	{
		int tempFind = (int)tempLine.find(aFindLine);
		if (tempFind != std::string::npos)
		{
			tempFind = -1;
			do
			{
				tempFind = (int)tempLine.find(aFindLine, tempFind + 1);
				if (tempFind != -1)
				{
					//Removes the specified string to get what is in between.
					tempLine = tempLine.substr(0, tempFind) + tempLine.substr(tempFind + aFindLine.length());
				}
			} while (tempFind != -1);
			tempLine.erase(std::remove_if(tempLine.begin(), tempLine.end(), &ispunct), tempLine.end());
			tempLine.erase(std::remove_if(tempLine.begin(), tempLine.end(), &isspace), tempLine.end());
			break;
		}
	}

	std::cout << "Loaded in: " << aFindLine << ", " << tempLine << std::endl;

	return tempLine;
}

inline std::vector<std::string> GetXmlFiles(const std::string & aPath)
{
	std::vector<std::string> tempFiles;
	for (auto& files : std::experimental::filesystem::v1::directory_iterator(aPath))
	{
		int tempFind = (int)files.path().string().find(".xml");
		if (tempFind != std::string::npos)
		{
			tempFiles.push_back(files.path().string());
		}
	}

	return tempFiles;
}

#endif
