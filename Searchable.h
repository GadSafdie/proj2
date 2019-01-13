//
// Created by hezi on 1/9/19.
//

#ifndef PROJ2_SEARCHABLE_H
#define PROJ2_SEARCHABLE_H

#include "State.h"
#include <vector>
#include <algorithm>

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

    virtual string getDirections(vector<State<T>*> path) = 0;


    vector<State<T>*> backtrace(State<T>* g) {
        vector<State<T>*> path;
        path.push_back(g);

        while(g->getCamefrom()!= NULL){
            State<T> *dad = g->getCamefrom();

            path.push_back(dad);
            g = dad;
        }

        reverse(path.begin(),path.end());
        return path;
    }





};


#endif //PROJ2_SEARCHABLE_H
