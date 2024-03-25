#include <iostream>

using std::cout;
using std::endl;

void foo(int* x, double* y, char& z);

int main (void) {
    int i = 10;
    double d = 2.5;
    char c = 'e';

    int* iPtr = &i;
    double* dPtr = &d;

    cout << "iPtr = " << iPtr << ", dPtr = " << dPtr << endl;
    cout << "*iPtr = " << *iPtr << ", *dPtr = " << *dPtr << endl;

    *iPtr = 5;
    *dPtr = 4.25;

    cout << "*iPtr = " << *iPtr << ", *dPtr = " << *dPtr << endl;
    cout << "i = " << i << ", d = " << d << ", c = " << c << endl;

    foo(&i, &d, c);
    cout << "i = " << i << ", d = " << d << ", c = " << c << endl;

    foo(iPtr, dPtr, c);
    cout << "i = " << i << ", d = " << d << ", c = " << c << endl;

    return EXIT_SUCCESS;

}

void foo(int* x, double* y, char& z) {
    *x += 1;
    *y += 2;
    ++z;
}