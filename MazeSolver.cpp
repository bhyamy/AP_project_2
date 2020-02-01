//
// Created by iris on 30/01/2020.
//

#include "MazeSolver.h"

//ctor
MazeSolver::MazeSolver() {
    //put all the algorithms in the list
    _searchers.push_back(new AStar<pair<int, int>>);
    _searchers.push_back(new BestFS<pair<int, int>>);
    _searchers.push_back(new BFS<pair<int, int>>);
    _searchers.push_back(new DFS<pair<int, int>>);
}

//dtor
MazeSolver::~MazeSolver() {
    delete _searchable;

}

//this function finds the shortest solution to the maze using 4 algorithms and returns it
string MazeSolver::solve(string problem) {
    //creating an int matrix from the given string problem
    vector<vector<int>> mat;
    int current = 0;
    int size = problem.size();
    while (current < size) {
        //rows
        vector<int> inside_mat;
        while (problem.substr(current, 1) != "\n") {
            //put each number inside a cell, numbers are separated with commas
            string cell = problem.substr(current,
                    min(problem.find_first_of(',', current), problem.find_first_of('\n', current)) - current); //todo think about \r
            int cell_mat = stoi(cell);
            inside_mat.push_back(cell_mat);
            current += cell.size();
            if (problem.substr(current, 1) == ",") {
                current++;
            }
        }
        current++;
        //add the row to the matrix
        mat.push_back(inside_mat);
    }
    //taking the start and end point out of the vector and creating the searchable
    vector<int> point = mat.back();
    pair<int, int> end = {point[1], point[0]};
    mat.pop_back();
    point = mat.back();
    pair<int, int> start = {point[1], point[0]};
    mat.pop_back();
    _searchable = new MatrixMaze(mat, start, end);

    //finding the shortest solution
    int cost = -1;
    State<pair<int, int>>* solution_path = nullptr;
    for (Searcher<pair<int, int>>* searcher : _searchers) {
        State<pair<int, int>>* temp = searcher->search(_searchable);
        if (temp != nullptr) {
            if (cost == -1 || searcher->getCost() < cost) {
                solution_path = temp;
                cost = searcher->getCost();
            }
        }
    }
    //turning the solution path to a string and returning it
    return buildSolution(solution_path);
}

string MazeSolver::buildSolution(State<pair<int, int>> *solution_path) {
    //the came from are actually acting as next
    string solution;
    bool first = true;
    State<pair<int, int>> *temp = solution_path;
    if (solution_path == nullptr) {
        return "No Solution.";
    }
    while (temp != nullptr) {
        if (!first) {
            solution += "(" + to_string(temp->getG()) + ")";
        }
        if (temp->getCameFrom() != nullptr) {
            if (!first) {
                solution += " ,";
            }
            if (temp->getState().first > temp->getCameFrom()->getState().first) {
                solution += "Up ";
            } else if (temp->getState().first < temp->getCameFrom()->getState().first) {
                solution += "Down ";
            } else if (temp->getState().second > temp->getCameFrom()->getState().second) {
                solution += "Left ";
            } else if (temp->getState().second < temp->getCameFrom()->getState().second) {
                solution += "Right ";
            }
        }
        if (first)
            first = !first;
        temp = temp->getCameFrom();
    }
    return solution;
}
