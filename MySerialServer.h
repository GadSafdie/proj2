//
// Created by gad on 1/3/19.
//

#ifndef PROJ2_MYSERIALSERVER_H
#define PROJ2_MYSERIALSERVER_H


#include "Server.h"
class MySerialServer : public server_side::Server{
    int port;

public:
    MySerialServer(int port){
        port=port;
    };
    virtual void open(int port, ClientHandler* c);
    virtual void stop(){};
    static void clientQuque(int newsockfd, ClientHandler* c);


};


#endif //PROJ2_MYSERIALSERVER_H
