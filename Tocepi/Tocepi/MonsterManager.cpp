#include "MonsterManager.h"

MonsterManager::MonsterManager(std::string aLocation)
	: myMonsterLocation(aLocation)
{
}

MonsterManager::~MonsterManager()
{
}

void MonsterManager::LoadDefaults(int anAmount)
{
	std::string tempProfile;
	try
	{
		myMonsterProfiles = GetXmlFiles(myMonsterLocation);

		for (size_t i = 0; i < anAmount; i++)
		{
			//TODO: Use spawnchance to choose monster
			tempProfile = myMonsterProfiles[
				Randomize(0, myMonsterProfiles.size())];

			myMonsters.push_back
			(
				Monster
				(
					GetFromXml(tempProfile, "Username"),
					ConvertToInt(GetFromXml(tempProfile, "Health")),
					ConvertToInt(GetFromXml(tempProfile, "Vision")),
					ConvertToFloat(GetFromXml(tempProfile, "SpawnRate")),
					ConvertToFloat(GetFromXml(tempProfile, "BaseDamage")),
					(ConvertToInt(GetFromXml(tempProfile, "Toxic")) == 1 ? true : false),
					(ConvertToInt(GetFromXml(tempProfile, "Bleed")) == 1 ? true : false),
					(ConvertToInt(GetFromXml(tempProfile, "ProvokeSight")) == 1 ? true : false),
					(ConvertToInt(GetFromXml(tempProfile, "ProvokeHit")) == 1 ? true : false)
				)
			);
			myMonsters[i].LoadDefaults(GetFromXml(tempProfile, "Profile"));
		}
	}
	catch (...)
	{
		std::cout << "Couldn't load monsters" << std::endl;
	}

	PrintLoaded("Monsters " + anAmount);
}

void MonsterManager::Update(float& aDelta, tz::Vector2f & aPos)
{
	for (size_t i = 0; i < myMonsters.size(); i++)
	{
		myMonsters[i].Update(aDelta, aPos);
	}
}

void MonsterManager::Draw(sf::RenderWindow & aWindow, const float& aRenderDis, tz::Vector2f & aPos)
{
	for (size_t i = 0; i < myMonsters.size(); i++)
	{
		if (tz::DisBetweenVec(myMonsters[i].GetPosition(), aPos) <= aRenderDis)
		{
			myMonsters[i].Draw(aWindow);
		}
	}
}

void MonsterManager::SetMonsters(std::vector<Monster> someMonsters)
{
	myMonsters = someMonsters;
}

std::vector<Monster>& MonsterManager::GetMonsters()
{
	return myMonsters;
}
