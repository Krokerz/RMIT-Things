#include <iostream>
#include <string>
#include <vector>

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

Library::Library() {}

Library::~Library() {
    // do something here
}

// Printing the right book becomes much simpler

std::ostream & operator<<(std::ostream& os, Library& lib) {
    for(auto m : lib.media) {
        m->print(os);
    }
    return os;

}

void Library::addMedia(Media* media) {
    // add the media to the vector
    this->media.push_back(media);

}

// Same as above, but with a std::string for the title instead.

void Library::searchMedia(std::string target) {
    // your implementation here
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {

    Library lib;

    lib.addMedia(new Media("Not Real", "Never"));
    lib.addMedia(new Book("Worm", "2011", "UNKNOWN", "John C. McCrae"));
    lib.addMedia(new AudioBook("Ward", "2018", "John C. McCrae", "Rein"));
    lib.addMedia(new Movie("Dune", "2021", "Denis Villeneuve", "4K IMAX"));
    lib.addMedia(new VideoGame("Outer Wilds", "2019", "Annapurna", "Mobius Digital"));

    // std::cout << lib;

    lib.searchMedia("Worm");
    lib.searchMedia("2018");
    lib.searchMedia("Denis Villeneuve");
    lib.searchMedia("Mobius Digital");

    return EXIT_SUCCESS;

}