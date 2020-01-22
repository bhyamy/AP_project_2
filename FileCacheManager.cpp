//
// Created by bhyamy on 1/17/20.
//

#include "FileCacheManager.h"
#include <iostream>
#include <fstream>

//ctor
FileCacheManager::FileCacheManager() {}

//dtor
FileCacheManager::~FileCacheManager() {}

bool FileCacheManager::hasSolved(string problem) {
    ifstream file;
    file.open(problem);
    if (file.is_open()) {
        file.close();
        return true;
    } else {
        return false;
    }
}

string FileCacheManager::getSolution(string problem) {
    ifstream file;
    file.open(problem, ios::in);
    if (!file.is_open()) {
        throw "Could not open file";
    }
    char buffer[problem.size()];
    file.read(buffer, problem.size());
    file.close();
    string solution;
    solution.assign(buffer, problem.size());
    return solution;
}

void FileCacheManager::saveSolution(string problem, string solution) {
    ofstream file;
    file.open(problem);
    if (!file.is_open()) {
        throw "Could not open file";
    }
    file.write(solution.c_str(), solution.size());
    file.close();
}
