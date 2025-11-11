#ifndef MINIMAX_H
#define MINIMAX_H
#include "main.h"                                       // definie le type board_t          /!\ ce type doit etre copiable par simple affectation(=) /!\ 


#define SUCCESS 0

#define ERROR_nextBoardPointerIsNULL -1
#define ERROR_evaluatePointerIsNULL -2
#define ERROR_targetDephtIsNegative -3
#define ERROR_noNextMove -4 
#define ERROR_destPointeurIsNULL -5

int choseBestMove(                                      // calcule le meilleur coups a joué dans la position donné par startBoard selon l'algorithme minimax
    board_t startBoard,                                 // plateau a partir du quel minimax ser a appliqué
    int targetDepth,                                    // profondeur maximale de l'exploration
    board_t *(*nextBoard)(board_t board, int *size),    // fonction qui revoie un pointeur vers un tableau (alloué dynamiquement) des differents coups possibles 
    int(*evaluate)(board_t board),                      // fonction d'evalutation d'un plateau (plus la valeur est grande meilleur est le plateau pour le joueur appelant chooseBestMove)
    board_t *dest                                       // pointeur vers la variable de retour
);                                                      // revoie SUCCESS en cas de success, une des valeurs negative en cas d'erreur


#endif