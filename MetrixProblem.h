//
// Created by hezi on 1/10/19.
//

#ifndef PROJ2_MATRIXPROBLEM_H
#define PROJ2_MATRIXPROBLEM_H

#include "Searchable.h"

template<class T>
class MetrixProblem : public Searchable<T> {
    vector<vector<State<vector<int>> *>> metrix;
    State<T> *root;
    State<T> *goal;
    int horizonBound;
    int verticalBound;

public:

    MetrixProblem(vector<vector<State<vector<int>> *>> metrix1, State<T> *root, State<T> *goal) {
        this->root = root;
        this->goal = goal;
        this->horizonBound = metrix1.size() - 1;
        this->verticalBound = metrix1[0].size() - 1;
        this->metrix = metrix1;
    }

    virtual State<T> *getInitalState() {
        return root;
    }

    virtual State<T> *getGoalState() {
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
            if ((metrix[x][y]) >= 0) {
                return true;
            }
        }
        return false;

    }

    virtual vector<State<T>> getAllPossibleStates(State<T> *s) {
        vector<State<T>> states;

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
            auto newStateRight = new State<T>(newPoint);
            newStateRight->setcameFrom(s);
            newStateRight->setCost(metrix[newX][newY]);
            newPoint.pop_back();
            newPoint.pop_back();
            states.push_back(newStateRight);
        }

        if (canWeStepThere(x, y + 1)) {
            newX = x;
            newY = y + 1;
            newPoint.push_back(newX);
            newPoint.push_back(newY);
            auto newStateDown = new State<T>(newPoint);
            newStateDown->setcameFrom(s);
            newStateDown->setCost(metrix[newX][newY]);
            newPoint.pop_back();
            newPoint.pop_back();
            states.push_back(newStateDown);
        }

        if (canWeStepThere(x - 1, y)) {
            newX = x - 1;
            newY = y;
            newPoint.push_back(newX);
            newPoint.push_back(newY);
            auto newStateLeft = new State<T>(newPoint);
            newStateLeft->setcameFrom(s);
            newStateLeft->setCost(metrix[newX][newY]);
            newPoint.pop_back();
            newPoint.pop_back();
            states.push_back(newStateLeft);

        }

        if (canWeStepThere(x, y - 1)) {
            newX = x + 1;
            newY = y;
            newPoint.push_back(newX);
            newPoint.push_back(newY);
            auto newStateUp = new State<T>(newPoint);
            newStateUp->setcameFrom(s);
            newStateUp->setCost(metrix[newX][newY]);
            newPoint.pop_back();
            newPoint.pop_back();
            states.push_back(newStateUp);

        }

        return states;


    }

    virtual string getDirections(vector<State<T>> path) {

    }


};


#endif //PROJ2_MATRIXPROBLEM_H
