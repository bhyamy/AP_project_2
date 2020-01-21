//
// Created by bhyamy on 1/17/20.
//

#include "StringReverser.h"

//ctor
StringReverser::StringReverser() {}
//dtor
StringReverser::~StringReverser() {}

//
//this function receives a problem as a string, "solves" it by returning a reversed string, aka the solution
string StringReverser::solve(string problem) {
    reverse(problem.begin(), problem.end());
    return problem;
}