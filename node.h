#ifndef NODE_H
#define NODE_H

#include "board.h"

class Node
{
private:
    Board board;
    unsigned int depth;

public:
    Node(const Board&, unsigned int = 0);
    Node(const Node&);

    Node& operator=(const Node&);
    bool operator==(const Node&);

    unsigned int getDepth() const;
    const Board& getBoard() const;
};

#endif // NODE_H
