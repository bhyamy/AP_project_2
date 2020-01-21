//
// Created by bhyamy on 1/16/20.
//

#ifndef AP_PROJECT2_MYTESTCLIENTHANDLER_H
#define AP_PROJECT2_MYTESTCLIENTHANDLER_H
#include "ClientHandler.h"
#include "Solver.h"

class MyTestClientHandler : public ClientHandler {
    MyTestClientHandler();
    Solver* solver;
};


#endif //AP_PROJECT2_MYTESTCLIENTHANDLER_H
