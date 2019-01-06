//
// Created by gad on 1/6/19.
//

#include <algorithm>
#include "StringReverser.h"

string StringReverser::solve(string p){
    reverse(p.begin(), p.end());
    return p;
}