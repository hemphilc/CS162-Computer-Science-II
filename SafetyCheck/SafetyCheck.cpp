#include <iostream>

using namespace std;

const int BOARD_SIZE = 10;

void printBoard(char curBoard[BOARD_SIZE][BOARD_SIZE]) {
    cout << " ";
    for(int c = 0; c < BOARD_SIZE; c++)
        cout << c;
    cout << endl;
    for(int r = 0; r < BOARD_SIZE; r++) {
        cout << r;
        for(int c = 0; c < BOARD_SIZE; c++) {
            cout << curBoard[r][c] ;
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void getContamLocale(int& rowSource, int& colSource) {
    while(rowSource >= 0 && colSource >= 0) {
        cout << "Enter contaminated location (x y):" << endl;
        cin >> rowSource >> colSource;
        if(rowSource < BOARD_SIZE && colSource < BOARD_SIZE) {
            if(rowSource >= 0 && colSource >= 0) {
                break;
            }
        }
        cout << "(" << rowSource << ", " << colSource << ") is not a valid coordinate. ";
        cout << "Cannot place contaminate source outside of the boardspace..." << endl;
        cout << "Please try again..." << endl;
        rowSource = 0;
        colSource = 0;
    }
}

void placeWalls(char picture[BOARD_SIZE][BOARD_SIZE], const int& rowSource, const int& colSource) {
    int placeWallRow = 1;
    int placeWallCol = 1;
    while(placeWallRow >= 0 && placeWallCol >= 0) {
        cout << "Enter wall locations (x y), followed by 0 0 to indicate end of input:" << endl;
        cin >> placeWallRow >> placeWallCol;
        if(placeWallRow == 0 && placeWallCol == 0) {
            break;
        }
        else if(placeWallRow >= BOARD_SIZE || placeWallCol >= BOARD_SIZE) {
            cout << "Location not available: Coordinate does not exist..." << endl;
            placeWallRow = 1;
            placeWallCol = 1;
        }
        else if(placeWallRow < 0 || placeWallCol < 0) {
            cout << "Location not available: Coordinate does not exist..." << endl;
            placeWallRow = 1;
            placeWallCol = 1;
        }
        else if(placeWallRow == rowSource && placeWallCol == colSource) {
            cout << "Location not available: Cannot place wall on contaminate source..." << endl;
        }
        else if(picture[placeWallRow][placeWallCol] == '#') {
            cout << "Location not available: Wall already in place..." << endl;        
        }
        else {
            picture[placeWallRow][placeWallCol] = '#';
        }
        printBoard(picture);
    }
}

void contaminate(char picture[BOARD_SIZE][BOARD_SIZE], int sourceRow, int sourceCol, int& contamArea) {
    if(sourceRow < 0 || sourceCol < 0 || sourceRow >= BOARD_SIZE || sourceCol >= BOARD_SIZE) {
        return;
    }
    if(picture[sourceRow][sourceCol] != ' ') {
        return;
    }

    picture[sourceRow][sourceCol] = '.';
    contamArea += 1;

    contaminate(picture, sourceRow, sourceCol - 1, contamArea);
    contaminate(picture, sourceRow, sourceCol + 1, contamArea);
    contaminate(picture, sourceRow - 1, sourceCol, contamArea);
    contaminate(picture, sourceRow + 1, sourceCol, contamArea);
    contaminate(picture, sourceRow - 1, sourceCol - 1, contamArea);
    contaminate(picture, sourceRow - 1, sourceCol + 1, contamArea);
    contaminate(picture, sourceRow + 1, sourceCol - 1, contamArea);
    contaminate(picture, sourceRow + 1, sourceCol + 1, contamArea);
}

bool isExposed(char picture[BOARD_SIZE][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(picture[0][i] == '.' || picture[i][0] == '.') {
            return true;
        }
        else if(picture[9][i] == '.' || picture[i][9] == '.') {
            return true;
        }
    }
    return false;
}

int main()
{
    char picture[BOARD_SIZE][BOARD_SIZE] =
    {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};

    printBoard(picture);

    int rowContamSource = 0;
    int colContamSource = 0;
    getContamLocale(rowContamSource, colContamSource);

    placeWalls(picture, rowContamSource, colContamSource);

    int contamArea = 0;
    contaminate(picture, rowContamSource, colContamSource, contamArea);
    printBoard(picture);
    if(isExposed(picture) == true) {
        cout << "Not Safe!" << endl;
    }
    else {
        cout << "Safe!" << endl;
        cout << "Contaminated area: " << contamArea << endl;
    }

    return 0;
}
