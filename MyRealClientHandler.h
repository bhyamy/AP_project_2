//
// Created by bhyamy on 1/30/20.
//

#ifndef AP_PROJECT_2_MYREALCLIENTHANDLER_H
#define AP_PROJECT_2_MYREALCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "FileCacheManager.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <algorithm>
using namespace std;


class MyRealClientHandler : public ClientHandler {

    Solver<string, string>* _solver;
    CacheManager<string, string>* _cacheManager;

    //private methods
    string readData(int client_socket);
    void switchCache(CacheManager<string, string>* cacheManager);

public:
    //ctor
    MyRealClientHandler();
    //clone

    //dtor
    virtual ~MyRealClientHandler();
    //implemented functions
    void handleClient(int socket) override;

    ClientHandler *clone() override;
};


#endif //AP_PROJECT_2_MYREALCLIENTHANDLER_H
