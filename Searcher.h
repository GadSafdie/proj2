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
    class Compere {
    public:
        bool operator()(State<T>* left, State<T>* right) {
            return (left->getpathCost()) > (right->getpathCost());
        }
    };

protected:
    priority_queue<State<T>*, vector<State<T>*>, Compere> openList;
    int evaluatedNodes;

public:

    priority_queue<State<T>*, vector<State<T>*>,Compere> getOpenList() {
        return openList;
    }


    State<T>* popOpenList() {
        State<T>* s = openList.top();
        openList.pop();
        return s;
    }

    void pushToOpenList(State <T> *newSate) {
       openList.push(newSate);
    }

    bool contains(State<T> *check) {
        bool stateCon = false;
        vector<State<T>*> temp;
        // check if s is in the queue by pop all the elements
        while (!this->openList.empty()) {
            State<T>* var = this->popOpenList();
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

    void updatePriority(State<T> *current,State<T> *update) {
        double cost;
        vector<State<T>*> temp;
        while (!this->openList.empty()){
            State<T>* top = this->popOpenList();
            temp.push_back(top);
            if(current == top){
                top->setcameFrom(update);
                cost = update->getpathCost()+current->getCost();
                top->setpathCost(cost);
                break;
            }
        }
        for(int i = 0 ; i<temp.size();i++){
            this->openList.push(temp[i]);
        }
    }

    virtual string search(Searchable<T> *searchable) = 0;

    virtual int getNumberOfNodesEvaluated(){
        return evaluatedNodes;
    }

    void setNumberOfNodesEvaluated(int nodes){
        this->evaluatedNodes = nodes;
    }

};

#endif //PROJ2_SEARCHER_H
