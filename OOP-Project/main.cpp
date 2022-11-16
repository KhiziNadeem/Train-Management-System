#include<iostream>
#include "Bogie.h"
#include "Train.h"

int main()
{

	Bogie b1(10);
	Bogie b2(210);
	Train t1;
	t1.addBogie(&b1);
	t1.addBogie(&b2);
	std::cout<<t1.printBogies();
	std::cout << std::endl;
	t1.deleteBogie(20);
	std::cout << t1.printBogies();

	//to print the data of certain bogiey use
	b1.addAdultPassenger("abdullah", 18, 'M', "student", "hardly bs cs", "03008424758");//to add passengers use this member functions


	//searching with boge id
	std::cout << std::endl;
	std::cout<<b1.getBogieData();
	bool found = (t1.bogieExist(150) ? true : false);
	if (found)
	{
		std::cout << "\nBOGEY FOUND WITH INPUTTED IDD\n";
	}
	else
	{
		std::cout << "\nBOGEY NOT FOUND\n";
	}

}
