#ifndef __Location_H
#define __Location_H

class Location
{
	int locationId
	int numOfPlaces;
	char* name;
	Person* places;
	bool isMethLab;
public:
	Location(const char* name, int numOfPlaces = 1, bool isMethLab = false, int locationId);
	Location(const Location& location) = delete;
	~Location();

	//getters and setters
	const char* const getName() const;
	void setName(const char& newName);
	const Person* const getPersonById(int id) const;
	int getId() const;
	int getNumOfPlaces() const;
	//methods
	void add(const &Person person);
	void remove(const &Person person);
	void show() const;
	void convertToMethLab();
	void convertToNormalLocation();
}

#endif