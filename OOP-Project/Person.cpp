#include "Person.h"
#include <stdexcept>


Person::Person()
{
	/**/
}

Person::Person(const std::string& nom, const int& age, const char& gen)
	:Name{nom},Age{age},Gender{gen}
{
	/*Empty Constructors*/
}

Person::~Person()
{
	/*virtual destructors*/
}

std::string Person::getName() const
{
	return this->Name;
}

int Person::getAge() const
{
	return this->Age;
}

char Person::getGender() const
{
	return Gender;
}

void Person::setName(const std::string& nom)
{
	this->Name = nom;
}

void Person::setAge(const int& age)
{
	this->Age = (age > 0 ? age : throw std::invalid_argument("AGE MUST BE GREATER THAN 0"));
}

void Person::setGender(const char& gen)
{
	this->Gender = gen;
}
