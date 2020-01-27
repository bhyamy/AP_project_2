//
// Created by iris on 27/01/2020.
//

#ifndef UNTITLED_DFS_H
#define UNTITLED_DFS_H

#include "SearcherBase.h"
#include <stack>
template <typename T>

class DFS : public SearcherBase<T> {
    map<T, State<T>*> _closed;
    stack<State<T>*> _stack;
public:
    //ctor
    DFS() : SearcherBase<T>() {}
    //dtor
    virtual ~DFS() {}
    //implemented functions
    State<T>* search(Searchable<State<T>*> &searchable) override {
        _closed[searchable.getStart()->getState()] = searchable.getStart();
        _stack.push(searchable.getStart());
        while (!_stack.empty()) {
            auto v = _stack.top();
            _stack.pop();
            if (searchable.isGoal(v)) {
                this->setTotalCost(v->getCost());
                return this->backTrace(v);
            }
            list<State<T>*> successors = searchable.getPossibleStates(v);
            for (State<T>* s : successors) {
                if (_closed->find(s->getState()) == _closed->end()) {
                    _closed[s->getState()] = s;
                    _stack.push(s);
                }
            }
        }
    }
};


#endif //UNTITLED_DFS_H