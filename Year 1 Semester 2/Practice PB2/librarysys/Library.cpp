#include <cctype>

#include "Library.h"

Library::Library() {
    this->titles = titles;
    this->authors = authors;

    for (unsigned int i = 1; i < titles.size(); i++) {
        ISBNs.push_back(i);
    }
}

void Library::AddBook(std::string title, std::string author) {
    titles.push_back(title);
    authors.push_back(author);
    ISBNs.push_back(ISBNs.size() + 1);
}

void Library::SearchBook(std::string title) {
    std::vector<int> temp;

    for (unsigned int i = 0; i < titles.size(); i++) {
        bool same = true;

        for (unsigned int j = 0; j < title.size(); j++) {
            if (tolower(titles.at(i).at(j)) != tolower(title.at(j))) {
                same = false;
                break;
            }
        }

        if (same) {
            temp.push_back(i);
        }
    }

    for (unsigned int i = 0; i < temp.size(); i++) {
        std::cout << i + 1 << "." << std::endl;
        std::cout << "Title: " << titles.at(temp.at(i)) << std::endl;
        std::cout << "Author: " << authors.at(temp.at(i)) << std::endl;
        std::cout << "ISBN: " << ISBNs.at(temp.at(i)) << std::endl;
        std::cout << std::endl;
    }
}
void Library::SearchBook(int ISBN) {
    std::vector<int> temp;

    for (unsigned int i = 0; i < ISBNs.size(); i++) {
        if (ISBNs.at(i) == ISBN) {
            temp.push_back(i);
        }
    }

    for (unsigned int i = 0; i < temp.size(); i++) {
        std::cout << i + 1 << "." << std::endl;
        std::cout << "Title: " << titles.at(temp.at(i)) << std::endl;
        std::cout << "Author: " << authors.at(temp.at(i)) << std::endl;
        std::cout << "ISBN: " << ISBNs.at(temp.at(i)) << std::endl;
        std::cout << std::endl;
    }
}