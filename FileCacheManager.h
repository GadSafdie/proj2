//
// Created by hezi on 1/3/19.
//

#ifndef PROJ2_FILECACHEMANAGER_H
#define PROJ2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "Solution.h"
#include "Problem.h"
#include "WriteFile.h"
#include "MyTestClientHandler.h"
#include "ReadFile.h"

using namespace std;

template<class P, class S>
class FileCacheManager : public CacheManager<P, S> {
    map<P, S> cacheMap;
    int flag;
    string ans;

public:
    FileCacheManager() {
        this->flag = 0;
    }

    bool isThereSolution(P porblem) {
        if (flag == 0) {
            ReadFile *readFile;
            cacheMap = readFile->ReadFileCacheManager();
            flag = 1;
        }
        std::map<MatrixProblem*, string>::iterator it;
        for (it=cacheMap.begin(); it!=cacheMap.end(); ++it){
            MatrixProblem* temp = it->first;
            if(*porblem == *temp) {
                ans = it->second;
                return true;
            }
        }
        return false;
    }

    virtual string getSolution(P porblem) {
        return ans;
    }

    map<P, S> getCacheMap(){
        return cacheMap;
    }


    virtual void addSolution(S s, P porblem) {
        s=s+'\n';
        cacheMap.insert(std::pair<P, S>(porblem, s));
    }


    void exit() {
//        WriteFile *write;
//        typename ::map<P, S>::iterator iterator;
//        P first;
//        S second;
//        for (iterator = this->cacheMap.begin(); iterator != this->cacheMap.end(); ++iterator) {
//            first = iterator->first;
//            second = iterator->second;
//            write->writeFileCacheManager(first, second);
//        }
    }

};


#endif //PROJ2_FILECACHEMANAGER_H
