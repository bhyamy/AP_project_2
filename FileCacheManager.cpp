//
// Created by bhyamy on 1/17/20.
//

#include "FileCacheManager.h"
#include <iostream>
#include <fstream>

/*get solution - read till end of file, put all inside a string with buffer/append etc. put all to solution
return solution.*/

//ctor
FileCacheManager::FileCacheManager() {}

//dtor
FileCacheManager::~FileCacheManager() {}

bool FileCacheManager::hasSolved(string problem) {
    ifstream file;
    file.open("Solution" + to_string(hash(problem)) + ".txt");
    if (file.is_open()) {
        file.close();
        return true;
    }
    return false;
}

string FileCacheManager::getSolution(string problem) {
    ifstream file;
    file.open("Solution" + to_string(hash(problem)), ios::in);
    if (!file.is_open()) {
        throw "Could not open file";
    }
    file.seekg(0, ios::end);
    streampos length = file.tellg();
    file.seekg(0, ios::beg);
    vector<char> buffer(length);
    file.read(&buffer[0],length);
    file.close();
    string solution;
    solution.assign(buffer.data());
    return solution;
    //TODO check if works, if yes delete this comments below!
    /*char buffer[problem.size()];
    file.read(buffer, problem.size());
    file.close();
    string solution;
    solution.assign(buffer, problem.size());
    return solution;*/
}

void FileCacheManager::saveSolution(string problem, string solution) {
    ofstream file;
    file.open(to_string(hash(problem)));
    if (!file.is_open()) {
        throw "Could not open file";
    }
    file.write(solution.c_str(), solution.size());
    file.close();
}
