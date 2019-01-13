//
// Created by gad on 1/6/19.
//

#ifndef PROJ2_READFILE_H
#define PROJ2_READFILE_H

#include "MatrixProblem.h"
#include "State.h"

#include <iostream>
#include <fstream>
#include "ReadFile.h"
#include "vector"
#include <map>


using namespace std;

class ReadFile {

public:
    map<MatrixProblem*, string> ReadFileCacheManager();


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
