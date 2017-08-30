#ifndef __Provider_H
#define __Provider_H

#include "DrugDealer.h"

class Provider: public DrugDealer
{
	static constexpr INGRIDIENTS_TYPES = 2;
	Ingridient ingridients[INGRIDIENTS_TYPES];
	Location** locations;
	int fee;
public:
	Provider(const DrugDealer& dealer, int fee);
	Provider(const Provider& p) = delete;
	~Provider();
	//getters and setters
	const Location** const getLocations() const;
	Ingridient[] getIngridients() const;
	int getFee() const;
	void setFee(int amount);
	//methods
	void addLocation(const Location& location);
	void addIngridient(const Ingridient&);
	void provideTo(Location& location);
	
};

#endif
