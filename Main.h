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
        Solver<Searchable<vector<int>> *, string>* solver = new SearcherSolver(new AStar<vector<int>>());
        FileCacheManager<MatrixProblem *, string>* fcm;
        auto clientHandler = new MyClientHandler(solver, fcm);
        server->open(port, clientHandler);

//        delete server;
//        delete solver;
//        delete cacheManager;
//        delete clientHandler;

    }
};


#endif //PROJ2_MAIN_H
