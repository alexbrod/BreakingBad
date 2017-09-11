
#include <iostream>
using namespace std;
#include "DeaAgent.h"
#include "CorruptDeaAgent.h"
#include "Provider.h"
#include "Action.h"
#include "Recipe.h"
#include "Distributor.h"
#include "BreakingBad.h"
#include "Cook.h"



int main()
{
	int constexpr NUM_OF_PERSONS = 12;
	int constexpr NUM_OF_LOCATIONS = 10;
	int constexpr PLACES_IN_LOCATION = 3;
	int constexpr NUM_OF_DEA_AGENTS = 1;
	int constexpr NUM_OF_PROVIDERS = 2;
	int constexpr NUM_OF_DISTRIBUTORS = 2;
	int constexpr NUM_OF_COOKS = 2;
	int constexpr NUM_OF_CORRUPT_AGENTS = 2;
	int constexpr NUM_OF_CLIENTS = 3;
	int constexpr AGENT_SEARCHES = 7;
	int constexpr PROVIDER_FEE = 1500;
	int constexpr PROTECTION_FEE = 500;
    int constexpr NUM_OF_ACTIONS = 4;
    int constexpr NUM_OF_INGREDIENTS = 2;


	Person* persons[NUM_OF_PERSONS];
	Location* locations[NUM_OF_LOCATIONS];
	const char* personsNames[] = {"Hank", "Gomie", "Mike", "Jessie", "Walter", "Marie",
	 	"Skyler", "Gustavo", "Ted", "Sol", "Todd", "Lydia", 0};
	const char* locationNames[] = {"Walter's House", "Laundry", "DEA", "Los Hermanos", 
		"Jessie's House", "The Caravan", "Car Wash", "Hank's House", "Cartel", "Skyler's Office", 0};
    const char* actionNames[] = {"Combine" , "Melt" , "Freeze", "Break and Pack", 0};
    const char* ingredientNames[] = {"Methylamine" , "Aluminium", 0};
	bool isMethLab = false;

    BreakingBad breakingBad;

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
	 		persons[i] = new DeaAgent(i, const_cast<char*>(personsNames[i]), (i + 1) * 1000, AGENT_SEARCHES);
	 		cout << "-------------------\n";
	 		cout << *persons[i] << "\n";	 		
	 		cout << "-------------------\n";

		}
		else if(i < NUM_OF_DEA_AGENTS + NUM_OF_PROVIDERS)
		{
			persons[i] = new Provider(i, const_cast<char*>(personsNames[i]), (i + 1) * 1000, PROVIDER_FEE);
            Ingredient** ingredients = breakingBad.initBreakingBadIngredients(ingredientNames, NUM_OF_INGREDIENTS);
//            ((Provider*)persons[i])->addIngredients(reinterpret_cast<const Ingredient **>(ingredients));
			cout << "-------------------\n";
			cout << *persons[i] << "\n";	 		
	 		cout << "-------------------\n";
		}
		else if(i < NUM_OF_DEA_AGENTS + NUM_OF_PROVIDERS + NUM_OF_DISTRIBUTORS)
		{
			persons[i] = new Distributor(i, const_cast<char *>(personsNames[i]), (i + 1) * 1000);
			cout << "-------------------\n";
		}
		else if(i < NUM_OF_DEA_AGENTS + NUM_OF_PROVIDERS + NUM_OF_DISTRIBUTORS + NUM_OF_COOKS)
		{
			persons[i] = new Cook(i, const_cast<char *>(personsNames[i]), (i + 1) * 1000);
            Action** actions = breakingBad.initActions(actionNames, NUM_OF_ACTIONS);
            Ingredient** ingredients = breakingBad.initIngredients(ingredientNames, NUM_OF_INGREDIENTS);
            Recipe* recipe = breakingBad.createRecepie(actions, ingredients);
            (dynamic_cast<Cook*>(persons[i]))->setRecipe(recipe);
			cout << "-------------------\n";
		}
		else if(i < NUM_OF_DEA_AGENTS + NUM_OF_PROVIDERS + NUM_OF_DISTRIBUTORS + NUM_OF_COOKS + NUM_OF_CLIENTS)
		{
			persons[i] = new Client(i, const_cast<char *>(personsNames[i]), (i + 1) * 1000);
			cout << "-------------------\n";
		}
		else if(i < NUM_OF_DEA_AGENTS + NUM_OF_PROVIDERS + NUM_OF_DISTRIBUTORS + NUM_OF_COOKS + NUM_OF_CLIENTS
			+ NUM_OF_CORRUPT_AGENTS)
		{
			persons[i] = new CorruptDeaAgent(DeaAgent(i, const_cast<char*>(personsNames[i]), (i + 1) * 1000, AGENT_SEARCHES), PROTECTION_FEE);
			cout << "-------------------\n";
			cout << *persons[i] << "\n";	 		
	 		cout << "-------------------\n";
		}
	}

    breakingBad.addPersons(persons);
    breakingBad.addLocations(locations);

    breakingBad.assignProvidersToCooks();
    breakingBad.assignDistributorsToCooks();


    while(breakingBad.endOfGame())
    {
        //random allocation of each person to a location
        breakingBad.allocatePersonsToNewLocations();
        //all persons should do their work
        breakingBad.workForThisTurn();
    }

    breakingBad.showPersonsStats();
    breakingBad.showWhoWon();

	return 1;
}

