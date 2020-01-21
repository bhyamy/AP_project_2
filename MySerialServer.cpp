//
// Created by bhyamy on 1/16/20.
//

#include "MySerialServer.h"

//ctor
MySerialServer::MySerialServer() {
    _should_stop = false;
}
//dtor
MySerialServer::~MySerialServer() {}

//implemented methods
void MySerialServer::open(int port, ClientHandler clientHandler) {
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

    _readingLoop = new thread(&MySerialServer::reading, this, &clientHandler);
}

void MySerialServer::stop() {
    _should_stop = true;
    _readingLoop->join();
}

void MySerialServer::reading(ClientHandler* clientHandler) {
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    while (!_should_stop) {
        //in case of an error in the listening part
        if (listen(_sock, 10) == -1) {
            throw "Error during listen command";
        }
        //checks for timeout
        if (setsockopt(_sock, SOL_SOCKET, SO_RCVTIMEO, (const char*) &timeout, sizeof(timeout))) {
            break;
        }
        //accepting the client
        _client_socket = accept(_sock, (struct sockaddr *) &_address, (socklen_t *) &_address);
        //in case of a client accepting error
        if (_client_socket == -1) {
            throw "Could not accept the client";
        }
        clientHandler->handleClient(_client_socket);
    }
    close(_sock);
}
