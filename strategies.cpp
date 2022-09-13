#include "strategies.h"
#define SIDE_SIZE 3

unsigned int manhattan(const Board& board){
    std::vector<unsigned int> squares = board.getSquares();

    unsigned int manhattanSum = 0;
    int X, Y, targetX, targetY; // abs accepts only signed types

    for (unsigned int i = 0; i < squares.size(); i++)
	{
		//if (squares[i] == 0)
		//	continue;

		X = i / SIDE_SIZE;
		targetX = squares[i] / SIDE_SIZE;

		Y = i % SIDE_SIZE;
		targetY = squares[i] % SIDE_SIZE;

        manhattanSum += abs(targetX - X) + abs(targetY - Y);
	}

    return manhattanSum;
}

unsigned int misplacements(const Board& board) {
    std::vector<unsigned int> squares = board.getSquares();
    unsigned int misplacedNum = 0;
    for (unsigned int i = 0; i < squares.size(); i++)
        if (i != squares[i] /*&& squares[i] != 0*/)
            misplacedNum++;

    return misplacedNum;
}

unsigned int euclidean(const Board& board) {
    std::vector<unsigned int> squares = board.getSquares();
    unsigned int euclideanSum = 0;
    int X, Y, targetX, targetY;

    for (unsigned int i = 0; i < squares.size(); i++){
		//if (squares[i] == 0)
		//	continue;

		X = i / SIDE_SIZE;
		targetX = squares[i] / SIDE_SIZE;

		Y = i % SIDE_SIZE;
		targetY = squares[i] % SIDE_SIZE;

		euclideanSum += (targetX - X) * (targetX - X) + (targetY - Y) * (targetY - Y);
    }

    return euclideanSum;
}
