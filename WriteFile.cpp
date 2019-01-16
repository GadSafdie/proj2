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
    ofstream myfile;
    myfile.open("info.txt", ofstream::app);
        myfile << *first;
        myfile << second;

//    else cout << "Unable to open file";
    myfile.close();
}
