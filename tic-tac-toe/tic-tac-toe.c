#include <stdio.h>
#include "tic-tac-toe.h"

static int min(int a, int b){
    if (a < b) return a;
    return b;
}
int switchPlayer(char *player){
    if (player == NULL) return ERROR_playerPointerIsNULL
    return player==P1?P2:P1;
}

int convertPos(int x, int y){
    return(x + (LENLINE * y));
}

static int verify(board_t board, int pos){
    if (pos >= LEN) return ERROR_positionOutOfBounds;
    if (board[pos] != nobody) return ERROR_positionAlreadyFilled;
    return success;
}

int updateBoard(board_t board, int pos, char player){
    int result = verify(board,pos);
    if (result ==  success) board[pos] = player;
    return result;
}

void initBoard(board_t board){
    for (int i = 0; i<LEN; i++) board[i] = nobody;
}

char whoWins(board_t board){
    static int nbRounds = 0;
    int sum = 0;
    nbRounds++;
    if (nbRounds < (2 * min(LENLINE, LENROW) - 1) ) return nobody;         // si il n'y a pas eu assez de round pour avoir un vainqueur
    

    for (int y = 0; y<NBROW; y++){                      // verification des lignes
        for (int x = 0; x < NBLINE; x++){
            sum += board[convertPos(x, y)];
        }
        if (sum == LENLINE*P1) return P1;
        if (sum == LENLINE*P2) return P2;
        sum = 0;
    }
    for (int x = 0; x<NBLINE; x++){                     // verification des collones
        for (int y = 0; y < NBLINE; y++){
            sum += board[convertPos(x, y)];
        }
        if (sum == LENROW*P1) return P1;
        if (sum == LENROW*P2) return P2;
        sum = 0;
    }
    int min;
    int diff;
    if (NBLINE > NBROW){
        min = NBROW;
        diff = NBLINE - NBROW;
        for (int shift = 0; shift <= diff; shift++){    // verification des diagonales haut gauche -> bas droite
            for (int i = 0; i < min; i++){
                sum += board[convertPos(i + shift, i)];
            }
            if (sum == min*P1) return P1;
            if (sum == min*P2) return P2;
            sum = 0;
        }
        for (int shift = 0; shift <= diff; shift++){    // verification des diagonales haut droite -> bas gauche
            for (int i = 0; i < min; i++){
                sum += board[convertPos(min -1 - i + shift, i)];
            }
            if (sum == min*P1) return P1;
            if (sum == min*P2) return P2;
            sum = 0;
        }
    }
    else{
        min = NBLINE;
        diff = NBROW - NBLINE;
        for (int shift = 0; shift <= diff; shift++){    // verification des diagonales haut gauche -> bas droite
            for (int i = 0; i < min; i++){
                sum += board[convertPos(i, i + shift)];
            }
            if (sum == min*P1) return P1;
            if (sum == min*P2) return P2;
            sum = 0;
        }
        for (int shift = 0; shift <= diff; shift++){    // verification des diagonales haut droite -> bas gauche
            for (int i = 0; i < min; i++){
                sum += board[convertPos(min - 1 - i, i + shift)];
            }
            if (sum == min*P1) return P1;
            if (sum == min*P2) return P2;
            sum = 0;
        }
    }

    return nobody;
}

void showBoard(board_t board){
    printf("  ");
     for (int x = 0; x < LENLINE; x++){
        printf("%d ",x + 1);
    }
    printf("\n");

    for (int y=0; y < LENROW; y++){
        printf("%d ", y + 1);
        for (int x = 0; x < LENLINE; x++){
            printf("%c ",board[convertPos(x,y)]);
        }
        printf("\n");
    }

    
}

