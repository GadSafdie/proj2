//
// Created by gad on 1/10/19.
//

#include "MyClientHandler.h"


#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <error.h>
#include <vector>
#include "FileCacheManager.h"
#include "State.h"
#include "MatrixProblem.h"

using namespace std;

void MyClientHandler::handleClient(int newsockfd) {
    int counter;
    int check = 0;
    bool end = false;
    vector<vector<State<vector<int>> *>> tempMatrix;
    vector<vector<State<vector<int>> *>> matrix;
    string root = "";
    string goal = "";


    while (end != true) {
        char buff[256];
        ssize_t n;
        // This send() function sends the 13 bytes of the string to the new socket

        bzero(buff, 256);

        n = read(newsockfd, buff, 255);
        if (n < 0) cout << ("ERROR reading from socket") << endl;

        int size = strlen(buff);
        string str = "";
        for (int i = 0; i < size - 2; ++i) {
            str.push_back(buff[i]);
        }


        if (str == "end") {
            int matrixSize = tempMatrix.size() - 2;
            for (int i = 0; i < tempMatrix.size(); ++i) {
                if (i < matrixSize) {
                    matrix.push_back(tempMatrix[i]);
                } else {
                    if (check == 0) {
                        int temp = tempMatrix[i][0]->getCost();//double to string
                        root = to_string(temp);
                        check = 1;
                    } else {
                        int temp = ((int)tempMatrix[i][0]->getCost());//double to string
                        goal = to_string(temp);
                    }

                }
            }
            MatrixProblem* mp = new MatrixProblem(matrix, findStatePoint(root), findStatePoint(goal));
            //we need to check if this matrix already exist in our files if not we will pass
            // the matrix to the solver - and getting back the path UP/LEFT/DOEN/RIGHT
            if (cm->isThereSolution(mp)) {
                //write on socket
                string h = cm->getSolution(mp);
                h = h + "\n";
                const char *charKochavitName = h.c_str(); // convert the string to char *
                send(newsockfd, charKochavitName, h.size(), 0);
            } else {
                string h = solver->solve(mp);
                cm->addSolution(h, mp);
                h = h + "\n";
                const char *charKochavitName = h.c_str(); // convert the string to char *
                send(newsockfd, charKochavitName, h.size(), 0);
            }
//            FileCacheManager* fileCacheManager = dynamic_cast<FileCacheManager*>(this->cm);
//            fileCacheManager->exit();
            close(newsockfd);
            end = true;
        } else {

            vector<State<vector<int>> *> stateVector;
            stateVector = makeTheStateFromLine(str);
            tempMatrix.push_back(stateVector);
            stateVector.clear();
//
//            } else if (flag < MatrixLinesNumber) {
//                stateVector = makeTheStateFromLine(str);
//                matrix.push_back(stateVector);
//                stateVector.clear();
//                flag = flag + 1;
//            } else if (flag == MatrixLinesNumber) {
//                root = str;
//                flag = flag + 1;
//            } else if (flag == MatrixLinesNumber + 1) {
//                goal = str;
//                flag = flag + 1;
//        } else if (flag == MatrixLinesNumber + 2) {
//
//        }


        }

    }


}

vector<State<vector<int>> *> MyClientHandler::makeTheStateFromLine(string str) {
    vector<State<vector<int>> *> returnVector;
    string newString = "";
    int x = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != ',') {
            newString = newString + str[i];
        } else {
            returnVector.push_back(makeOneStateFromLine(newString, x));
            x = x + 1;
            newString = "";
        }
    }
    if(newString != ""){
        returnVector.push_back(makeOneStateFromLine(newString, x));
    }
    this->flag++;
    return returnVector;
}

State<vector<int>> *MyClientHandler::makeOneStateFromLine(string str, int x) {
    double cost = stod(str);
    vector<int> point;
    point.push_back(x);
    point.push_back(flag);
    State<vector<int>> *returnState = new State<vector<int>>(point, cost);
    myMap.insert(std::make_pair(point, returnState));
    point.clear();
    return returnState;
}

State<vector<int>> *MyClientHandler::findStatePoint(string str) {
    int localFlag = 0;
    string x = "";
    string y = "";
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != ',') {
            if (localFlag == 0) {
                x = x + str[i];
            } else {
                y = y + str[i];
            }
        } else {
            localFlag = 1;
        }
    }
    vector<int> point;
    point.push_back(atoi(x.c_str()));
    point.push_back(atoi(y.c_str()));
//std::map<vector<int>, State<vector<int>> *>::iterator
    auto it = myMap.find(point);
    if (it != myMap.end()) {
        return it->second;
    } else {
        cout << "point doesnt exist" << endl;
        throw (0);
    }

}

string MyClientHandler::read_until(int sockfd, string sep) {
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