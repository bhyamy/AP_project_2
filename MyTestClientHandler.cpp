//
// Created by bhyamy on 1/16/20.
//

#include "MyTestClientHandler.h"

//ctor
MyTestClientHandler::MyTestClientHandler() {
    _cacheManager = new FileCacheManager();
    _solver = new StringReverser();
}

void MyTestClientHandler::handleClient(int client_socket) {
    string problem, solution;
    while ((problem = readData(client_socket)) != "end") {
        if (_cacheManager->hasSolved(problem)) {
            solution = _cacheManager->getSolution(problem);
        } else {
            solution = _solver->solve(problem);
            _cacheManager->saveSolution(problem, solution);
        }
        send(client_socket, solution.c_str(), solution.size(), 0);
    }
}
//dtor
MyTestClientHandler::~MyTestClientHandler() {
    delete _cacheManager;
    delete _solver;
}
//private methods
string MyTestClientHandler::readData(int client_socket) {
    string data;
    int valRead, pos;
    char buffer[1024];
    valRead = read(client_socket, buffer, 1024);
    int currRead = valRead;
    data.append(buffer, valRead);
    //if there are no \n in the buffer, read the whole info from buffer
    while ((pos = data.find('\n', valRead - currRead)) == -1) {
        currRead = read(client_socket, buffer, 1024);
        data.append(buffer);
        valRead += currRead;
    }
    //takes the exact data from the buffer
    string exactData = data.substr(0, pos);
    return exactData;
}
