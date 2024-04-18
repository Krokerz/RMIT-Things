#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"

class Movie : public Media {
    private:
        std::string director;
        std::string resolution;

    public:
        Movie();
        Movie(std::string, std::string, std::string, std::string);
        std::vector<std::string> info() override;
        void print() override;
        void print(std::ostream&) override;
};

#endif