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
        vector<State<T>> path;
        unordered_set<State<T>> closed;
        State<T> *root = searchable->getInitalState();
        State<T> *goal = searchable->getGoalState();
        root->setHasVisited();
        this->pushToOpenList(root);

        typename vector<State<T> *>::iterator it;

        while (!this->getOpenList().empty()) {
            State<T> *n = this->popOpenList();
            if (n == goal) {
                closed.insert(goal);
                path = this->backTrace(goal);
                break;
            }

            vector<State<T>> successors = searchable->getAllPossibleStates(root);
            it = successors.begin();
            for (; it != successors.end(); ++it) {
                if ((*it)->getHasVisited() == false) {
                    (*it)->setcameFrom(n);
                    this->pushToOpenList(n);
                    (*it)->setHasVisited();
                }
            }
        }

        string newPath = searchable->getDirections;
cour<<"gadd"<<endl;
        return newPath;

    }
};


#endif //PROJ2_BFS_H
