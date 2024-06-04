#ifndef SOLVEMAZE_H
#define SOLVEMAZE_H

// SOLVEMAZE AS A SEPERATE FILE MAY BE UNNECESSARY DEPENDING ON IMPLEMENTATION

#include <random>
#include <mcpp/mcpp.h>
#include "Agent.h"
#include "Rectangle.h"

class SolveMaze {
    private:
        mcpp::MinecraftConnection mc;
        Agent solver;
        bool isTestMode;
    
    public:
        SolveMaze(bool testMode);
        ~SolveMaze();

        void solveManually(std::vector<mcpp::Coordinate> &coordVect, mcpp::Coordinate &base);
        void showEscapeRoute(std::vector<mcpp::Coordinate> &coordVect, mcpp::Coordinate &base, int length, int width);
};

#endif