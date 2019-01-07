//
// Created by gad on 1/3/19.
//

#ifndef PROJ2_MYSERIALSERVER_H
#define PROJ2_MYSERIALSERVER_H


#include "Server.h"
#include "WriteFile.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"

class MySerialServer : public server_side::Server{
    ClientHandler* ca;
public:
    MySerialServer(){};
    virtual void open(int port, ClientHandler* ca);
    virtual void stop(){


    };
    static void clientQuque(int newsockfd, ClientHandler* c);
    virtual void handleClient(int newsockfd){};



};


#endif //PROJ2_MYSERIALSERVER_H
