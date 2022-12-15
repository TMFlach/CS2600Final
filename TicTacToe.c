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

    return 0;
}