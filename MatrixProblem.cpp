//
// Created by hezi on 1/10/19.
//

#include "MatrixProblem.h"


MatrixProblem::MatrixProblem(vector<vector<State<vector<int>> *>> matrix1, State<vector<int>> *root,
                             State<vector<int>> *goal) {
    this->matrix = matrix1;
    this->root = root;
    this->goal = goal;
    this->horizonBound = matrix1[0].size() - 1;
    this->verticalBound = matrix1.size() - 1;
    vector<int> p = root->getState();
    matrix[p[0]][p[1]]->setHasVisited();
    matrix[p[0]][p[1]]->setpathCost(root->getCost());
}


bool MatrixProblem::isInBounds(int x, int y) {
    if (((x <= horizonBound) && (y <= verticalBound)) && ((x >= 0) && (y >= 0))) {
        return true;
    } else {
        return false;
    }
}

bool MatrixProblem::canWeStepThere(int x, int y) {
    if (!isInBounds(x, y)) {
        return false;
    } else {
//for -1 as minus infinite
        if ((matrix[x][y]->getCost()) >= 0) {
            return true;
        }
    }
    return false;
}


string MatrixProblem::getDirections(vector<State<vector<int>>*> path) {
    string directions;
    for (int i = 0; i < path.size() - 1; ++i) {
        vector<int> first = path[i]->getState();
        vector<int> second = path[i + 1]->getState();
        // check if up
        if (first[1] < second[1]) {
            directions = directions + "RIGHT";
        }
            // check if down
        else if (first[1] > second[1]) {
            directions = directions + "LEFT";
        }
            // check if right
        else if (first[0] < second[0]) {
            directions = directions + "DOWN";
        }
            // check if left
        else if (first[0] > second[0]) {
            directions = directions + "UP";
        }
        if (i != path.size() - 2)
            directions = directions + ",";
    }
    return directions;
}


vector<State<vector<int>> *> MatrixProblem:: getAllPossibleStates(State<vector<int>> *s) {

    vector<State<vector<int>> *> states;

    vector<int> point = s->getState();
    int x=point[0];
    int y=point[1];

    int newX;
    int newY;
    vector<int> newPoint;

    if (canWeStepThere(x + 1, y)) {
        if(matrix[x+1][y]->getHasVisited() == false){
            matrix[x+1][y]->setHasVisited();
            states.push_back(matrix[x+1][y]);
        }
    }

    if (canWeStepThere(x, y + 1)) {
        if(matrix[x][y+1]->getHasVisited() == false){
            matrix[x][y+1]->setHasVisited();
            states.push_back(matrix[x][y+1]);
        }
    }

    if (canWeStepThere(x - 1, y)) {
        if(matrix[x-1][y]->getHasVisited() == false){
            matrix[x-1][y]->setHasVisited();
            states.push_back(matrix[x-1][y]);
        }
    }

    if (canWeStepThere(x, y - 1)) {
        if(matrix[x][y-1]->getHasVisited() == false){
            matrix[x][y-1]->setHasVisited();
            states.push_back(matrix[x][y-1]);
        }
    }

    return states;
}


vector<State<vector<int>> *> MatrixProblem:: getAllPossibleStatesAstar(State<vector<int>> *s) {

    vector<State<vector<int>> *> states;

    vector<int> point = s->getState();
    int x=point[0];
    int y=point[1];

    int newX;
    int newY;
    vector<int> newPoint;

    if (canWeStepThere(x + 1, y)) {
        if(matrix[x+1][y]->getHasVisited() == false){
            states.push_back(matrix[x+1][y]);
        }
    }

    if (canWeStepThere(x, y + 1)) {
        if(matrix[x][y+1]->getHasVisited() == false){
            states.push_back(matrix[x][y+1]);
        }
    }

    if (canWeStepThere(x - 1, y)) {
        if(matrix[x-1][y]->getHasVisited() == false){
            states.push_back(matrix[x-1][y]);
        }
    }

    if (canWeStepThere(x, y - 1)) {
        if(matrix[x][y-1]->getHasVisited() == false){
            states.push_back(matrix[x][y-1]);
        }
    }

    return states;
}