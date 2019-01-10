//
// Created by hezi on 1/9/19.
//

#ifndef PROJ2_SEARCHABLE_H
#define PROJ2_SEARCHABLE_H

#include "State.h"
#include "vector"
template <class T>

class Searchable {
public:

    virtual State <T> getInitalState() = 0;

    virtual State<T> getGoalState() = 0;

    virtual vector<State<T>>getAllPossibleStates(State<T> s) = 0;

    virtual void InitlizeAllStates() = 0;

    virtual string getDirections(vector<State<T>> path) = 0;

};


#endif //PROJ2_SEARCHABLE_H
