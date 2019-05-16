#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "pch.h"
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Init(std::vector<std::string>& someObjectLocations);

private:
	std::vector<Object> myObjects;
};

#endif //OBJECTMANAGER_H