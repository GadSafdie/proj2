//#include "Main.h"
#include <iostream>
#include "State.h"
#include <vector>
#include "MatrixProblem.h"
#include "BFS.h"
#include "BestFirstSearch.h"
#include "DFS.h"
#include "ReadFile.h"
#include "Astar.h"
#include "WriteFile.h"
#include "CacheManager.h"
#include "ClientHandler.h"
#include "MyClientHandler.h"
#include "FileCacheManager.h"
#include "MyParallelServer.h"
#include "SearcherSolver.h"
#include "Main.h"


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

//    ReadFile *readFile;
//    map<MatrixProblem *, string> myMap;
//    myMap = readFile->ReadFileCacheManager();
//    map<MatrixProblem *, string>::iterator i;
////    cout<<"Best First Serach:"<<endl;
//    for (i = myMap.begin(); i != myMap.end(); ++i) {
//        MatrixProblem *ma = i->first;
//        ISearcher<vector<int>> *one = new BestFirstSearch<vector<int>>();
//        string h = one->search(ma);
//        int x = one->getNumberOfNodesEvaluated();
//        int y = ma->getGoalState()->getpathCost();
//        cout<<y<<","<<x<<endl;
//    }
//    ReadFile *readFile1;
//    map<MatrixProblem *, string> myMap1;
//    myMap1 = readFile1->ReadFileCacheManager();
//    map<MatrixProblem *, string>::iterator i1;
//    cout<<"DFS:"<<endl;
//    for (i1 = myMap1.begin(); i1 != myMap1.end(); ++i1) {
//        MatrixProblem *ma = i1->first;
//        ISearcher<vector<int>> *one = new DFS<vector<int>>();
//        string h = one->search(ma);
//        int x = one->getNumberOfNodesEvaluated();
//        int y = ma->getGoalState()->getpathCost();
//        cout<<y<<","<<x<<endl;
//    }
//    ReadFile *readFile2;
//    map<MatrixProblem *, string> myMap2;
//    myMap2 = readFile2->ReadFileCacheManager();
//    map<MatrixProblem *, string>::iterator i2;
//    cout<<"BFS:"<<endl;
//    for (i2 = myMap2.begin(); i2 != myMap2.end(); ++i2) {
//        MatrixProblem *ma = i2->first;
//        ISearcher<vector<int>> *one = new BFS<vector<int>>();
//        string h = one->search(ma);
//        int x = one->getNumberOfNodesEvaluated();
//        int y = ma->getGoalState()->getpathCost();
//        cout<<y<<","<<x<<endl;
//    }
//    ReadFile *readFile3;
//    map<MatrixProblem *, string> myMap3;
//    myMap3 = readFile3->ReadFileCacheManager();
//    map<MatrixProblem *, string>::iterator i3;
//    cout<<"ASTAR:"<<endl;
//    for (i3 = myMap3.begin(); i3 != myMap3.end(); ++i3) {
//        MatrixProblem *ma = i3->first;
//        ISearcher<vector<int>> *one = new AStar<vector<int>>();
//        string h = one->search(ma);
//        int x = one->getNumberOfNodesEvaluated();
//        int y = ma->getGoalState()->getpathCost();
//        cout<<y<<","<<x<<endl;
//    }





//    cout << "gad" << endl;
//
//
//
//    string h = one->search(ma);
//
//
//    string gadi = myMap.find(ma)->second;
//    hezi->writeFileCacheManager(ma, gadi);
//    MatrixProblem *rrr;
//    // show content:
//    for (std::map<MatrixProblem *, string>::iterator it = myMap.begin(); it != myMap.end(); ++it){
//        rrr = it->first;
//        gadi = it->second;
//    }
//    hezi->writeFileCacheManager(rrr, gadi);
//    if(*ma == *rrr){
//        cout<<"ennnn"<<endl;
//    }
//
//
//    cout<<h<<endl;
//

//        boot::Main m;
//    *    m.main(argc, argv);

    char* port1 = argv[1];
    int port = atoi(port1);
    boot::Main* m;
    m->main(port);
    while (true){}



        return 0; }










//}