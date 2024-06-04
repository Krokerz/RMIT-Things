#include "../include/Agent.h"

Agent::Agent() : isSet(false) {
    mc = mcpp::MinecraftConnection();
    currLoc = EMPTY;
}

Agent::Agent(int x, int y, int z) : isSet(true) {
    mc = mcpp::MinecraftConnection();
    currLoc = mcpp::Coordinate(x, y, z);
}

Agent::Agent(const mcpp::Coordinate& currLoc) : isSet(true) {
    mc = mcpp::MinecraftConnection();
    this->currLoc = currLoc;
}

Agent::~Agent() {}

void Agent::setCoord(const mcpp::Coordinate& coord) {
    currLoc = coord;
    isSet = true;
}

void Agent::setCoord(int x, int y, int z) {
    currLoc.x = x;
    currLoc.y = y;
    currLoc.z = z;
    isSet = true;
}

void Agent::solve() {
    SolvingAlgo algo = ALGO;

    if (!isSet) {
        throw "Internal logic error lol, go fix it";
    }
    else if (algo == LEFT_HAND_FOLLOW) {
        // do I need to use the enums?
        // do I have to #define the 0?
        int iter = 0;

        // A linked list may be more suitable for this
        const std::vector<mcpp::Coordinate> coordVect = ANTI_CLOCKWISE;

        mcpp::BlockType currBlock = mcpp::Blocks::AIR;

        mcpp::Coordinate left = EMPTY;
        mcpp::Coordinate front = EMPTY;

        while (!(currBlock == EXITBLOCK)) {
            left = currLoc + coordVect.at((iter + CHECKLEFT) % coordVect.size());
            front = currLoc + coordVect.at(iter);

            if (!(mc.getBlock(left) == WALLBLOCK)) {
                iter++;
                iter = iter % coordVect.size();
            }
            else if (mc.getBlock(front) == WALLBLOCK) {
                iter--;
                iter = abs(iter) % coordVect.size();
            }
            else {
                currLoc = front;
            }

            currBlock = mc.getBlock(currLoc);

            mc.setBlock(currLoc, ROUTEBLOCK);

            // wait for 1 sec

            mc.setBlock(currLoc, currBlock);
        }
    }
    else {
        // BFS Algo
    }
}