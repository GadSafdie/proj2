//
// Created by hezi on 1/3/19.
//

#ifndef PROJ2_CACHEMANAGER_H
#define PROJ2_CACHEMANAGER_H


#include "Problem.h"
#include "Solution.h"

class CacheManager {

public:
    virtual bool isThereSolution(Problem porblem) = 0;
    virtual Solution getSolution(Problem porblem) = 0;
    virtual void addSolution(Solution s,Problem porblem) = 0;

};


#endif //PROJ2_CACHEMANAGER_H
