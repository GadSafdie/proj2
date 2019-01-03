//
// Created by gad on 1/3/19.
//

#ifndef PROJ2_SERVER_H
#define PROJ2_SERVER_H


#include "ClientHandler.h"




class Server
//for future         : public ClientHandler
{

    public:
    virtual void open(int port, ClientHandler c)=0;
    virtual void stop()=0;
};


#endif //PROJ2_SERVER_H
