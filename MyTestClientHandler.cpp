//
// Created by gad on 1/3/19.
//

#include <unistd.h>
#include <cstring>
#include <iostream>
#include "MyTestClientHandler.h"

using namespace std;

void MyTestClientHandler::handleClient(int newsockfd) {
    bool end = false;

    while (end != true) {

        string buff = read_until(newsockfd, "\n");
        if (buff == "end") {
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
