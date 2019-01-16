//
// Created by gad on 1/15/19.
//

#ifndef PROJ2_SEARCHERSOLVER_H
#define PROJ2_SEARCHERSOLVER_H

#include <string>
#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"


using namespace std;

class SearcherSolver : public Solver<Searchable<vector<int>> *, string> {
    Searcher<vector<int>> *searcher;
public:
    SearcherSolver(Searcher<vector<int>> *searcher) : searcher(searcher) {}

    string solve(Searchable<vector<int>> *point) override;
    virtual ~SearcherSolver() {

    }

};


#endif //PROJ2_SEARCHERSOLVER_H
