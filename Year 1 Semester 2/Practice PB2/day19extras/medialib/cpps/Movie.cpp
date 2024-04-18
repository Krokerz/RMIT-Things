#include "../headers/Movie.h"

Movie::Movie() {}

Movie::Movie(std::string title, std::string year, std::string director, std::string resolution) : Media(title, year), director(director), resolution(resolution) {}

std::vector<std::string> Movie::info() {
    std::vector<std::string> out = Media::info();

    out.push_back(director);
    out.push_back(resolution);

    return out;
}

void Movie::print() {
    Media::print();
    std::cout << "\n\tDirector: " << director << "\n\tResolution: " << resolution;
}

void Movie::print(std::ostream &out) {
    Media::print(out);
    out << "\n\tDirector: " << director << "\n\tResolution: " << resolution;
}