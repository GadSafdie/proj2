//
// Created by hezi on 1/10/19.
//

#ifndef PROJ2_MATRIXPROBLEM_H
#define PROJ2_MATRIXPROBLEM_H

#include "Searchable.h"

class MatrixProblem : public Searchable<vector<int>> {
    int horizonBound;
    int verticalBound;

public:

    MatrixProblem(std::vector<vector<State<vector<int>> *>> matrix1, State<vector<int>> *root,
                  State<vector<int>> *goal);

    bool isInBounds(int x, int y);

    bool canWeStepThere(int x, int y);

    virtual vector<State<vector<int>> *> getAllPossibleStates(State<vector<int>> *s) override;

    virtual string getDirections(vector<State<vector<int>>*> path) override;

    friend ostream & operator << (ostream &out, const MatrixProblem &c);

};


#endif //PROJ2_MATRIXPROBLEM_H
