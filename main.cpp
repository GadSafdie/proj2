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


    State<std::string>* a = new State<std::string>("A");
    State<std::string>* b = new State<std::string>("B");
    State<std::string>* goal = new State<std::string>("B");




}