//
// Created by bhyamy on 1/28/20.
//

#include "MyParallelServer.h"

//ctor
MyParallelServer::MyParallelServer() {
    _should_stop = false;
}
//dtor
MyParallelServer::~MyParallelServer() {}

//implemented methods
void MyParallelServer::open(int port, ClientHandler* clientHandler) {
    //socket opening - a TCP protocol
    _sock = socket(AF_INET, SOCK_STREAM, 0);
    //in case of socket opening error
    if (_sock == -1) {
        throw "Could not open socket";
    }

    //creating a socket address
    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = INADDR_ANY;
    _address.sin_port = htons(port);
    //in case an error occurred during binding
    if (bind(_sock, (struct sockaddr *) &_address, sizeof(_address)) == -1) {
        throw "Could not bind the socket to an IP address";
    }

    _readingLoop = new thread(&MyParallelServer::reading, this, clientHandler);
    _readingLoop->join();
}

void MyParallelServer::stop() {
    _should_stop = true;
    _readingLoop->join();
}

void MyParallelServer::reading(ClientHandler* clientHandler) {
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(_sock, SOL_SOCKET, SO_RCVTIMEO, (const char*) &timeout, sizeof(timeout));
    while (!_should_stop) {
        //in case of an error in the listening part
        if (listen(_sock, 10) == -1) {
            throw "Error during listen command";
        }
        //accepting the client
        _client_socket = accept(_sock, (struct sockaddr *) &_address, (socklen_t *) &_address);
        //in case of a client accepting error
        if (_client_socket == -1) {
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
                cout << "server time out." << endl;
                break;
            }
            cout << errno << endl;
            throw "Could not accept the client";
        }
        
        _client_threads.push_back(new thread(&ClientHandler::handleClient, clientHandler, _client_socket));
    }
    for (thread* t : _client_threads) {
        t->join();
    }
    close(_sock);
}