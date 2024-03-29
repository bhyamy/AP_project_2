//
// Created by bhyamy on 1/23/20.
//

#ifndef AP_PROJECT2_SEARCHABLE_H
#define AP_PROJECT2_SEARCHABLE_H
#include <list>
#include <iostream>
#include "State.h"
using namespace std;
template <typename T>

class Searchable {
public:
    virtual State<T>* getStart() = 0;
    virtual bool isGoal(State<T>* state) = 0;
    virtual State<T>* getGoal() = 0;
    virtual list<State<T>*> getPossibleStates(State<T>* state) = 0;

    virtual ~Searchable() {}
};


#endif //AP_PROJECT2_SEARCHABLE_H
