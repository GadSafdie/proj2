//
// Created by gad on 1/9/19.
//

#ifndef PROJ2_SEARCHER_H
#define PROJ2_SEARCHER_H


#include <queue>
#include <unordered_set>
#include "State.h"
#include "ISearcher.h"

template<class S, class T>
class Searcher : public ISearcher<S, T> {
    priority_queue<State<T>> openList;
    int evaluatedNodes;

public:
    Searcher() {
        openList = new priority_queue<State<T>>();
        evaluatedNodes = 0;
    }

//    priority_queue<State<T>> popOpenList() {
//        return openList;
//    }

//    bool openListCOntains(){
//        const_iterator find(const priority_queue<State<T>>&val) const
//        {
//            auto first = this->c.cbegin();
//            auto last = this->c.cend();
//            while (first!=last) {
//                if (*first==val) return first;
//                ++first;
//            }
//            return last;
//        }
//    }

protected:
    State<T> popOpenList() {
        evaluatedNodes++;
        return openList.pop();
    }

};

#endif //PROJ2_SEARCHER_H
