#include <iostream>
#include <string>
#include <ctime>
#include <map>

class Cell {
public:
    int row; //строка
    int colomn; //столбец
    bool ship;
    std::string fill; // . || #

    Cell() {
        row = 0;
        colomn = 0;
        ship = 0;
        fill = "";
    }
};

void Print(Cell coordinates[10][10]) {
    std::map<int, std::string> alph = {
            {1,  "A"},
            {2,  "B"},
            {3,  "C"},
            {4,  "D"},
            {5,  "E"},
            {6,  "F"},
            {7,  "G"},
            {8,  "H"},
            {9,  "I"},
            {10, "J"},
    };
    std::cout << "  1  2  3  4  5  6  7  8  9  10" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << alph[i + 1];
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

void DeliverShip(Cell ComputerCoordinates[10][10], int i, int j, std::string shipData,
                 std::map<std::string, int> &alphabet) {
    std::string line1 = shipData.substr(0, 1);
    std::string column1, column2, line2;
    if (shipData[2] == '0') {
        column1 = shipData.substr(1, 2);
        line2 = shipData.substr(4, 1);
        column2 = shipData.substr(5, size(shipData) - 5);
    } else {
        column1 = shipData.substr(1, 1);
        line2 = shipData.substr(3, 1);
        column2 = shipData.substr(4, size(shipData) - 4);
    }
    int Column1 = std::stoi(column1);
    int Column2 = std::stoi(column2);
    if (alphabet[line1] == alphabet[line2]) {
        for (i = Column1; i < Column2 + 1; i++) {
            ComputerCoordinates[alphabet[line1]-1][i-1].fill = " # ";
        }
    } else {
        for (i = alphabet[line1]; i < alphabet[line2] + 1; i++)
            ComputerCoordinates[i-1][Column1-1].fill = " # ";
    }
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

    Cell ComputerCoordinates[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ComputerCoordinates[i][j].fill = " . ";
            std::cout << "";
        }
    }

    std::string shipData;

    //временно по умолчанию прописали

    DeliverShip(ComputerCoordinates, sizeField, sizeField, "A1-A4", alphabet);
    DeliverShip(ComputerCoordinates, sizeField, sizeField, "C2-E2", alphabet);
    DeliverShip(ComputerCoordinates, sizeField, sizeField, "B8-D8", alphabet);
    DeliverShip(ComputerCoordinates, sizeField, sizeField, "C4-C5", alphabet);
    DeliverShip(ComputerCoordinates, sizeField, sizeField, "F5-F6", alphabet);
    DeliverShip(ComputerCoordinates, sizeField, sizeField, "I5-I5", alphabet);
    DeliverShip(ComputerCoordinates, sizeField, sizeField, "H2-H3", alphabet);
    DeliverShip(ComputerCoordinates, sizeField, sizeField, "H7-H7", alphabet);
    DeliverShip(ComputerCoordinates, sizeField, sizeField, "F9-F9", alphabet);
    DeliverShip(ComputerCoordinates, sizeField, sizeField, "I9-I9", alphabet);

    //запись координат пользователем
/*
   std::cout << "Enter coordinates for  four - deck ship " << std::endl;
   std::cin >> shipData;
   DeliverShip(ComputerCoordinates, sizeField, sizeField, shipData, alphabet);
   for (int i = 0; i<2; i++) {
       std::cout << "Enter coordinates for three - deck ship " << std::endl;
       std::cin >> shipData;
       DeliverShip(ComputerCoordinates, sizeField, sizeField, shipData, alphabet);
   }
   for (int i = 0; i<3; i++) {
       std::cout << "Enter coordinates for two - deck ship " << std::endl;
       std::cin >> shipData;
       DeliverShip(ComputerCoordinates, sizeField, sizeField, shipData, alphabet);
   }
   for (int i = 0; i<4; i++) {
       std::cout << "Enter coordinates for one - deck ship " << std::endl;
       std::cin >> shipData;
       DeliverShip(ComputerCoordinates, sizeField, sizeField, shipData, alphabet);
   }
   */

    Print(ComputerCoordinates);

    return 0;
}