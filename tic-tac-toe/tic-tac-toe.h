#ifndef TICTACTOE
#define TICTACTOE

#define LENROW 3
#define LENLINE 3
#define NBLINE LENROW
#define NBROW LENLINE
#define LEN 9
#define nobody '_'
#define P1 'X'
#define P2 'O'

#define success 1

#define ERROR_positionAlreadyFilled -1
#define ERROR_positionOutOfBounds -2



typedef char board_t[LENLINE*LENROW];

int updateBoard(board_t board, int pos, char player);

void showBoard(board_t board);

void initBoard(board_t board);

char whoWins(board_t board);      // returns constant "P1" if player 1 has won, constant "P2" if player 2 did and constant "nobody" if none has won

int convertPos(int x, int y);   // returns a position in the board array based on a position in x,y

#endif