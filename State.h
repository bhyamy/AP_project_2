//
// Created by bhyamy on 1/23/20.
//

#ifndef AP_PROJECT2_STATE_H
#define AP_PROJECT2_STATE_H
template <typename T>

class State {
    T _state;
    double _cost;
    State<T> _cameFrom;
public:
    //ctor
    State(T state);
    //dtor
    virtual ~State();
    //methods
    bool Equals(State<T> other);
};


#endif //AP_PROJECT2_STATE_H
