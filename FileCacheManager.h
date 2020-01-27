//
// Created by bhyamy on 1/17/20.
//

#ifndef AP_PROJECT2_FILECACHEMANAGER_H
#define AP_PROJECT2_FILECACHEMANAGER_H
#include "CacheManager.h"
#include <string>
#include <vector>
using namespace std;

class FileCacheManager : public CacheManager<string, string> {
    hash<string> hash;
public:
    //ctor
    FileCacheManager();
    //dtor
    virtual ~FileCacheManager();
    // implemented functions
    bool hasSolved(string problem) override;
    string getSolution(string problem) override;
    void saveSolution(string problem, string solution) override;
};


#endif //AP_PROJECT2_FILECACHEMANAGER_H
