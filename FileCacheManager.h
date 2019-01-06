//
// Created by hezi on 1/3/19.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H

#include <map>
#include <vector>
#include "CacheManager.h"
#include "Solution.h"
#include "Problem.h"


using namespace std;

class FileCacheManager : public CacheManager {
    map<Problem,Solution> map1;

 public:
    FileCacheManager();
    virtual bool isThereSolution(Problem porblem);
    virtual Solution getSolution(Problem porblem);
    virtual void addSolution(Solution s,Problem porblem);
};


#endif //PROJ2_FILECACHEMANAGER_H
