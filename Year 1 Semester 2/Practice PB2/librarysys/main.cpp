#include <iostream>

#include "Library.h"

int main() {
    Library lib = Library();

    lib.AddBook("a", "a");
    lib.AddBook("b", "b");
    lib.AddBook("c", "c");
    lib.AddBook("d", "d");
    lib.AddBook("e", "e");
    lib.AddBook("f", "f");
    lib.AddBook("Dunno");
    
    lib.SearchBook("a");
    lib.SearchBook("c");
    lib.SearchBook("f");
    lib.SearchBook("d");

    return EXIT_SUCCESS;
}