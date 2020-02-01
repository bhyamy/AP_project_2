//
// Created by bhyamy on 1/23/20.
//

#ifndef AP_PROJECT2_STATE_H
#define AP_PROJECT2_STATE_H

#include <ostream>

template <typename T>

class State {
    T _state;
    int _cost = 0;
    State<T>* _cameFrom;
    int _g = 0;
    int _heuristic = 0;
public:
    //ctor
    State(T state):_state(state) {}
    //dtor
    virtual ~State() {
        if (_cameFrom != nullptr)
            delete _cameFrom;
    }
    //methods
    bool operator==(State<T> other) {
        return _state == other->_state;
    }
    //getters
    int getCost() const {
        return _cost;
    }

    T getState() const {
        return _state;
    }

    State<T> *getCameFrom() const {
        return _cameFrom;
    }

    //operators
    bool operator<(const State &rhs) const {
        return (_state < rhs._state);
    }

    int getG() const {
        return _g;
    }

    //setters
    void setCameFrom(State<T>* cameFrom) {
        _cameFrom = cameFrom;
    }

    void setCost(int cost) {
        _g = cost;
        _cost = _g + _heuristic;
    }

    void setHeuristic(int heuristic) {
        _heuristic = heuristic;
        _cost = _g + _heuristic;
    }

};


#endif //AP_PROJECT2_STATE_H
