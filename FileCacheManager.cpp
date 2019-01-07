////
//// Created by hezi on 1/3/19.
////
//
//#include "FileCacheManager.h"
//#include "ReadFile.h"
//
//
//void FileCacheManager::addSolution(string s, string p) {
//    cacheMap.insert(std::pair<string, string>(p, s));
//}
//
//bool FileCacheManager::isThereSolution(string porblem) {
//    if (flag == 0) {
//        ReadFile *readFile;
//        cacheMap = readFile->ReadFileCacheManager();
//        flag = 1;
//    }
//    map<string, string>::iterator i = cacheMap.find(porblem);
//    if (i == cacheMap.end()) {
//        return false;
//    } else {
//        return true;
//    }
//
//
//}
//
//
//string FileCacheManager::getSolution(string porblem) {
//    return cacheMap.find(porblem)->second;
//}
//
