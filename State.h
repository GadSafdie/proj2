//
// Created by gad on 1/7/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H

#include <string>

using namespace std;

template<class T>

class State {
    T state;
    double cost;
    State<T>* camefrom;
    double pathCost;
    bool hasVisted;



public:
    State(T state) {
        this->state = state;
        this->cost = 0;
    }

    bool operator==(State<T> other);

    State<T>* getCamefrom() {
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

    State<T>* getcameFrom() {
        return camefrom;
    }

    void setcameFrom(State<T>* pc) {
        camefrom = pc;
    }

};


#endif //PROJ2_STATE_H
