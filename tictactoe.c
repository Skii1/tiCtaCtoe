#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define MIN_SIZE 3

char boardMatrix[][];

int main() {

    int boardSize, gameMode, boardHeight, boardWidth;

    printf("Enter a game mode (1 = AI, 2 = 2 Player) : ");
    scanf("%d", gameMode);

    printf("Enter a game mode (1 = AI, 2 = 2 Player) : ");
    scanf(" %d,%d", boardWidth, boardHeight);



return 0;
}

initializeBoard(){

    char board[width][height];

    printf("%d", board[0][0]);

}

displayBoard(char boardMatrix){

    char boardMatrix[2][3] = { {O, X, X}, {0, 0, X} };

    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d\n", matrix[i][j]);
        }
    } 
}
playerMove(int playerIn[0][0]){

    board[i][j] = //selection

}

aiMove(){
    //prediction algorithm
    //pre-cursive formula
    //assumption
    //play move
    //LIMIT to 3x3

}

checkDraw(){
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

