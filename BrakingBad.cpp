#include <iostream>
#include "DeaAgent.h"
#include "CorruptDeaAgent.h"

int main()
{
	Person p1(1,"Hank");
	Person p2(2,"Jessie");
	DeaAgent agent(p1,4);
	DrugDealer dealer(p2);
	CorruptDeaAgent corruptAgent(agent,dealer,1000);
	return 0;
}

