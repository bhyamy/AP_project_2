//
// Created by bhyamy on 1/23/20.
//

#ifndef AP_PROJECT2_STATE_H
#define AP_PROJECT2_STATE_H

#include <ostream>

template <typename T>

class State {
    T _state;
    int _cost;
    State<T>* _cameFrom;
public:
    //ctor
    State(T state):_state(state) {}
    //dtor
    virtual ~State() {}
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

    //setters
    void setCameFrom(const State<T>* cameFrom) {
        _cameFrom = cameFrom;
    }

    void setCost(int cost) {
        _cost = cost;
    }

};


#endif //AP_PROJECT2_STATE_H
