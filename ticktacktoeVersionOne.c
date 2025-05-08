#include <stdio.h>
//check the upgraded version on git, user Name is TchambaMSK 

// Defining my board size 
char ticTacBoard[3][3];

// Defining all my functions except main one 'cause no need
void initializeBoard();//function which generates a new board, in this case a 3x3 matrix

void printTheBoard();//the function which prints the board after each update

int isTheMoveOk(int row, int col);//function which verifies if the index choosen is within the range

int checkIfWon();//function that checks a win either for rows and columns, and returns 1 if win else 0

int isBoardFull();//checks if board is full by looping through it to verify if there is again an empty space




//main program
int main() {
    int row, //for entering rows index
        col, //for entering columns index
        turnToPlay = 0, //verify what character to play now
        gameStatus = 0; //verify if game is ended either by win or draw(lack of board space)
    char playerNow; //indicates who as character is playing now

    printf("This is the first version of my tic-Tac-Toe game\n\tHere is the board...\n\n");

    initializeBoard();

    while (gameStatus == 0) {
        printTheBoard();
        playerNow = (turnToPlay % 2 == 0) ? 'X' : 'O';
        printf("Player %c, enter row and column (from 0 to 2(index  )): ", playerNow);
        scanf("%d %d", &row, &col);

        if (isTheMoveOk(row, col)) {
            ticTacBoard[row][col] = playerNow;
            turnToPlay++;

            gameStatus = checkIfWon();
            if (gameStatus == 0 && isBoardFull()) {
                gameStatus = 2; // to indicate a Draw
            }
        } else {
            printf("Invalid move, try again.\n");
        }
    }

    printTheBoard();

    if (gameStatus == 1) {
        printf("Player %c wins!\n\n\ncopyrights Tchamba Mbasseune Steve Karell", (turnToPlay % 2 == 0) ? 'O' : 'X');
    } else {
        printf("It's a draw!\n\n\ncopyrights Tchamba Mbasseune Steve Karell");
    }

    return 0;
}
//main function stops here

//function for new board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ticTacBoard[i][j] = ' ';
        }
    }
}
//function for new board ends

//the function to print the board with each of its updates
void printTheBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", ticTacBoard[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}
//function to print board ends

//function which verifies if index is valid
int isTheMoveOk(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && ticTacBoard[row][col] == ' ');
}
//function ends

//function which checks for a win
int checkIfWon() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (ticTacBoard[i][0] == ticTacBoard[i][1] && ticTacBoard[i][1] == ticTacBoard[i][2] && ticTacBoard[i][0] != ' ') {
            return 1;
        }
        if (ticTacBoard[0][i] == ticTacBoard[1][i] && ticTacBoard[1][i] == ticTacBoard[2][i] && ticTacBoard[0][i] != ' ') {
            return 1;
        }
    }

    // Check diagonals
    if (ticTacBoard[0][0] == ticTacBoard[1][1] && ticTacBoard[1][1] == ticTacBoard[2][2] && ticTacBoard[0][0] != ' ') {
        return 1;
    }
    if (ticTacBoard[0][2] == ticTacBoard[1][1] && ticTacBoard[1][1] == ticTacBoard[2][0] && ticTacBoard[0][2] != ' ') {
        return 1;
    }

    return 0;
}

int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ticTacBoard[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}
//end function 

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
