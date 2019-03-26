#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <string.h>
#include <vector>

void Println(std::string str) 
{
	std::cout << str.c_str() << std::endl;
}

template<typename T>
void DelPtr(T* ptr) 
{
	delete[](ptr);
	ptr = nullptr;
}

#endif //PCH_H