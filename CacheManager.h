//
// Created by hezi on 1/3/19.
//

#ifndef PROJ2_CACHEMANAGER_H
#define PROJ2_CACHEMANAGER_H


#include "Problem.h"
#include "Solution.h"
template <class P, class S>
class CacheManager {

public:
    CacheManager(){};
    virtual bool isThereSolution(P porblem) = 0;
    virtual S getSolution(P porblem) = 0;
    virtual void addSolution(S s,P porblem) = 0;

};


#endif //PROJ2_CACHEMANAGER_H
