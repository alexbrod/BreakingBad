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
public:
	Person(int id, const char* name, const Location* location = nullptr, float balance = 0);
	Person(const Person& p) = delete;
	~Person();

	//getters and setters
	int getId() const;
	const char* const getName() const;
	void setName(const char& newName);
	const Location* const getLocation() const;
	void setBalance(float amount);
	float getBalance() const;
	void moveToLocation(Location* newLocation);	
};

#endif