//
// Created by gad on 1/6/19.
//

#include "WriteFile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "string.h"
#include "MatrixProblem.h"
#include <fstream>
#include <map>

using namespace std;


void WriteFile::writeFileCacheManager(MatrixProblem* first, string second) {
    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
        myfile << *first;
        myfile << second;
        myfile.close();
    }
    else cout << "Unable to open file";

}
