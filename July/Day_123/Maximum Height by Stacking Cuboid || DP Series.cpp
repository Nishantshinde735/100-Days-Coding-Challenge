#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxHeight(vector<vector<int>>& cuboids) {
    // Normalize each cuboid so that dimensions are sorted
    for (auto& cuboid : cuboids) {
        sort(cuboid.begin(), cuboid.end());
    }

    // Sort cuboids
    sort(cuboids.begin(), cuboids.end());

    int n = cuboids.size();
    vector<int> dp(n);

    int maxHeight = 0;

    // Initialize dp array
    for (int i = 0; i < n; ++i) {
        dp[i] = cuboids[i][2];  // Initial height is the height of the cuboid itself
        for (int j = 0; j < i; ++j) {
            if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
            }
        }
        maxHeight = max(maxHeight, dp[i]);
    }

    return maxHeight;
}

int main() {
    vector<vector<int>> cuboids = {{50,45,20}, {95,37,53}, {45,23,12}};
    cout << "Maximum height by stacking cuboids: " << maxHeight(cuboids) << endl;
    return 0;
}
