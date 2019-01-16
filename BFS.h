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
class BFS : public Searcher<T> {

public:
    string search(Searchable<T> *searchable) {
        this->evaluatedNodes = 0;
        vector<State<T>*> path;
        unordered_set<State<T>*> closed;
        State<T> *goal = searchable->getGoalState();
        this->pushToOpenList(searchable->getInitalState());
        searchable->getInitalState()->setHasVisited();

        typename vector<State<T> *>::iterator it;

        while (!this->getOpenList().empty()) {
            State<T> *n = this->popOpenList();
            if (n->getState() == goal->getState()) {
                *goal = *n;
                closed.insert(goal);
//                cout << n->getCost() << " ";
                path = searchable->backtrace(n);
                break;
            }
//            cout << n->getCost() << " ";
            this->evaluatedNodes++;
            vector<State<T>*> successors = searchable->getAllPossibleStates(n);
            it = successors.begin();
            for (; it != successors.end(); ++it) {
                double currPath = n->getpathCost() + (*it)->getCost();
                (*it)->setcameFrom(n);
                (*it)->setpathCost(currPath);
                this->pushToOpenList(*it);
                }
            }

        string newPath = searchable->getDirections(path);
        if(newPath == ""){
            searchable->getGoalState()->setpathCost(-1);
        }
        return newPath;

    }
};


#endif //PROJ2_BFS_H
