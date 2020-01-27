//
// Created by iris on 27/01/2020.
//

#ifndef UNTITLED_BFS_H
#define UNTITLED_BFS_H
#include "SearcherBase.h"
#include <queue>
template <typename T>

class BFS : public SearcherBase<T> {
    map<T, State<T>*> _closed;
    queue<State<T>*> _queue;
public:
    //ctor
    BFS() : SearcherBase<T>() {}
    //dtor
    virtual ~BFS() {}
    //implemented functions
    State<T>* search(Searchable<State<T>*> &searchable) override {
        _closed[searchable.getStart()->getState()] = searchable.getStart();
        _queue.push(searchable.getStart());
        while (!_queue.empty()) {
            auto v = _queue.front();
            _queue.pop();
            if (searchable.isGoal(v)) {
                this->setTotalCost(v->getCost());
                return this->backTrace(v);
            }
            list<State<T>*> successors = searchable.getPossibleStates(v);
            for (State<T>* s : successors) {
                if (_closed->find(s->getState()) == _closed->end()) {
                    _closed[s->getState()] = s;
                    _queue.push(s);
                }
            }
        }
    }
};


#endif //UNTITLED_BFS_H
