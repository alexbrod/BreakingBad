
#include <iostream>
using namespace std;
#include "DeaAgent.h"
#include "CorruptDeaAgent.h"
#include "Provider.h"
#include "Client.h"

int main()
{
	int constexpr NUM_OF_PERSONS = 12;
	int constexpr NUM_OF_LOCATIONS = 10;
	int constexpr PLACES_IN_LOCATION = 3;
	int constexpr NUM_OF_DEA_AGENTS = 1;
	int constexpr NUM_OF_PROVIDERS = 2;
	int constexpr NUM_OF_DISTRIBUTERS = 2;
	int constexpr NUM_OF_COOCKS = 2;
	int constexpr NUM_OF_CORRUPT_AGENTS = 2;
	int constexpr NUM_OF_CLIENTS = 3;
	int constexpr AGENT_SEARECHES = 7;
	int constexpr PROVIDER_FEE = 1500;
	int constexpr PROTECTION_FEE = 500;

	Person* persons[NUM_OF_PERSONS];
	Location* locations[NUM_OF_LOCATIONS];
	const char* personsNames[] = {"Hank", "Gomie", "Mike", "Jessie", "Walter", "Marie",
	 	"Skyler", "Gustavo", "Ted", "Sol", "Todd", "Lydia", 0};
	const char* locationNames[] = {"Walter's House", "Laundry", "DEA", "Los Hermanos", 
		"Jessie's House", "The Caravan", "Car Wash", "Hank's House", "Cartel", "Skyler's Office", 0};
	bool isMethLab = false;
	
	
	cout << "name 0: " << locationNames[0] << "\n";
	//create locations array
	cout << "create locations array:\n";

	for(int i = 0; i<NUM_OF_LOCATIONS; i++)
	{
		cout << "new location:\n";
		locations[i] = new Location(i,const_cast<char*>(locationNames[i]), PLACES_IN_LOCATION, isMethLab);
		isMethLab = !isMethLab;
		cout << "-------------------\n";
		cout << *locations[i] << "\n";
		cout << "-------------------\n";
	}
	 
	//create Persons array
	cout << "create persons array:\n";
	for(int i = 0; i<NUM_OF_PERSONS; i++)
	{
	 	if(i < NUM_OF_DEA_AGENTS)
	 	{
	 		persons[i] = new DeaAgent(i, const_cast<char*>(personsNames[i]), (i + 1) * 1000, AGENT_SEARECHES);
	 		cout << "-------------------\n";
	 		cout << *persons[i] << "\n";	 		
	 		cout << "-------------------\n";

		}
		else if(i < NUM_OF_DEA_AGENTS + NUM_OF_PROVIDERS)
		{
			persons[i] = new Provider(i, const_cast<char*>(personsNames[i]), (i + 1) * 1000, PROVIDER_FEE);
			cout << "-------------------\n";
			cout << *persons[i] << "\n";	 		
	 		cout << "-------------------\n";
		}
		else if(i < NUM_OF_DEA_AGENTS + NUM_OF_PROVIDERS + NUM_OF_DISTRIBUTERS)
		{
			//persons[i] = new Distributer(i, personsNames[i], (i + 1) * 1000);
			cout << "-------------------\n";
		}
		else if(i < NUM_OF_DEA_AGENTS + NUM_OF_PROVIDERS + NUM_OF_DISTRIBUTERS + NUM_OF_COOCKS)
		{
			//persons[i] = new Coock(i, personsNames[i], (i + 1) * 1000);
			cout << "-------------------\n";
		}
		else if(i < NUM_OF_DEA_AGENTS + NUM_OF_PROVIDERS + NUM_OF_DISTRIBUTERS + NUM_OF_COOCKS + NUM_OF_CLIENTS)
		{
			persons[i] = new Client(i, const_cast<char *>(personsNames[i]), (i + 1) * 1000);
			cout << "-------------------\n";
		}
		else if(i < NUM_OF_DEA_AGENTS + NUM_OF_PROVIDERS + NUM_OF_DISTRIBUTERS + NUM_OF_COOCKS + NUM_OF_CLIENTS
			+ NUM_OF_CORRUPT_AGENTS)
		{
			persons[i] = new CorruptDeaAgent(DeaAgent(i, const_cast<char*>(personsNames[i]), (i + 1) * 1000, AGENT_SEARECHES), PROTECTION_FEE);
			cout << "-------------------\n";
			cout << *persons[i] << "\n";	 		
	 		cout << "-------------------\n";
		}
	}
	
	
	return 1;
}

