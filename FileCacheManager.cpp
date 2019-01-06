//
// Created by hezi on 1/3/19.
//

#include "FileCacheManager.h"


void FileCacheManager::addSolution(string s, string p) {
    map1.insert(std::pair<string, string>(p, s));
}

bool FileCacheManager::isThereSolution(string porblem) {
    map<string, string>::iterator i = map1.find(porblem);
    if (i == map1.end()) {
        return false;
    } else {
        return true;
    }
}


string FileCacheManager::getSolution(string porblem) {
    return map1.find(porblem)->second;
}

