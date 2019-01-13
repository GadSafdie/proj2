//
// Created by gad on 1/6/19.
//

#include "ReadFile.h"


map<MatrixProblem *, string> ReadFile::ReadFileCacheManager() {
    vector<vector<State<vector<int>> *>> matrix;
    vector<State<vector<int>> *> newLine;
    map<MatrixProblem *, string> returnn;
    State<vector<int>> *root;
    State<vector<int>> *goal;
    State<vector<int>> *temp;
    std::ifstream infile("info.txt");
    int flagDimension = 0;
    int lineCounter = 0;
    int flag = 0;
    int matrixFlag = 1;
    vector<int> dimension;
    vector<int> point;
    string cost = "";
    string first = "";
    string second = "";
    string solution = "";
    int x = 0;
    int dataFlag = 0;
    int counter = 0;
    int flag11 = 0;
    MatrixProblem *matrixProblem;


    if (infile.is_open()) {
        std::string line;
        while (getline(infile, line)) {
            if (flagDimension == 0) {
                flag = 0;
                for (int i = 0; i < line.length(); ++i) {
                    if (flag == 0) {
                        if (line[i] != ',') {
                            first = first + line[i];
                        } else {
                            flag = 1;
                        }
                    } else {
                        second = second + line[i];
                    }
                }
                //change
                dimension.push_back(std::stoi(second) - 1);
                dimension.push_back(std::stoi(first) - 1);
                first = "";
                second = "";
                flag = 0;
                flagDimension = 1;
                matrixFlag = 1;
            } else if (matrixFlag == 1) {
                for (int j = 0; j < line.length(); ++j) {
                    if (line[j] != ',') {
                        cost = cost + line[j];
                    } else {
                        //change
                        point.push_back(lineCounter);
                        point.push_back(x);
                        //change
                        temp = new State<vector<int>>(point, stod(cost));
                        newLine.push_back(temp);
                        point.clear();
                        cost = "";
                        x = x + 1;
                    }
                }
                ////change
                point.push_back(lineCounter);
                point.push_back(x);
                ////change
                temp = new State<vector<int>>(point, stod(cost));
                newLine.push_back(temp);
                point.clear();
                cost = "";
                x = x + 1;
                lineCounter++;
                matrix.push_back(newLine);
                x=0;
                newLine.clear();
                if (lineCounter - 1 == dimension[0]) {
                    matrixFlag = 0;
                }
            } else {
                if (flag11 == 0) {
                    if ((counter == 1) || (counter == 0)) {
                        if (counter == 0) {
                            for (int i = 0; i < line.length(); ++i) {
                                if (flag == 0) {
                                    if (line[i] != ',') {
                                        first = first + line[i];
                                    } else {
                                        flag = 1;
                                    }
                                } else {
                                    second = second + line[i];
                                    flag = 0;
                                }
                            }
                        }
                        if (counter == 1) {
                            for (int i = 0; i < line.length(); ++i) {
                                if (flag == 0) {
                                    if (line[i] != ',') {
                                        first = first + line[i];
                                    } else {
                                        flag = 1;
                                    }
                                } else {
                                    second = second + line[i];

                                }
                            }
                        }

                        point.clear();
                        ////change
                        point.push_back(std::stoi(second));
                        point.push_back(std::stoi(first));
                        ////change
                        if (counter == 0) {
                            root = matrix[std::stoi(first)][std::stoi(second)];
                            first = "";
                            second = "";

                        }
                        if (counter == 1) {
                            goal = matrix[std::stoi(first)][std::stoi(second)];
                            matrixProblem = new MatrixProblem(matrix, root, goal);
                            flag11 = 1;
                            first = "";
                            second = "";
                        }
                    }
                }

                if (counter == 2) {
                    for (int i = 0; i < line.length(); ++i) {
                        solution = solution + line[i];
                    }
                }
                counter++;
                if (counter == 3) {
                    flagDimension = 0;
                    returnn.insert(std::make_pair(matrixProblem, solution));
//                    flagDimension = 0;
//                    lineCounter = 0;
//                    flag = 0;
//                    matrixFlag = 1;
//                    point.clear();
//                    cost = "";
//                    first = "";
//                    second = "";
//                    solution = "";
//                    x = 0;
//                    dataFlag = 0;
//                    counter = 0;
//                    flag11 = 0;
                }
            }
        }
    }
    infile.close();
//    remove("info.txt");

    return returnn;
}

