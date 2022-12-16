//TicTacToe Game client
#include <stdio.h>
#include <stdbool.h>

int TicTacToeGame(int (*)(char *)); //takes a function pointer of whether human player or computer player moves.
int PlayerMove(char[]);
int ComputerMove(char[]);
bool GameOver(char[]); //checks games state to check for game over.
void PrintBoard(char*);
char * NewBoard(); //TicTacToe board is represented by 1D array of char.

int main() {
    int input = 0;
    int exit;
    do
    {
        if(input == 2) {
            TicTacToeGame(PlayerMove);
            
        }
        printf("Enter your selection:\n");
        printf("1: 1 player game.\n");
        printf("2: 2 player game.\n");
        printf("q: quit\n");
        exit = scanf(" %d", &input);
        printf("You entered: %d\n", input);
    } while (exit > 0);
    printf("Last enterd selection: %d\n", input);
    return 0;
}

char * NewBoard() {
    static char b[10];
    for (int i = 0; i < 9; i++) {
        b[i] = i + '1';
    }
    b[9] = '\0'; //be safe with the string ending in null terminator.
    return b;
}

void PrintBoard(char * board) {
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            printf("| %c |", board[(row * 3) + col]);
        }
        printf("\n");
    }
}

int TicTacToeGame(int (*movement)(char*)) {
    char* board = NewBoard();
    //PrintBoard(board);
    int nextMove = movement(board);
    board[nextMove] = 'X';
    PrintBoard(board);
}

int PlayerMove(char * game) {
    int selection;
    do
    {
        PrintBoard(game);
        printf("Make your move\n");
        int valid = scanf(" %d", &selection);
        selection = selection - 1;
        if(valid <= 0 || selection < 0 || selection >= 9) {
            continue;
        }
    } while (game[selection] == 'X' || game[selection] == 'O');
    return selection;
}