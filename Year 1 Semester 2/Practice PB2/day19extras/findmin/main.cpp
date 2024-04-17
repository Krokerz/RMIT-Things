#include <iostream>

int find_minimum(int* arr, int arr_size, int & index);

int main() {
    int arr[] = {10,3,4,1,2,6,5} ;
    int index = 0 ;
    std::cout << "Actual output: " << find_minimum(arr, 7, index) << ", Expected output: 1" << std::endl ;
    std::cout << "Actual index: " << index << ", Expected index: 3" << std::endl ;

    std::cout << std::endl;

    int arr2[] = {9,234,654,754,765,423,65,3456,35876,8,7645,2,34,1432,5,234,52,456,35647,586,87,546,8764,356,7,45,26} ;
    std::cout << "Actual output: " << find_minimum(arr2, 27, index) << ", Expected output: 2" << std::endl ;
    std::cout << "Actual index: " << index << ", Expected index: 11" << std::endl ;

}

int find_minimum(int* arr, int arr_size, int & index) {
    int smallest = arr[0];
    index = 0;

    for (int i = 1; i < arr_size; i++) {
        if (smallest > arr[i]) {
            smallest = arr[i];
            index = i;
        }
    }

    return smallest;
}