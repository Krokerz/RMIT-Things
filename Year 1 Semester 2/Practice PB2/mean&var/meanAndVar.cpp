#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;

void MeanAndVar(int& N, int x[]);

int main() {
    int size;

    cout << endl;

    cin >> size;

    cout << endl;

    if (size < 1) {
        cout << "The size can't be less than 1 smh supid 🤦🤦" << endl << endl;

        return EXIT_FAILURE;
    }

    cout << "Insert " << size << " integer(s) for calculation" << endl << endl;

    int x[size];

    for (int i = 0; i < size; i++) {
        cin >> x[i];
    }

    cout << endl;

    MeanAndVar(size, x);

    return EXIT_SUCCESS;
}

void MeanAndVar(int& N, int x[]) {
    double mean = 0.0;
    double var = 0.0;

    for (int i = 0; i < N; i++) {
        mean += x[i];
    }

    mean /= N;

    cout << "The mean is: " << fixed << setprecision(3) << mean << endl;

    for (int i = 0; i < N; i++) {
        double temp = x[i] - mean;

        temp *= temp;

        var += temp;
    }

    var /= N;

    cout << "The variance is: " << fixed << setprecision(3) << var << endl;
}