//
// Created by gad on 1/3/19.
//

#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <thread>
#include <mutex>

using namespace std;


void MySerialServer:: open(int port, ClientHandler* c){
    int sockfd, portno;
    struct sockaddr_in serv_addr;

/* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }


/* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

/* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
// This listen() call tells the socket to listen to the incoming connections.
    // The listen() function places all incoming connection into a backlog queue
    // until accept() call accepts the connection.
    // Here, we set the maximum size for the backlog queue to 10.
    listen(sockfd, 10);
    thread serverThread(clientQuque, sockfd, c);
    serverThread.detach();

}

void MySerialServer::clientQuque(int sockfd, ClientHandler* c){
while (true){
    int clilen;
    int newsockfd;
    struct sockaddr_in cli_addr;

    clilen = sizeof(cli_addr);

/* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    c->handleClient(newsockfd);


}




}
