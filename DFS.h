//
// Created by gad on 1/10/19.
//

#ifndef PROJ2_DFS_H
#define PROJ2_DFS_H


#include "Searchable.h"
#include "Searcher.h"
#include <stack>

template<class T>

class DFS : public Searcher<T> {

public:
    string search(Searchable<T> *searchable) {
        this->evaluatedNodes = 0;
        State<T>* goal = searchable->getGoalState();
        stack<State<T>*> stack;
        State<T>* current = searchable->getInitalState();
        current->setcameFrom(NULL);

        typename vector<State<T>*>::iterator it;

        stack.push(current);

        while (!stack.empty())
        {
            current = stack.top();
            stack.pop();
            this->evaluatedNodes+=1;
            if(current->getState() == goal->getState()){
                *current = *goal;
                break;
            }
            if (!current->getHasVisited())
            {
                current->setHasVisited();
            }
            vector<State<T>*> checkIfCanGo = searchable->getAllPossibleStates(current);
            it = checkIfCanGo.begin();
            for(; it!= checkIfCanGo.end() ;++it){
                    State<T>* temp = *it;
                    double currPath = current->getpathCost() + temp->getCost();
                    temp->setcameFrom(current);
                    temp->setpathCost(currPath);
                    stack.push(temp);
            }
        }
        vector<State<T>*> path = searchable->backtrace(current);
        string solution =  searchable->getDirections(path);
        if(solution == ""){
            searchable->getGoalState()->setpathCost(-1);
        }
        return solution;
    }

};


#endif //PROJ2_DFS_H
