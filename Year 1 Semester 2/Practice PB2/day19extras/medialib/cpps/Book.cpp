#include "../headers/Book.h"

Book::Book() {}

Book::Book(std::string title, std::string year, std::string isbn, std::string author) : Media(title, year), isbn(isbn), author(author) {}

std::vector<std::string> Book::info() {
    std::vector<std::string> out = Media::info();

    out.push_back(isbn);
    out.push_back(author);

    return out;
}

void Book::print() {
    Media::print();
    std::cout << "\n\tISBN: " << isbn << "\n\tAuthor: " << author;
}

void Book::print(std::ostream &out) {
    Media::print(out);
    out << "\n\tISBN: " << isbn << "\n\tAuthor: " << author;
}