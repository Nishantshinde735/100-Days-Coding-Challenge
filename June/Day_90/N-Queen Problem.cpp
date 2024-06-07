#include <iostream>
#include <vector>
using namespace std;

// Function to print the solution
void printSolution(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Utility function to check if a queen can be placed on board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int N = board.size();

    // Check this row on the left side
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; j >= 0 && i < N; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Utility function to solve the N-Queen problem using backtracking
bool solveNQueenUtil(vector<vector<int>>& board, int col) {
    int N = board.size();

    // If all queens are placed
    if (col >= N) {
        return true;
    }

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueenUtil(board, col + 1)) {
                return true;
            }

            // If placing the queen in board[i][col] doesn't lead to a solution, remove the queen
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

// Function to solve the N-Queen problem
bool solveNQueen(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueenUtil(board, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    solveNQueen(N);

    return 0;
}
