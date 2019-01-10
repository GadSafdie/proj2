//
// Created by hezi on 1/9/19.
//

#ifndef PROJ2_SEARCHABLE_H
#define PROJ2_SEARCHABLE_H

#include "State.h"
#include "vector"

class Searchable {
public:

    virtual State* getInitalState() = 0;

    virtual State* getGoalState() = 0;

    virtual vector<State>getAllPossibleStates(State* s) = 0;

    virtual void InitlizeAllStates() = 0;

    virtual string getDirections(vector<State> path) = 0;

};


#endif //PROJ2_SEARCHABLE_H
