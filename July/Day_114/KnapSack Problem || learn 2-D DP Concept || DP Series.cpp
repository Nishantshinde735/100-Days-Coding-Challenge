#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapSack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<int> dp(W + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }
    
    return dp[W];
}

int main() {
    int W = 50; // Knapsack capacity
    vector<int> weights = {10, 20, 30}; // Weights of items
    vector<int> values = {60, 100, 120}; // Values of items
    int n = weights.size(); // Number of items

    cout << "Maximum value in Knapsack: " << knapSack(W, weights, values, n) << endl;
    return 0;
}
