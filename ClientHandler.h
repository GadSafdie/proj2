//
// Created by gad on 1/3/19.
//

#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H



class ClientHandler {

public:
    ClientHandler(){};
    virtual void handleClient(int newsockfd)=0;
    virtual ~ClientHandler() = default;



};


#endif //PROJ2_CLIENTHANDLER_H
