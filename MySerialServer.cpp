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


void MySerialServer::open(int port, ClientHandler *c) {
    this->ca = c;
    int sockfd, portno;
    struct sockaddr_in serv_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    sockfd = sockfd;

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

    clientQuque(sockfd, c);
    thread thread4(clientQuque, sockfd, c);
    thread4.detach();
    close(sockfd);

}

void MySerialServer::clientQuque(int sockfd, ClientHandler *c) {
    struct sockaddr_in cli_addr;
    int clilen, newSockfd;
    while (true) {
        int val = 0;
        listen(sockfd, 1);
        clilen = sizeof(cli_addr);
        // Accept actual connection from the client
        std::thread t1([&]() {
            newSockfd = accept(sockfd, (struct sockaddr *) &cli_addr,
                               (socklen_t *) &clilen);
            val = 1;
        });
        std::this_thread::sleep_for(std::chrono::seconds(6));
        t1.detach();
        if (val == 0) {
            cout << "time out" << endl;
            stop();
        }
        if (newSockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        c->handleClient(newSockfd);
    }


}







