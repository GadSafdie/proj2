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
                break;
            }

            // Stack may contain same vertex twice. So
            // we need to print the popped item only
            // if it is not visited.
            if (!current->getHasVisited())
            {
                current->setHasVisited();
            }
            vector<State<T>*> canGo = searchable->getAllPossibleStates(current);
            it = canGo.begin();
            for(; it!= canGo.end() ;++it){
                State<T>* temp = *it;
                    temp->setcameFrom(current);
                    stack.push(temp);
            }

        }

        vector<State<T>*> path = searchable->backtrace(current);
        string solution =  searchable->getDirections(path);
        return solution;
    }

};


#endif //PROJ2_DFS_H
