//
// Created by iris on 27/01/2020.
//

#ifndef UNTITLED_DFS_H
#define UNTITLED_DFS_H

#include "SearcherBase.h"
#include <stack>
template <typename T>

class DFS : public SearcherBase<T> {
    stack<State<T>*> _stack;
public:
    //ctor
    DFS() : SearcherBase<T>() {}
    //dtor
    virtual ~DFS() {}
    //implemented functions
    State<T>* search(Searchable<T>* searchable) override {
        this->pushClose(searchable->getStart());
        _stack.push(searchable->getStart());
        while (!_stack.empty()) {
            auto v = _stack.top();
            _stack.pop();
            if (searchable->isGoal(v)) {
                this->setTotalCost(v->getCost());
                return this->backTrace(v);
            }
            list<State<T>*> successors = searchable->getPossibleStates(v);
            for (State<T>* s : successors) {
                if (this->close_not_contains(s)) {
                    this->pushClose(s);
                    _stack.push(s);
                }
            }
        }
        nullptr;
    }
};


#endif //UNTITLED_DFS_H
