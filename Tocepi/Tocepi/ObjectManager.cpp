#include "ObjectManager.h"

//TODO: Load Objects

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::Init(std::vector<std::string>& someObjectLocations)
{
	//TODO: Load Objects
	//TODO: Create public function for DataLoader to set and load object.
	for (size_t i = 0; i < someObjectLocations.size(); i++)
	{
		myObjects.push_back(Object());
	}
}