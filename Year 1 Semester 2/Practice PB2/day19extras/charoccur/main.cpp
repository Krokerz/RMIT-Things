#include <iostream>

#define AMOUNT 3

int count_char(char* str, char c);
int* count_chars(char** strs, char c);

int main() {

    char str[] = "Hello programming bootcamp 2! How are you doing today?" ;
    char str2[] = " " ;

    std::cout << "count_char():" << std::endl;
    
    std::cout << "Actual output: " << count_char(str, 'H') << ", Expected output: 2" << std::endl ;
    std::cout << "Actual output: " << count_char(str, 'o') << ", Expected output: 8" << std::endl ;
    std::cout << "Actual output: " << count_char(str, '2') << ", Expected output: 1" << std::endl ;
    std::cout << "Actual output: " << count_char(str2, '1') << ", Expected output: 0" << std::endl ;

    char * strs[AMOUNT] ;
    strs[0] = "Apple" ;
    strs[1] = "Lemon" ;
    strs[2] = "Pear" ;

    std::cout << "\ncount_chars():" << std::endl;

    int* results = count_chars(strs, 'e') ;

    std::cout << "Actual output: " << results[0] << ", Expected output: 1" << std::endl ;
    std::cout << "Actual output: " << results[1] << ", Expected output: 1" << std::endl ;
    std::cout << "Actual output: " << results[2] << ", Expected output: 1" << std::endl ;

    results = count_chars(strs, 'p') ;

    std::cout << "Actual output: " << results[0] << ", Expected output: 2" << std::endl ;
    std::cout << "Actual output: " << results[1] << ", Expected output: 0" << std::endl ;
    std::cout << "Actual output: " << results[2] << ", Expected output: 0" << std::endl ;
}

int count_char(char* str, char c) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            count++;
        }
    }

    return count;
}

int* count_chars(char** strs, char c) {
    int *counts = new int[AMOUNT];

    for (int i = 0; i < AMOUNT; i++) {
        int count = 0;

        for (int j = 0; strs[i][j] != '\0'; j++) {
            if (strs[i][j] == c) {
                count++;
            }
        }

        counts[i] = count;
    }

    return counts;
}