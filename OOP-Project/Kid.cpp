#include "Kid.h"

Kid::Kid()
{
	/**/
}

Kid::Kid(const std::string& nom, const int& age, const char& gen,const std::string& bform)
	:Person(nom, age, gen),B_form_number{bform}
{
	/*Empty Body*/
}

Kid::~Kid()
{
	/*compiler provided constructor is OK*/
}

std::string Kid::getBform() const
{
	return this->B_form_number;
}

void Kid::setBform(const std::string& bform)
{
	this->B_form_number = bform;
}
