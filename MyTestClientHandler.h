//
// Created by gad on 1/3/19.
//

#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "string"

using namespace std;

class MyTestClientHandler : public ClientHandler {
    Solver<string, string> *solver;
    CacheManager<string, string> *cm;

public:
    MyTestClientHandler(Solver<string, string> &s, CacheManager<string, string> &cm1) {
        solver = &s;
        cm = &cm1;
    }
    MyTestClientHandler() {

    }


    virtual void handleClient(int newsockfd);

    //void writeSoultion(int id,char* buffer);
    string read_until(int sockfd, string sep);
    CacheManager<string, string>* getCacheManager(){
        return this->cm;
    }

};


#endif //PROJ2_MYTESTCLIENTHANDLER_H
