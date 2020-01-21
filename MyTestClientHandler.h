//
// Created by bhyamy on 1/16/20.
//

#ifndef AP_PROJECT2_MYTESTCLIENTHANDLER_H
#define AP_PROJECT2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "Solver.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>

using namespace std;

class MyTestClientHandler : public ClientHandler {

    Solver<string, string>* _solver;
    CacheManager<string, string>* _cacheManager;

    //private methods
    string readData(int client_socket);

public:
    //ctor
    MyTestClientHandler();
    //dtor
    virtual ~MyTestClientHandler();
    //implemented functions
    void handleClient(int client_socket) override;
};


#endif //AP_PROJECT2_MYTESTCLIENTHANDLER_H
