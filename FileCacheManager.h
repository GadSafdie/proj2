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
#include "WriteFile.h"
#include "MyTestClientHandler.h"


using namespace std;


class FileCacheManager : public CacheManager<string,string> {
    map<string,string> cacheMap;
    int flag;

 public:
    FileCacheManager(){
        this->flag=0;
    }
    bool isThereSolution(string porblem);
    virtual string getSolution(string porblem);
    virtual void addSolution(string s,string porblem);

    map<string,string> getCacheMap(){
        return cacheMap;
    }
    void exit(){
        WriteFile *write;
        map<string,string>::const_iterator iterator;
        string first;
        string second;
        for (iterator =  this->cacheMap.begin(); iterator != this->cacheMap.end(); ++iterator) {
            first = iterator->first;
            second = iterator->second;
            write->writeFileCacheManager(first,second);
        }
    }

};


#endif //PROJ2_FILECACHEMANAGER_H
