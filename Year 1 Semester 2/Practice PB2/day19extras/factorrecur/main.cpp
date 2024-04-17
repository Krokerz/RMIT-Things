#include <iostream>

int factorial_recursive(int num);

int factorial_iterative(int num);

int main() {
    std::cout << "RECURSIVE:" << std::endl ;
    std::cout << "\tActual output: " << factorial_recursive(5) << " Expected output: 120" << std::endl ;
    std::cout << "\tActual output: " << factorial_recursive(10) << " Expected output: 3628800" << std::endl ;
    std::cout << "\tActual output: " << factorial_recursive(1) << " Expected output: 1" << std::endl ;
    std::cout << "\tActual output: " << factorial_recursive(0) << " Expected output: 1" << std::endl ;
    std::cout << "\tActual output: " << factorial_recursive(-1) << " Expected output: 1" << std::endl ;

    std::cout << "ITERATIVE:" << std::endl ;
    std::cout << "\tActual output: " << factorial_iterative(5) << " Expected output: 120" << std::endl ;
    std::cout << "\tActual output: " << factorial_iterative(10) << " Expected output: 3628800" << std::endl ;
    std::cout << "\tActual output: " << factorial_iterative(1) << " Expected output: 1" << std::endl ;
    std::cout << "\tActual output: " << factorial_iterative(0) << " Expected output: 1" << std::endl ;
    std::cout << "\tActual output: " << factorial_iterative(-1) << " Expected output: 1" << std::endl ;

}

int factorial_recursive(int num) {
    if (num <= 1) {
        return 1;
    }

    return num * factorial_recursive(num - 1);
}

int factorial_iterative(int num) {
    int sum = 1;

    for (int i = num; i >= 2; i--) {
        sum *= i;
    }
    return sum;
}