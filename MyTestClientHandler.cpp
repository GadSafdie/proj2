//
// Created by gad on 1/3/19.
//

#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <error.h>
#include "MyTestClientHandler.h"

using namespace std;

void MyTestClientHandler::handleClient(int newsockfd, int sockfd) {
    bool end = false;

    while (end != true) {
        char buff[256];
        ssize_t n;
        // This send() function sends the 13 bytes of the string to the new socket
        send(newsockfd, "Hello, world!\n", 13, 0);

        bzero(buff, 256);
        n = read(sockfd, buff, 255);
        printf("Here is the message: %s\n", buff);
        if (n < 0) cout << ("ERROR reading from socket") << endl;
        
        if (strcmp(buff, "end") == 1) {
            end = true;
        } else {
            if (cm->isThereSolution(buff)) {
                //write on socket
                cout << cm->getSolution(buff) << endl;
            } else {
                string temp = solver->solve(buff);
                cout << temp << endl;
                cm->addSolution(temp, buff);
            }
        }

    }
}


string MyTestClientHandler::read_until(int sockfd, string sep) {
    char buffer[256];
    string remainder;
    //clock open
    while (remainder.find(sep) == string::npos) {
        ssize_t bytes_read = (read(sockfd, buffer, 255));
        //if 15 sec passed{end=true}

        if (bytes_read < 0) {
            perror("Invalid socket read");
            exit(1);
        }
        buffer[bytes_read] = 0;
        remainder += string(buffer);
    }

    unsigned long pos = remainder.find(sep);
    pair<string, string> output;
    output.first = remainder.substr(0, pos);
    output.second = remainder.substr(pos + 1);

    return output.first;
}
