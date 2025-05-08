#include <stdio.h>
#include <stdlib.h>
//check the upgraded version on git, user Name is TchambaMSK

#define MAX_SIZE 9

char board[MAX_SIZE][MAX_SIZE];
int boardSize;
int moveHistory[MAX_SIZE * MAX_SIZE][2];
int moveCount = 0;

void initializeBoard(int size);
void printBoard();
int isValidMove(int row, int col);
int isBoardFull();
int checkWin();
void recordMove(int row, int col);
void undoMove();
int minimax(int depth, int isMaximizing);
int findBestMove();

int main() {
    int row, col, gameStatus = 0;
    char currentPlayer;

    printf("Enter board size (3-9): ");
    scanf("%d", &boardSize);
    if (boardSize < 3 || boardSize > 9) {
        printf("Invalid board size. Exiting...\n");
        return 1;
    }

    initializeBoard(boardSize);

    while (gameStatus == 0) {
        printBoard();
        currentPlayer = (moveCount % 2 == 0) ? 'X' : 'O';

        if (currentPlayer == 'X') {
            printf("Player X, enter row and column (0-%d): ", boardSize - 1);
            scanf("%d %d", &row, &col);
            if (isValidMove(row, col)) {
                board[row][col] = currentPlayer;
                recordMove(row, col);
                moveCount++;
            } else {
                printf("Invalid move, try again.\n");
                continue;
            }
        } else {
            printf("Player O (AI) is making a move...\n");
            int bestMove = findBestMove();
            row = moveHistory[bestMove][0];
            col = moveHistory[bestMove][1];
            board[row][col] = currentPlayer;
            recordMove(row, col);
            moveCount++;
        }

        gameStatus = checkWin();
        if (gameStatus == 0 && isBoardFull()) {
            gameStatus = 2; // Draw
        }
    }

    printBoard();
    if (gameStatus == 1) {
        printf("Player %c wins!\n", currentPlayer);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

void initializeBoard(int size) {
    boardSize = size;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            printf(" %c ", board[i][j]);
            if (j < boardSize - 1) printf("|");
        }
        printf("\n");
        if (i < boardSize - 1) {
            for (int j = 0; j < boardSize - 1; j++) {
                printf("----");
            }
            printf("\n");
        }
    }
    printf("\n");
}

int isValidMove(int row, int col) {
    return (row >= 0 && row < boardSize && col >= 0 && col < boardSize && board[row][col] == ' ');
}

int isBoardFull() {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int checkWin() {
    // Check rows and columns
    for (int i = 0; i < boardSize; i++) {
        int rowWin = 1, colWin = 1;
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] != board[i][0] || board[i][j] == ' ') rowWin = 0;
            if (board[j][i] != board[0][i] || board[j][i] == ' ') colWin = 0;
        }
        if (rowWin || colWin) return 1;
    }

    // Check diagonals
    int diag1Win = 1, diag2Win = 1;
    for (int i = 0; i < boardSize; i++) {
        if (board[i][i] != board[0][0] || board[i][i] == ' ') diag1Win = 0;
        if (board[i][boardSize - i - 1] != board[0][boardSize - 1] || board[i][boardSize - i - 1] == ' ') diag2Win = 0;
    }
    if (diag1Win || diag2Win) return 1;

    return 0;
}

void recordMove(int row, int col) {
    moveHistory[moveCount][0] = row;
    moveHistory[moveCount][1] = col;
}

void undoMove() {
    if (moveCount > 0) {
        moveCount--;
        int row = moveHistory[moveCount][0];
        int col = moveHistory[moveCount][1];
        board[row][col] = ' ';
    }
}

int minimax(int depth, int isMaximizing) {
    int score = checkWin();
    if (score == 1) return isMaximizing ? -10 : 10;
    if (isBoardFull()) return 0;

    if (isMaximizing) {
        int best = -1000;
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int val = minimax(depth + 1, 0);
                    best = (val > best) ? val : best;
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int val = minimax(depth + 1, 1);
                    best = (val < best) ? val : best;
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

int findBestMove() {
    int bestVal = -1000;
    int
::contentReference[oaicite:0]{index=0}

//#copyrights stevekarelltchamba@gmail.com
//##########       #####      ###         #######       ##      ##
//##########       #####     ####       ##              ##    ##
//    ##           ## ##    ## ##     ##                ##  ##
//    ##           ##  ##  ##  ##       ##              ####
//    ##           ##   ####   ##         ####          ####
//    ##           ##   ####   ##             ##        ##  ##
//    ##           ##          ##               ##      ##    ##
//    ##           ##          ##         ######        ##      ##

//Note: Type of variable naming format I use here is the camel case naming format 'cause I work most of the time with javaScript






















//Code by Tchamba Mbasseune Steve Karell  
//Documentation by Tchamba Mbasseune Steve Karell
//git TchambaMSK
