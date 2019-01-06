//
// Created by hezi on 1/3/19.
//

#include "FileCacheManager.h"


void FileCacheManager::addSolution(Solution s,Problem p) {
    map1.insert ( std::pair<Problem,Solution>(p,s));
}

bool FileCacheManager::isThereSolution(Problem porblem) {
    map<Problem,Solution>::iterator i = map1.find(porblem);
    if (i == map1.end()) {
        return false;
    }else {
        return true;
    }
}


Solution FileCacheManager :: getSolution(Problem porblem){
    return map1.find(porblem)->second;
}

