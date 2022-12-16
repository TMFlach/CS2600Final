//TicTacToe Game client
#include <stdio.h>
#include <stdbool.h>

int TicTacToeGame(void); //takes a function pointer of whether human player or computer player moves.
int PlayerMove(char[]);
int ComputerMove(char[]);
bool GameOver(char[]); //checks games state to check for game over.
void PrintBoard(char*);
char * NewBoard(); //TicTacToe board is represented by 1D array of char.

int main() {
    int input;
    int exit;
    do
    {
        printf("Enter your selection:\n");
        printf("1: 1 player game.\n");
        printf("2: 2 player game.\n");
        printf("q: quit\n");
        exit = scanf(" %d", &input);
        if(input == 1) {
            char* board = NewBoard();
            PrintBoard(board);
        }
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