//
// Created by hezi on 1/10/19.
//

#ifndef PROJ2_MATRIXPROBLEM_H
#define PROJ2_MATRIXPROBLEM_H

#include "Searchable.h"
class MatrixProblem : public Searchable {
    vector<vector<State>> matrix;
    State* root;
    State* goal;
    int horizonBound;
    int verticalBound;

public:

    MatrixProblem(vector<vector<State>> matrix1, State *root, State *goal) {
        this->root = root;
        this->goal = goal;
        this->horizonBound = matrix1.size() - 1;
        this->verticalBound = matrix1[0].size() - 1;
        this->matrix = matrix1;
    }

    State* getInitalState() {
        return root;
    }

    State *getGoalState() {
        return goal;
    }

    bool isInBounds(int x, int y) {
        if (((x <= horizonBound) && (y <= verticalBound)) && ((x >= 0) && (y >= 0))) {
            return true;
        } else {
            return false;
        }
    }

    bool canWeStepThere(int x, int y) {
        if (!isInBounds(x, y)) {
            return false;
        } else {
//for -1 as minus infinite
            if ((matrix[x][y].getCost()) >= 0) {
                return true;
            }
        }
        return false;

    }

    vector<State> getAllPossibleStates(State *s) {
        vector<State> states;

        vector<int> point = s->getState();
        int x = point[0];
        int y = point[1];

        int newX;
        int newY;
        vector<int> newPoint;

        if (canWeStepThere(x + 1, y)) {
            newX = x + 1;
            newY = y;
            newPoint.push_back(newX);
            newPoint.push_back(newY);
            auto newStateRight = new State(newPoint);
            newStateRight->setcameFrom(s);
            newStateRight->setCost(matrix[newX][newY].getCost());
            newPoint.pop_back();
            newPoint.pop_back();
            states.push_back(*newStateRight);
        }

        if (canWeStepThere(x, y + 1)) {
            newX = x;
            newY = y + 1;
            newPoint.push_back(newX);
            newPoint.push_back(newY);
            auto newStateDown = new State(newPoint);
            newStateDown->setcameFrom(s);
            newStateDown->setCost(matrix[newX][newY].getCost());
            newPoint.pop_back();
            newPoint.pop_back();
            states.push_back(*newStateDown);
        }

        if (canWeStepThere(x - 1, y)) {
            newX = x - 1;
            newY = y;
            newPoint.push_back(newX);
            newPoint.push_back(newY);
            auto newStateLeft = new State(newPoint);
            newStateLeft->setcameFrom(s);
            newStateLeft->setCost(matrix[newX][newY].getCost());
            newPoint.pop_back();
            newPoint.pop_back();
            states.push_back(*newStateLeft);

        }

        if (canWeStepThere(x, y - 1)) {
            newX = x + 1;
            newY = y;
            newPoint.push_back(newX);
            newPoint.push_back(newY);
            auto newStateUp = new State(newPoint);
            newStateUp->setcameFrom(s);
            newStateUp->setCost(matrix[newX][newY].getCost());
            newPoint.pop_back();
            newPoint.pop_back();
            states.push_back(*newStateUp);

        }

        return states;


    }

    string getDirections(vector<State> path) {
        string directions;
        for (int i = 0; i <path.size() -1 ; ++i) {
            vector<int> first = path[i].getState();
            vector<int> second = path[i+1].getState();
            // check if up
            if(first[1] < second[1]){
                directions = directions + "UP";
            }
                // check if down
            else if(first[1] > second[1]){
                directions = directions + "DOWN";
            }
                // check if right
            else if(first[0] < second[0]){
                directions = directions + "RIGHT";
            }
                // check if left
            else if(first[0] > second[0]){
                directions = directions + "LEFT";
            }
            if(i != path.size() -2)
                directions = directions + ",";
        }
        return directions;
    }

    void InitlizeAllStates() {};


};


#endif //PROJ2_MATRIXPROBLEM_H
