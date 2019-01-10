//
// Created by hezi on 1/10/19.
//

#ifndef PROJ2_MATRIXPROBLEM_H
#define PROJ2_MATRIXPROBLEM_H

#include "Searchable.h"

template<class T>
class MatrixProblem : public Searchable<T> {
    vector<vector<State<vector<int>> *>> metrix;
    State<T> start;
    State<T> goal;

public:
    virtual State <T> getInitalState(){
        t





    }

    virtual State<T> getGoalState(){

    }

    virtual vector<State<T>>getAllPossibleStates(State<T> s);

    virtual void InitlizeAllStates();



};


#endif //PROJ2_MATRIXPROBLEM_H
