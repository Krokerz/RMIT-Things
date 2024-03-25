#include "matrixstuff.h"

std::vector< std::vector<float> > create_random_matrix(int x, int y) {
    std::vector<float> temp(y, 0);
    std::vector< std::vector<float> > vect(x, temp);
    srand(time(0));

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            vect.at(i).at(j) = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        }
    }

    return vect;
}

std::vector< std::vector<float> > add_matrices(const std::vector< std::vector<float> > left, const std::vector< std::vector<float> > right) {
    std::vector<float> temp(left.at(0).size(), 0);
    std::vector< std::vector<float> > out(left.size(), temp);

    for (unsigned int i = 0; i < left.size(); i++) {
        for (unsigned int j = 0; j < left.at(0).size(); j++) {
            out.at(i).at(j) = left.at(i).at(j) + right.at(i).at(j);
        }
    }

    return out;
}

std::vector< std::vector<float> > scalar_multiply(const std::vector< std::vector<float> > mat, float scalar) {
    std::vector<float> temp(mat.at(0).size(), 0);
    std::vector< std::vector<float> > out(mat.size(), temp);

    for (unsigned int i = 0; i < mat.size(); i++) {
        for (unsigned int j = 0; j < mat.at(0).size(); j++) {
            out.at(i).at(j) = mat.at(i).at(j) * scalar;
        }
    }

    return out;
}

void print_matrix(std::vector< std::vector<float> > mat) {
    for(auto row : mat) {
        for (auto col : row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
}