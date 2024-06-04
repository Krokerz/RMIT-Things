#include "Env.h"

Env::Env()
{
    this->height = 0;
    this->width = 0;

    envStructure = nullptr;
    start = nullptr;
}

Env::Env(int height, int width):
                        height(height),
                        width(width)
{
    this->envStructure = nullptr;
    this->start = nullptr;
}

Env::~Env()
{
    //TODO
}


int Env::getHeight(void){
    return this->height;
}

int Env::getWidth(void){
    return this->width;
}

void Env::setHeight(int height){
    this->height = height;
}

void Env::setWidth(int width){
    this->width = width;
}


//Identify is there are any issues
void Env::setStart(mcpp::Coordinate* start){
    this->start = start;
}


mcpp::Coordinate* Env::getStart(void){
    return this->start;
}

//Identify is there are any issues
void Env::setEnvStructure(char** envStructure){
    this->envStructure = envStructure;
}

char** Env::getEnvStructure(void){
    return this->envStructure;
}

