#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes) {
    if (envelopes.empty()) return 0;

    // Sort envelopes by width ascending, and by height descending if widths are the same
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });

    // Extract the heights
    vector<int> heights;
    for (const auto& envelope : envelopes) {
        heights.push_back(envelope[1]);
    }

    // Find LIS of heights using binary search
    vector<int> dp;
    for (int height : heights) {
        auto it = lower_bound(dp.begin(), dp.end(), height);
        if (it == dp.end()) {
            dp.push_back(height);
        } else {
            *it = height;
        }
    }

    return dp.size();
}

int main() {
    vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
    cout << "Maximum number of envelopes: " << maxEnvelopes(envelopes) << endl;
    return 0;
}



