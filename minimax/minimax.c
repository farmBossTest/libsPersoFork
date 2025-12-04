#include "minimax.h"
#include <stdlib.h>

static int choseBestMove_aux( // explore recursivement les coups jusqu'à la profondeur cible
    MINIMAXBOARDTYPE startBoard,
    int currentDepth,
    int targetDepth,
    MINIMAXBOARDTYPE *(*nextBoard)(MINIMAXBOARDTYPE board, int *size),
    int(*evaluate)(MINIMAXBOARDTYPE board)
){
    if (currentDepth == targetDepth) return evaluate(startBoard);

    int nbNextBoards;
    MINIMAXBOARDTYPE *nextBoards = nextBoard(startBoard, &nbNextBoards);
    if (nbNextBoards <= 0 || nextBoards == NULL) {free(nextBoards); return evaluate (startBoard);}

    int extremScore = choseBestMove_aux(nextBoards[0], currentDepth + 1, targetDepth, nextBoard, evaluate);
    int currentScore;
    for (int i = 1; i<nbNextBoards; i++){
        currentScore = choseBestMove_aux(nextBoards[i], currentDepth + 1, targetDepth, nextBoard, evaluate);
        // profondeur paire -> joueur -> maximisation
        if (currentDepth%2 == 0 && currentScore > extremScore){
             extremScore = currentScore;
        }
        // profondeur impaire -> aversaire -> minimisation
        if (currentDepth%2 == 1 && currentScore < extremScore){
            extremScore = currentScore;
        }
    }
    free(nextBoards);
    return extremScore;
}

int choseBestMove(
    MINIMAXBOARDTYPE startBoard,
    int targetDepth,
    MINIMAXBOARDTYPE *(*nextBoard)(MINIMAXBOARDTYPE board, int *size),
    int(*evaluate)(MINIMAXBOARDTYPE board),
    MINIMAXBOARDTYPE *dest
){
    if (nextBoard == NULL) return ERROR_nextBoardPointerIsNULL;
    if (evaluate == NULL) return ERROR_evaluatePointerIsNULL;
    if (targetDepth <= 0) return ERROR_targetDephtIsNegative;
    if (dest == NULL) return ERROR_destPointeurIsNULL;

    int nbNextBoards;
    MINIMAXBOARDTYPE * nextBoards = nextBoard(startBoard, &nbNextBoards);
    if (nbNextBoards <= 0 || nextBoards == NULL) {free(nextBoards); return ERROR_noNextMove;}
    
    int bestScore = choseBestMove_aux(nextBoards[0], 1, targetDepth, nextBoard, evaluate);
    int bestIndex = 0;
    int currentScore;
    for (int i = 1; i < nbNextBoards; i++){
        currentScore = choseBestMove_aux(nextBoards[i], 1, targetDepth, nextBoard, evaluate);
        if (currentScore > bestScore){
            bestScore = currentScore;
            bestIndex = i;
        }
    }
    *dest = nextBoards[bestIndex];
    free(nextBoards);
    return SUCCESS;
}
