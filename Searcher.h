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

template<class S, class T>
class Searcher : public ISearcher<S, T> {
    priority_queue<State<T>> openList;
    int evaluatedNodes;

public:
    Searcher() {
        openList = new priority_queue<State<T>>();
        evaluatedNodes = 0;
    }


protected:

    priority_queue<State<T>> getOpenList(){
        return openList;
    }


    State<T> popOpenList() {
        evaluatedNodes++;
        return openList.pop();
    }

    void pushToOpenList(State<T>* newSate){
        openList.push(newSate);
    }

    bool contains(State<T>* check){
        bool stateCon = false;
        vector<State <T>> temp;
        // check if s is in the queue by pop all the elements
        while(!this->pq.empty()){
            State<T> var = this->popFromthePq();
            if(var == check){
                stateCon = true;
                break;
            }

        }
        // put back the elements to the original queue

        for(int i = 0 ; i <temp.size();i++ ){
            this->pushToOpenList(temp[i]);
        }

        return stateCon;

    }


    void updatePriority(State<T>* check){

    }



};

#endif //PROJ2_SEARCHER_H
