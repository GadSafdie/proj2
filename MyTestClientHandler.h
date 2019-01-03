//
// Created by gad on 1/3/19.
//

#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"

class MyTestClientHandler : public ClientHandler {
    Solver solver;
    CacheManager cm;
};


#endif //PROJ2_MYTESTCLIENTHANDLER_H
