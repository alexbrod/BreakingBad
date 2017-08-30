#ifndef __DeaAgent_H
#define __DeaAgent_H

#include "Person.h"
class DrugDealer;

class DeaAgent: virtual public Person
{
protected:
	int maxSearches;
	int numOfArrests;
	
	DeaAgent(const DeaAgent& agent);
public:
	DeaAgent(const Person& p, int maxSearches = 1): 
	  Person(p), numOfArrests(0), maxSearches(maxSearches){}
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
