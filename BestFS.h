//
// Created by bhyamy on 1/23/20.
//

#ifndef AP_PROJECT_2_BESTFS_H
#define AP_PROJECT_2_BESTFS_H

#include "SearcherBase.h"


template <typename T>
class BestFS : public SearcherBase<T> {
public:
    //ctor
    BestFS() : SearcherBase<T>() {}
    //dtor
    virtual ~BestFS() {}
    //implemented functions
    State<T>* search(Searchable<T>* searchable) override {
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
};


#endif //AP_PROJECT_2_BESTFS_H
