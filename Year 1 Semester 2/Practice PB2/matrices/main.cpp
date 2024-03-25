#include <iostream>
#include <vector>

#include "matrixstuff.h"

int main() {
    int x;
    int y;
    float z;

    std::cout << "Please enter two values for the matrix row and column respectively: ";

    std::cin >> x;
    std::cin >> y;

    std::cout << std::endl;

    std::vector< std::vector<float> > vect1 = create_random_matrix(x, y);

    std::cout << "Random Initial Matrix" << std::endl;
    print_matrix(vect1);

    std::cout << std::endl;

    std::cout << "Please do it again to try out Matrix Addition: ";

    std::cin >> x;
    std::cin >> y;

    std::cout << std::endl;

    std::vector< std::vector<float> > vect2 = create_random_matrix(x, y);

    std::cout << "Random Initial Matrix Number 2" << std::endl;
    print_matrix(vect2);

    std::cout << std::endl;

    std::vector< std::vector<float> > vect3 = add_matrices(vect1, vect2);

    std::cout << "Added Matrix" << std::endl;
    print_matrix(vect3);

    std::cout << std::endl;

    std::cout << "Please enter a float value for scalar multiplication with first matrix: ";

    std::cin >> z;

    std::cout << std::endl;

    std::vector< std::vector<float> > vect4 = scalar_multiply(vect1, z);

    std::cout << "Multiplied Matrix" << std::endl;
    print_matrix(vect4);

    return EXIT_SUCCESS;
}