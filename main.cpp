//#include "Main.h"
#include <iostream>
#include "State.h"
#include "vector"
#include "MatrixProblem.h"
#include "BFS.h"
#include "BestFirstSearch.h"
#include "DFS.h"

using namespace std;


int main(int argc, char *argv[]) {

//    char* port1 = argv[1];
//    int port = atoi(port1);
//    boot::Main* m;
//    m->main(port);
//    while (true){}


//    State<std::string>* a = new State<std::string>("A");
//    State<std::string>* b = new State<std::string>("B");
//    State<std::string>* goal = new State<std::string>("B");

    double input;
    vector<vector<State<vector<int>>*>> matrix;

    for (int i = 0; i < 3; i++) {
        vector<State<vector<int>>*> myvector;
        for (int j = 0; j < 3; j++) {
            vector<int> point;
            point.push_back(i);
            point.push_back(j);
            State<vector<int>>* state = new State<vector<int>>(point,6);
            cin >> input;
            state->setCost(input);
            myvector.push_back(state);
        }
        matrix.push_back(myvector);
    }
    vector<int> p;
    p.push_back(0);
    p.push_back(0);
    State<vector<int>>* root = new State<vector<int>>(p,1);
    p.clear();
    p.push_back(1);
    p.push_back(2);
    State<vector<int>>* goal = new State<vector<int>>(p,2);

    Searchable<vector<int>>* ma = new MatrixProblem(matrix,root,goal);

   ISearcher<vector<int>>* one = new BFS<vector<int>>();
   string h = one->search(ma);



//    vector<State<vector<int>>> gad

    cout<<h<<endl;


//    State<vector<int,int>>* root;
//    State<T>* goal;











}