//TicTacToe Game client
#include <stdio.h>
#include <stdbool.h>

int TicTacToeGame(void); //takes a function pointer of whether human player or computer player moves.
int PlayerMove(char[]);
int ComputerMove(char[]);
bool GameOver(char[]); //checks games state to check for game over.
void PrintBoard(char[]);
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
    } while (exit > 0);
    printf("Last enterd char: %c\n", input);
    return 0;
}