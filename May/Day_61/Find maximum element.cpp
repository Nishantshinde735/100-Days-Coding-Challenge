#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> slidingWindowMaximum(const vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;  // Double-ended queue

    for (int i = 0; i < nums.size(); i++) {
        
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

     
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

   
        dq.push_back(i);

       
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = slidingWindowMaximum(nums, k);

    cout << "Sliding window maximums: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
