//
// Created by bhyamy on 1/23/20.
//

#ifndef AP_PROJECT_2_SEARCHERBASE_H
#define AP_PROJECT_2_SEARCHERBASE_H
#include <queue>
#include <iostream>
#include <map>
#include "Searcher.h"
#include "State.h"
#include <set>
#include <stack>
using namespace std;
template <typename T>
struct ptrcomp {
    bool operator() (State<T>* lhs, State<T>* rhs) const
    {return lhs->getCost() < rhs->getCost();}
};

template <typename T>
class SearcherBase : public Searcher<T> {
    int _totalCost;
    multiset<State<T>*, ptrcomp<T>> _open;
    map<T, State<T>*> _closed;
    map<T, typename multiset<State<T>*, ptrcomp<T>>::iterator> _open_map;

public:
    //ctor
    SearcherBase() {
        _totalCost = 0;
    }

    //dtor
    virtual ~SearcherBase() {}

    //implemented methods
    int getCost() override {
        return _totalCost;
    }

protected:
    //methods
    State<T>* popQueue() {
        auto save = _open.begin();
        _open.erase(save);
        _open_map.erase((*save)->getState());
        return *save;
    }

    void pushQueue(State<T>* state) {
        _open_map[state->getState()] = _open.insert(state);
    }

    bool open_not_empty() { return !_open.empty(); }

    bool open_not_contains(State<T>* s) { return _open_map.find(s->getState()) == _open_map.end(); }

    void open_replace(State<T>* s) {
        _open.erase(_open_map.at(s->getState()));
        _open_map[s->getState()] = _open.insert(s);
    }

    bool shorter(State<T>* s) {
        typename multiset<State<T>*, ptrcomp<T>>::iterator it = _open_map.at(s->getState());
        return s->getCost() < (*it)->getCost();
    }

    State<T>* backTrace(State<T>* n) {
        State<T>* start;
        State<T>* temp;
        stack<State<T>*> track;
        start = n;
        while (start != nullptr) {
            track.push(start);
            start = start->getCameFrom();
        }
        start = track.top();
        temp = track.top();
        track.pop();
        while (!track.empty()) {
            temp->setCameFrom(track.top());
            temp = track.top();
            track.pop();
        }
        temp->setCameFrom(nullptr);
        return start;
    }

    void pushClose(State<T>* state) {
        _closed[state->getState()] = state;
    }

    bool close_not_contains(State<T>* s) { return _closed.find(s->getState()) == _closed.end(); }

public:
    void setTotalCost(int totalCost) {
        _totalCost = totalCost;
    }

};

#endif //AP_PROJECT_2_SEARCHERBASE_H
