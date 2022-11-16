#pragma once

#include<string>

#include "Person.h"
class Kid :
	public Person
{
public:
	Kid();
	Kid(const std::string&, const int&, const char&,const std::string&);
	virtual ~Kid();
	std::string getBform()const;
	void setBform(const std::string&);
private:
	std::string B_form_number;
};

