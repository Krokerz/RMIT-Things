#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "Media.h"

class AudioBook : public Media {
    private:
        std::string author;
        std::string narrator;

    public:
        AudioBook();
        AudioBook(std::string, std::string, std::string, std::string);
        std::vector<std::string> info() override;
        void print() override;
        void print(std::ostream&) override;
};

#endif