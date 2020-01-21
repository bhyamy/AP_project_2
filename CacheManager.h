//
// Created by bhyamy on 1/17/20.
//

#ifndef AP_PROJECT2_CACHEMANAGER_H
#define AP_PROJECT2_CACHEMANAGER_H

template <typename Problem, typename Solution>

class CacheManager {
public:
    virtual bool hasSolved(Problem problem) = 0;
    virtual Solution getSolution(Problem problem) = 0;
    virtual void saveSolution(Problem problem, Solution solution) = 0;
};


#endif //AP_PROJECT2_CACHEMANAGER_H
