#include "board.h"

void Board::updateZeroID() {
    for (unsigned int i = 0; i < squares.size(); i++)
        if (squares[i] == 0) {
            zeroID = i;
            break;
        }
}

bool Board::canBeSolved() const {
    unsigned int inversions = 0;
    for (unsigned int i = 0; i < squares.size() - 1; i++)
        for (unsigned int j = i + 1; j < squares.size(); j++)
            if (squares[i] > squares[j] && squares[i] != 0 && squares[j] != 0)
                inversions++;

    return !(inversions % 2);
}

Board::Board() {
        squares = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        zeroID = 0;
}

Board::Board(std::vector<unsigned int>& vect) {
    squares = vect;
    updateZeroID();
}

Board::Board(const Board& other) {
    squares = other.squares;
    zeroID = other.zeroID;
}

Board& Board::operator=(const Board& other) {
    if (this != &other) {
        squares = other.squares;
        zeroID = other.zeroID;
    }

    return *this;
}

bool Board::operator==(const Board& other) {
    return squares == other.squares;
}

void Board::shuffle() {
    srand(time(NULL));

    do {
        std::random_shuffle(squares.begin(), squares.end());
    } while(!canBeSolved());

    updateZeroID();
}

void Board::swapZeroAnd(unsigned int id) {
    squares[zeroID] = squares[id];
    squares[id] = 0;
    zeroID = id;
}

unsigned int Board::getZeroID() const {
    return zeroID;
}

unsigned int Board::toUnsigned() const {
    unsigned int number = 0;
    for (unsigned int i = 0; i < squares.size(); i++)
        number = number*10 + squares[i];

    return number;
}

std::vector<unsigned int> Board::getSquares() const {
    return squares;
}

std::ostream& operator<<(std::ostream& os, const Board& other) {
    for (unsigned int i = 0; i < other.squares.size(); i++){
        os << other.squares[i] << " ";
        if ((i % 3) == 2)
            os << "\n";
    }

    return os;
}
