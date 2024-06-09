#include <iostream>
#include <vector>
using namespace std;

#define N 9

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (int r = 0; r < N; ++r) {
        for (int d = 0; d < N; ++d) {
            cout << board[r][d] << " ";
        }
        cout << endl;
    }
}

// Function to check if it is safe to place a number in the given row, column and box
bool isSafe(const vector<vector<int>>& board, int row, int col, int num) {
    for (int x = 0; x < N; ++x) {
        // Check the row
        if (board[row][x] == num) {
            return false;
        }
        // Check the column
        if (board[x][col] == num) {
            return false;
        }
        // Check the box
        if (board[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return false;
        }
    }
    return true;
}

// Utility function to solve the Sudoku problem using backtracking
bool solveSudoku(vector<vector<int>>& board) {
    int row = -1;
    int col = -1;
    bool isEmpty = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    // No empty space left, puzzle solved
    if (isEmpty) {
        return true;
    }

    // Try all possible numbers from 1 to 9
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;
            }
            board[row][col] = 0; // BACKTRACK
        }
    }
    return false;
}

int main() {
    vector<vector<int>> board = {
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

    if (solveSudoku(board)) {
        printBoard(board);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
