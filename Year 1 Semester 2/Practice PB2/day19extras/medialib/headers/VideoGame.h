#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Media.h"

class VideoGame : public Media {
    private:
        std::string publisher;
        std::string developer;

    public:
        VideoGame();
        VideoGame(std::string, std::string, std::string, std::string);
        std::vector<std::string> info() override;
        void print() override;
        void print(std::ostream&) override;
};

#endif