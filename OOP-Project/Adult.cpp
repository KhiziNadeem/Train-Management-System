#include "Adult.h"

Adult::Adult()
{
	/**/
}

Adult::Adult(const std::string& nom, const int& age , const char& gen, const std::string& occu, const std::string& qual, const std::string& nic)
	:Person(nom,age,gen),Occupation{occu},Qualification{qual},NIC{nic}
{
	/*constructor with empty body*/
}

Adult::~Adult()
{
	/*default desatructor is ok*/
}

std::string Adult::getOccupation() const
{
	return Occupation;
}

std::string Adult::getQualification() const
{
	return Qualification;
}

std::string Adult::getNIC() const
{
	return NIC;
}

void Adult::setOccupation(const std::string& occu)
{
	this->Occupation = occu;
}

void Adult::setQualification(const std::string& qual)
{
	this->Qualification = qual;
}

void Adult::setNIC(const std::string& nic)
{
	this->NIC = nic;
}
