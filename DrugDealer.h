#ifndef __DrugDealer_H
#define __DrugDealer_H

#include "Person.h"

class DrugDealer: virtual public Person
{
protected:
	bool arrested;
	
	DrugDealer(const DrugDealer& dealer): Person(dealer), arrested(arrested)
		{cout << "DrugDealer::DrugDealer(copy)\n";}
	DrugDealer(int id, char* name = NULL, float balance = 0): 
		Person(id, name, balance) ,arrested(false){cout << "DrugDealer::DrugDealer\n";}

public:
	virtual ~DrugDealer(){cout << "DrugDealer::~DrugDealer\n";}

	//getters and setters
	bool isArrested() const;
	void getArrested();
	//operators
	virtual bool operator==(const Person& p) const =0;
	virtual void toOs(ostream& os) const
	{
		os << "In DrugDealer arrested:" << arrested << " ";
	}
	
};

#endif
