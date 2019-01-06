//
// Created by gad on 1/3/19.
//

#ifndef PROJ2_SOLVER_H
#define PROJ2_SOLVER_H


#include "Solution.h"
#include "Problem.h"

class Solver {
public:
    virtual Solution solve(Problem p) = 0;

};


#endif //PROJ2_SOLVER_H
