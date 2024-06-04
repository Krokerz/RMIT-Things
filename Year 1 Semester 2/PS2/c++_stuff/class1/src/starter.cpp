#include <iostream>
#include <string>
#include "../include/Rectangle.h"
#include "../include/SolveMaze.h"

int main() {
    MCRectangle rect = MCRectangle();
    SolveMaze sm = SolveMaze(true);

    std::string filename = "";

    std::cout << "Please input a .input filename: " << std::flush;
    std::cin >> filename;
    
    std::cout << std::endl;

    rect.ReadRectangle(filename);

    rect.PrintBlocks();
    rect.PrintAxises();

    rect.BuildRectangle();

    std::vector<mcpp::Coordinate> emptySpaces = rect.GetEmptySpaces();
    mcpp::Coordinate basePoint = rect.GetAxises();

    while (filename != "exit") {
        std::cout << "Teleport?" << std::endl;
        std::cin >> filename;

        sm.solveManually(emptySpaces, basePoint);
    }


    return EXIT_SUCCESS;
}