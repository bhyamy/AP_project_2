//
// Created by bhyamy on 1/23/20.
//

#ifndef AP_PROJECT_2_BESTFS_H
#define AP_PROJECT_2_BESTFS_H

#include "SearcherBase.h"
#include <stack>


template <typename T>
class BestFS : public SearcherBase<T> {
    map<T, State<T>*> *_closed;
public:
    //ctor
    BestFS() : SearcherBase<T>() {
        _closed = new map<T, State<T>*>;
    }

    //dtor
    virtual ~BestFS() {}

    //implemented functions
    State<T>* search(Searchable<State<T>*> &searchable) override {
        this->pushQueue(searchable.getStart());
        while (this->open_not_empty()) {
            auto n = this->popQueue();
            _closed[n->getState()] = n;
            if (searchable.isGoal(n)) {
                this->setTotalCost(n->getCost());
                return backTrace(n);
            }
            list<State<T>*> successors = searchable.getPossibleStates(n);
            for (State<T>* s : successors) {
                if (_closed->find(s) == _closed->end()) {
                    if (this->open_not_contains(s)){
                        //todo define also where the state came from in get successors
                        this->pushQueue(s);
                    } else if (shorter(s)) {
                        this->open_replace(s);
                    }
                }
            }
        }
        //todo no solution
    }

private:
    State<T>* backTrace(State<T>* n) {
        //todo this method
        State<T>* start, temp;
        stack<State<T>*> track;
        start = n;
        while (start != nullptr) {
            track.push(start);
            start = start->getCameFrom();
        }
        temp = track.top();
        track.pop();
        while (!track.empty()) {
            temp.setCameFrom(track.top());
            temp = track.top();
            track.pop();
        }
        temp.setCameFrom(nullptr);
        return start;
    }
};


#endif //AP_PROJECT_2_BESTFS_H
