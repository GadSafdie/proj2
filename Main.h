//
// Created by gad on 1/6/19.
//

#ifndef PROJ2_MAIN_H
#define PROJ2_MAIN_H

#include "MySerialServer.h"
#include "Server.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyParallelServer.h"
#include "SearcherSolver.h"
#include "MyClientHandler.h"
#include "Astar.h"

namespace boot {
    class Main;
}

class boot::Main {
public:
    void main(int port) {
//        StringReverser sr;
//        FileCacheManager<string,string> fcm;
//        auto c = new MyTestClientHandler(sr,fcm);
//        auto mySerialServer = new MySerialServer();
//        mySerialServer->open(port,c);

//            MyClientHandler(Solver<MatrixProblem*,string> &s, CacheManager<MatrixProblem*,string> &cm1) {


        auto server = new MyParallelServer();
        Solver<Searchable<vector<int>> *, string> *solver = new SearcherSolver(new AStar<vector<int>>());
        CacheManager<MatrixProblem *, string> *cm = new FileCacheManager<MatrixProblem *, string>();
        auto clientHandler = new MyClientHandler(solver, cm);
        server->open(port, clientHandler);

//        delete server;
//        delete solver;
//        delete clientHandler;

    }

};




#endif //PROJ2_MAIN_H
