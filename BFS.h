//
// Created by iris on 27/01/2020.
//

#ifndef UNTITLED_BFS_H
#define UNTITLED_BFS_H
#include "SearcherBase.h"
#include <queue>
template <typename T>

class BFS : public SearcherBase<T> {
    queue<State<T>*> _queue;
public:
    //ctor
    BFS() : SearcherBase<T>(){}
    //dtor
    virtual ~BFS() {}
    //implemented functions
    State<T>* search(Searchable<T>* searchable) {
        this->pushClose(searchable->getStart());
        _queue.push(searchable->getStart());
        while (!_queue.empty()) {
            auto v = _queue.front();
            _queue.pop();
            if (searchable->isGoal(v)) {
                this->setTotalCost(v->getCost());
                return this->backTrace(v);
            }
            list<State<T>*> successors = searchable->getPossibleStates(v);
            for (State<T>* s : successors) {
                if (this->close_not_contains(s)) {
                    this->pushClose(s);
                    _queue.push(s);
                }
            }
        }
        return nullptr;
    }
};


#endif //UNTITLED_BFS_H
