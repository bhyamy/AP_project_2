//
// Created by bhyamy on 1/16/20.
//

#include "MySerialServer.h"

//ctor
MySerialServer::MySerialServer() {}
//dtor
MySerialServer::~MySerialServer() {}

void MySerialServer::open(int port, ClientHandler clientHandler) {
    //socket opening - a TCP protocol
    sock = socket(AF_INET, SOCK_STREAM, 0);
    //in case of socket opening error
    if (sock == -1) {
        throw "Could not open socket";
    }

    //creating a socket address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    //in case an error occurred during binding
    if (bind(sock, (struct sockaddr *) &address, sizeof(address)) == -1) {
        throw "Could not bind the socket to an IP address";
    }

    while (true) {
        //in case of an error in the listening part
        if (listen(sock, 10) == -1) {
            throw "Error during listen command";
        }
        struct timeval timeout;
        timeout.tv_sec = 120;
        timeout.tv_usec = 0;
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*) &timeout, sizeof(timeout));

        //accepting the client
        client_socket = accept(sock, (struct sockaddr *) &address, (socklen_t *) &address);
        //in case of a client accepting error
        if (client_socket == -1) {
            throw "Could not accept the client";
        }
        thread HandleThread(&ClientHandler::handleClient, &clientHandler, client_socket);
        HandleThread.join();
    }
}

void MySerialServer::stop() {

}
//implemented methods

