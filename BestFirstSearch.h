//
// Created by gad on 1/9/19.
//

#ifndef PROJ2_BESTFIRSTSEARCH_H
#define PROJ2_BESTFIRSTSEARCH_H

#include <list>
#include "Searcher.h"
#include <unordered_set>

template<class T>
class BestFirstSearch : public Searcher<T> {


public:

    string search(Searchable<T> *searchable) { // Searcher's abstract method overriding
        this->evaluatedNodes = 0;
        this->openList.push(searchable->getInitalState());// inherited from Searcher
        this->evaluatedNodes++;
        searchable->getInitalState()->setHasVisited();
        vector<State<T>*> path;
        unordered_set<State<T>*> closed;
        while (this->getOpenList().size() > 0) {

            State<T>* n = this->popOpenList(); // inherited from Searcher, removes the best state
            closed.insert(n);
            State<T>* goal = searchable->getGoalState();
            if (n->getState() == goal->getState()){
                path = searchable->backtrace(n);
                break;
            }
            this->evaluatedNodes++;
// calling the delegated method, returns a list of states with n as a parent
            vector<State<T>*> succerssors = searchable->getAllPossibleStates(n);
            std::list<State<T>*> myList(succerssors.begin(), succerssors.end());
            typename list<State<T>*>::iterator s;
            for (s = myList.begin(); s != myList.end(); ++s) {
                State<T>* temp = *s;
                double currPath = n->getpathCost() + temp->getCost();
                const bool is_in = closed.find(temp) != closed.end();
                if ((is_in == false) && !(this->contains(temp))) {
                    temp->setcameFrom(n);
                    temp->setpathCost(currPath);
                    this->pushToOpenList(temp);
                } else if (currPath < temp->getpathCost()) {
                    if (!this->contains(temp)){
                        if(temp->getCost() == -1) {
                            cout << "gadifff" << endl;
                        }
                        this->openList.push(temp);
                    } else {
                        this->updatePriority(temp,n);
                    }
                }
            }
        }
        string solution = searchable->getDirections(path);
        if(solution == ""){
            searchable->getGoalState()->setpathCost(-1);
        }
        return solution;
    }







};


#endif //PROJ2_BESTFIRSTSEARCH_H
