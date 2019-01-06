//
// Created by gad on 1/3/19.
//

#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H


#include <fstream>

class ClientHandler {
public:
    virtual void handleClient(int newsockfd)=0;

};


#endif //PROJ2_CLIENTHANDLER_H
