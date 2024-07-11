#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();
    vector<vector<int>> dp(n, vector<int>(4, INT_MAX));

    dp[0][1] = 1; // Starting lane
    dp[0][2] = 0; // Starting lane
    dp[0][3] = 1; // Starting lane

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (obstacles[i] != j) {
                dp[i][j] = dp[i-1][j];
            }
        }

        for (int j = 1; j <= 3; ++j) {
            if (obstacles[i] != j) {
                dp[i][j] = min(dp[i][j], min(dp[i][1] + (j != 1), min(dp[i][2] + (j != 2), dp[i][3] + (j != 3))));
            }
        }
    }

    return min({dp[n-1][1], dp[n-1][2], dp[n-1][3]});
}

int main() {
    vector<int> obstacles = {0,1,2,3,0};
    cout << "Minimum sideways jumps: " << minSideJumps(obstacles) << endl;
    return 0;
}

