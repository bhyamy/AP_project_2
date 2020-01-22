//
// Created by bhyamy on 1/16/20.
//

#ifndef AP_PROJECT2_MYSERIALSERVER_H
#define AP_PROJECT2_MYSERIALSERVER_H

#include "server_side.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#define TIMEOUT 120
using namespace std;

class MySerialServer : public server_side::Server{
    //member attributes
    int _sock, _client_socket;
    sockaddr_in _address;
    bool _should_stop;
    thread* _readingLoop;

    //private functions
    void reading(ClientHandler* clientHandler);

public:
    //ctor
    MySerialServer();
    //dtor
    virtual ~MySerialServer();

    //implemented methods
    void open(int port, ClientHandler* clientHandler) override;
    void stop() override;

};


#endif //AP_PROJECT2_MYSERIALSERVER_H
