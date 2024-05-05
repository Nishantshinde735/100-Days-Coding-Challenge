#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int largestRectangleArea(const vector<int>& heights) {
    
    stack<int> s;

  
    vector<int> extendedHeights = heights;
    extendedHeights.push_back(0);

    int maxArea = 0;
    int i = 0;

   
    while (i < extendedHeights.size()) {
        if (s.empty() || extendedHeights[i] >= extendedHeights[s.top()]) {
            s.push(i);
            i++;
        } else {
            int height = extendedHeights[s.top()];
            s.pop();

            int width = s.empty() ? i : i - s.top() - 1;

            maxArea = max(maxArea, height * width);
        }
    }

    return maxArea;
}


int maxRectangleInBinaryMatrix(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

   
    vector<int> heights(cols, 0);

    int maxArea = 0;

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          
            if (matrix[i][j] == 1) {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }

   
        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main() {
    
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

   
    cout << "Binary Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

 
    int maxArea = maxRectangleInBinaryMatrix(matrix);

   
    cout << "Maximum rectangular area with all 1's: " << maxArea << endl;

    return 0;
}
