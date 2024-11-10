#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define MIN_SIZE 3

char board[MAX_SIZE][MAX_SIZE];
int size;
int gameMode;

void initializeBoard(int size);
void displayBoard();
void playerMove(int playerRow, int playerCol);
void aiMove();
void checkDraw();
void updateScore();
void gameLoop();
int minimax(int depth, int isMaximizing);



int main() {

    int boardSize, gameMode, boardHeight, boardWidth;

    printf("Enter a game mode (1 = AI, 2 = 2 Player : ");
    scanf("%d", gameMode);

    printf("Enter a board size : ");
    scanf("%d", size);

    initializeBoard(size);

    while(1){
        player = (turn % 2 == 0) ? 1: 2;
    }
    return 0;
}

initializeBoard(){

    int width = size;
    int height = size;
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            board[i][j] = '*';
            printf("%d\n", board[i][j]);
        }
    } 

}

displayBoard(char board[][]){

    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d\n", board[i][j]);
        }
    } 
}

playerMove(int playerCol, int playerRow){

    if(player == 1){
        if(board[playerRow][playerCol] != '*')
            printf("That playspace has already been used. Please select an empty playspace indicated by '*'");

        else
            board[playerRow][playerCol] = 'X';
    }
    
    if(player == 2){
        if(board[playerRow][playerCol] != '*')
            printf("That playspace has already been used. Please select an empty playspace indicated by '*'");

        else
            board[playerRow][playerCol] = 'X';
    }
     //selection

}

aiMove(){
    //prediction algorithm
    //pre-cursive formula
    //assumption
    //play move
    //LIMIT to 3x3



}

checkDraw(){

    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if(board[i][j] = '*')
                return 0;
            else
                continue;
        }

        return 1;
    } 
    //if all matrix[i][j] do NOT contain blank,
    //check for full row span in.. 
    //diagonal (matrix[i - 1][j + 1] vise versa makes complete span of j or i without break) 
    //horizontal (consecutive "x" in all matrix[i][K]))
    //horizontal (consecutive "x" in all matrix[K][j]))
    }

updateScore(){
    //if player1 win, += player score
    //if player2 or AI win, += player2/ai score

}

gameLoop(){

    if (checkWin(PLAYER1 == 1)){
    printf("Player 1 Wins!");
    }

    else if(checkWin(PLAYER2 == 1)){
        if (ai == true)
            printf("AI Wins!");
        else if(ai == false)
            printf("Player 2 Wins");
    }

    else if(checkDraw == 1) 
        printf("It's a draw!");
    
}

int minimax(int depth, int isMaximizing) {
    // Check if there's a winner or if it's a draw
    if (checkWinner(PLAYER_1)) return -10 + depth;
    if (checkWinner(PLAYER_2)) return 10 - depth;
    if (isBoardFull()) return 0;

    if (isMaximizing) {
        int best = -1000;
        // Try all possible moves for the AI (Player O)
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_2;
                    best = (best > minimax(depth + 1, 0)) ? best : minimax(depth + 1, 0);
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;

    } else {
        int best = 1000;
        // Try all possible moves for the player (Player X)
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_1;
                    best = (best < minimax(depth + 1, 1)) ? best : minimax(depth + 1, 1);
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
}

