#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int last_day = days.back();
    vector<int> dp(last_day + 1, 0);
    vector<bool> travel_day(last_day + 1, false);
    
    for (int day : days) {
        travel_day[day] = true;
    }

    for (int i = 1; i <= last_day; ++i) {
        if (!travel_day[i]) {
            dp[i] = dp[i - 1];
            continue;
        }
        dp[i] = dp[i - 1] + costs[0]; // 1-day ticket
        dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]); // 7-day ticket
        dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]); // 30-day ticket
    }

    return dp[last_day];
}

int main() {
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    cout << "Minimum cost of tickets: " << mincostTickets(days, costs) << endl;
    return 0;
}

