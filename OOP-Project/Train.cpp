#include "Train.h"
#include<iostream>
#include<sstream>


Train::Train(Bogie* const arg)
	:engine{arg}
{
}

void Train::addBogie(Bogie* const arg)
{
	if (this->bogieExist(arg->getBogieId())!=nullptr)
	{
		std::cout << "BOGIE WITH THIS ID EXIST ALREADY\n";
	}
	else if (this->engine == nullptr)
	{
		engine = arg;
	}
	else
	{
		
		Bogie* current = engine ;
		Bogie* next = engine->getBogieNext();

		while (next != nullptr)
		{
			current = next;
			next=(current->getBogieNext());
		}
		current->setBogieNext(arg);
	}
}

void Train::deleteBogie(const int& idd)
{
	if (this->engine == nullptr)
	{
		std::cout << "NOTING TO DELETE\n";
	}
	else
	{
		if (engine->getBogieNext() == nullptr)
		{
			engine = nullptr;
		}
		else
		{
			bool flag{ false };
			Bogie* current = engine;
			Bogie* next = engine->getBogieNext();
			while (next != nullptr)
			{
				if (next != nullptr)
				{
					if (next->getBogieId() == idd)
					{
						current->setBogieNext(next->getBogieNext());
						flag = true;
						break;
					}
				}
				current = next;
				next = next->getBogieNext();
			}
			if (!flag)
			{
				std::cout << "BOGIE ID DOESNOT EXIST\n";
			}
		}
	}
}

Bogie* const Train::bogieExist(const int& idd)
{
	Bogie* start = engine;
	while (start!=nullptr)
	{
		if (start->getBogieId() == idd)
		{
			return start;
		}
		else
		{
			start = start->getBogieNext();
		}
	}
	return nullptr;//not found case
}

std::string Train::printBogies() const
{
	std::ostringstream output;
	Bogie* start = engine;
	while (start != nullptr)
	{
		output << "|" << start->getBogieId() << "|-> ";
		start = start->getBogieNext();
	}
	return output.str();
}
