#include "../headers/Library.h"

Library::Library() {}

Library::~Library() {
    for (Media *i : media) {
        delete i;
    }

    media.clear();
}

// Printing the right book becomes much simpler

std::ostream & operator<<(std::ostream& os, Library& lib) {
    for(auto m : lib.media) {
        m->print(os);
        os << "\n\n";
    }
    return os;

}

void Library::addMedia(Media* media) {
    // add the media to the vector
    this->media.push_back(media);

}

// Same as above, but with a std::string for the title instead.

void Library::searchMedia(std::string target) {
    bool isFound = false;

    for (Media *i : media) {
        for (std::string j : i->info()) {
            if (j == target) {
                i->print();
                isFound = true;
                break;
            }
        }
    }

    isFound ? std::cout : std::cout << "Media not found lol xd";

    std::cout << std::endl;
}