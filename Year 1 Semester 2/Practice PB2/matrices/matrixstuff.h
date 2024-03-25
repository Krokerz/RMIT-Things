#ifndef MATRIXSTUFF_H
#define MATRIXSTUFF_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

std::vector< std::vector<float> > create_random_matrix(int x, int y);
std::vector< std::vector<float> > add_matrices(const std::vector< std::vector<float> > left, const std::vector< std::vector<float> > right); 
std::vector< std::vector<float> > scalar_multiply(const std::vector< std::vector<float> > mat, float scalar);
void print_matrix(std::vector< std::vector<float> > mat);

#endif