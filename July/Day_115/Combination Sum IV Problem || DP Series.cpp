#include <iostream>
#include <vector>

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; i++) {
        for (int num : nums) {
            if (i >= num) {
                dp[i] += dp[i - num];
            }
        }
    }

    return dp[target];
}

int main() {
    vector<int> nums = {1, 2, 3};
    int target = 4;
    cout << "Number of combinations: " << combinationSum4(nums, target) << endl;
    return 0;
}
