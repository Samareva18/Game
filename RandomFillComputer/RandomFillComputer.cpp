#include <iostream>
#include "string"
#include "ctime"

using namespace std;

class Cell {
public:
    int row; //строка
    int colomn; //столбец
    bool ship;
    string fill;

    Cell() {
        row = 0;
        colomn = 0;
        ship = 0;
        fill = "";
    }
};

void Print(Cell coordinates[10][10]) {
    cout << "  1  2  3  4  5  6  7  8  9  10"<< endl;
    for (int i = 0; i < 10; i++) {
        cout << i+1;
        for (int j = 0; j < 10; j++) {
            cout << coordinates[i][j].fill;
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Cell coordinates[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            coordinates[i][j].fill = " . ";
            cout << "";
        }
    }

    unsigned int randVar = clock();
    randVar+=4730284671;

    if (randVar % 2 == 0) {
        coordinates[1][0].fill = " # ";
        coordinates[1][1].fill = " # ";
        coordinates[1][2].fill = " # ";
        coordinates[1][3].fill = " # ";
    } else {
        coordinates[2][0].fill = " # ";
        coordinates[2][1].fill = " # ";
        coordinates[2][2].fill = " # ";
        coordinates[2][3].fill = " # ";
    }

    if (randVar / 10 % 2 == 0) {
        coordinates[4][1].fill = " # ";
        coordinates[5][1].fill = " # ";
        coordinates[6][1].fill = " # ";
    } else {
        coordinates[4][2].fill = " # ";
        coordinates[5][2].fill = " # ";
        coordinates[6][2].fill = " # ";
    }

    if (randVar / 100 % 2 == 0) {
        coordinates[0][5].fill = " # ";
        coordinates[1][5].fill = " # ";
        coordinates[2][5].fill = " # ";
    } else {
        coordinates[0][6].fill = " # ";
        coordinates[1][6].fill = " # ";
        coordinates[2][6].fill = " # ";
    }
    if (randVar / 1000 % 2 == 0) {
        coordinates[4][4].fill = " # ";
        coordinates[4][5].fill = " # ";
    } else {
        coordinates[5][4].fill = " # ";
        coordinates[5][5].fill = " # ";
    }

    if (randVar / 10000 % 2 == 0) {
        coordinates[8][2].fill = " # ";
        coordinates[8][3].fill = " # ";
    } else {
        coordinates[9][2].fill = " # ";
        coordinates[9][3].fill = " # ";
    }

    if (randVar / 100000 % 2 == 0) {
        coordinates[7][7].fill = " # ";
        coordinates[8][7].fill = " # ";
    } else {
        coordinates[7][8].fill = " # ";
        coordinates[8][8].fill = " # ";
    }

    if (randVar / 1000000 % 2 == 0) {
        coordinates[1][8].fill = " # ";
    } else {
        coordinates[2][8].fill = " # ";
    }
    if (randVar / 10000000 % 2 == 0) {
        coordinates[4][7].fill = " # ";
    } else {
        coordinates[5][7].fill = " # ";
    }
    if (randVar / 100000000 % 2 == 0) {
        coordinates[7][5].fill = " # ";
    } else {
        coordinates[8][5].fill = " # ";
    }
    if (randVar / 1000000000 % 2 == 0) {
        coordinates[4][9].fill = " # ";
    } else {
        coordinates[5][9].fill = " # ";
    }

    Cell turnCoordinates[10][10];

    if (randVar%2 == 0){
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
            turnCoordinates[i][j].fill = coordinates[j][i].fill;
            }
        }
        coordinates[10][10] = turnCoordinates[10][10];
    }
    Print(coordinates);

    return 0;
}
