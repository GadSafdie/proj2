//
// Created by gad on 1/10/19.
//

#ifndef PROJ2_BFS_H
#define PROJ2_BFS_H

#include <unordered_set>
#include <list>
#include "Searchable.h"
#include "Searcher.h"
using namespace std;



template<class T>

class BFS : public Searcher<string, T> {

public:
    string search(Searchable<T> *searchable) {
          State<T> *root = searchable->getInitalState();
          State<T> *goal = searchable->getGoalState();
          root->

    }
};


#endif //PROJ2_BFS_H
