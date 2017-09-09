#ifndef __Provider_H
#define __Provider_H

#include "DrugDealer.h"

class Provider: public DrugDealer
{
	Ingredient ingredients[NUM_OF_INGREDIENTS];
	Location** locations;
	int fee;
public:
	Provider(int id, char* name = NULL, float balance = 0, int fee = 0):
		Person(id, name, balance), DrugDealer(id, name, balance){cout << "Provider::Provider\n";}
	Provider(const Provider& p) = delete;
	~Provider(){cout << "Provider::~Provider\n";}
	//getters and setters
	const Location * const * const getLocations() const;
	Ingredient* getIngredients() const;
	int getFee() const;
	void setFee(int amount);
	//methods
	void addLocation(const Location& location);
	void addIngredients(const Ingredient*& ingredients);
	void provideTo(Location& location);
	//operators
	virtual bool operator==(const Person& p) const{}
	virtual void toOs(ostream& os) const 
	{
		os << "In Provider fee:" << fee << " ";
	}
};

#endif
