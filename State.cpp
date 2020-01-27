//
// Created by bhyamy on 1/23/20.
//

#include "State.h"

template<typename T>
State<T>::State(T state):_state(state) {}

template<typename T>
State<T>::~State() {}

template<typename T>
bool State<T>::Equals(State<T> other) {
    return _state == other->_state;
}


