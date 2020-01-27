//
// Created by bhyamy on 1/23/20.
//

#ifndef AP_PROJECT2_SEARCHER_H
#define AP_PROJECT2_SEARCHER_H

#include "Searchable.h"
#include "State.h"
template <typename T>

class Searcher {
public:
    virtual State<T>* search(Searchable<State<T>*> searchable) = 0;
    virtual int getCost() = 0;
};


#endif //AP_PROJECT2_SEARCHER_H
