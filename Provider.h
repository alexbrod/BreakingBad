#ifndef __Provider_H
#define __Provider_H

class Provider: public DrugDealer
{
	int ingridientTypesNum;
	Ingridient ingridients[ingridientTypesNum];
	Location** locations;
public:
	Provider(int id, char* name, ingridientTypesNum = 1);
};

#endif