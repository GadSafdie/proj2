//
// Created by gad on 1/6/19.
//

#ifndef PROJ2_WRITEFILE_H
#define PROJ2_WRITEFILE_H

#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <error.h>
#include "string"

using namespace std;


class WriteFile {
public:
//    void writeNewEmployee(Employee *emp);
//
//    void writeNewPlane(Plane *plane);
//
//    void writeNewFlight(Flight *flight);
//
//    void writeNewCustomer(Customer *customer);
//
//    void writeNewRerveservation(Reservation *reservation);
//
//    void writeNewMyPlaneList(MyPlaneList *mpl);

    void writeFileCacheManager(string first, string second);
};


#endif //PROJ2_WRITEFILE_H
