#ifndef PROGRAM_H
#define PROGRAM_H

#include "pch.h"

class Program
{
public:
	Program();
	~Program();

	void Run();

private:
	void ChooseAlgorithm();
	std::vector<std::string> getAlgorithms();
};

#endif //Program_H