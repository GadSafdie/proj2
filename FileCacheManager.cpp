//
// Created by hezi on 1/3/19.
//

#include "FileCacheManager.h"


void FileCacheManager::addSolution(Solution s,Problem p) {
    map1.find(p)->second.push_back(s);
}