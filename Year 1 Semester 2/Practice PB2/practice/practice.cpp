#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::fixed;
using std::setprecision;

vector<int> rand_vect(int size, int min, int max, bool wantExclu);
float meanFromVect(vector<int>);

int main() {
    
    int bot;
    int top;
    int size;
    bool yenah;
    vector<int> vc;
    
    cout << "Input size: ";
    cin >> size;
    
    cout << endl << "Input minimum value: ";
    cin >> bot;
    
    cout << endl << "Input maximum value: ";
    cin >> top;
    
    cout << endl << "Do you want the limits to be exclusive (Y / N)? ";
    
    char temp;
    cin >> temp;
    
    yenah = (tolower(temp) == 'y') ? true : false;
    
    vc = rand_vect(size, bot, top, yenah);
    
    cout << endl;
    
    for (int i : vc) {
        cout << i << endl;
    }
    
    cout << endl << "The mean of these string of numbers is " << fixed << setprecision(3) << meanFromVect(vc) << endl;

    return 0;
}

vector<int> rand_vect(int size, int min, int max, bool wantExclu) {
    vector<int> vect;
    
    srand(time(0));
    
    if (wantExclu) {
        for (int i = 0; i < size; i++) {
        vect.push_back((rand() % (max - min - 1)) + min + 1);
        }
    }
    else {
        for (int i = 0; i < size; i++) {
        vect.push_back((rand() % (max - min) + 1) + min);
        } 
    }
    
    return vect;
}

float meanFromVect(vector<int> vect) {
    float val = 0.0;
    
    for (int i : vect) {
        val += i;
    }
    
    val /= vect.size();
    
    return val;
}