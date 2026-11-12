#include <stdio.h>
#include <stdbool.h>

#define N 9

void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true; 
}

bool solveSudoku(int grid[N][N]) {
    int row = -1;
    int col = -1;
    bool isEmpty = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true; 
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    if (!isEmpty) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            // Assign tentative number
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false; 
}

int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Original Sudoku Grid:\n");
    printGrid(grid);
    printf("\n");

    if (solveSudoku(grid)) {
        printf("Solved Sudoku Grid:\n");
        printGrid(grid);
    } else {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}