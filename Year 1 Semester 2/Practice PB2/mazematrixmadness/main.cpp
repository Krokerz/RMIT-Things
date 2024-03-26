#include <iostream>

class Maze {
    private:
        char** env;
        int rows;
        int cols;
    public: 
        Maze();
        ~Maze();
        Maze(const Maze &);
        Maze& operator=(const Maze &);

        void getSize() const;
        void readMazeFromTerminal();
        void printMaze() const;
};

Maze::Maze() : rows(0), cols(0) {}

Maze::~Maze() {
    for (int i = 0; i < rows; i++) {
        delete[] *(env + i);
    }
    
    delete[] env;
}

Maze::Maze(const Maze &maze) : rows(maze.rows), cols(maze.cols) {
    env = new char*[maze.rows];

    for (int i = 0; i < maze.rows; i++) {
        char *temp = new char[maze.cols];

        for (int j = 0; j < maze.cols; j++) {
            *(temp + j) = *(*(maze.env + i) + j);
        }

        *(env + i) = temp;
    }
}

Maze& Maze::operator=(const Maze &other) {
    for (int i = 0; i < rows; i++) {
        delete[] *(env + i);
    }
    
    delete[] env;

    rows = other.rows;
    cols = other.cols;

    env = new char*[other.rows];

    for (int i = 0; i < other.rows; i++) {
        char *temp = new char[other.cols];

        for (int j = 0; j < other.cols; j++) {
            *(temp + j) = *(*(other.env + i) + j);
        }

        *(env + i) = temp;
    }

    return *this;
}

void Maze::getSize() const {
    std::cout << "Rows: " << rows << std::endl << "Columns: " << cols << std::endl;
}

void Maze::readMazeFromTerminal() {
    std::cout << "Enter Row Size: ";
    std::cin >> rows;

    std::cout << std::endl;

    std::cout << "Enter Column Size: ";
    std::cin >> cols;

    std::cout << std::endl << std::endl;

    env = new char*[rows];

    for (int i = 0; i < rows; i++) {
        char *temp = new char[cols];

        for (int j = 0; j < cols; j++) {
            std::cin >> *(temp + j);
        }

        *(env + i) = temp;
    }
}

void Maze::printMaze() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << *((*(env + i)) + j) << " ";
        }

        std::cout << std::endl;
    }
}

int main() {
    
    Maze maze = Maze();
    maze.readMazeFromTerminal();

    std::cout << std::endl;

    std::cout << "maze.printMaze():" << std::endl;
    maze.printMaze();

    std::cout << std::endl;

    Maze copyMaze = Maze(maze);

    std::cout << "copyMaze.printMaze():" << std::endl;
    copyMaze.printMaze();

    std::cout << std::endl;

    Maze copyMaze2 = maze;

    std::cout << "copyMaze2.printMaze():" << std::endl;
    copyMaze.printMaze();
    
    return 0;
}
