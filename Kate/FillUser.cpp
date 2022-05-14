#include <iostream>
#include <string>
#include <ctime>
#include <map>

class Cell {
public:
    int row; //строка
    int colomn; //столбец
    bool ship;
    std::string fill;

    Cell() {
        row = 0;
        colomn = 0;
        ship = 0;
        fill = "";
    }
};

void Print(Cell coordinates[10][10]) {
    std::cout << "  1  2  3  4  5  6  7  8  9  10" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << i + 1;
        for (int j = 0; j < 10; j++) {
            std::cout << coordinates[i][j].fill;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void All(std::map<std::string, int> &cu) {
    for (auto &item: cu) {
        std::cout << item.first << " " << item.second << std::endl;
    }
}

void DeliverShip(std::string **&A, int i, int j, std::string a, std::map<std::string, int> &alphabet) {
    std::string line1 = a.substr(0, 1);
    std::string column1, column2, line2;
    if (a[2] == '0') {
        column1 = a.substr(1, 2);
        line2 = a.substr(4, 1);
        column2 = a.substr(5, size(a) - 5);
    } else {
        column1 = a.substr(1, 1);
        line2 = a.substr(3, 1);
        column2 = a.substr(4, size(a) - 4);
    }
    int Column1 = std::stoi(column1);
    int Column2 = std::stoi(column2);
    if (alphabet[line1] == alphabet[line2]) {
        for (i = Column1; i < Column2 + 1; i++) {
            A[alphabet[line1]][i] = " # ";
        }
    } else {
        for (i = alphabet[line1]; i < alphabet[line2] + 1; i++)
            A[i][Column1] = " # ";
    }
    /* std::cout <<std::endl;
     for (int i = 1; i < 11; i++) {
         for (int j=1; j < 11; j++) {
             std::cout << A[i][j] << ' ';
         }
         std::cout <<std::endl;
     }
     */
}

int main() {
    Cell coordinates[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            coordinates[i][j].fill = " . ";
            std::cout << "";
        }
    }

    unsigned int randVar = clock();
    randVar *= 4730284671;

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

    if (randVar % 2 == 0) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                turnCoordinates[i][j].fill = coordinates[j][i].fill;
            }
        }
        coordinates[10][10] = turnCoordinates[10][10];
    }

    Print(coordinates);

    int sizeField = 11;
    std::map<std::string, int> alphabet = {
            {"A", 1},
            {"B", 2},
            {"C", 3},
            {"D", 4},
            {"E", 5},
            {"F", 6},
            {"G", 7},
            {"H", 8},
            {"I", 9},
            {"J", 10},
    };
    std::string **A = new std::string *[sizeField];
    std::cout << std::endl;
    for (int i = 1; i < sizeField; i++) {
        A[i] = new std::string[sizeField];
    }
    for (int i = 1; i < sizeField; i++) {
        for (int j = 1; j < sizeField; j++) {
            A[i][j] = " . ";
            // std::cout << A[i][j] << ' ';
        }
        // std::cout <<std::endl;
    }
    std::string shipData;


    //временно по умолчанию прописали

    DeliverShip(A, sizeField, sizeField, "A1-A4", alphabet);
    DeliverShip(A, sizeField, sizeField, "C2-E2", alphabet);
    DeliverShip(A, sizeField, sizeField, "B8-D8", alphabet);
    DeliverShip(A, sizeField, sizeField, "C4-C5", alphabet);
    DeliverShip(A, sizeField, sizeField, "F5-F6", alphabet);
    DeliverShip(A, sizeField, sizeField, "A1-A4", alphabet);
    DeliverShip(A, sizeField, sizeField, "H2-H3", alphabet);
    DeliverShip(A, sizeField, sizeField, "H6-H6", alphabet);
    DeliverShip(A, sizeField, sizeField, "F9-F9", alphabet);
    DeliverShip(A, sizeField, sizeField, "G4-G4", alphabet);

/*
 *
    std::cout << "Enter coordinates for  four - deck ship " << std::endl;
    std::cin >> shipData;
    DeliverShip(A, sizeField, sizeField, shipData, alphabet);
    for (int i = 0; i<2; i++) {
        std::cout << "Enter coordinates for three - deck ship " << std::endl;
        std::cin >> shipData;
        DeliverShip(A, sizeField, sizeField, shipData, alphabet);
    }
    for (int i = 0; i<3; i++) {
        std::cout << "Enter coordinates for two - deck ship " << std::endl;
        std::cin >> shipData;
        DeliverShip(A, sizeField, sizeField, shipData, alphabet);
    }
    for (int i = 0; i<4; i++) {
        std::cout << "Enter coordinates for one - deck ship " << std::endl;
        std::cin >> shipData;
        DeliverShip(A, sizeField, sizeField, shipData, alphabet);
    }
    */

    for (int i = 1; i < sizeField; i++) {
        for (int j = 1; j < sizeField; j++) {
            std::cout << A[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
