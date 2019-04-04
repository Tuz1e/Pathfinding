#ifndef PROGRAM_H
#define PROGRAM_H

#include "pch.h"
#include "SFML/Graphics.hpp"

class Program
{
public:
	Program();
	~Program();

	void Init();
	void Update(float aDelta);
	void Draw(sf::RenderWindow &aWindow);
	void LateDraw(sf::RenderWindow &aWindow);

private:
};

#endif //Program_H