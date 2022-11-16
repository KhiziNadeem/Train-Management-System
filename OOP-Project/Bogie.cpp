#include<stdexcept>
#include<sstream>

#include "Bogie.h"

Bogie::Bogie(const int& idd)
	:Bogie_ID{idd},next{nullptr},Adults{new Adult[MAX_ADULTS]},Kids{new Kid[MAX_KIDS]}
	,registeredAdults{0},registeredKids{0}
{
	/*Empty body Constructor */
}

Bogie::~Bogie()
{
}

int Bogie::getBogieId() const
{
	return this->Bogie_ID;
}

 Bogie* Bogie::getBogieNext() const
{
	return this->next;
}

std::string Bogie::getFamilyName() const
{
	return this->familyName;
}

void Bogie::setBogieId(const int& id)
{
	this->Bogie_ID = id;
}

void Bogie::setBogieNext(Bogie* const nextAdd)
{
	next = (nextAdd==nullptr?nullptr:nextAdd);
}

void Bogie::setFamilyName(const std::string& fname)
{
	this->familyName = fname;
}

std::string Bogie::getBogieData() const
{
	std::ostringstream output;
	if (registeredAdults != 0) 
	{
		Adult* temp;
		output << "************************************************* Bogie ID NO.:" << Bogie_ID << " ADULTS INFO *****************************************" << std::endl;
		for (int t{ 0 }; t < registeredAdults; ++t) {
			output << " Name of ADULT " << t + 1 << " is " << this->Adults[t].getName() << std::endl <<
				" Age of ADULT " << t + 1 << " is " << this->Adults[t].getAge() << std::endl <<
				" Gender of ADULT " << t + 1 << " is " << this->Adults[t].getGender() << std::endl;
			//Downcasting
			temp = dynamic_cast<Adult*>(&this->Adults[t]);//temp for storing the casted object

			output << " Occupation of ADULT " << t + 1 << " is " << (*temp).getOccupation() << std::endl <<
				" Qualification of ADULT " << t + 1 << " is " << (*temp).getQualification() << std::endl <<
				" NIC of ADULT " << t + 1 << " is " << (*temp).getNIC() << std::endl;
			output << "********************************************************************************************************";
			temp = nullptr;
		}//end for loop adults
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (registeredKids != 0) 
	{
		Kid* temp;
		output << "************************************************* Bogie ID NO. :" << Bogie_ID << " KIDS INFO **********************************************" << std::endl;
		for (int t{ 0 }; t < registeredKids; ++t)
		{
			output << " Name of KID " << t + 1 << " is " << this->Kids[t].getName() << std::endl <<
				" Age of KID " << t + 1 << " is " << this->Kids[t].getAge() << std::endl <<
				" Gender of  KID " << t + 1 << " is " << this->Kids[t].getGender() << std::endl;
			//Downcasting
			temp = dynamic_cast<Kid*>(&this->Kids[t]);//temp for storing the casted object

			output << " BForm Number Of KID " << t + 1 << " is " << temp->getBform() << std::endl;
			output << "*****************************************************************************************************";
			temp = nullptr;
		}//end for loop of kids
	}
	else if(registeredAdults && registeredKids)
	{
		output << "NO DATA AVAILABLE CURRENTLY FOR THAT BOGIE\n";
	}
		return output.str();
}

void Bogie::addAdultPassenger(const std::string& nom, const int& age, const char& gen, const std::string& oocu, const std::string& quali, const std::string& nic)
{
	if (registeredAdults < MAX_ADULTS)
	{
		Adults[registeredAdults].setName(nom);
		Adults[registeredAdults].setAge(age);
		Adults[registeredAdults].setGender(gen);
		Adult* temp = dynamic_cast<Adult*>(&this->Adults[registeredAdults]);//temp for storing the casted object
		temp->setOccupation(oocu);
		temp->setQualification(quali);
		temp->setNIC(nic);
		registeredAdults++;
		temp = nullptr;
	}
	else
	{
		throw std::invalid_argument("CANT ADD MORE ADULT PASSENGERS");
	}
}

void Bogie::addKidPassenger(const std::string& nom, const int& age, const char& gen,const std::string& bform)
{
	if (registeredKids < MAX_KIDS)
	{
		Kids[registeredAdults].setName(nom);
		Kids[registeredAdults].setAge(age);
		Kids[registeredAdults].setGender(gen);
		Kid* temp = dynamic_cast<Kid*>(&this->Kids[registeredKids]);
		temp->setBform(bform);
		registeredKids++;
		temp = nullptr;
	}
}
