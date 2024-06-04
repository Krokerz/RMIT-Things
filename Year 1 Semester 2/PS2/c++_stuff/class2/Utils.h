#include <iostream>
#include "Env.h"
#include <mcpp/mcpp.h>

bool ReadEnvSize(int& envHeight, int& envWidth){
    bool works = true;

    std::cout << "Enter the size of the rectangular Environment (H, W): " << std::endl;
    std::cin >> envHeight;
    std::cin >> envWidth;

    if (envHeight == 0 || envWidth == 0) {
        works = false;
        throw "sumn wrong lol";
    }

    return works;
}

void ReadEnvStart(mcpp::Coordinate** start){
    int x=0;
    int y=0;
    int z=0;
    std::cout << "Enter the start coordinate of rectangular Environment (X, Y, Z): " << std::endl;
    std::cin >> x;
    std::cin >> y;
    std::cin >> z;

    *start = new mcpp::Coordinate(x, y, z);
}


void readEnvStdin(char** EnvStruct, int height, int width){
    //int charsRead = 0;
    char readC;

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            if(std::cin.good()){
                std::cin >> readC;
                EnvStruct[row][col] = readC;
                //++charsRead;
            }
        }
        
    }
    
}


void BuildEnvironment(Env* env){
    mcpp::MinecraftConnection mc;
    mc.setPlayerPosition(*(env->getStart()) + mcpp::Coordinate(0, 1, 0));
    
    for(int h =0; h < env->getHeight(); h++){
        for(int w = 0; w < env->getWidth(); w++){
            if((env->getEnvStructure())[h][w] == 'x'){
                mc.setBlock(*(env->getStart()) + mcpp::Coordinate(h, 0, w), mcpp::Blocks::BRICKS);
                mc.setBlock(*(env->getStart()) + mcpp::Coordinate(h, 1, w), mcpp::Blocks::BRICKS);
            }
        }
    }
}
