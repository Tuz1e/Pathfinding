#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <string.h>
#include <vector>


template<typename T>
void DelPtr(T* ptr) 
{
	delete[](ptr);
	ptr = nullptr;
}

#endif //PCH_H