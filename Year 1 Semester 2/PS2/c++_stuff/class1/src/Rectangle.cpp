#include "../include/Rectangle.h"

MCRectangle::MCRectangle() : blocks({}), axises(mc.getPlayerPosition()) {}

MCRectangle::~MCRectangle() {}

void MCRectangle::ReadRectangle(std::string file) {
    std::ifstream Fin;
    std::string line = "";

    try {
        Fin.open(file + ".input");

        if (!Fin) {
            throw 1;
        }
    }
    catch (int errNum) {
        std::cout << "oopsies, sumn wrong wit the input lol" << std::endl;
    }

    while (getline(Fin, line)) {
        blocks.push_back(line);
    }
}

void MCRectangle::BuildRectangle() {
    for (int k = 0; k < HEIGHT; k++) {
        for (int i = 0; i < blocks.size(); i++) {
            for (int j = 0; j < blocks.at(i).size(); j++) {
                mcpp::Coordinate coord(axises.x + j + 1, axises.y + k, axises.z + i + 1);

                if (blocks.at(i).at(j) == 'x') {
                    mc.setBlock(coord, mcpp::Blocks::ACACIA_WOOD_PLANK);
                }
                else if (blocks.at(i).at(j) == 'w') {
                    mc.setBlock(coord, mcpp::Blocks::BLUE_CARPET);
                }
                else {
                    mc.setBlock(coord, mcpp::Blocks::AIR);
                }
            }
        }
    }
}

void MCRectangle::PrintBlocks() {
    for (std::string i : blocks) {
        std::cout << i << "\n";
    }

    std::cout << std::endl;
}

void MCRectangle::PrintAxises() {
    std::cout << axises << std::endl;
}

std::vector<std::string> MCRectangle::GetBlocks() {
    return blocks;
}

mcpp::Coordinate MCRectangle::GetAxises() {
    return axises;
}

std::vector<mcpp::Coordinate> MCRectangle::GetEmptySpaces() {
    std::vector<mcpp::Coordinate> vect = {};

    if (blocks.size() > 0) {
        for (int i = 0; i < blocks.size(); i++) {
            for (int j = 0; j < blocks.at(i).size(); j++) {
                if (blocks.at(i).at(j) == '.') {
                    mcpp::Coordinate coord(axises.x + j + 1, axises.y, axises.z + i + 1);

                    vect.push_back(coord);
                }
            }
        }
    }

    return vect;
}