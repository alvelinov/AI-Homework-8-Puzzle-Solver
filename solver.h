#ifndef SOLVER_H
#define SOLVER_H

#include "strategies.h"
#include "node.h"
#include <queue>
#include <forward_list>
#include <map>
#include <set>

struct Pair {
    Node first;
    unsigned int second;

    friend bool operator>(const Pair&, const Pair&);
};

class Solver
{
    Node& start;
    const Node& target;
    Strategy strategy;
    Heuristic heuristic;
    std::map<unsigned int, std::vector<unsigned int>> adjacencies;

    unsigned int solveWith(unsigned int(*)(const Board&));
    unsigned int evaluateNodeWith(const Node&, unsigned int(*)(const Board&));
    void generateAdjacencies();

public:
	Solver(Node&, const Node&, Strategy, Heuristic);
	unsigned int solve();

};
#endif // SOLVER_H
