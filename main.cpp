//#include "Main.h"
#include <iostream>
#include "State.h"
#include "vector"
#include "MatrixProblem.h"

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
    vector<vector<State>> matrix;

    for (int i = 0; i < 3; i++) {
        vector<State> myvector;
        for (int j = 0; j < 3; j++) {
            vector<int> point;
            point.push_back(i);
            point.push_back(j);
            State* state = new State(point);
            cin >> input;
            state->setCost(input);
            myvector.push_back(*state);
        }
        matrix.push_back(myvector);
    }
    vector<int> p;
    p.push_back(0);
    p.push_back(0);
    State* root = new State(p);
    p.clear();
    p.push_back(2);
    p.push_back(2);
    State* goal = new State(p);

    MatrixProblem* ma = new MatrixProblem(matrix,root,goal);

//    vector<State<vector<int>>> gad

    cout<<"hello"<<endl;


//    State<vector<int,int>>* root;
//    State<T>* goal;











}