#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Cell {
    int row;
    int col;
    int time;
};

int minTimeToRottenOranges(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<Cell> q;
    int freshCount = 0;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j, 0});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    int maxTime = 0;

 
    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();

        
        for (int i = 0; i < 4; i++) {
            int newRow = curr.row + directions[i][0];
            int newCol = curr.col + directions[i][1];

           
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                grid[newRow][newCol] = 2; 
                q.push({newRow, newCol, curr.time + 1});
                freshCount--;
                maxTime = max(maxTime, curr.time + 1);
            }
        }
    }

   
    return freshCount == 0 ? maxTime : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 2, 0},
        {0, 0, 0, 1}
    };

    int minTime = minTimeToRottenOranges(grid);
    cout << "Minimum time to rot all fresh oranges: " << minTime << endl;

    return 0;
}
