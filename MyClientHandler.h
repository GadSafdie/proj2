//
// Created by gad on 1/10/19.
//

#ifndef PROJ2_MYCLIENTHANDLER_H
#define PROJ2_MYCLIENTHANDLER_H

#include <map>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "State.h"
#include "vector"
#include "MatrixProblem.h"
#include "FileCacheManager.h"

using namespace std;

class MyClientHandler : public ClientHandler {
    string tempStr="";
    Solver<Searchable<vector<int>> *, string>* solver;
    CacheManager<MatrixProblem*,string> *cm = new FileCacheManager<MatrixProblem*,string>();
    int flag;
    std::map<vector<int>, State<vector<int>> *> myMap;
public:
    MyClientHandler(Solver<Searchable<vector<int>> *, string>* s, CacheManager<MatrixProblem*,string>* cm1) {
        solver = s;
        cm = cm1;
        flag = 0;
    }
    MyClientHandler() {
        flag = 0;

    }
    vector<State<vector<int>> *> makeTheStateFromLine(string str);
    State<vector<int>> *makeOneStateFromLine(string str, int x);

    State<vector<int>> *findStatePoint(string str);

    virtual void handleClient(int newsockfd);

    //void writeSoultion(int id,char* buffer);
    string read_until(int sockfd, string sep);

    CacheManager<MatrixProblem*,string> *getCacheManager() {
        return this->cm;
    }

};

#endif //PROJ2_MYCLIENTHANDLER_H
