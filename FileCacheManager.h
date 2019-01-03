//
// Created by hezi on 1/3/19.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H

#include <string>
#include <list>
#include <map>
#include "CacheManager.h"
#include "Solution.h"
#include "Problem.h"


using namespace std;

class FileCacheManager : public CacheManager {
    map<Problem,list<Solution>> map1;

 public:
    virtual bool isThereSolution(Problem porblem);
    virtual Solution getSolution(Problem porblem);
    virtual void addSolution(Solution s,Problem porblem);
};


#endif //PROJ2_FILECACHEMANAGER_H
