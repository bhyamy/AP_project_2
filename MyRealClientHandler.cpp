//
// Created by bhyamy on 1/30/20.
//

#include "MyRealClientHandler.h"

//ctor
MyRealClientHandler::MyRealClientHandler() {
    _cacheManager = new FileCacheManager();
    _solver = new MazeSover();
}
//dtor
MyRealClientHandler::~MyRealClientHandler() {
    delete _cacheManager;
    delete _solver;
}
//implemented methods
void MyRealClientHandler::handleClient(int client_socket) {
    string problem, solution;
    problem = readData(client_socket);
    if (_cacheManager->hasSolved(problem)) {
        solution = _cacheManager->getSolution(problem);
    } else {
        solution = _solver->solve(problem);
        _cacheManager->saveSolution(problem, solution);
    }
    solution.push_back('\n');
    send(client_socket, solution.c_str(), solution.size(), 0);
}

ClientHandler *MyRealClientHandler::clone() {
    MyRealClientHandler* rch = new MyRealClientHandler();
    rch->switchCache(_cacheManager);
    return rch;
}

//private methods
string MyRealClientHandler::readData(int client_socket) {
    string data;
    int valRead, pos;
    char buffer[1024];
    valRead = read(client_socket, buffer, 1024);
    int currRead = valRead;
    data.append(buffer, valRead);
    //if there are no \n in the buffer, read the whole info from buffer
    while ((pos = data.find("end", valRead - currRead)) == -1) {
        currRead = read(client_socket, buffer, 1024);
        data.append(buffer);
        valRead += currRead;
    }
    //takes the exact data from the buffer
    string exactData = data.substr(0, pos - 2);
    string::iterator end_pos = remove(exactData.begin(), exactData.end(), ' ');
    exactData.erase(end_pos, exactData.end());
    return exactData;
}

void MyRealClientHandler::switchCache(CacheManager<string, string> *cacheManager) {
    delete _cacheManager;
    _cacheManager = cacheManager;
}


