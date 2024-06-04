#ifndef RECTANGLE_H
#define RECTANGLE_H

#define HEIGHT 3

#include <mcpp/mcpp.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

class MCRectangle {
    public:
        MCRectangle();
        ~MCRectangle();

        void ReadRectangle(std::string file);
        void BuildRectangle();

        void PrintBlocks();
        void PrintAxises();

        std::vector<std::string> GetBlocks();
        mcpp::Coordinate GetAxises();
        std::vector<mcpp::Coordinate> GetEmptySpaces(); 

    private:
        mcpp::MinecraftConnection mc;
        std::vector<std::string> blocks;
        mcpp::Coordinate axises;
};

#endif