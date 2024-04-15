#include <iostream>
#include <ctime>
#include <iomanip>

class Board {
    private:
        char **board;
        int size;

    public:
        Board();
        Board(int);
        ~Board();
        void Put(int, char);
        bool CheckEnded();
        char CheckWin();
        void PrintBoard();
        void Autoplay();
};

int main() {
    srand(time(0));
    int size;

    std::cout << '\n';

    std::cout << "Input size of the board:" << std::endl;
    std::cin >> size;

    std::cout << '\n';

    if (size < 4) {
        std::cout << "Size is too small" << std::endl;
        return EXIT_FAILURE;
    }

    Board b = Board(size);

    b.Autoplay();

    return EXIT_SUCCESS;
}

Board::Board() {
    size = 4;
    board = new char*[size];

    for (int i = 0; i < size; i++) {
        char *temp = new char[size];

        for (int j = 0; j < size; j++) {
            temp[j] = '-';
        }

        board[i] = temp;
    }
}

Board::Board(int size) {
    this->size = size;
    board = new char*[size];

    for (int i = 0; i < size; i++) {
        char *temp = new char[size];

        for (int j = 0; j < size; j++) {
            temp[j] = '-';
        }

        board[i] = temp;
    }
}

Board::~Board() {
    for (int i = 0; i < size; i++) {
        delete board[i];
    }

    delete board;
}

void Board::Put(int x, char want) {
    for (int i = 0; i < size; i++) {
        if (board[i][x] != '-') {
            continue;
        }
        else {
            board[i][x] = want;
            break;
        }
    }
}

bool Board::CheckEnded() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == '-') {
                return true;
            }
        }
    }

    return false;
}

// KSJBFGHJSHBFSLKUDNLUVBI.NAAAAAAAAAAAAAAAAHAHAHAHAHAHHa
char Board::CheckWin() {
    // Check Horizontal
    for (int i = 0; i < size - 3; i++) {
        for (int j = 0; j < size - 3; j++) {
            bool isWin = true;

            for (int k = 1; k < 4; k++) {
                if ((board[i][j] != board[i][j + k]) || (board[i][j] == '-')) {
                    isWin = false;
                    break;
                }
            }

            if (isWin) {
                return board[i][j];
            }
        }
    }

    // Check Vertical
    for (int i = 0; i < size - 3; i++) {
        for (int j = 0; j < size - 3; j++) {
            bool isWin = true;

            for (int k = 1; k < 4; k++) {
                if ((board[i][j] != board[i + k][j]) || (board[i][j] == '-')) {
                    isWin = false;
                    break;
                }
            }

            if (isWin) {
                return board[i][j];
            }
        }
    }

    // Check Diagonal From Left
    for (int i = 0; i < size - 3; i++) {
        for (int j = 0; j < size - 3; j++) {
            bool isWin = true;

            for (int k = 1; k < 4; k++) {
                if ((board[i][j] != board[i + k][j + k]) || (board[i][j] == '-')) {
                    isWin = false;
                    break;
                }
            }

            if (isWin) {
                return board[i][j];
            }
        }
    }

    // Check Diagonal From Right
    for (int i = 0; i < size - 3; i++) {
        for (int j = 0; j < size - 3; j++) {
            bool isWin = true;

            for (int k = 1; k < 4; k++) {
                if ((board[i][j + 3] != board[i + k][j + 3 - k]) || (board[i][j + 3] == '-')) {
                    isWin = false;
                    break;
                }
            }

            if (isWin) {
                return board[i][j + 3];
            }
        }
    }

    return '-';
}

void Board::PrintBoard() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << board[i][j] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void Board::Autoplay() {
    for (int i = 0; CheckEnded(); i++) {
            // // Test 1 (vert)
            // Put(0, 'R');
            // Put(0, 'R');
            // Put(0, 'R');
            // Put(0, 'R');

            // // Test 2 (hori)
            // Put(0, 'R');
            // Put(1, 'R');
            // Put(2, 'R');
            // Put(3, 'R');

            // // Test 3 (diag left)
            // Put(0, 'R');

            // Put(1, 'B');

            // Put(1, 'R');

            // Put(2, 'B');
            // Put(2, 'B');

            // Put(2, 'R');

            // Put(3, 'B');
            // Put(3, 'B');
            // Put(3, 'B');

            // Put(3, 'R');

            // // Test 4 (diag right)
            // Put(3, 'R');

            // Put(2, 'B');

            // Put(2, 'R');

            // Put(1, 'B');
            // Put(1, 'B');

            // Put(1, 'R');

            // Put(0, 'B');
            // Put(0, 'B');
            // Put(0, 'B');
            
            // Put(0, 'R');

        if (i % 2 == 0) {
            Put(rand() % size, 'R');
        }
        else {
            Put(rand() % size, 'B');
        }

        char win = CheckWin();

        if (win == 'R') {
            std::cout << "Red Wins!" << std::endl;
            PrintBoard();
            return;
        }
        else if (win == 'B') {
            std::cout << "Blue Wins!" << std::endl;
            PrintBoard();
            return;
        }
        else {
            std::cout << std::endl;
            PrintBoard();
        }
    }

    std::cout << "Nobody Wins... :(" << std::endl;
}