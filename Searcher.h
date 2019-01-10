//
// Created by gad on 1/9/19.
//

#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H


#include <queue>
#include <unordered_set>
#include "State.h"
#include "ISearcher.h"
#include <iostream>
#include <list>

template<class T>
class Searcher : public ISearcher<T> {
protected:
    priority_queue<State<T>> openList;
    int evaluatedNodes;

public:


    priority_queue<State <T>> getOpenList() {
        return openList;
    }


    State<T>* popOpenList() {
        evaluatedNodes++;
        State<T>* s = openList.pop();
        return s;
    }

    void pushToOpenList(State <T> *newSate) {
        openList.push(newSate);
    }

    bool contains(State<T> *check) {
        bool stateCon = false;
        vector<State<T>> temp;
        // check if s is in the queue by pop all the elements
        while (!this->openList.empty()) {
            State<T> var = this->popFromthePq();
            if (var == check) {
                stateCon = true;
                break;
            }
            temp.push_back(var);
        }
        // put back the elements to the original queue

        for (int i = 0; i < temp.size(); i++) {
            this->pushToOpenList(temp[i]);
        }
        return stateCon;

    }


    void updatePriority(State<T> *check) {
        vector<State<T>> temp;
        // check if s is in the queue by pop all the elements
        while (!this->openList.empty()) {
            State<T> var = this->popFromthePq();
            if (var == check) {
                temp.push_back(check); // change the state in the new one
            } else {
                temp.push_back(var); // add the other states
            }
        }
        // put back the elements to the original queue
        for (int i = 0; i < temp.size(); i++) {
            this->pushToOpenList(temp[i]);
        }
    }


    vector<State<T> *> backtrace(State<T> *goal) {
        vector<State<T> *> path;
        path.push_back(goal);

        while (goal->getCamefrom() != NULL) {
            State<T> *dad = goal->getCamefrom();
            path.push_back(dad);
            goal = dad;
        }
        reverse(path.begin(), path.end());
        return path;
    }

    virtual string search(Searchable<T> *searchable) = 0;

    virtual int getNumberOfNodesEvaluated(){
        return evaluatedNodes;
    }

};

#endif //PROJ2_SEARCHER_H
