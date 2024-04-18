#include "../headers/Media.h"

Media::Media() {}

Media::Media(std::string title, std::string year) : title(title), year(year) {}

std::vector<std::string> Media::info() {
    std::vector<std::string> out;

    out.push_back(title);
    out.push_back(year);

    return out;
}

void Media::print() {
    std::cout << "\tTitle: " << title << "\n\tYear: " << year;
}

void Media::print(std::ostream &out) {
    out << "\tTitle: " << title << "\n\tYear: " << year;
}