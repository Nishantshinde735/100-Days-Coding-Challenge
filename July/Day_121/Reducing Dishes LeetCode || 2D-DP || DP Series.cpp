#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + j * satisfaction[i-1]);
        }
    }

    int maxSatisfaction = 0;
    for (int j = 1; j <= n; ++j) {
        maxSatisfaction = max(maxSatisfaction, dp[n][j]);
    }

    return maxSatisfaction;
}

int main() {
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout << "Maximum satisfaction: " << maxSatisfaction(satisfaction) << endl;
    return 0;
}
