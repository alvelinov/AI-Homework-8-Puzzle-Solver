#include "solver.h"

bool operator>(const Pair& left, const Pair& right){
    return left.second > right.second;
}

void Solver::generateAdjacencies() {
    adjacencies.insert({0, {1, 3}});
    adjacencies.insert({1, {0, 2, 4}});
    adjacencies.insert({2, {1, 5}});
    adjacencies.insert({3, {0, 4, 6}});
    adjacencies.insert({4, {1, 3, 5, 7}});
    adjacencies.insert({5, {2, 4, 8}});
    adjacencies.insert({6, {3, 7}});
    adjacencies.insert({7, {4, 6, 8}});
    adjacencies.insert({8, {5, 7}});
}

Solver::Solver(Node& _start, const Node& _target, Strategy _strategy, Heuristic _heuristic)
: start(_start), target(_target), strategy(_strategy), heuristic(_heuristic)
{
    generateAdjacencies();
}

unsigned int Solver::solveWith(unsigned int(*h)(const Board&)) {
    bool *visited = new bool[900000000];
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair> > frontier;

    frontier.push({start, evaluateNodeWith(start, h)});

    while (!frontier.empty()){
        Node parent = frontier.top().first;
        Board parentBoard = parent.getBoard();

        if (parentBoard == target.getBoard()){
            delete [] visited;
            return parent.getDepth();
        }

        frontier.pop();
        visited[parentBoard.toUnsigned()] = true;

        std::vector<unsigned int> adj = adjacencies.find(parentBoard.getZeroID())->second;
        for (std::vector<unsigned int>::iterator it = adj.begin(); it != adj.end(); ++it){
            Board childBoard = parentBoard;
            childBoard.swapZeroAnd(*it);

            if (visited[childBoard.toUnsigned()])
                continue;

            Node child(childBoard, parent.getDepth() + 1);
            frontier.push({child, evaluateNodeWith(child, h)});

        }
    }

    delete [] visited;
    return -1;
}

unsigned int Solver::evaluateNodeWith(const Node& node, unsigned int(*h)(const Board&)) {
    switch(strategy){
    case ASTAR:
        return h(node.getBoard()) + node.getDepth();
    case BESTFIRST:
        return h(node.getBoard());
    }
}

unsigned int Solver::solve() {
    switch (heuristic){
    case MANHATTAN:
        return solveWith(manhattan);
        break;
    case MISPLACEMENTS:
        return solveWith(misplacements);
        break;
    case EUCLIDEAN:
        return solveWith(euclidean);
    }
}
