#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
void printTable(char table[3][3]);
void playAgain(char* again);
void playerMove(char table[3][3], int x, int y);
bool win(char table[3][3], char b);
void computerMove(char* table[3][3], int x, int y);
void computerXY(char table[3][3]);
void emptyArray(char* table[3][3]);
bool equal(char table[3][3]);

int main(void) {
    char again = ' ';
    char table[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
    int x, y;
    printf("\n");

    do {
        bool z = false, b = false;
        do {
            printTable(table);
            printf("\n\nEnter your move (row,column) ");
            scanf("%d,%d", &x, &y);
            playerMove(table, x, y);
            z = win(table, 'X');
            if (z == true)
            {
                printf("Congratulations you won\n\n");
                printTable(table);
                break;
            }

            // will be a draw
            z = equal(table);
            if (z == true)
            {
                printf("\n\nDraw\n\n");
                printTable(table);
                break;
            }

            printf("\n\n");
            printTable(table);
            computerXY(table);
            printf("\n\nThe computer made its move");
            z = win(table, 'O');
            if (z == true)
            {
                printf("\n\nYou lost\n\n");
                printTable(table);
                break;
            }

            // will be a draw
            z = equal(table);
            if (z == true)
            {
                printf("\n\nDraw\n\n");
                printTable(table);
                break;
            }
            printf("\n\n");
        } while (z != true);
        playAgain(&again);
        emptyArray(table[0]);
    } while ((tolower(again) == 'c'));
    return 0;
}

void printTable(char table[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (column == 2 && row == 2) {
                printf(" %c ", table[row][column]);
            }
            else if (row == 2) {
                printf(" %c |", table[row][column]);
            }
            else if (column == 2) {
                printf(" %c  \n", table[row][column]);
                printf("---|---|---\n");
            }
            else {
                printf(" %c |", table[row][column]);
            }
        }
    }
}

void playAgain(char* again) {
    printf("\n\n\nDo you want to play again? (press c) ");
    scanf(" %c", again);
    printf("\n\n\n");
}

void playerMove(char table[3][3], int x, int y) {
    if (table[x - 1][y - 1] == ' ') {
        table[x - 1][y - 1] = 'X';
    }
    else {
        printf("Error: This field is already occupied. Please make another move.\n");
        int newX, newY;
        do {
            printf("Enter your new move (row, column): ");
            scanf("%d,%d", &newX, &newY);
        } while (table[newX - 1][newY - 1] != ' ');
        table[newX - 1][newY - 1] = 'X';
    }
}

bool win(char table[3][3], char b) {
    if (table[0][0] == b && table[1][1] == b && table[2][2] == b) {
        return true;
    }
    if (table[0][2] == b && table[1][1] == b && table[2][0] == b) {
        return true;
    }
    for (int row = 0; row < 3; row++)
    {
        bool t = false;
        for (int column = 0; column < 3; column++)
        {
            for (int i = 0; i < 3; i++) {
                bool f = true;
                if (column == i)
                    continue;
                if (table[row][column] == table[row][i] && table[row][column] == b 
                    && table[row][i] == b) { f = true; t = f; }
                else { f = false; t = f; break; }

            }
            if (t == true) { return true; }
        }
    }
    for (int column = 0; column < 3; column++)
    {
        bool t = false;
        for (int row = 0; row < 3; row++)
        {
            for (int i = 0; i < 3; i++) {
                bool f = true;
                if (row == i)
                    continue;
                if (table[row][column] == table[i][column] && table[row][column] == b 
                    && table[i][column] == b) { f = true; t = f; }
                else { f = false; t = f; break; }

            }
            if (t == true) { return true; }
        }
    }
    return false;
}

void computerXY(char table[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (table[row][column] == ' ') {
                table[row][column] = 'O';
                if (win(table, 'O')) {
                    computerMove(table, row + 1, column + 1);
                    return;
                }
                table[row][column] = ' ';
            }
        }
    }
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (table[row][column] == ' ') {
                table[row][column] = 'X';
                if (win(table, 'X')) {
                    computerMove(table, row + 1, column + 1);
                    return;
                }
                table[row][column] = ' ';
            }
        }
    }
    int availableMoves[9][2];
    int moveCount = 0;

    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (table[row][column] == ' ') {
                availableMoves[moveCount][0] = row;
                availableMoves[moveCount][1] = column;
                moveCount++;
            }
        }
    }

    if (moveCount > 0) {
        int randomMove = rand() % moveCount;
        int a = availableMoves[randomMove][0];
        int b = availableMoves[randomMove][1];
        computerMove(table, a + 1, b + 1);
    }
}

void computerMove(char* table[3][3], int x, int y) {
    char(*table2)[3] = table;
    *(*(table2 + x - 1) + y - 1) = 'O';
}


void emptyArray(char* tablo[3][3]) {
    char(*table2)[3] = tablo;
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++) {
            *(*(table2 + row) + column) = ' ';
        }
    }
}

bool equal(char table[3][3]) {
    for (int row = 0; row < 3; row++)
    {
        bool g = false;
        for (int column = 0; column < 3; column++) {
            if (table[row][column] != ' ')
                g = true;
            else
            {
                g = false;
                return false;
            }
        }
    }
    return true;
}