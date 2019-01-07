//
// Created by gad on 1/6/19.
//

#ifndef PROJ2_READFILE_H
#define PROJ2_READFILE_H
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <error.h>
#include <map>

using namespace std;

class ReadFile {

public:

    map<string,string> ReadFileCacheManager();

//    Employee *getEmployee(string id, list<Employee *> le);

//    Flight *getFlight(string id,list<Flight *> lf);
//
//    Customer *getCustomer(string id,list<Customer *> lc);
//
//    list<Plane *> ReadFilePlane();
//
//    list<Reservation *> ReadFileReservation(list<Flight *> lf,list<Customer *> lc);
//
//    list<Customer *> ReadFileCustomer();
//
//    list<Flight *> ReadFileFlight();
//
//    list <MyPlaneList*> ReadFileAvPlane ();
//
//    list <MyCrewList*> ReadFileAvCrew ();


};



#endif //PROJ2_READFILE_H
