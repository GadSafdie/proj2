//
// Created by gad on 1/3/19.
//

#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
    Solver* solver;
    CacheManager* cm;
public:
    virtual void handleClient(std::ifstream ifstream,std::ofstream ofstream);
    void writeSoultion(int id,char* buffer);


};


#endif //PROJ2_MYTESTCLIENTHANDLER_H
