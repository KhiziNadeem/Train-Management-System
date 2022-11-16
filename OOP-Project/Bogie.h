#pragma once

#include "Person.h"
#include "Adult.h"
#include "Kid.h"

#include<string>

#define MAX_ADULTS 4
#define MAX_KIDS   6

class Bogie
{
public:
	Bogie(const int&);
	virtual ~Bogie();

	int getBogieId()const;
	Bogie* getBogieNext()const;
	std::string getFamilyName()const;

	void setBogieId(const int&);
	void setBogieNext(Bogie* const);
	void setFamilyName(const std::string&);

	std::string getBogieData()const;
	void addAdultPassenger(const std::string&, const int&, const char&, const std::string&, const std::string&, const std::string&);
	void addKidPassenger(const std::string&, const int&, const char&,const std::string&);;

private:

	int			 Bogie_ID;
	Bogie*		 next; 
	Person*		 Adults; 
	Person*      Kids;  
	std::string  familyName;

	int registeredAdults;
	int registeredKids;
};

