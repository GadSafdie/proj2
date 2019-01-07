//
// Created by gad on 1/6/19.
//

#include "WriteFile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "string.h"
#include <fstream>

using namespace std;


void WriteFile::writeFileCacheManager(string first, string second) {
    ofstream myfile;
    myfile.open("RFCM.txt", ofstream::app);
    myfile << first << "$" << second << '\n';
    myfile.close();
}
