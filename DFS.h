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
//            cout<<current->getCost()<< "";
            this->evaluatedNodes+=1;

            if(current->getState() == goal->getState()){
//                cout<<current->getCost()<< "";
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
                    temp->setcameFrom(current);
                    stack.push(temp);
            }

        }

        vector<State<T>*> path = searchable->backtrace(current);
        string solution =  searchable->getDirections(path);
        if(solution == ""){
            solution = "-1";
        }
        return solution;
    }

};


#endif //PROJ2_DFS_H
