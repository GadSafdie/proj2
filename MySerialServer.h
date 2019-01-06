//
// Created by gad on 1/3/19.
//

#ifndef PROJ2_MYSERIALSERVER_H
#define PROJ2_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer : public Server{
    int socketId;


public:
    virtual void open(int port, ClientHandler c);
    virtual void stop();
    //static void listenClient(int sockid,ClientHandler c);


};


#endif //PROJ2_MYSERIALSERVER_H
