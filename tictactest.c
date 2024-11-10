#include <stdio.h>
#include <stdlib.h>

#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY ' '

char board[3][3];

// Function to initialize the board to be empty
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = EMPTY;
        }
    }
}

// Function to print the board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check if the board is full
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if there's a winner
int checkWinner(char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

// Minimax algorithm to evaluate the best move
int minimax(int depth, int isMaximizing) {
    // Check if there's a winner or if it's a draw
    if (checkWinner(PLAYER_X)) return -10 + depth;
    if (checkWinner(PLAYER_O)) return 10 - depth;
    if (isBoardFull()) return 0;

    if (isMaximizing) {
        int best = -1000;
        // Try all possible moves for the AI (Player O)
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O;
                    best = (best > minimax(depth + 1, 0)) ? best : minimax(depth + 1, 0);
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        // Try all possible moves for the player (Player X)
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_X;
                    best = (best < minimax(depth + 1, 1)) ? best : minimax(depth + 1, 1);
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
}

// Function to find the best move for the AI
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

// Function to get the player's move
void playerMove() {
    int row, col;
    while (1) {
        printf("Enter your move (row and column [0-2]): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY) {
            board[row][col] = PLAYER_X;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

// Function to play the game
void playGame() {
    int turn = 0; // 0 for Player X, 1 for AI (Player O)
    while (1) {
        printBoard();

        if (turn % 2 == 0) {
            // Player X's turn
            playerMove();
        } else {
            // AI (Player O)'s turn
            printf("AI is making its move...\n");
            bestMove();
        }

        if (checkWinner(PLAYER_X)) {
            printBoard();
            printf("Player X wins!\n");
            break;
        } else if (checkWinner(PLAYER_O)) {
            printBoard();
            printf("AI (Player O) wins!\n");
            break;
        } else if (isBoardFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        turn++;
    }
}

// Main function to start the game
int main() {
    printf("Welcome to Tic-Tac-Toe! You are Player X, AI is Player O.\n");
    initializeBoard();
    playGame();
    return 0;
}
