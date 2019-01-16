//
// Created by gad on 1/15/19.
//

#include "SearcherSolver.h"

string SearcherSolver::solve(Searchable<vector<int>> *point) {
    return searcher->search(point);
}
