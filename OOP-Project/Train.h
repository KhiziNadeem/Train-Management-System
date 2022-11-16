#pragma once
#include "Bogie.h"

class Train
{
public:
	Train(Bogie*const = nullptr);
	void addBogie(Bogie* const = nullptr);
	void deleteBogie(const int&);
	Bogie* const bogieExist(const int&);
	std::string printBogies()const;
private:
	Bogie* engine;
};