//
// Created by gad on 1/7/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H

#include <string>
#include "vector"


using namespace std;


class State {
    vector<int> state;
    double cost;
    State *camefrom;
    double pathCost;
    bool hasVisted;


public:
    State(vector<int> state) {
        this->state = state;
        this->cost = 0;
        this->hasVisted = false;
    }


    bool operator==(State* other);

    State *getCamefrom() {
        return camefrom;
    }

    double getCost() {
        return cost;
    }

    void setCost(double c) {
        cost = c;
    }

    double getpathCost() {
        return pathCost;
    }

    void setpathCost(double pc) {
        pathCost = pc;
    }

    State *getcameFrom() {
        return camefrom;
    }

    void setcameFrom(State *pc) {
        camefrom = pc;
    }

    bool getHasVisited() {
        return hasVisted;
    }

    void setHasVisited() {
        hasVisted = true;
    }

    vector<int> getState() {
        return state;
    }

};


#endif //PROJ2_STATE_H
