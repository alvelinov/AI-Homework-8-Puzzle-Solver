#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

class Board
{
private:
    unsigned int zeroID;
    std::vector<unsigned int> squares;


    void updateZeroID();
    bool canBeSolved() const;

public:
    Board();
    Board(std::vector<unsigned int>&);
    Board(const Board&);
    Board& operator=(const Board&);
    bool operator==(const Board&);

    void shuffle();
    void swapZeroAnd(unsigned int);
    unsigned int getZeroID() const;
    unsigned int toUnsigned() const;
    std::vector<unsigned int> getSquares() const;

    friend std::ostream& operator<<(std::ostream&, const Board&);
};

#endif // BOARD_H
