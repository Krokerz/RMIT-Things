#ifndef LIBRARY_H
#define LIBRARY_H

#include "Media.h"
#include "utils.h"

class Library {
    private:
        std::vector<Media*> media;

    public:
        Library();
        ~Library();
        void addMedia(Media*);
        void searchMedia(std::string);
        friend std::ostream & operator<<(std::ostream&, Library&);
};

#endif