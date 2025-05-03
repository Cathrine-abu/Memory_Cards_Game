#ifndef MEMORY_GAME_H
#define MEMORY_GAME_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants
#define MAX_PLAYERS 10                 // Maximum number of players
#define MAX_BOARD_SIZE 30              // Maximum dimensions of the board (n x n)
#define MAX_OBJECTS 450                // Maximum number of objects (half of board cells)
#define MAX_OBJECT_NAME 7              // Maximum length of each object's name
#define MAX_PLAYER_NAME 20             // Maximum length of each player's name

/**
 * Splits a single string of player names (delimited by '#') into individual names.
 * @param strNamePlayers: Input string containing all names separated by '#'
 * @param players: Output array to store split names
 * @return Number of players parsed
 */
int splitPlayerName(char* strNamePlayers, char players[MAX_PLAYERS][MAX_PLAYER_NAME]);

/**
 * Initializes the hidden board by placing object names at specified positions.
 * @param hidenBoard: The board to be filled
 * @param n: Board dimension (n x n)
 * @param argv: Command-line arguments
 * @param indexFirstPos: Start index in argv for positions
 * @param firstObject: Start index in argv for object names
 */
void finalBoard(char hidenBoard[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME], int n, char *argv[],
                int indexFirstPos, int firstObject);

/**
 * Prints a specified number of spaces to the screen.
 * @param num: Number of spaces to print
 */
void spacePrint(int num);

/**
 * Prints a horizontal line of dashes for board formatting.
 * @param num: Number of dashes
 */
void linesPrint(int num);

/**
 * Prints the current visible game board.
 * @param n: Board size
 * @param board: The current state of the board
 */
void printBoard(int n, char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME]);

/**
 * Initializes the board with 'X' to indicate hidden cards and displays it.
 * @param n: Board size
 * @param boardGame: The game board to initialize
 */
void gameBoard(int n, char boardGame[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME]);

/**
 * Displays the welcome message, board coordinates, and object list.
 * @param argv: Command-line arguments
 */
void gameMenu(char *argv[]);

/**
 * Compares the current game board with the hidden board to check for completion.
 * @return 0 if equal, 1 if different
 */
int compareBoards(char boardGame[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME], int n,
                  char hidenBoard[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME]);

/**
 * Reveals two cards from the hidden board onto the game board.
 */
void copyCard(int row1, int col1, int row2, int col2, 
              char boardGame[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME],
              char hidenBoard[MAX_BOARD_SIZE][MAX_BOARD_SIZE][MAX_OBJECT_NAME]);

/**
 * Sums the score of all players.
 * @param playersPoints: Array of scores for each player
 * @param m: Number of players
 * @return Total score
 */
int countScorePlayers(int playersPoints[MAX_PLAYERS], int m);

/**
 * Validates initial input arguments, checks for unique card positions.
 * @return 1 if input is valid, 0 otherwise
 */
int invalidInput(int argc , char *argv[]);

/**
 * Main function that runs the memory card game.
 * Validates input, initializes game state, and controls game flow.
 */
int main(int argc , char *argv[]);

#endif // MEMORY_GAME_H
