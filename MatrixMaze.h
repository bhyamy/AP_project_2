//
// Created by bhyamy on 1/27/20.
//

#ifndef AP_PROJECT_2_MATRIXMAZE_H
#define AP_PROJECT_2_MATRIXMAZE_H


#include "Searchable.h"
#include <vector>


class MatrixMaze : public Searchable<pair<int, int>> {
    vector<vector<int>> _matrix;
    pair<int, int> _start;
    pair<int, int> _goal;
    int _lim_y;
    int _lim_x;

public:
    //ctor
    MatrixMaze(const vector<vector<int>> &matrix, const pair<int, int> &start, const pair<int, int> &goal):
    _matrix (matrix), _start(start), _goal(goal) {
        _lim_y = _matrix.size();
        _lim_x = _matrix[0].size();
    }

    //dtor
    virtual ~MatrixMaze() {}

    //implemented functions
    State<pair<int, int>> *getStart() override {
        auto* start = new State<pair<int, int>>(_start);
        start->setCost(_matrix[_start.first][_start.second]);
        start->setCameFrom(nullptr);
        return start;
    }

    bool isGoal(State<pair<int, int>> *state) override {
        return state->getState() == _goal;
    }

    list<State<pair<int, int>>*> getPossibleStates(State<pair<int, int>> *state) override {
        list<State<pair<int, int>>*> successors;
        int y = state->getState().first;
        int x = state->getState().second;

        //below
        if (state->getState().first < _lim_y && _matrix[y + 1][x] > -1) {
            successors.push_back(stateBuilder(y - 1, x, state));
        }
        //right
        if (state->getState().second < _lim_x && _matrix[y][x + 1] > -1) {
            successors.push_back(stateBuilder(y, x + 1, state));
        }
        //left
        if (state->getState().second < _lim_x && _matrix[y][x - 1] > -1) {
            successors.push_back(stateBuilder(y, x - 1, state));
        }
        //above
        if (state->getState().first > 0 && _matrix[y - 1][x] > -1) {
            successors.push_back(stateBuilder(y - 1, x, state));
        }

        return successors;
    }

private:
    State<pair<int, int>>* stateBuilder(int y, int x, State<pair<int, int>>* state) {
        auto* temp = new State<pair<int, int>>({y, x});
        temp->setCost(_matrix[y][x]);
        temp->setCameFrom(state);
        return temp;
    }
};


#endif //AP_PROJECT_2_MATRIXMAZE_H
