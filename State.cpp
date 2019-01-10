//
// Created by gad on 1/7/19.
//

#include "State.h"


bool State::operator==(State* other) {
    if (this->state == other->state) {
        return true;
    } else {
        return false;
    }

}
