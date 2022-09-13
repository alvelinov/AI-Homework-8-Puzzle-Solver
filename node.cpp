#include "node.h"

Node::Node(const Board& _board, unsigned int _depth) {
    board = _board;
    depth = _depth;
}

Node::Node(const Node& other) {
    board = other.board;
    depth = other.depth;
}

Node& Node::operator=(const Node& other) {
    if (this != &other){
        board = other.board;
        depth = other.depth;
    }

    return *this;
}

bool Node::operator==(const Node& other) {
    return board == other.board;
}

unsigned int Node::getDepth() const {
    return depth;
}

const Board& Node::getBoard() const {
    return board;
}
