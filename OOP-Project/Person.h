#ifndef PERSON_H
#define PERSON_H
#include<string>

class Person
{
public:
	Person();
	Person(const std::string&,const int&,const char&);
	virtual ~Person();
	std::string getName()const;
	int getAge()const;
	char getGender()const;
	void setName(const std::string&);
	void setAge(const int&);
	void setGender(const char&);

private:
	std:: string    Name;  
	int				Age;  
	char			Gender;
};
#endif

