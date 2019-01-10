//
// Created by hezi on 1/9/19.
//

#ifndef PROJ2_SEARCHABLE_H
#define PROJ2_SEARCHABLE_H

#include "State.h"
#include <vector>
template <class T>

class Searchable {
protected:
    std::vector<vector<State<T>*>> matrix;
    State<T>* root;
    State<T>* goal;

public:

    virtual vector<vector<State<T>*>> getMatrix(){
        return matrix;
    }

    virtual State <T>* getInitalState(){
        return root;
    }

    virtual State<T>* getGoalState(){
        return goal;
    }

    virtual vector<State<T>*>getAllPossibleStates(State<T>* s) = 0;

    virtual string getDirections(vector<T> path) = 0;

};


#endif //PROJ2_SEARCHABLE_H
