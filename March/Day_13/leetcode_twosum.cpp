#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash_map;
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (hash_map.find(complement) != hash_map.end()) {
            result.push_back(hash_map[complement]);
            result.push_back(i);
            break;
        }
        hash_map[nums[i]] = i;
    }

    return result;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indices = twoSum(nums, target);

    if (indices.size() == 2) {
        cout << "Indices of the two numbers: " << indices[0] << " and " << indices[1] << endl;
    } else {
        cout << "No two elements sum up to the target." << endl;
    }

    return 0;
}
