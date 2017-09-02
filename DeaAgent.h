#ifndef __DeaAgent_H
#define __DeaAgent_H

#include "Person.h"
class DrugDealer;

class DeaAgent: virtual public Person
{
protected:
	int maxSearches;
	int numOfArrests;
	
	DeaAgent(const DeaAgent& agent): Person(agent), maxSearches(maxSearches),
		numOfArrests(numOfArrests) {cout << "DeaAgent::DeaAgent(copy)\n";}
public:
	DeaAgent(int id, char* name = NULL, float balance = 0, int maxSearches = 1): 
	  Person(id, name, balance), numOfArrests(0), maxSearches(maxSearches){cout << "DeaAgent::DeaAgent\n";}
	virtual ~DeaAgent(){cout << "DeaAgent::~DeaAgent\n";}

	//getter and setters
	int getMaxSearches() const;
	void setMaxSearches(int num);
	int getNumOfArrests() const;
	void setNumOfArrests(int num);

	//methods
	DrugDealer** const Search(const Location& location) const; 
	virtual void arrest(DrugDealer** dealers){}
	virtual void arrest(DrugDealer* dealer){}
	//operators
	virtual bool operator==(const Person& p) const{}
	virtual void toOs(ostream& os) const
	{
		os << "In DeaAgent maxSearches:" << maxSearches << " numOfArrests: ";
	}
};

#endif
