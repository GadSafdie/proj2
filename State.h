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
    State<T> camefrom;

public:
    State(T state) {
        this->state = state;
        this->cost = 0;
    }

    bool operator==(State<T> other);

    State<T>* getCamefrom() {
        return camefrom;
    }

    void setCamefrom(T camefrom) {
        this->camefrom  =camefrom;
    }

    double getCost() {
        return cost;
    }

    double setCost() {
        return cost;
    }


};


#endif //PROJ2_STATE_H
