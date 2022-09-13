#ifndef STRATEGIES_H
#define STRATEGIES_H

#include "board.h"

enum Strategy {
    ASTAR,
    BESTFIRST,
};

enum Heuristic {
    MANHATTAN,
    MISPLACEMENTS,
    EUCLIDEAN,
};

unsigned int manhattan(const Board&);
unsigned int misplacements(const Board&);
unsigned int euclidean(const Board&);

#endif // STRATEGIES_H
