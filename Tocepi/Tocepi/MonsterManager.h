#ifndef MONSTERMANAGER_H
#define MONSTERMANAGER_H

#include "pch.h"
#include "Monster.h"

class MonsterManager
{
public:
	MonsterManager(std::string aLocation);
	~MonsterManager();

	void
		LoadDefaults(int anAmount),
		Update(float& aDelta, tz::Vector2f& aPos),
		Draw(sf::RenderWindow& aWindow, const float& aRenderDis, tz::Vector2f& aPos);

	std::vector<Monster>& GetMonsters();

private:
	std::string myMonsterLocation;
	std::vector<Monster> myMonsters;
	std::vector<std::string> myMonsterProfiles;
};

#endif //MONSTERMANAGER_H
