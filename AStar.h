//
// Created by bhyamy on 2/1/20.
//

#ifndef AP_PROJECT_2_ASTAR_H
#define AP_PROJECT_2_ASTAR_H

#include "SearcherBase.h"
#include <cmath>

template <typename T>
class AStar : public SearcherBase<T> {
public:
    //ctor
    AStar() : SearcherBase<T>() {}
    //dtor
    virtual ~AStar() {}
    //implemented functions
    State<T> *search(Searchable<T> *searchable) override {
        this->pushQueue(searchable->getStart());
        while (this->open_not_empty()) {
            auto n = this->popQueue();
            this->pushClose(n);
            if (searchable->isGoal(n)) {
                this->setTotalCost(n->getCost());
                return this->backTrace(n);
            }
            list<State<T>*> successors = searchable->getPossibleStates(n);
            for (State<T>* s : successors) {
                s->setHeuristic(getHeuristic(s, searchable->getGoal()->getState()));
                if (this->close_not_contains(s)) {
                    if (this->open_not_contains(s)){
                        this->pushQueue(s);
                    } else if (this->shorter(s)) {
                        this->open_replace(s);
                    }
                }
            }
        }
        return nullptr;
    }

    //private methods
private:
    int getHeuristic(State<T>* s, pair<int,int> goal) {
        int i;
        i = abs(goal.first - s->getState().first) + abs(goal.second - s->getState().second);
        return i;
    }
};


#endif //AP_PROJECT_2_ASTAR_H
