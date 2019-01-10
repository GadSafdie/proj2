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

public:
    FileCacheManager() {
        this->flag = 0;
    }

    bool isThereSolution(string porblem) {
        if (flag == 0) {
            ReadFile *readFile;
            cacheMap = readFile->ReadFileCacheManager();
            flag = 1;
        }

        for (typename ::map<P, S>::iterator it = cacheMap.begin(); it != cacheMap.end(); ++it) {
            if (it == cacheMap.end()) {
                return true;
            }
        }
        return false;
    }

    virtual string getSolution(P porblem) {
        return cacheMap.find(porblem)->second;
    }

    virtual void addSolution(S s, P porblem) {
        cacheMap.insert(std::pair<P, S>(porblem, s));
    }


    void exit() {
        WriteFile *write;
        typename ::map<P, S>::iterator iterator;
        P first;
        S second;
        for (iterator = this->cacheMap.begin(); iterator != this->cacheMap.end(); ++iterator) {
            first = iterator->first;
            second = iterator->second;
            write->writeFileCacheManager(first, second);
        }
    }

};


#endif //PROJ2_FILECACHEMANAGER_H
