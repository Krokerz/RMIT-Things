#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include <iostream>

class Library {
    private: 
        std::vector<std::string> titles;
        std::vector<std::string> authors;
        std::vector<int> ISBNs;

    public:
        Library();
        void AddBook(std::string title, std::string author = "Unknown");
        void SearchBook(std::string title);
        void SearchBook(int ISBN);
};

#endif