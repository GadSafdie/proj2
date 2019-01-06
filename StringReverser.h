//
// Created by gad on 1/6/19.
//

#ifndef PROJ2_STRINGREVERSER_H
#define PROJ2_STRINGREVERSER_H
using namespace std;

#include <string>
#include "Solver.h"

class StringReverser : public Solver<string,string>{


public:
    StringReverser(){};
    string solve(string p);
};


#endif //PROJ2_STRINGREVERSER_H
