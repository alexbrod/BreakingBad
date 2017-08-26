#ifndef __DrugDealer_H
#define __DrugDealer_H

#include "Person.h"

class DrugDealer: virtual public Person
{
protected:
	bool arrested;
public:
	DrugDealer(int id, const char* name): Person(id,name), arrested(false){}
	DrugDealer(const DrugDealer& d) = delete;
	~DrugDealer();

	//getters and setters
	bool isArrested() const;
	void getArrested();

};

#endif