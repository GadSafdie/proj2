////
//// Created by gad on 1/3/19.
////
//
//#include <unistd.h>
//#include <cstring>
//#include <iostream>
//#include <sys/socket.h>
//#include <error.h>
//#include "MyTestClientHandler.h"
//#include "FileCacheManager.h"
//
//using namespace std;
//
//void MyTestClientHandler::handleClient(int newsockfd) {
//    bool end = false;
//
//    while (end != true) {
//        char buff[256];
//        ssize_t n;
//        // This send() function sends the 13 bytes of the string to the new socket
//
//        bzero(buff, 256);
//
//        n = read(newsockfd, buff, 255);
//        if (n < 0) cout << ("ERROR reading from socket") << endl;
//
//        int size = strlen(buff);
//        string str = "";
//        for (int i = 0; i < size - 2; ++i) {
//            str.push_back(buff[i]);
//        }
//
//
//        if (str == "end") {
////            FileCacheManager* fileCacheManager = dynamic_cast<FileCacheManager*>(this->cm);
////            fileCacheManager->exit();
//            close(newsockfd);
//            end = true;
//        } else {
//            if (cm->isThereSolution(str)) {
//                //write on socket
//                string h = cm->getSolution(str);
//                h = h + "\n";
//                const char *charKochavitName = h.c_str(); // convert the string to char *
//                send(newsockfd, charKochavitName, h.size(), 0);
//            } else {
//                string h = solver->solve(str);
//                cm->addSolution(h, str);
//                h = h + "\n";
//                const char *charKochavitName = h.c_str(); // convert the string to char *
//                send(newsockfd, charKochavitName, h.size(), 0);
//
//            }
//        }
//
//    }
//
//
//}
//
//
//string MyTestClientHandler::read_until(int sockfd, string sep) {
//    char buffer[256];
//    string remainder;
//    //clock open
//    while (remainder.find(sep) == string::npos) {
//        ssize_t bytes_read = (read(sockfd, buffer, 255));
//        //if 15 sec passed{end=true}
//
//        if (bytes_read < 0) {
//            perror("Invalid socket read");
//            exit(1);
//        }
//        buffer[bytes_read] = 0;
//        remainder += string(buffer);
//    }
//
//    unsigned long pos = remainder.find(sep);
//    pair<string, string> output;
//    output.first = remainder.substr(0, pos);
//    output.second = remainder.substr(pos + 1);
//
//    return output.first;
//}
