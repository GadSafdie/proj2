//
// Created by hezi on 1/10/19.
//

#ifndef PROJ2_MATRIXPROBLEM_H
#define PROJ2_MATRIXPROBLEM_H

#include "Searchable.h"

template<class T>
class MetrixProblem : public Searchable<T> {
    vector<vector<State<vector<int>>*>> metrix;
    State<T>* root;
    State<T>* goal;

public:
    virtual State <T> getInitalState(){
        return root;
    }
    virtual State<T> getGoalState(){
        return goal;
    }

    virtual vector<State<T>>getAllPossibleStates(State<T> s){


    }

    virtual string getDirections(vector<State<T>> path){

    }





};


#endif //PROJ2_MATRIXPROBLEM_H
