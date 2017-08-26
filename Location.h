#ifndef __Location_H
#define __Location_H

#include "Person.h"

class Location
{
	Location(const Location& location);
	int locationId;
	int numOfPlaces;
	char* name;
	Person** places;
	bool isMethLab;
public:
	Location(int locationId, const char* name, int numOfPlaces = 1, bool isMethLab = false):
	  numOfPlaces(numOfPlaces), isMethLab(isMethLab){}
	~Location();

	//getters and setters
	int getId() const;	
	const char* const getName() const;
	void setName(const char& newName);
	const Person* const getPersonById(int id) const;
	int getNumOfPlaces() const;
	//methods
	void add(Person* person);
	void remove(Person* person);
	void show() const;
	void convertToMethLab();
	void convertToNormalLocation();
};

#endif