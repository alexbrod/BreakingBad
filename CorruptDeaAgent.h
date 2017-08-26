#ifndef __CorruptDeaAgent_H
#define __CorruptDeaAgent_H

#include "DeaAgent.h"
#include "DrugDealer.h"

class CorruptDeaAgent: public DeaAgent, public DrugDealer
{
	int maxProtectionDemands;
public:
	CorruptDeaAgent(int id, const char* name, int maxSearches, int maxProtectionDemands = 0):
	  Person(id, name), DeaAgent(id, name, maxSearches), DrugDealer(id, name),
		  maxProtectionDemands(maxProtectionDemands){}
	CorruptDeaAgent(CorruptDeaAgent& agent) = delete;
	~CorruptDeaAgent();

	//getters and setters
	int getMaxProtectionDemands() const;
	void setMaxProtectionDemands(int num);
	//methods
	float getProtection(DrugDealer& dealer);
	//Override. if drug dealer is a corrupt agent, get bribe from him for not arresting him
	void arrest(DrugDealer* dealer); 
	float getBribe(CorruptDeaAgent* agent);
};

#endif