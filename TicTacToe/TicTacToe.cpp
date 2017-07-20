/**
  * @brief Assignment 1
  * @author Corey Hemphill
  */

#include <iostream>
#include <iomanip>
#include <string>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe() {}


void TicTacToe::print() {
    cout << right << setw(3) << "1";
    cout << right << setw(3) << "2";
    cout << right << setw(3) << "3";
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << left << setw(2) << (i + 1);
        for (int j = 0; j < 3; j++) {
            cout << left << setw(3) << board[i][j];
    }
        cout << endl;
    }
}


char TicTacToe::getCurrentPlayer() {
    return currentPlayer;
}


bool TicTacToe::isDone() {
    if (TicTacToe::checkRowWin()) {
        return true;
    }
    else if (TicTacToe::checkColWin()) {
        return true;
    }
    else if (TicTacToe::checkDiagWin()) {
        return true;
    }
    else if (TicTacToe::checkBoard()) {
        return true;
    }
    else {
        return false;
    }
}


bool TicTacToe::checkRowWin() {
    int totalRowX;
    int totalRowO;
    for (int i = 0; i < 3; i++) {
        totalRowX = 0;
        totalRowO = 0;
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                totalRowX += 1;
                if (totalRowX == 3) {
                    currentPlayer = 'X';
                    return true;
                }
            }
            else if (board[i][j] == 'O') {
                totalRowO += 1;
                if (totalRowO == 3) {
                    currentPlayer = 'O';
                    return true;
                }
            }
        }
    }
    return false;
}


bool TicTacToe::checkColWin() {
    int totalColX;
    int totalColO;
    for (int i = 0; i < 3; i++) {
        totalColX = 0;
        totalColO = 0;
        for (int j = 0; j < 3; j++) {
            if (board[j][i] == 'X') {
                totalColX += 1;
                if (totalColX == 3) {
                    currentPlayer = 'X';
                    return true;
                }
            }
            else if (board[j][i] == 'O') {
                totalColO += 1;
                if (totalColO == 3) {
                    currentPlayer = 'O';
                    return true;
                }
            }
        }
    }
    return false;
}


bool TicTacToe::checkDiagWin() {
    int totalDiagTopDownX = 0;
    int totalDiagTopDownO = 0;
    int totalDiagBotUpX = 0;
    int totalDiagBotUpO = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((i == 1) && (j == 1)) {
                if (board[i][j] == 'X') {
                    totalDiagBotUpX += 1;
                    totalDiagTopDownX += 1;
                    continue;
                }
                else if (board[i][j] == 'O') {
                    totalDiagBotUpO += 1;
                    totalDiagTopDownO += 1;
                    continue;
                }
            }
            else if ((i + j) == 2) {
                if (board[i][j] == 'X') {
                    totalDiagBotUpX += 1;
                    if (totalDiagBotUpX == 3) {
                        currentPlayer = 'X';
                        return true;
                    }
                }
                else if (board[i][j] == 'O') {
                    totalDiagBotUpO += 1;
                    if (totalDiagBotUpO == 3) {
                        currentPlayer = 'O';
                        return true;
                    }
                }
            }
            else if ((i == j)) {
                if (board[i][j] == 'X') {
                    totalDiagTopDownX += 1;
                    if (totalDiagTopDownX == 3) {
                        currentPlayer = 'X';
                        return true;
                    }
                }
                else if (board[i][j] == 'O') {
                    totalDiagTopDownO += 1;
                    if (totalDiagTopDownO == 3) {
                        currentPlayer = 'O';
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


bool TicTacToe::checkBoard() {
    int totalOpen = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j ++) {
            if (board[i][j] == '-') {
                totalOpen += 1;
                if (totalOpen >= 1) {
                    break;
                }
            }
        }
    }
    if (totalOpen == 0) {
        currentPlayer = '-';
        return true;
    }
    else
        return false;
}


char TicTacToe::getWinner() {
    return currentPlayer;
}


bool TicTacToe::isValidMove(int row, int col) {
    if (((row - 1) < 0) || ((row - 1) > 2)) {
        return false;
    }
    else if (((col - 1) < 0) || ((col - 1) > 2)) {
        return false;
    }
    else if (board[row - 1][col - 1] != '-') {
        return false;
    }
    else {
        return true;
    }
}


void TicTacToe::makeMove(int row, int col) {
    board[row - 1][col - 1] = currentPlayer;
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    }
    else {
        currentPlayer = 'X';
    }
}
