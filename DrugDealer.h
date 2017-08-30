#ifndef __DrugDealer_H
#define __DrugDealer_H

#include "Person.h"

class DrugDealer: virtual public Person
{
protected:
	bool arrested;
	
	DrugDealer(const DrugDealer& d);
public:
	DrugDealer(const Person& p): Person(p) ,arrested(false){}
	~DrugDealer();

	//getters and setters
	bool isArrested() const;
	void getArrested();

};

#endif
