#ifndef BOOK_H
#define BOOK_H

#include "Media.h"

class Book : public Media {
    private:
        std::string isbn;
        std::string author;

    public:
        Book();
        Book(std::string, std::string, std::string, std::string);
        std::vector<std::string> info() override;
        void print() override;
        void print(std::ostream&) override;
};

#endif