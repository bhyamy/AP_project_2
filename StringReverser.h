//
// Created by bhyamy on 1/17/20.
//

#ifndef AP_PROJECT2_STRINGREVERSER_H
#define AP_PROJECT2_STRINGREVERSER_H

#include "Solver.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


//this class implements the solver interface, it's implement is to reverse a given string
class StringReverser : public Solver<string, string> {
public:
    //ctor
    StringReverser();
    //dtor
    virtual ~StringReverser();
    //implemented functions
    string solve(string problem) override;
};


#endif //AP_PROJECT2_STRINGREVERSER_H
