#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <filesystem>
#include <sstream>

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
			//tempLine.erase(std::remove_if(tempLine.begin(), tempLine.end(), &ispunct), tempLine.end());
			tempLine.erase(std::remove_if(tempLine.begin(), tempLine.end(), &isspace), tempLine.end());
			tempLine = tempLine.substr(2, tempLine.length() - 5);
			break;
		}
	}

	std::cout << "Loaded in data: " << aFindLine << ", " << tempLine << std::endl;

	return tempLine;
}

inline std::string GetMapData(const std::string& aPath) 
{
	std::string tempLine, tempFullLine;
	char tempDelimiter = ';';
	std::ifstream tempFile;
	tempFile.open(aPath);

	std::vector<std::string> tempStrVec;

	std::getline(tempFile, tempLine);

	while (std::getline(tempFile, tempLine))
	{
		tempFullLine += tempLine;
	}
	tempFile.close();

	tempFullLine.erase(std::remove_if(tempFullLine.begin(), tempFullLine.end(), &isspace), tempFullLine.end());

	std::cout << "Loaded data: map, " << aPath << std::endl;

	return tempFullLine;
}

inline std::vector<std::string> SplitString(std::string& aStr, char aDelimiter)
{
	size_t tempStart, tempEnd = 0;
	std::vector<std::string> tempStrVec;

	while ((tempStart = aStr.find_first_not_of(aDelimiter, tempEnd)) != std::string::npos)
	{
		tempEnd = aStr.find(aDelimiter, tempStart);
		tempStrVec.push_back(aStr.substr(tempStart, tempEnd - tempStart));
	}

	return tempStrVec;
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
