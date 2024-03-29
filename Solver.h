//
// Created by bhyamy on 1/16/20.
//

#ifndef AP_PROJECT2_SOLVER_H
#define AP_PROJECT2_SOLVER_H
template <typename Problem, typename Solution>

class Solver {
public:
    virtual Solution solve(Problem problem) = 0;

    virtual ~Solver() {}
};


#endif //AP_PROJECT2_SOLVER_H
