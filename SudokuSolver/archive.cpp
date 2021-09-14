#include <iostream>
constexpr auto N = 9;


bool foundInRow(int grid[N][N], int row, int number);
bool foundInCol(int grid[N][N], int col, int number);
bool foundInBox(int grid[N][N], int row, int col, int number);
bool testAnswer(int grid[N][N], int row, int col, int number);

bool findUnassigned(int grid[N][N], int& row, int& col);

bool SolveSudoku(int grid[N][N]);
void printGrid(int grid[N][N]);

int(&createSudokuTable(int(&grid)[N][N]))[N][N]{
    std::cout << grid << std::endl;
    return grid;
}

//void createSudokuTable(int grid[N][N]) {
//    std::cout << grid << std::endl;
//}

bool SolveSudoku(int grid[N][N]) {
    int row, col;
    if (!findUnassigned(grid, row, col)) return true;

    for (int i = 1; i <= 9; i++) {
        if (testAnswer(grid, row, col, i)) {
            grid[row][col] = i;
            //std::cout << "Testing at (" << row << ", " << col << ") with " << i << std::endl;
            if (SolveSudoku(grid)) return true;

            grid[row][col] = 0;
        }
    }

    //std::cout << "Testing at (" << row << ", " << col << ") Failed." << std::endl;
    return false;
}

bool findUnassigned(int grid[N][N], int& row, int& col) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (grid[r][c] == 0) {
                row = r;
                col = c;
                return true;
            }
        }
    }

    //std::cout << "None found :(" << std::endl;
    return false;
}

bool testAnswer(int grid[N][N], int row, int col, int number) {
    return  !foundInRow(grid, row, number) &&
            !foundInCol(grid, col, number) &&
            !foundInBox(grid, row, col, number);
}

bool foundInRow(int grid[N][N], int row, int number) {
    for (int c = 0; c < N; c++) {
        //std::cout << "Row " << row << " Col " << c << " Number " << grid[row][c] << std::endl;
        if (grid[row][c] == number) return true;
    }
    return false;
}

bool foundInCol(int grid[N][N], int col , int number) {
    for (int r = 0; r < N; r++) {
        //std::cout << "Row " << r << " Col " << col << " Number " << grid[r][col] << std::endl;
        if (grid[r][col] == number) return true;
    }
    return false;
}

bool foundInBox(int grid[N][N], int row, int col, int number) {
    int box_row = row - row % 3;
    int box_col = col - col % 3;

    for (int r = box_row; r < box_row + 3; r++) {
        for (int c = box_col; c < box_col + 3; c++) {
            if (grid[r][c] == number) return true;
        }
    }

    return false;
}

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            printf("%2d", grid[row][col]);
        printf("\n");
    }
}



int main() {
    /*
     3 0 6 5 0 8 4 0 0
     5 2 0 0 0 0 0 0 0
     0 8 7 0 0 0 0 3 1
     0 0 3 0 1 0 0 8 0
     9 0 0 8 6 3 0 0 5
     0 5 0 0 9 0 6 0 0
     1 3 0 0 0 0 2 5 0
     0 0 0 0 0 0 0 7 4
     0 0 5 2 0 6 3 0 0
    */

    int grid[N][N] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0} };

    std::cout << SolveSudoku(grid) << std::endl;

    printGrid(grid);

    return 0;
}
