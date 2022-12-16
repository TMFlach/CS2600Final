//TicTacToe Game client
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int TicTacToeGame(int (*)(char *)); //takes a function pointer of whether human player or computer player moves.
int PlayerMove(char[]);
int ComputerMove(char[]);
bool GameOver(char[]); //checks games state to check for game over.
void PrintBoard(char*);
char * NewBoard(); //TicTacToe board is represented by 1D array of char.

int main() {
    int input = 0;
    int exit;
    srand(time(NULL));
    do
    {
        if(input == 1) {
            TicTacToeGame(ComputerMove);
        }
        else if(input == 2) {
            TicTacToeGame(PlayerMove);
        }
        printf("Enter your selection:\n");
        printf("1: 1 player game.\n");
        printf("2: 2 player game.\n");
        printf("q: quit\n");
        exit = scanf(" %d", &input);
        printf("You entered: %d\n", input);
    } while (exit > 0);
    printf("Last entered selection: %d\n", input);
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
    while (!GameOver(board)) {
        int playerMove = PlayerMove(board);
        if(playerMove < 0) {
            return 1;//player has chosen to quit.
        }
        board[playerMove] = 'O';
        if(GameOver(board)) {
            PrintBoard(board);
            return 0;
        }
        int nextMove = movement(board);
        if(nextMove < 0) {
            return 1; //player has chosen to quit.
        }
        board[nextMove] = 'X';
    }
    PrintBoard(board);
    return 0;
}

int PlayerMove(char game[]) {
    int selection = 0;
    do
    {
        PrintBoard(game);
        printf("Make your move\n");
        char line[10];
        scanf("%s", line);
        //printf("Read %s\n", line);
        selection = atoi(line);
        selection = selection - 1;
        if (selection == -1) { //if atoi failed to read a number, returns 0 which is now -1.
            return -1; //no number we assume the user wanted to quit.
        }else if(selection < 0 || selection >= 9) {
            continue;
        }
    } while (game[selection] == 'X' || game[selection] == 'O');
    return selection;
}

int ComputerMove(char game[])
{
    int move = 0;
    do
    {
        move = rand() % 9;
    } while (game[move] == 'X' || game[move] == 'O');
    
    return move;
}

bool GameOver(char board[]) {
    //check columns
    for(int i = 0; i < 3; i++) {
        if(board[i] == board[i+3] && board[i+3] == board[i+6]){
            return true;
        } //check rows 
        else if(board[0 + (3*i)] == board[1 + (3*i)] && board[1 + (3*i)] == board[2 + (3*i)]) {
            return true;
        }
    }
    //check diagonals
    if((board[0] == board[4] && board[4] == board[8]) ||
        board[6] == board[4] && board[4] == board[2]) {
        return true;
    }
    //check to see if the game is tied.
    for(int i = 0; i < 9; i++) {
        if(board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}