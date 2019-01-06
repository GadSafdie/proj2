//
// Created by gad on 1/3/19.
//

#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H


#include <fstream>

class ClientHandler {

public:
    ClientHandler(){};
    virtual void handleClient(int newsockfd,int sockfd)=0;

};


#endif //PROJ2_CLIENTHANDLER_H
