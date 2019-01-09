//
// Created by gad on 1/7/19.
//

#include "State.h"

template<class T>

bool State<T>::operator==(State<T> other) {
    if (this->state == other.state) {
        return true;
    } else {
        return false;
    }

}
