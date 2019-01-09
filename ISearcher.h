//
// Created by gad on 1/9/19.
//

#ifndef PROJ2_ISEARCHER_H
#define PROJ2_ISEARCHER_H

#include "Searchable.h"

template<class S, class T>

class ISearcher {
public:
    // the search method
    virtual S search(Searchable<T> *searchable) = 0;

// get how many nodes were evaluated by the algorithm
    int getNumberOfNodesEvaluated() = 0;
};


#endif //PROJ2_ISEARCHER_H
