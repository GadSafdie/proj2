//#include "Main.h"
#include <iostream>
#include "State.h"
#include <vector>
#include "MatrixProblem.h"
#include "BFS.h"
#include "BestFirstSearch.h"
#include "DFS.h"
#include "ReadFile.h"

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

    ReadFile* readFile;
    map<MatrixProblem *, string> myMap;
    myMap =readFile->ReadFileCacheManager();

    cout<<"gad"<<endl;

    Searchable<vector<int>>* ma = myMap.begin()->first;
    ISearcher<vector<int>>* one = new DFS<vector<int>>();

   string h = one->search(ma);
   int x = one->getNumberOfNodesEvaluated();
    int y = ma->getGoalState()->getpathCost();


//    vector<State<vector<int>>> gad

    cout<<x<<endl;
    cout<<y<<endl;
    cout<<h<<endl;


//    State<vector<int,int>>* root;
//    State<T>* goal;











}