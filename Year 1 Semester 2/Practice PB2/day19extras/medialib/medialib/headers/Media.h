#ifndef MEDIA_H
#define MEDIA_H

#include "utils.h"

class Media {
    protected:
        std::string title;
        std::string year;

    public:
        Media();
        Media(std::string, std::string);
        virtual std::vector<std::string> info();
        virtual void print();
        virtual void print(std::ostream&);
};

#endif