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
    int sockfd, newsockfd, portno;
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
    thread serverThread(clientQuque, newsockfd, c);
    serverThread.detach();

}

void MySerialServer::clientQuque(int newsockfd, ClientHandler* c){
while (true){
    int clilen;
    struct sockaddr_in cli_addr;
    /* Now start listening for the clients, here process will
   * go in sleep mode and will wait for the incoming connection
*/

    listen(newsockfd, 5);
    clilen = sizeof(cli_addr);

/* Accept actual connection from the client */
    newsockfd = accept(newsockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    c->handleClient(newsockfd);


}




}
