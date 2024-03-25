#include <iostream>

using std::cout; using std::endl;

int stringLength(char* string);
void copyString(char* src, char* dest);

int main(void) {
    std::cout << "Testing stringLength" << std::endl;
    char* nullStr = nullptr;
    char empty[] = "";
    char hello[] = "Hello World";
    std::cout << "Should be 0 but is: " << stringLength(nullStr) << std::endl;
    std::cout << "Should be 0 but is: " << stringLength(empty) << std::endl;
    std::cout << "Should be 11 but is: " << stringLength(hello) << std::endl;

    char from[100] = "this should be copied";
    char to[100] = "";
    cout << "Before: from: [" << from << "], to: [" << to << "]" << endl;
    copyString(from, to);
    cout << "After: from: [" << from << "], to: [" << to << "]" << endl;

    return EXIT_SUCCESS;
}

int stringLength(char* string) {
    int i = 0;

    if (string == nullptr) {
        return i;
    }
    else {
        while (*(string + i) != '\0') {
            i++;
        }
    }

    return i;
}

void copyString(char* src, char* dest) {
    int i = 0;

    if (src == nullptr) {
        return;
    }
    else {
        while (*(src + i) != '\0') {
            *(dest + i) = *(src + i);
            i++;
        }
    }
}