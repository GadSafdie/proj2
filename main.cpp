#include <iostream>
#include "Main.h"

using namespace std;


int main(int argc, char *argv[]) {

    char* port1 = argv[1];
    int port = atoi(port1);
    boot::Main* m;
    m->main(port);
    return 0;
}