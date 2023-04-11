#include <iostream>
#include <vector>

using namespace std;

const int N = 9;  // Size of the Sudoku grid
const int UNASSIGNED = 0;

// Helper function to print the Sudoku grid
void printGrid(const vector<vector<int>>& grid) {
  for (int row = 0; row < N; ++row) {
    for (int col = 0; col < N; ++col) cout << grid[row][col] << " ";
    cout << endl;
  }
}

// Helper function to check if a number is already used in a row
bool usedInRow(const vector<vector<int>>& grid, int row, int num) {
  for (int col = 0; col < N; ++col)
    if (grid[row][col] == num) return true;
  return false;
}

// Helper function to check if a number is already used in a column
bool usedInCol(const vector<vector<int>>& grid, int col, int num) {
  for (int row = 0; row < N; ++row)
    if (grid[row][col] == num) return true;

  return false;
}

// Helper function to check if a number is already used in a 3x3 subgrid
bool usedInSubgrid(const vector<vector<int>>& grid, int startRow, int startCol,
                   int num) {
  for (int row = 0; row < 3; ++row)
    for (int col = 0; col < 3; ++col)
      if (grid[startRow + row][startCol + col] == num) return true;
  return false;
}

// Helper function to check if a number is safe to place in a cell
bool isSafe(const vector<vector<int>>& grid, int row, int col, int num) {
  return !usedInRow(grid, row, num) && !usedInCol(grid, col, num) &&
         !usedInSubgrid(grid, row - row % 3, col - col % 3, num);
}

// Recursive function to solve the Sudoku grid
bool solveSudoku(vector<vector<int>>& grid, int row, int col) {
  if (row == N) return true;  // Base case: All rows have been filled

  // Check if we need to move to the next row
  if (col == N) return solveSudoku(grid, row + 1, 0);

  // Check if the current cell is already filled
  if (grid[row][col] != UNASSIGNED) return solveSudoku(grid, row, col + 1);

  // Try different numbers in the current cell
  for (int num = 1; num <= N; ++num) {
    if (isSafe(grid, row, col, num)) {
      grid[row][col] = num;
      if (solveSudoku(grid, row, col + 1)) return true;  // Found a solution
      grid[row][col] = UNASSIGNED;                       // Backtrack
    }
  }

  return false;  // No solution found
}

int main() {
  // Example input Sudoku grid (0 represents an unassigned cell)
  vector<vector<int>> grid = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 3, 0, 8, 5},
      {0, 0, 1, 0, 2, 0, 0, 0, 0},
      {0, 0, 0, 5, 0, 7, 0, 0, 0},
      {0, 0, 4, 0, 0, 0, 1, 0, 0},
      {0, 9, 0, 0, 0, 0, 0, 0, 0},
      {5, 0, 0, 0, 0, 0, 0, 7, 3},
      {0, 0, 2, 0, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 4, 0, 0, 0, 9}};

  cout << "This algorithm is slow! Be patient ..." << endl;
  if (solveSudoku(grid, 0, 0)) {
    cout << "Solution:\n";
    printGrid(grid);
  } else {
    cout << "No solution found.\n";
  }

  return 0;
}
