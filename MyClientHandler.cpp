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
#include "ISearcher.h"
#include "Astar.h"
#include "BFS.h"

using namespace std;

void MyClientHandler::handleClient(int newsockfd) {
    int counter;
    int check = 0;
    bool end = false;
    vector<vector<State<vector<int>> *>> tempMatrix;
    vector<vector<State<vector<int>> *>> matrix;
    string root;
    string goal;
    State<vector<int>> *stateRoot;
    State<vector<int>> *stateGoal;


    while (end != true) {
        char buff[256];
        ssize_t n;
        // This send() function sends the 13 bytes of the string to the new socket

        bzero(buff, 256);

        n = read(newsockfd, buff, 255);
        if (n < 0) cout << ("ERROR reading from socket") << endl;

        int size = strlen(buff);
        string str = "";
        string str1 = "";
        str=str+tempStr;
        tempStr="";
        for (int i = 0; i < size - 2; ++i) {
            str.push_back(buff[i]);
        }

        for (char j : str) {
            if ('\r' == j) {
                if (str.size() > j + 1) {
                    if ('\n' == j + 1) {
                        for (int i = j; i < str.size(); ++i) {
                            tempStr = tempStr + str[i];
                        }
                        break;
                    }
                }


            } else {
                str1 = str1 + str[j];
            }

        }


        if (str == "end") {
            int matrixSize = tempMatrix.size() - 2;
            for (int i = 0; i < tempMatrix.size(); ++i) {
                if (i < matrixSize) {
                    matrix.push_back(tempMatrix[i]);
                } else {
                    if (check == 0) {
                        int temp = static_cast<int>(tempMatrix[i][0]->getCost());//double to string
                        int temp1 = static_cast<int>(tempMatrix[i][1]->getCost());//double to string
                        double cost = static_cast<int>(tempMatrix[temp][temp1]->getCost());//double to string
                        vector<int> point;
                        point.push_back(temp);
                        point.push_back(temp1);
                        stateRoot = new State<vector<int>>(point, cost);

//                        vector<int>* vec = new vector<int>({temp, temp1});
//                        stateRoot->setState(vec);
//                        stateRoot->setCost(tempMatrix[temp][temp1]->getCost());
                        check = 1;
                    } else {
                        int temp = static_cast<int>(tempMatrix[i][0]->getCost());//double to string
                        int temp1 = static_cast<int>(tempMatrix[i][1]->getCost());//double to string
                        double cost = static_cast<int>(tempMatrix[temp][temp1]->getCost());//double to string
                        vector<int> point;
                        point.push_back(temp);
                        point.push_back(temp1);
                        stateGoal = new State<vector<int>>(point, cost);

                    }

                }
            }
            MatrixProblem *mp = new MatrixProblem(matrix, stateRoot, stateGoal);
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
            close(newsockfd);
            end = true;
        } else {

            vector<State<vector<int>> *> stateVector;
            stateVector = makeTheStateFromLine(str);
            tempMatrix.push_back(stateVector);
            stateVector.clear();
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
    if (newString != "") {
        returnVector.push_back(makeOneStateFromLine(newString, x));
    }
    this->flag++;
    return returnVector;
}

State<vector<int>> *MyClientHandler::makeOneStateFromLine(string str, int x) {
    double cost = stod(str);
    vector<int> point;
    point.push_back(flag);
    point.push_back(x);
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
                y = y + str[i];
            } else {

                x = x + str[i];
            }
        } else {
            localFlag = 1;
        }
    }
    vector<int> point;
    point.push_back(atoi(y.c_str()));
    point.push_back(atoi(x.c_str()));
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