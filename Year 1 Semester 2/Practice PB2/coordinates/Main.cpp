#include <iostream>

class Coordinate {
    private:
        int x, y, z;

    public:
        Coordinate();
        Coordinate(int, int, int);
        Coordinate(const Coordinate &);
        Coordinate operator+(Coordinate&);
        Coordinate operator-(Coordinate&);

        friend std::ostream& operator<<(std::ostream&, const Coordinate&);
        friend bool operator==(const Coordinate&, const Coordinate&);


};

Coordinate::Coordinate() : x(0), y(0), z(0) {}
Coordinate::Coordinate(int x, int y, int z) : x(x), y(y), z(z) {}

// NOTE: Why is this needed? And what is it?
Coordinate::Coordinate(const Coordinate &other) : x(other.x), y(other.y), z(other.z) {}

std::ostream& operator<<(std::ostream& stream, const Coordinate& coord) {
    stream << "(" << coord.x << ", " << coord.y << ", " << coord.z << ")";

    return stream;
}

Coordinate Coordinate::operator+(Coordinate& other) {
    Coordinate out;

    out.x = x + other.x;
    out.y = y + other.y;
    out.z = z + other.z;
    
    return out;
}

Coordinate Coordinate::operator-(Coordinate& other) {
    Coordinate out;

    out.x = x - other.x;
    out.y = y - other.y;
    out.z = z - other.z;
    
    return out;
}

bool operator==(const Coordinate& other1, const Coordinate& other2) {
    return (other1.x == other2.x) && (other1.y == other2.y) && (other1.z == other2.z);
}

int main() {
    Coordinate c1(3, 2, 1);
    Coordinate c2(1, 2, 3);

    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c1 + c2 << std::endl;
    std::cout << c1 + c2 - c1 - c2 << std::endl;

    std::cout << (c1 == c2) << std::endl;
    std::cout << (c1 + c2 == c2 + c1) << std::endl;

    return EXIT_SUCCESS;

}