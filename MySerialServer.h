//
// Created by gad on 1/3/19.
//

#ifndef PROJ2_MYSERIALSERVER_H
#define PROJ2_MYSERIALSERVER_H


#include "Server.h"
#include "FileCacheManager.h"

class MySerialServer : public server_side::Server{
    ClientHandler* ca;
    int sock;
public:
    MySerialServer(){};

    void open(int port, ClientHandler* ca);
    static void exit11(ClientHandler* clientHandler);
    virtual void stop();
    static void clientQuque(int newsockfd, ClientHandler* c);
    virtual void handleClient(int newsockfd){};
};


#endif //PROJ2_MYSERIALSERVER_H
