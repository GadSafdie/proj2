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
    bool hasVisted = false;



public:
    State<T>(T state, double c) : state(state), cost(c), hasVisted(false), camefrom(nullptr) {}

    State<T>(){}


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

    void setcameFrom(State<T>* pc) {
        camefrom = pc;
    }

    bool getHasVisited() {
        return hasVisted;
    }

    void setHasVisited() {
        hasVisted=true;
    }

    T getState(){
        return state;
    }

    int getNumRow(){
        return state[0];
    }

    int getNumCol(){
        return state[1];
    }

    T setState(T* s){
        state = s;
    }

    bool operator < (const State<T>* &b) const{
        return this->PathCost < b->PathCost;
    }
    bool operator >(const State<T>* &b) const{
        return this->PathCost > b->PathCost;
    }
    bool operator == (const State<T>* &b) const{
        return this->PathCost == b->PathCost;
    }


    bool operator()(const State<T>* left , const State<T>* right){
        return left->getPathCost()>right->getPathCost();
    }

};


#endif //PROJ2_STATE_H
