//
// Created by vladimir khotyakov on 06/09/2017.
//

#ifndef BREAKINGBAD_RECIPE_H
#define BREAKINGBAD_RECIPE_H

#include "Ingredient.h"
#include "Action.h"

class Recipe{

protected:
    Ingredient* ingredient;
    Action* action;

public:
    Recipe(Ingredient *ingredient, Action *action) : ingredient(ingredient), action(action) {}
};

#endif //BREAKINGBAD_RECIPE_H
