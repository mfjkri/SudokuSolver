#include <iostream>

constexpr int N = 9;
constexpr int S = 3; // S = sqrt(N)

bool isInRow(int grid[N][N], int row, int number);
bool isInCol(int grid[N][N], int col, int number);
bool isInBox(int grid[N][N], int row, int col, int number);
bool isSafe(int grid[N][N], int row, int col, int number);

bool fetchEmpty(int grid[N][N], int& row, int& col);
bool solveSudoku(int grid[N][N]);

void prettyPrint(int grid[N][N]);

void prettyPrint(int grid[N][N]) {
	for (int r = 0; r < N; r++) {
		
		for (int c = 0; c < N; c++) {
			switch (c < N - 1) {
			case true:
				std::cout << grid[r][c] << ", ";
				break;
			case false:
				std::cout << grid[r][c];
				break;
			}
		}
		std::cout << std::endl;
	}

}

bool solveSudoku(int grid[N][N]) {
	int row, col;

	if (!fetchEmpty(grid, row, col)) return true;

	for (int testNumber = 1; testNumber <= 9; testNumber++) {
		if (isSafe(grid, row, col, testNumber)) {
			grid[row][col] = testNumber;

			if (solveSudoku(grid)) return true;

			grid[row][col] = 0;
		}
	}

	return false;
}

bool fetchEmpty(int grid[N][N], int& row, int& col) {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (grid[r][c] == 0) {
				row = r;
				col = c;

				return true;
			}
		}
	}

	return false;
}

bool isInRow(int grid[N][N], int row, int number) {
	for (int c = 0; c < N; c++) {
		if (grid[row][c] == number) return true;
	}
	return false;
}

bool isInCol(int grid[N][N], int col, int number) {
	for (int r = 0; r < N; r++) {
		if (grid[r][col] == number) return true;
	}
	return false;
}

bool isInBox(int grid[N][N], int row, int col, int number) {
	int box_row = row - row % S;
	int box_col = col - col % S;

	for (int r = box_row; r < box_row + 3; r++) {
		for (int c = box_col; c < box_col + 3; c++) {
			if (grid[r][c] == number) return true;
		}
	}

	return false;
}

bool isSafe(int grid[N][N], int row, int col, int number) {
	return !isInRow(grid, row, number) && !isInCol(grid, col, number) && !isInBox(grid, row, col, number);
}

int main() {
	int grid[N][N] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
					{5, 2, 0, 0, 0, 0, 0, 0, 0},
					{0, 8, 7, 0, 0, 0, 0, 3, 1},
					{0, 0, 3, 0, 1, 0, 0, 8, 0},
					{9, 0, 0, 8, 6, 3, 0, 0, 5},
					{0, 5, 0, 0, 9, 0, 6, 0, 0},
					{1, 3, 0, 0, 0, 0, 2, 5, 0},
					{0, 0, 0, 0, 0, 0, 0, 7, 4},
					{0, 0, 5, 2, 0, 6, 3, 0, 0} };
	std::cout << solveSudoku(grid) << std::endl;

	prettyPrint(grid);
	
	return 0;
}