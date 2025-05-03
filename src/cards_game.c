#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cards_game.h"
#define MAX_PLAYERS 10
#define MAX_BOARD_SIZE 30
#define MAX_OBJECTS 450 // (MAX_BOARD_SIZE*MAX_BOARD_SIZE) / 2
#define MAX_OBJECT_NAME 7
#define MAX_PLAYER_NAME 20

/************************
 * Cathrine Abu-Elazam
 * 325516193
 * ex_4
 ************************/

// function that split the name of the players
int splitPlayerName (char* strNamePlayers, char players[MAX_PLAYERS][MAX_PLAYER_NAME])// m=number of players
{
    int i = 0;
    char* token = strtok(strNamePlayers, "#");
    while (token != NULL) {
        strcpy(players[i], token);
        i++;
        token = strtok(NULL, "#");
    }
    return i;//return the number of the players
}

//function that save the final board
void finalBoard (char hidenBoard[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME], int n, char *argv[],
                 int indexFirstPos, int firstObject){
    for (int i = 0 ; i < (n*n) / 2; i++)
    {
        int indexPos1 = 2*i + indexFirstPos;
        int indexPos2 = 2*i + 1 + indexFirstPos;
        int position1 = atoi(argv[indexPos1]);
        int position2 = atoi(argv[indexPos2]);

        int indexRow1 = position1 / n;
        int indexColumn1 = position1 % n;
        strcpy(hidenBoard[indexRow1][indexColumn1], argv[firstObject]);

        int indexRow2 = position2 / n;
        int indexColumn2 = position2 % n;
        strcpy(hidenBoard[indexRow2][indexColumn2], argv[firstObject]);
        firstObject++;
    }
}

void spacePrint(int num )
{
    for (int i = 0; i < num ; ++i) {
        printf(" ");
    }
}
void linesPrint(int num )
{
    for (int i = 0; i < num ; ++i) {
        printf("-");
    }
}
//function that print the game board
void printBoard (int n, char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME])
{

    linesPrint(15*n + n + 1);
    for (int i = 0; i < n ; ++i) {
        printf("\n");
        for (int j = 0; j < n ; ++j) {
            printf("|");
            int lenStr = strlen(board[i][j]);
            int extraSpace = 15 - lenStr;
            if(lenStr % 2 != 0)// consist of odd number of letters
            {
                spacePrint(extraSpace/2);
                printf("%s",board[i][j]);
                spacePrint(extraSpace/2);
            }
            else// consist of even number of letters
            {
                spacePrint((extraSpace + 1)/2);
                printf("%s",board[i][j]);
                spacePrint((extraSpace - 1)/2);
            }
        }
        printf("|");
        printf("\n");
        linesPrint(15*n + n + 1);
    }
    printf("\n");
}

//function that initialize the board with x and print it at the beginning
void gameBoard(int n, char boardGame[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME])
{
    linesPrint(15*n + n + 1);
    for (int i = 0; i < n ; ++i) {
        printf("\n");
        for (int j = 0; j < n ; ++j) {
            printf("|");
            spacePrint(7);
            printf("X");
            strcpy(boardGame[i][j],"X");
            spacePrint(7);
        }
        printf("|");
        printf("\n");
        linesPrint(15*n + n + 1);
    }
    printf("\n");
}

void gameMenu (char *argv[])// print the menu/instructions of the game, and the board at the beginning
{
    int n = atoi(argv[1]); // n=board_dim

    printf("Welcome to the Memory Card Game!\n" "The game will be played on the following board:\n\n");
    printf(" |");
    for (int i = 0; i < n; ++i) {
        printf("  %d  |", i);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        linesPrint(5*n + n + 3);
        printf("\n");
        printf("%d |", i);
        for (int j = 0; j < n; ++j) {
            printf("(%d,%d)|", i, j);
        }
        printf("\n");
    }

    linesPrint(5*n + n + 3);
    printf("\n\nAnd the following objects:\n\n");
    //i=4 because the objects start from index 4 in argv and the h to number the objects
    for (int i = 4, h = 1; h <= (n * n) / 2; i++, h++) {
        printf("%d. %s\n", h, argv[i]);
    }
    printf("\nLet the game begin!\n");
}

//function that compare object between the game board and the hiden board
int compareBoards(char boardGame[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME], int n,
                  char hidenBoard[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Compare corresponding elements of the arrays
            if (boardGame[i][j] != hidenBoard[i][j]) {
                return 1; // objects are not equal
            }
        }
    }
    return 0; // objects are equal
}

//function that copy the objects from hiden board to the game board
void copyCard(int row1, int col1, int row2, int col2, char boardGame[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME],
              char hidenBoard[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME])
{
    strcpy(boardGame[row1][col1], hidenBoard[row1][col1]);
    strcpy(boardGame[row2][col2], hidenBoard[row2][col2]);
}

//function that count the score of all players at the end
int countScorePlayers ( int playersPoints[MAX_PLAYERS], int m)
{ int countScore = 0;
    for (int i = 0; i < m ; ++i) {
        countScore = countScore + playersPoints[i];
    }
    return countScore;
}

