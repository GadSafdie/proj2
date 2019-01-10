//
// Created by gad on 1/10/19.
//

#ifndef PROJ2_DFS_H
#define PROJ2_DFS_H


#include "Searchable.h"

template<class T>

class DFS {

public:
    string search(Searchable<T> *searchable) {
        DfsFunction(searchable->getInitalState(),searchable->getGoalState());
    }

};


#endif //PROJ2_DFS_H
