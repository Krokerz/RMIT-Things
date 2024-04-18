#include <iostream>
#include <string>
#include <vector>

#include "headers/Library.h"
#include "headers/Media.h"
#include "headers/Book.h"
#include "headers/AudioBook.h"
#include "headers/Movie.h"
#include "headers/VideoGame.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {
    
    Library lib;
    std::vector<std::string> searchQuery = {"Not Real", "Worm", "2018", "Denis Villeneuve", "Mobius Digital", "hghfkjvchyigou"};

    lib.addMedia(new Media("Not Real", "Never"));
    lib.addMedia(new Book("Worm", "2011", "UNKNOWN", "John C. McCrae"));
    lib.addMedia(new AudioBook("Ward", "2018", "John C. McCrae", "Rein"));
    lib.addMedia(new Movie("Dune", "2021", "Denis Villeneuve", "4K IMAX"));
    lib.addMedia(new VideoGame("Outer Wilds", "2019", "Annapurna", "Mobius Digital"));

    std::cout << lib << std::endl;

    for (std::string i : searchQuery) {
        lib.searchMedia(i);
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;

}