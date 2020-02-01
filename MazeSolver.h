//
// Created by iris on 30/01/2020.
//

#ifndef UNTITLED_MAZESOLVER_H
#define UNTITLED_MAZESOLVER_H
#include "Solver.h"
#include "MatrixMaze.h"
#include <list>
#include "BFS.h"
#include "DFS.h"
#include "BestFS.h"
#include "AStar.h"

class MazeSolver : public Solver<string, string> {

    Searchable<pair<int, int>>* _searchable;
    list<Searcher<pair<int, int>>*> _searchers;

    //private methods
    string buildSolution(State<pair<int,int>>* solution_path);

public:
    //ctor
    MazeSolver();
    //dtor
    virtual ~MazeSolver();
    //implemented functions
    string solve(string problem) override;
};


#endif //UNTITLED_MAZESOLVER_H
