#include "../include/SolveMaze.h"

SolveMaze::SolveMaze(bool testMode) : solver(Agent()), isTestMode(testMode) {
    mc = mcpp::MinecraftConnection();
};

SolveMaze::~SolveMaze() {}

void SolveMaze::solveManually(std::vector<mcpp::Coordinate> &coordVect, mcpp::Coordinate &base) {
    // Problem: how to get coords of maze and get maze empty spaces? maybe from other class if possible?
    if (isTestMode) {
        int max = 0;
        int index = 0;

        for (unsigned int i = 0; i < coordVect.size(); i++) {
            int temp = abs(coordVect.at(i).x - base.x) + abs(coordVect.at(i).z - base.z);

            if (max < temp) {
                index = i;
                max = temp;
            }
        }

        mc.setPlayerPosition(coordVect.at(index));
        std::cout << coordVect.at(index) << std::endl;
    }
    else {
        mc.setPlayerPosition(coordVect.at(rand() % coordVect.size()));
        std::cout << coordVect.at(rand() % coordVect.size()) << std::endl;
    }
}

void SolveMaze::showEscapeRoute(std::vector<mcpp::Coordinate> &coordVect, mcpp::Coordinate &base, int length, int width) {
    try {
        mcpp::Coordinate initialPos = mc.getPlayerPosition();

        // TODO: Check if player is in the boundaries of the maze, and check if the player is in an empty space, also "base" is an mcpp::Coordinate object with the base point
        // TODO: Make this shorter by making a function in util
        if ((initialPos.x >= (base.x + 1)) && (initialPos.z >= (base.z + 1)) && (initialPos.x <= (base.x + 1 + length)) && (initialPos.z <= (base.z + 1 + width))) {
            bool isInEmpty = false;

            for (mcpp::Coordinate i : coordVect) {
                if ((i.x == initialPos.x) && (i.z == initialPos.z)) {
                    isInEmpty = true;
                }
            }

            if (isInEmpty) {
                initialPos.y = base.y;
                solver.setCoord(initialPos);

                solver.solve();
            }
            else {
                throw "The player is not in an empty space!";
            }
        }
        else {
            throw "The player is not in the bounds of the maze!";
        }
    }
    catch (std::string str) {
        std::cout << str << std::endl;
    }
}