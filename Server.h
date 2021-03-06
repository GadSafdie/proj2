//
// Created by gad on 1/3/19.
//

#ifndef PROJ2_SERVER_H
#define PROJ2_SERVER_H


#include "ClientHandler.h"


namespace server_side{
    class Server;
}

class server_side::Server : public ClientHandler{

public:
    Server(){};
    virtual void open(int port, ClientHandler* c)=0;
    virtual void stop()=0;
    virtual void handleClient(int newsockfd)=0;
    virtual ~Server() = default;

};


#endif //PROJ2_SERVER_H
