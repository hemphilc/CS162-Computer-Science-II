/**
  * @brief Assignment 1
  * @author Corey Hemphill
  */

#ifndef TICTACTOE
#define TICTACTOE

/**
 * @brief The TicTacToe class TicTacToe is a functional two player board game
 */
class TicTacToe {
private:
    char currentPlayer = 'X';
    char board[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};

public:
//Constructor//
    /**
     * @brief TicTacToe Default Constructor. Sets empty board squares and sets currentPlayer to "X"
     */
    TicTacToe();

//Functions//
    /**
     * @brief print Prints current state of game board to console
     */
    void print();

    /**
     * @brief getCurrentPlayer Gets current player's character
     * @return Returns whose turn it is ("X" or "O")
     */
    char getCurrentPlayer();

    /**
     * @brief isDone Checks for a winner, and checks for open board spaces
     * @return Returns true if there is a winner or if the board is full, false if otherwise
     */
    bool isDone();

    /**
     * @brief checkRowWin Checks to see if either player has won via row
     * @return Returns true if a player has won, false otherwise
     */
    bool checkRowWin();

    /**
     * @brief checkColWin Checks to see if either player has won via column
     * @return Returns true if a player has won, false otherwise
     */
    bool checkColWin();

    /**
     * @brief checkDiagWin Checks to see if either player has won via diagonal
     * @return Returns true if a player has won, false otherwise
     */
    bool checkDiagWin();

    /**
     * @brief checkBoard Checks for open board spaces
     * @return Returns true if there are no empty board spaces left, false if otherwise
     */
    bool checkBoard();

    /**
     * @brief getWinner Gets winning player character
     * @return Returns the winner ("X" or "O")
     */
    char getWinner();

    /**
     * @brief isValidMove Checks to see if player move is valid
     * @param row Player's current move (row)
     * @param col Player's current move (column)
     * @return If the move is within the required domain (1-3), and the board space is open, returns true. Otherwise, returns false
     */
    bool isValidMove(int row, int col);

    /**
     * @brief makeMove Places current player's character in the selected board space, and changes player turn
     * @param row Player's current move (row)
     * @param col Player's current move (column)
     */
    void makeMove(int row, int col);
};

#endif // TICTACTOE
