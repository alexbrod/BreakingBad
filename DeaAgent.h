#ifndef __DeaAgent_H
#define __DeaAgent_H

#include "Person.h"
class DrugDealer;

class DeaAgent: virtual public Person
{
protected:
	int maxSearches;
	int numOfArrests;
public:
	DeaAgent(int id, const char* name, int maxSearches = 1): 
	  Person(id,name), numOfArrests(0), maxSearches(maxSearches){}
	DeaAgent(const DeaAgent& agent) = delete;
	~DeaAgent();

	//getter and setters
	int getMaxSearches() const;
	void setMaxSearches(int num);
	int getNumOfArrests() const;
	void setNumOfArrests(int num);

	//methods
	DrugDealer** const Search(const Location& location); 
	void arrest(DrugDealer** dealers);
	void arrest(DrugDealer* dealer);
};

#endif
