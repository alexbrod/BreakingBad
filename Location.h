#ifndef __Location_H
#define __Location_H


class Person;

class Location
{
	int id;
	int numOfPlaces;
	char* name;
	Person** places;
	bool isMethLab;
public:
	Location(int id, char* name = NULL, int numOfPlaces = 1, bool isMethLab = false):
	  id(id), name(name), numOfPlaces(numOfPlaces), isMethLab(isMethLab){cout << "Location::Location\n";}
	Location(const Location& location) = delete;
	~Location(){cout << "Location::~Location\n";}

	//getters and setters
	int getId() const {return id;}	
	const char* const getName() const{return name;}
	void setName(const char& newName);
	const Person* const getPersonById(int id) const;
	int getNumOfPlaces() const{return numOfPlaces;}
	bool getIsMethLab() const{return isMethLab;}
	//methods
	void add(Person* person);
	void remove(Person* person);
	void convertToMethLab();
	void convertToNormalLocation();
	//operators
	bool operator==(const Location& location) const;
	friend ostream& operator<<(ostream& os, const Location& l)
	{
		os << "In Location id:" << l.getId() << 
			" name:" << l.getName() << " numOfPlaces:" << l.getNumOfPlaces() <<
			" isMethLab:" << l.getIsMethLab() << "\n";
	}
};

#endif
