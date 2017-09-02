#ifndef __Person_H
#define __Person_H

#include "Location.h"


class Person
{
protected:
	int id;
	char* name;
	Location* location;
	float balance;
	
	Person(const Person& p): id(id), name(name), balance(balance) {cout << "Person::Person(copy)\n";}
	Person(int id, char* name = NULL, float balance = 0, Location* location = nullptr):
		id(id), balance(balance), location(location){cout << "Person::Person\n";}

public:
	virtual ~Person(){cout << "Person::~Person\n";}

	//getters and setters
	int getId() const {return id;}
	char* const getName() const{return name;}
	void setName(const char& newName);
	const Location* const getLocation() const{return location;}
	void setBalance(float amount);
	float getBalance() const{return balance;}
	void moveToLocation(Location* newLocation);	
	//operators
	virtual bool operator==(const Person& p) const =0;
	virtual void toOs(ostream& os) const {}
	friend ostream& operator<<(ostream& os, const Person& p)
	{
		os	<< "In Person id:" << p.getId() << //" name:" << p.getName() <<
			 " location:" << p.getLocation() << " balance:" << p.getBalance() << "\n";
	}
};

#endif
