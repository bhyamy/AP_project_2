//
// Created by bhyamy on 1/28/20.
//

#ifndef AP_PROJECT_2_MYPARALLELSERVER_H
#define AP_PROJECT_2_MYPARALLELSERVER_H

#include "server_side.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <iostream>
#include <vector>
#define TIMEOUT 120
using namespace std;

class MyParallelServer : public server_side::Server {
    //member attributes
    int _sock, _client_socket;
    sockaddr_in _address;
    bool _should_stop;
    thread* _readingLoop;
    vector<thread*> _client_threads;

    //private functions
    void reading(ClientHandler* clientHandler);

public:
    //ctor
    MyParallelServer();
    //dtor
    virtual ~MyParallelServer();

    //implemented methods
    void open(int port, ClientHandler* clientHandler) override;
    void stop() override;

};


#endif //AP_PROJECT_2_MYPARALLELSERVER_H