// function that check the validity of the input at the beginning
int invalidInput(int argc , char  *argv[])
{
    int n = atoi(argv[1]);// board_dim
    int numCards = (n*n)/2;
    int startPos = 4 + numCards;
    int numPositions = argc - 4 - numCards;
    if(numPositions != 2*numCards)
        return 0;
    int startPositions = startPos;
    for (int i = startPos; i < numPositions + startPositions ; i++)// check that there are not two same positions
    {
        for (int j = i + 1; j < numPositions + startPositions ; j++) {
            if(strcmp(argv[i],argv[j] ) == 0)
                return 0;
        }

    }
    return  1;//valid input
}


int main(int argc , char  *argv[]) {

    if (argc == 1)// because the first one is C:\Users\cat01\Desktop\ex_4.exe
    {
        printf("INVALID INPUT\n");
        return 0;
    }
    int m = atoi(argv[2]);// number of players
    int n = atoi(argv[1]);// board_dim
    if(argc != ((n*n)/2) + n*n + 4 )
    {
        printf("INVALID INPUT\n");
        return 0;
    }
    char *strNamePlayers = argv[3];
    char players[MAX_PLAYERS][MAX_PLAYER_NAME];
    int numPl = splitPlayerName(strNamePlayers, players);

    if( m != numPl )
    {
        printf("INVALID INPUT\n");
        return 0;
    }

    if(invalidInput(argc, argv))// if valid input
    {
        gameMenu(argv);
        int playerPoint[MAX_PLAYERS] = {0};
        char objects[MAX_OBJECTS][MAX_OBJECT_NAME];

        //copy the names of objects from argv to objects
        for (int i = 4, j = 0; i < ((n * n) / 2) + 4; i++, j++) // +4 because we start from i=4
        {
            strcpy(objects[j], argv[i]);
        }

        int firstPos = ((n * n) / 2) + 4;
        int firstObject = 4;
        char hidenBoard[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME];
        finalBoard(hidenBoard, n, argv, firstPos, firstObject);

        printf("\nCurrent board state:\n");
        char boardGame[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME];
        gameBoard(n, boardGame);// call the function gameBoar
        printf("\n");

        //a sign to know that the player do am invalid move, and we do not want to print the name of the player turn again
        int tryAgain = 0;

        int score = 0;// score of player
        int countScorePl =0;
        while(countScorePl != (n*n)/2)// if we did not yet finish and got all the points continue
        {
            int row1, row2, col1, col2;
            if(tryAgain == 0)
                printf("It is %s's turn.\n", players[score]);
            tryAgain = 0;
            printf("Enter the coordinates of the first card (row col): ");
            scanf("%d ", &row1);
            scanf("%d", &col1);

            if(row1 >= 0 && row1 < n && col1 >= 0 && col1 < n )
            {
                printf("Enter the coordinates of the second card (row col): ");
                scanf("%d ", &row2);
                scanf("%d", &col2);
                if((row1 != row2 || col1 != col2) && row2 >= 0 && row2 < n && col2 >= 0 && col2 < n &&
                   strcmp(hidenBoard[row1][col1],boardGame[row1][col1]))// check that we do not open the card
                {
                    if(strcmp(hidenBoard[row1][col1],hidenBoard[row2][col2]) == 0) {
                        playerPoint[score] = playerPoint[score] + 1;
                        // score++;
                        printf("Match!\n\n");
                        printf("The scores are:\n");

                        for (int j = 0, k = 1; j < m; ++j, ++k) { // m=number of players
                            printf("%s: %d", players[j], playerPoint[j]);
                            if (k < m)
                                printf(", ");
                            copyCard(row1, col1, row2, col2, boardGame, hidenBoard);
                            countScorePl = countScorePlayers(playerPoint,m);
                        }
                    }
                    else// not match
                    {
                        printf("No match. Try again.\n\n");
                        score++;
                        printf("The scores are:\n");
                        for (int j = 0, k = 1; j < m; j++, k++) { // m=number of players
                            printf("%s: %d", players[j], playerPoint[j]);
                            if (k < m)
                                printf(", ");
                        }
                    }

                    if(countScorePl != (n*n)/2)
                    {
                        printf("\nCurrent board state:\n");
                        printBoard(n, boardGame);
                        printf("\n");
                    }

                }
                else
                {
                    printf("Invalid move. Try again.\n");
                    tryAgain++;
                }
            }
            else
            {
                printf("Invalid move. Try again.\n");
                tryAgain++;
            }

        }
        int maybeMax = 0;// if we have two equal scores we have to save them and to check at the end if they are the max score
        int maxScore = playerPoint[0];
        int maxIndex = 0;
        for (int i = 1; i < m; ++i) // the player with the highest score
        {
            if(playerPoint[i] > maxScore)
            {
                maxScore = playerPoint[i];
                maxIndex=i;
            }
            else if(playerPoint[i] == maxScore)
                maybeMax = playerPoint[i];
            else
                maxScore = maxScore;

        }
        if(maybeMax == maxScore)// there are equal so tie
            printf("\nIt's a tie!");
        else
        {
            printf("\nCongratulations %s! You won!", players[maxIndex]);
        }
    }
    else// invalid input
        printf("INVALID INPUT\n");

    return 0;
}