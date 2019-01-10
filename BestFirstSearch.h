//
// Created by gad on 1/9/19.
//

#ifndef PROJ2_BESTFIRSTSEARCH_H
#define PROJ2_BESTFIRSTSEARCH_H

#include <unordered_set>
#include <list>
#include <vector>
#include "Searcher.h"

template<class T
class BestFirstSearch : public Searcher<string, T> {


public:
    string search(Searchable<T> *searchable) { // Searcher's abstract method overriding
        this->pushToOpenList(searchable->getInitalState()); // inherited from Searcher
        unordered_set<State<T>> closed;

        while (this->getOpenList().size() > 0) {
            State<T> n = this->popOpenList(); // inherited from Searcher, removes the best state
            closed.insert(n);
            if (n == (searchable->getGoalState()))
                return backtrace(n); // priv ate method, back traces through the parents
                                    // calling the delegated method, returns a list of states with n as a parent
            list<State<T>> succerssors = searchable->getAllPossibleStates(n);
            typename list<State<T>>::iterator s;
            for (s = succerssors.begin(); s != succerssors.end(); ++s) {
                double currPath = n.getpathCost() + *s->getCost();
                if (!(closed.find(*s)) && !(this->contains(*s))) {
                    *s->setcameFrom(n);
                    *s->setpathCost(currPath);
                    this->pushToOpenList(*s);
                } else if (currPath < *s->getpathCost()) {
                    if (!this->contains(*s)) {
                        this->pushToOpenList(*s);
                    } else {
                        this->updatePriority(*s);
                    }
                }
            }
        }

    }


};


#endif //PROJ2_BESTFIRSTSEARCH_H
