#include <iostream>

int* fibonacci(int start1, int start2, int length);

void print_fib(int * sequence, int length) {
    std::cout << "{" ;
    for(int i = 0 ; i < length ; i++ ) {
        if(i != length-1) {std::cout << sequence[i] << ",";}
        else {std::cout << sequence[i] ;}
    }
    std::cout << "}" << std::endl;
}

int main() {

    std::cout << "Actual output: " << std::endl ;
    int* fib1 = fibonacci(0, 1, 10) ;
    print_fib(fib1, 10) ;

    std::cout << "Expected output: " << std::endl ;
    std::cout << "{0,1,1,2,3,5,8,13,21,34}" << std::endl ;

    std::cout << std::endl ;

    std::cout << "Actual output: " << std::endl ;
    int* fib2 = fibonacci(4, 6, 10) ;
    print_fib(fib2, 10) ;

    std::cout << "Expected output: " << std::endl ;
    std::cout << "{4,6,10,16,26,42,68,110,178,288}" << std::endl ;
}

int* fibonacci(int start1, int start2, int length) {
    int *out = new int[length];

    out[0] = start1;
    out[1] = start2;

    for (int i = 2; i < length; i++) {
        out[i] = out[i - 1] + out[i - 2];
    }

    return out;
}