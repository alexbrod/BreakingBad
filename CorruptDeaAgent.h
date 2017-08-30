#ifndef __CorruptDeaAgent_H
#define __CorruptDeaAgent_H

#include "DeaAgent.h"
#include "DrugDealer.h"

class CorruptDeaAgent: public DeaAgent, public DrugDealer
{
	int maxProtectionDemands;
public:
	CorruptDeaAgent(const DeaAgent& agent, const DrugDealer& dealer, int maxProtectionDemands = 0):
	  Person(agent.getId(), agent.getName()), DeaAgent(agent), DrugDealer(dealer),
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
