//
// Created by gad on 1/6/19.
//

#ifndef PROJ2_MAIN_H
#define PROJ2_MAIN_H

#include "MySerialServer.h"
#include "Server.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"

namespace boot {
    class Main;
}

class boot::Main {
public:
    void main(int port){
        StringReverser* sr;
        FileCacheManager* fcm;
        MyTestClientHandler* c = new MyTestClientHandler(sr,fcm);

        MySerialServer* mySerialServer;
        mySerialServer->open(port,c);


    }
};


#endif //PROJ2_MAIN_H