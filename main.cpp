#include <iostream>
#include "Main.h"
#include "State.h"

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
    vector<vector<State<vector<int,int> >>> matrix;
    for (int i = 0; i < 3; i++) {
        vector<State<vector<int,int>>> myvector;
        for (int j = 0; j < 3; j++) {
            State<vector<int,int>> state;
            state.getState().push_back(i,j);
            cout << "Enter the number for Matrix 1"<<endl;
            cin >> input;
            state.setCost(input);
            myvector.push_back(state);
        }
        matrix.push_back(myvector);
    }



//    State<vector<int,int>>* root;
//    State<T>* goal;











}