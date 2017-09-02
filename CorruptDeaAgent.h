#ifndef __CorruptDeaAgent_H
#define __CorruptDeaAgent_H

#include "DeaAgent.h"
#include "DrugDealer.h"

class CorruptDeaAgent: public DeaAgent, public DrugDealer
{
	int maxProtectionDemands;
protected:
	CorruptDeaAgent(CorruptDeaAgent& agent) = delete;
	float getBribe(CorruptDeaAgent* agent);
public:
	CorruptDeaAgent(const DeaAgent& agent, int maxProtectionDemands = 0):
	  	Person(agent.getId(), agent.getName(), agent.getBalance()), DeaAgent(agent),
		DrugDealer(agent.getId(), agent.getName(), agent.getBalance()),
		maxProtectionDemands(maxProtectionDemands){cout << "In CorruptDeaAgent::CorruptDeaAgent\n";}
	~CorruptDeaAgent(){cout << "In CorruptDeaAgent::~CorruptDeaAgent\n";}

	//getters and setters
	int getMaxProtectionDemands() const;
	void setMaxProtectionDemands(int num);
	//methods
	float getProtection(DrugDealer& dealer);
	virtual void arrest(DrugDealer* dealer) override{}
	virtual void arrest(DrugDealer** dealer) override{} 
	//operators
	virtual bool operator==(const Person& p) const{}
	virtual void toOs(ostream& os) const
	{
		os << "In CorruptDeaAgent maxProtectionDemands:" << maxProtectionDemands << " ";
	}
};

#endif
