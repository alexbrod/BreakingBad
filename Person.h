#ifndef __Person_H
#define __Person_H

class Person
{
	int id;
	char* name;
	Location* location;
	float balance;
public:
	Person(int id, const char* name, const Location* location = nullptr, float balance = 0);
	Person(&Person p) = delete;
	~Person();

	//getters and setters
	int getId() const;
	const char* const getName() const;
	void setName(const char& newName);
	const Location* const getLocation() const;
	void setBalance(float amount);
	float getBalance() const;

	//methods
	void moveToLocation(Location* newLocation);

}

#endif