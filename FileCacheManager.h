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


class FileCacheManager : public CacheManager<string,string> {
    map<string,string> map1;

 public:
    FileCacheManager(){};
    virtual bool isThereSolution(string porblem);
    virtual string getSolution(string porblem);
    virtual void addSolution(string s,string porblem);
};


#endif //PROJ2_FILECACHEMANAGER_H
