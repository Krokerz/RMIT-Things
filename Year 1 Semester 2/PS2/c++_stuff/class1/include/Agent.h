#ifndef ASSIGN3_AGENT_H
#define ASSIGN3_AGENT_H

#include <iostream>
#include <vector>
#include <mcpp/mcpp.h>

#define EMPTY mcpp::Coordinate(0, 0, 0)
#define MOVE_XPLUS mcpp::Coordinate(1,0,0)
#define MOVE_XMINUS mcpp::Coordinate(-1,0,0)
#define MOVE_ZPLUS mcpp::Coordinate(0,0,1)
#define MOVE_ZMINUS mcpp::Coordinate(0,0,-1)

#define ANTI_CLOCKWISE {MOVE_XPLUS, MOVE_ZMINUS, MOVE_XMINUS, MOVE_ZPLUS}

#define ALGO LEFT_HAND_FOLLOW // Change algo used here
#define WALLBLOCK mcpp::Blocks::ACACIA_WOOD_PLANK // Change wall block used here
#define ROUTEBLOCK mcpp::Blocks::LIME_CARPET // Change route block used here
#define EXITBLOCK mcpp::Blocks::BLUE_CARPET // Change exit block used here

#define CHECKLEFT 1

/**
 * Assumptions:
 * - Walls of the maze have not been tampered with
 * - Obstacles in the form of wall blocks have not been added to the empty spaces of the maze
 * - The maze does not contain loops (if the algorithm used is the left-hand follow algorithm)
 * - The maze has an exit/end
 * - The block used for indication of the maze's exit/end has not been tampered with
*/

enum SolvingAlgo {
    LEFT_HAND_FOLLOW,
    BREATH_FIRST_SEARCH,
};

enum AgentOrient {
    X_PLUS,
    Z_MINUS,
    X_MINUS,
    Z_PLUS
};

class Agent {
    private:
        mcpp::MinecraftConnection mc;
        mcpp::Coordinate currLoc;
        bool isSet;
    
    public:
        Agent();
        Agent(int x, int y, int z);
        Agent(const mcpp::Coordinate& currLoc);
        ~Agent();

        void setCoord(const mcpp::Coordinate& coord);
        void setCoord(int x, int y, int z);
        void solve();
};



#endif //ASSIGN3_AGENT_H