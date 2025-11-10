#include "node.h"
#include "main.h"
#ifndef TREE
#define TREE


typedef struct vertex_s{
    board_t board;
    int depth;
    int score;
    node_t *children;
    struct vertex_s *parent;
} vertex_t;

vertex_t *makeTree(
    board_t startBoard,
    int targetDepth,
    board_t *(*nextBoard)(board_t board, int *size),
    int(*evaluate)(board_t board)
);

int freeTree(vertex_t *tree);

vertex_t chooseBestChild(vertex_t parent);

#endif