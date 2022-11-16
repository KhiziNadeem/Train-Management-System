#ifndef ADULT_H
#define ADULT_H
#include<string>

#include "Person.h"

class Adult :
	public Person
{
public:
	Adult();
	Adult(const std::string&, const int&, const char&, const std::string&, const std::string&, const std::string&);
	virtual ~Adult();

	std::string getOccupation()const;
	std::string getQualification()const;
	std::string getNIC()const;
	void setOccupation(const std::string&);
	void setQualification(const std::string&);
	void setNIC(const std::string&);
private:
	std::string Occupation;  
	std::string Qualification; 
	std::string NIC;
};
#endif
