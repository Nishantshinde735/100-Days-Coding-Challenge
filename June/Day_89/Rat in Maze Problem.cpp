#include <iostream>
#include <vector>
using namespace std;

// Utility function to print the solution matrix
void printSolution(const vector<vector<int>>& solution) {
    for (const auto& row : solution) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Utility function to check if x, y is a valid position in the maze
bool isSafe(int x, int y, const vector<vector<int>>& maze) {
    int n = maze.size();
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

// Utility function to solve the maze problem using backtracking
bool solveMazeUtil(int x, int y, const vector<vector<int>>& maze, vector<vector<int>>& solution) {
    int n = maze.size();
    // If (x, y) is the bottom-right corner, we've found the solution
    if (x == n - 1 && y == n - 1 && maze[x][y] == 1) {
        solution[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is a valid move
    if (isSafe(x, y, maze)) {
        // Mark x, y as part of the solution path
        solution[x][y] = 1;

        // Move forward in the x direction
        if (solveMazeUtil(x + 1, y, maze, solution)) {
            return true;
        }

        // If moving in x direction doesn't give a solution,
        // then move down in the y direction
        if (solveMazeUtil(x, y + 1, maze, solution)) {
            return true;
        }

        // If moving in y direction doesn't give a solution,
        // then move backward in the x direction
        if (solveMazeUtil(x - 1, y, maze, solution)) {
            return true;
        }

        // If moving backward in x direction doesn't give a solution,
        // then move upward in the y direction
        if (solveMazeUtil(x, y - 1, maze, solution)) {
            return true;
        }

        // If none of the above movements work, then BACKTRACK:
        // Unmark x, y as part of the solution path
        solution[x][y] = 0;
        return false;
    }

    return false;
}

// Function to solve the Rat in a Maze problem
bool solveMaze(const vector<vector<int>>& maze) {
    int n = maze.size();
    vector<vector<int>> solution(n, vector<int>(n, 0));

    if (!solveMazeUtil(0, 0, maze, solution)) {
        cout << "No solution exists" << endl;
        return false;
    }

    printSolution(solution);
    return true;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);

    return 0;
}
