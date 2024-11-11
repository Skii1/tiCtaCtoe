#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define MIN_SIZE 3

char board[MIN_SIZE][MIN_SIZE];
int size;
int gameMode;
int quit;
int turn;

void initializeBoard(int size);
void displayBoard();
void playerMove(int playerRow, int playerCol);
void aiMove();
void checkDraw();
void updateScore();
void gameLoop();
int minimax(int depth, int isMaximizing);
void playGame();

int main() {

    initializeBoard();

    while(quit != 1){
        playGame();         
    }
    return 0;
}

initializeBoard(){

    printf("Enter a game mode (1 = AI, 2 = 2 Player : ");
    scanf("%d", gameMode);

    printf("Enter a board size : ");
    scanf("%d", size);

    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            board[i][j] = '*';
            printf("%d\n", board[i][j]);
        }
    } 

}

displayBoard(char board[][]){

    int i, j;

    printf("|---|---|---|\n")

    for (i = 0; i < size; i++) {
        printf("|");
        for (j = 0; j < size; j++) {
            printf(" %d, ", board[i][j]);
        }
        printf("|");
    } 
    printf("|___|___|___|\n");
}

playerMove(int player){

    int row, col;

    printf("Player %d's turn : \n");
    printf("Enter a playspace in the form of (row, col) : ")
    scanf(" %d,%d", row, col);
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
    if(turn % 2 == 0)
        playerMove(1);
        
    else if(ai == 0)
        playerMove(2);

    else if(ai == 1)
        aiMove();

    
        
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

    turn++;
    
}

//MINIMAX optimization algorithm for the best possible move
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

//Function to calculate the best move for the AI 
void bestMove() {
    int bestVal = -1000;
    int moveRow = -1, moveCol = -1;

    // Try all possible moves for AI (Player O)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_O;
                int moveVal = minimax(0, 0);
                board[i][j] = EMPTY;
                if (moveVal > bestVal) {
                    moveRow = i;
                    moveCol = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    board[moveRow][moveCol] = PLAYER_O;
}

