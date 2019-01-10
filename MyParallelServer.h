//
// Created by gad on 1/10/19.
//

#ifndef PROJ2_MYPARALLELSERVER_H
#define PROJ2_MYPARALLELSERVER_H


#include "Server.h"
#include "FileCacheManager.h"

class MyParallelServer : public server_side::Server{
    ClientHandler* ca;
    int sock;

public:
    MyParallelServer(){};

    void open(int port, ClientHandler* ca);
    static void exit11(ClientHandler* clientHandler);
    virtual void stop();
    static void clientQuque(int newsockfd, ClientHandler* c);
    virtual void handleClient(int newsockfd){};
};


#endif //PROJ2_MYPARALLELSERVER_H
