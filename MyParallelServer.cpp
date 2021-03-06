//
// Created by gad on 1/10/19.
//

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

#include "MyParallelServer.h"
#include "MyClientHandler.h"

void MyParallelServer::exit11(ClientHandler *clientHandler) {
    WriteFile *write;
    map<MatrixProblem *, string>::const_iterator iterator;
    MatrixProblem * first;
    string second;
    MyClientHandler *mtch = dynamic_cast<MyClientHandler *>(clientHandler);
    CacheManager<MatrixProblem *, string> *cm1 = mtch->getCacheManager();
    FileCacheManager<MatrixProblem *, string> *fileCacheManager = dynamic_cast<FileCacheManager<MatrixProblem *, string> *>(cm1);
    map<MatrixProblem *, string> cacheMap = fileCacheManager->getCacheMap();
    for (iterator = cacheMap.begin(); iterator != cacheMap.end(); ++iterator) {
        first = iterator->first;
        second = iterator->second;
        write->writeFileCacheManager(first, second);
    }
    fileCacheManager->exit();

}

void MyParallelServer::open(int port, ClientHandler *c) {
    this->ca = c;
    int sockfd, portno;
    struct sockaddr_in serv_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    this->sock = sockfd;

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

    int n = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &n, sizeof(int));
    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    listen(sockfd, 5);

    struct sockaddr_in cli_addr;
    int clilen;

    clilen = sizeof(cli_addr);
//    clientQuque(sockfd, c);
    thread thread4(clientQuque, sockfd, c);
    thread4.detach();
//    close(sockfd);

}

void MyParallelServer::stop() {}

void MyParallelServer::clientQuque(int sockfd, ClientHandler *c) {
    struct sockaddr_in cli_addr;
    int clilen, newSockfd;
    bool gad = true;
    int counter = 0;
    while (gad) {
        int val = 0;

        // Accept actual connection from the client
        std::thread t1([&]() {
            newSockfd = accept(sockfd, (struct sockaddr *) &cli_addr,
                               (socklen_t *) &clilen);
            val = 1;
        });
        std::this_thread::sleep_for(std::chrono::seconds(6));
        t1.detach();
        if (val == 0) {
            if (counter == 0) {
                cout << "time out" << endl;
                gad = false;
                close(sockfd);
                exit11(c);
            }

        } else {
            if (newSockfd < 0) {
                perror("ERROR on accept");
                exit(1);
            }
            counter = counter + 1;
            std::thread t2([&]() {
                c->handleClient(newSockfd);
                counter = counter - 1;
            });
            t2.detach();

        }

    }
}





