//
// Created by hezi on 1/10/19.
//

#ifndef PROJ2_MATRIXPROBLEM_H
#define PROJ2_MATRIXPROBLEM_H

#include <iostream>
#include "Searchable.h"

class MatrixProblem : public Searchable<vector<int>> {
    int horizonBound;
    int verticalBound;

public:

    MatrixProblem(std::vector<vector<State<vector<int>> *>> matrix1, State<vector<int>> *root,
                  State<vector<int>> *goal);

    bool isInBounds(int x, int y);

    bool canWeStepThere(int x, int y);

    int gethorizonBound() {
        return horizonBound;
    }

    int getverticalBound() {
        return verticalBound;
    }

    virtual vector<State<vector<int>> *> getAllPossibleStates(State<vector<int>> *s) override;

    virtual string getDirections(vector<State<vector<int>> *> path) override;

    virtual vector<State<vector<int>> *> getAllPossibleStatesAstar(State<vector<int>> *s) override;


    friend ostream &operator<<(ostream &input, MatrixProblem &c) {
        string dim, root, goal;
        // get dim
        string r = std::to_string(c.gethorizonBound() + 1);
        string co = std::to_string(c.getverticalBound() + 1);
        dim = r + "," + co;
        input << dim << endl;
        // get root
        vector<int> rootP = c.getInitalState()->getState();
        string X = std::to_string(rootP[0]);
        string Y = std::to_string(rootP[1]);
        root = X + "," + Y;

        // get goal
        vector<int> goalP = c.getGoalState()->getState();
        X = std::to_string(goalP[0]);
        Y = std::to_string(goalP[1]);
        goal = X + "," + Y;

        // get the matrix
        for (int i = 0; i <= c.gethorizonBound(); ++i) {
            string row;
            for (int j = 0; j <= c.getverticalBound(); ++j) {
                string cost = std::to_string((int) c.getMatrix()[i][j]->getCost());
                if (row != "") {
                    row = row + "," + cost;
                } else {
                    row = row + cost;
                }
            }
            input << row << endl;
        }
        input << root << endl;
        input << goal << endl;
        return input;
    }


    bool operator==(MatrixProblem &b) const {
        if (horizonBound != b.gethorizonBound() || verticalBound != b.getverticalBound()) {
            return false;
        }
        vector<int> goalP = b.getGoalState()->getState();
        vector<int> rootP = b.getInitalState()->getState();
        if (!(goal->getState() == b.getMatrix()[goalP[0]][goalP[1]]->getState() && root->getState() == b.getMatrix()[rootP[0]][rootP[1]]->getState())) {
            return false;
        }
        for (int i = 0; i <= b.gethorizonBound(); ++i) {
            for (int j = 0; j <= b.getverticalBound(); ++j) {
                if (matrix[i][j]->getState() != b.getMatrix()[i][j]->getState())
                    return false;
            }
        }
        return true;
    }

};


#endif //PROJ2_MATRIXPROBLEM_H
